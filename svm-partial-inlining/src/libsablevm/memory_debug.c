/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**
 * \file memory_debug.c
 * \brief Memory leak detecting mode implementation
 */

#define MEMORY_BLOCK_SIZE (1<<19)	/* 524288  */
#define ALLOC_HISTORY_MAX_LINE_SIZE 150

/* #define ALLOC_HISTORY_FILENAME "allocation_history.log"  */
#define RESULTS_FILENAME "memory_debug_results"

/* This debugging mode uses one global variable */
_svmt_mdebug_env *_svmv_mdebug_env_ptr;

/*
----------------------------------------------------------------------
_svmf_tree_compare_mdebug_alloc_info 
----------------------------------------------------------------------
*/

inline static jint
_svmf_tree_compare_mdebug_alloc_info (_svmt_mdebug_alloc_info_node * value1,
				      _svmt_mdebug_alloc_info_node * value2)
{
  assert (value1 != NULL);
  assert (value2 != NULL);

  if (value1->ptr > value2->ptr)
    return 1;

  if (value1->ptr < value2->ptr)
    return -1;

  return 0;
}

/*
----------------------------------------------------------------------
_svmf_alloc_mdebug_memblock
----------------------------------------------------------------------
*/

inline static jint
_svmf_alloc_mdebug_memblock (_svmt_mdebug_memblock ** ptr)
{
  if ((*ptr = calloc (1, sizeof (_svmt_mdebug_memblock))) == NULL)
    {
      _svmf_printf (NULL, stderr,
		    "MDEBUG: Can't allocate memory for a _svmt_mdebug_memblock\n");
      return JNI_ERR;
    }

  if (((*ptr)->large_block =
       calloc (MEMORY_BLOCK_SIZE,
	       sizeof (_svmt_mdebug_alloc_info_node))) == NULL)
    {
      _svmf_printf (NULL, stderr,
		    "MDEBUG: Can't allocate _svmt_mdebug_memblock->large_block\n");
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_get_alloc_info_struct
----------------------------------------------------------------------
*/

inline static jint
_svmf_get_alloc_info_struct (_svmt_mdebug_alloc_info_node ** ptr)
{
  _svmt_mdebug_env *md_env = _svmv_mdebug_env_ptr;

  if (md_env->current_memblock_offset == MEMORY_BLOCK_SIZE)
    {
      _svmf_alloc_mdebug_memblock (&md_env->current_memblock->next);
      md_env->current_memblock_offset = 0;
      md_env->current_memblock = md_env->current_memblock->next;
    }

  *ptr =
    md_env->current_memblock->large_block + md_env->current_memblock_offset;
  md_env->current_memblock_offset++;

  return JNI_OK;
}

/* --------------------------------------------------------------------------- */

/* Prototypes for splay trees functions */

inline svm_static void
_svmf_tree_splay_mdebug_alloc_info (_svmt_mdebug_alloc_info_node ** proot,
				    _svmt_mdebug_alloc_info_node * node);

#define _svmm_tree_find_mdebug_alloc_info(root, value) \
_svmh_tree_find_mdebug_alloc_info (&root, value)

svm_static _svmt_mdebug_alloc_info_node
  * _svmh_tree_find_mdebug_alloc_info (_svmt_mdebug_alloc_info_node ** proot,
				       _svmt_mdebug_alloc_info_node * value);

#define _svmm_tree_insert_mdebug_alloc_info(root, value) \
_svmh_tree_insert_mdebug_alloc_info (&root, value)

svm_static void
_svmh_tree_insert_mdebug_alloc_info (_svmt_mdebug_alloc_info_node ** proot,
				     _svmt_mdebug_alloc_info_node * value);

#define _svmm_tree_remove_mdebug_alloc_info(root, node) \
_svmh_tree_remove_mdebug_alloc_info (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_mdebug_alloc_info (_svmt_mdebug_alloc_info_node ** proot,
				     _svmt_mdebug_alloc_info_node * node);

/* --------------------------------------------------------------------------- */

/*
----------------------------------------------------------------------
_svmf_mdebug_init
----------------------------------------------------------------------
*/

inline static void
_svmf_mdebug_init (void)
{
  _svmt_mdebug_env *md_env;

  if ((md_env = calloc (1, sizeof (_svmt_mdebug_env))) == NULL)
    {
      _svmf_printf (NULL, stderr,
		    "MDEBUG: Can't allocate memory for _svmt_mdebug_env\n");
    }

  _svmv_mdebug_env_ptr = md_env;

  md_env->history_curr_line = 1;
  md_env->mdebug_enabled = JNI_TRUE;

  _svmm_mutex_init (md_env->history_file_mutex);
  _svmm_mutex_init (md_env->addalloc_mutex);

  /*
     if ((md_env->alloc_history = fopen (ALLOC_HISTORY_FILENAME, "w+")) == NULL)
     {
     _svmf_printf (NULL, stderr, "MDEBUG: Can't open ");
     _svmf_printf (NULL, stderr, ALLOC_HISTORY_FILENAME);
     _svmf_printf (NULL, stderr, " file\n");
     }
   */

  if ((md_env->alloc_history = tmpfile ()) == NULL)
    {
      _svmf_printf (NULL, stderr,
		    "MDEBUG: Can't open temporary allocations history file\n");
    }

  if ((md_env->results_file = fopen (RESULTS_FILENAME, "w")) == NULL)
    {
      _svmf_printf (NULL, stderr, "MDEBUG: Can't open ");
      _svmf_printf (NULL, stderr, RESULTS_FILENAME);
      _svmf_printf (NULL, stderr, " file\n");
    }

  _svmf_alloc_mdebug_memblock (&md_env->memblock_list);
  md_env->current_memblock = md_env->memblock_list;
  md_env->current_memblock_offset = 0;

}

/*
----------------------------------------------------------------------
_svmf_mdebug_print2log
----------------------------------------------------------------------
*/

inline static void
_svmf_mdebug_print2log (const char *type, const char *func, const char *file,
			int line, int size, void *ptr_before, void *ptr_after)
{
  _svmt_mdebug_env *md_env = _svmv_mdebug_env_ptr;

  if (md_env->mdebug_enabled)
    {
      if (md_env->alloc_history != NULL)
	{
	  _svmm_mutex_lock (md_env->history_file_mutex);

	  /* no line number */
	  _svmf_printf (NULL, md_env->alloc_history,
			"%-9s %-45s %-30s %-6d %-10d %-12p %-12p\n", type,
			func, file, line, size, ptr_before, ptr_after);

	  /* with line number */
	  /*  _svmf_printf(NULL, md_env->alloc_history, "%-8d %-9s %-45s %-30s %-6d %-10d %-12p %-12p\n",
	     md_env->history_curr_line, type, func, file, line, size, ptr_before, ptr_after); */
	  md_env->history_curr_line++;
	  _svmm_mutex_unlock ();
	}
    }
}

/*
----------------------------------------------------------------------
_svmf_mdebug_add_alloc
----------------------------------------------------------------------
*/

inline static void
_svmf_mdebug_add_alloc (void *allocptr, jint nbbytes)
{
  _svmt_mdebug_env *md_env = _svmv_mdebug_env_ptr;
  _svmt_mdebug_alloc_info_node *alloc_info = NULL;

  if (md_env->mdebug_enabled)
    {
      _svmm_mutex_lock (md_env->addalloc_mutex);

      _svmf_get_alloc_info_struct (&alloc_info);

      alloc_info->ptr = allocptr;
      alloc_info->line = md_env->history_curr_line;
      alloc_info->nb_bytes = nbbytes;

      _svmm_tree_insert_mdebug_alloc_info (md_env->alloc_info_tree,
					   alloc_info);

      md_env->alloc_count++;
      md_env->alloc_bcount += nbbytes;

      _svmm_mutex_unlock ();
    }
}

/*
----------------------------------------------------------------------
_svmf_mdebug_remove_alloc
----------------------------------------------------------------------
*/

inline static void
_svmf_mdebug_remove_alloc (void *freed_ptr)
{
  _svmt_mdebug_env *md_env = _svmv_mdebug_env_ptr;
  _svmt_mdebug_alloc_info_node tmp;
  _svmt_mdebug_alloc_info_node *to_delete = NULL;

  tmp.ptr = freed_ptr;

  if (md_env->mdebug_enabled)
    {
      _svmm_mutex_lock (md_env->addalloc_mutex);

      to_delete =
	_svmm_tree_find_mdebug_alloc_info (md_env->alloc_info_tree, &tmp);

      if (to_delete != NULL)
	{
	  md_env->freed_bcount += to_delete->nb_bytes;
	  _svmm_tree_remove_mdebug_alloc_info (md_env->alloc_info_tree,
					       to_delete);
	  md_env->free_count++;
	}

      _svmm_mutex_unlock ();
    }
}

/*
----------------------------------------------------------------------
_svmf_u64_compar
----------------------------------------------------------------------
*/

static int
_svmf_u64_compar (const void *a, const void *b)
{
  _svmt_u64 *n1 = (_svmt_u64 *) a;
  _svmt_u64 *n2 = (_svmt_u64 *) b;

  if (*n1 > *n2)
    return 1;
  if (*n2 < *n2)
    return -1;
  return 0;
}

/*
----------------------------------------------------------------------
_svmf_mdebug_print_leaks
----------------------------------------------------------------------
*/

inline static void
_svmf_mdebug_print_leaks (_svmt_mdebug_env * md_env)
{
  _svmt_u32 i;
  _svmt_u32 nb_leaks;
  _svmt_u32 node_count = 0;
  _svmt_u64 curr_line = 0;
  _svmt_u64 *lines_to_print;

  char buf[ALLOC_HISTORY_MAX_LINE_SIZE];

  _svmt_mdebug_alloc_info_node *prev = NULL;
  _svmt_mdebug_alloc_info_node *current = md_env->alloc_info_tree;
  _svmt_mdebug_alloc_info_node *next = NULL;

  nb_leaks = md_env->alloc_count - md_env->free_count;

  if ((lines_to_print = malloc (nb_leaks * sizeof (_svmt_u64))) == NULL)
    {
      _svmf_printf (NULL, stderr,
		    "MDEBUG: Can't allocate memory for lines_to_print array\n");
      return;
    }

  /* in-order iterative tree traversal - get line numbers to print */
  while (current != NULL)
    {
      if (prev == current->parent)
	{
	  prev = current;
	  next = current->left;
	}

      if (next == NULL || prev == current->left)
	{
	  md_env->unfreed_bcount += current->nb_bytes;
	  lines_to_print[node_count] = current->line;
	  node_count++;

	  prev = current;
	  next = current->right;
	}

      if (next == NULL || prev == current->right)
	{
	  prev = current;
	  next = current->parent;
	}

      current = next;
    }

  qsort (lines_to_print, nb_leaks, sizeof (_svmt_u64), _svmf_u64_compar);

  fseek (md_env->alloc_history, 0, SEEK_SET);

  for (i = 0; i < nb_leaks; i++)
    {
      while (curr_line != lines_to_print[i])
	{
	  curr_line++;
	  fgets (buf, ALLOC_HISTORY_MAX_LINE_SIZE, md_env->alloc_history);
	}
      fputs (buf, md_env->results_file);
    }

  free (lines_to_print);
}

/*
----------------------------------------------------------------------
_svmf_mdebug_print_stats
----------------------------------------------------------------------
*/

inline static void
_svmf_mdebug_print_stats (_svmt_mdebug_env * md_env)
{
  _svmf_printf (NULL, md_env->results_file,
		"\n%lli unfreed pointers indentified\n",
		md_env->alloc_count - md_env->free_count);
  _svmf_printf (NULL, md_env->results_file,
		"allocation count: %lli  free count: %lli\n",
		md_env->alloc_count, md_env->free_count);
  _svmf_printf (NULL, md_env->results_file,
		"%.1f%% of allocations unfreed\n\n",
		100.0 -
		((double) (md_env->free_count) / md_env->alloc_count * 100));

  _svmf_printf (NULL, md_env->results_file, "memory allocated:%10lli bytes\n",
		md_env->alloc_bcount);
  _svmf_printf (NULL, md_env->results_file, "unfreed memory:  %10lli bytes\n",
		md_env->unfreed_bcount);
  _svmf_printf (NULL, md_env->results_file, "freed memory:    %10lli bytes\n",
		md_env->freed_bcount);
  _svmf_printf (NULL, md_env->results_file,
		"%.1f%% of allocated memory unfreed\n",
		100.0 -
		((double) (md_env->freed_bcount) / md_env->alloc_bcount *
		 100));

  if (md_env->sys_exit == JNI_TRUE)
    _svmf_printf (NULL, md_env->results_file,
		  "\nThe Java program exited with a system exit\n");

  /* To be removed if using a temporary file */
  /*
     if (md_env->alloc_history != NULL)
     {
     _svmm_mutex_lock (md_env->history_file_mutex);
     fseek (md_env->alloc_history, 0, SEEK_END);
     _svmf_printf (NULL, md_env->alloc_history,
     "\nallocation count: %lli  free count: %lli\n",
     md_env->alloc_count, md_env->free_count);
     _svmm_mutex_unlock ();
     }
   */
}

/*
----------------------------------------------------------------------
_svmf_mdebug_cleanup
----------------------------------------------------------------------
*/

inline static void
_svmf_mdebug_cleanup (_svmt_mdebug_env * md_env)
{
  _svmt_mdebug_memblock *current, *tmp;

  _svmm_mutex_destroy (md_env->history_file_mutex);
  _svmm_mutex_destroy (md_env->addalloc_mutex);

  if (md_env->alloc_history != NULL)
    fclose (md_env->alloc_history);

  if (md_env->results_file != NULL)
    fclose (md_env->results_file);

  current = md_env->memblock_list;

  /* free memory blocks used for memory debugging */
  while (current != NULL)
    {
      tmp = current->next;
      free (current->large_block);
      free (current);
      current = tmp;
    }

  free (_svmv_mdebug_env_ptr);
}

/*
----------------------------------------------------------------------
_svmf_mdebug_finalize
----------------------------------------------------------------------
*/

inline static void
_svmf_mdebug_finalize (void)
{
  _svmt_mdebug_env *md_env = _svmv_mdebug_env_ptr;

  md_env->mdebug_enabled = JNI_FALSE;

  if (md_env->results_file != NULL)
    {
      _svmf_mdebug_print_leaks (md_env);
      _svmf_mdebug_print_stats (md_env);
    }
  _svmf_mdebug_cleanup (md_env);
}

/*
----------------------------------------------------------------------
_svmf_free_alloc_info_node
----------------------------------------------------------------------
*/

inline static void
_svmf_free_alloc_info_node (_svmt_mdebug_alloc_info_node * ptr)
{
  if (ptr != NULL)
    free (ptr);
}
