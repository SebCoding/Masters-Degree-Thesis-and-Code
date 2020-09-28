/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_file_head
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_head:])";
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_file_tail
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_tail:])";
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zalloc_no_exception
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zalloc_no_exception)
 */

m4svm_define_begin v = ":], [:m4svm_global_zalloc_no_exception:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzalloc_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static jint
_svmh_gzalloc_$1_no_exception (const char *file, const char *func, int line,
			       $2 ** ptr)
{
  $2 *tmp;
  size_t size = sizeof ($2);

  tmp = _svmm_calloc_ndebug (1, size);

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  _svmf_mdebug_add_alloc (tmp, size);
  _svmf_mdebug_print2log ("calloc", func, file, line, size, NULL, tmp);

  *ptr = tmp;
  return JNI_OK;
}

#else

svm_static jint
_svmh_gzalloc_$1_no_exception ($2 ** ptr)
{
  $2 *tmp;

  tmp = _svmm_calloc (1, sizeof ($2));

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzfree_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static void SVM_UNUSED
_svmh_gzfree_$1_no_exception (const char *file, const char *func, int line,
			      $2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free_ndebug (*ptr);
  _svmf_mdebug_remove_alloc (*ptr);
  _svmf_mdebug_print2log ("free", func, file, line, 0, *ptr, NULL);

  *ptr = NULL;
}

#else

svm_static void SVM_UNUSED
_svmh_gzfree_$1_no_exception ($2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free (*ptr);
  *ptr = NULL;
}

#endif

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zmalloc_no_exception
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zmalloc_no_exception)
 */

m4svm_define_begin v = ":], [:m4svm_global_zmalloc_no_exception:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzmalloc_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static jint
_svmh_gzmalloc_$1_no_exception (const char *file, const char *func,
				int line, size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

  if (size < nmemb)
    return JNI_ERR;

  tmp = _svmm_calloc_ndebug (1, size);

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  _svmf_mdebug_add_alloc (tmp, size);
  _svmf_mdebug_print2log ("calloc", func, file, line, size, NULL, tmp);

  *ptr = tmp;
  return JNI_OK;
}

#else

svm_static jint
_svmh_gzmalloc_$1_no_exception (size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

  if (size < nmemb)
    return JNI_ERR;

  tmp = _svmm_calloc (1, size);

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

#endif


/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzmfree_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static void SVM_UNUSED
_svmh_gzmfree_$1_no_exception (const char *file, const char *func,
			       int line, $2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free_ndebug (*ptr);
  _svmf_mdebug_remove_alloc (*ptr);
  _svmf_mdebug_print2log ("free", func, file, line, 0, *ptr, NULL);

  *ptr = NULL;
}

#else

svm_static void SVM_UNUSED
_svmh_gzmfree_$1_no_exception ($2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free (*ptr);
  *ptr = NULL;
}

#endif

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zalloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_zalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static jint
_svmh_gzalloc_$1 (const char *file, const char *func, int line,
		  _svmt_JNIEnv *env, $2 ** ptr)
{
  $2 *tmp;

  size_t size = sizeof ($2);

  tmp = _svmm_calloc_ndebug (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  _svmf_mdebug_add_alloc (tmp, size);
  _svmf_mdebug_print2log ("calloc", func, file, line, size, NULL, tmp);

  *ptr = tmp;
  return JNI_OK;
}

#else

svm_static jint
_svmh_gzalloc_$1 (_svmt_JNIEnv *env, $2 ** ptr)
{
  $2 *tmp;

  tmp = _svmm_calloc (1, sizeof ($2));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static void SVM_UNUSED
_svmh_gzfree_$1 (const char *file, const char *func, int line, $2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free_ndebug (*ptr);
  _svmf_mdebug_remove_alloc (*ptr);
  _svmf_mdebug_print2log ("free", func, file, line, 0, *ptr, NULL);

  *ptr = NULL;
}

#else

svm_static void SVM_UNUSED
_svmh_gzfree_$1 ($2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free (*ptr);
  *ptr = NULL;
}

#endif

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_malloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_malloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_malloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gmalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static jint
_svmh_gmalloc_$1 (const char *file, const char *func, int line,
		  _svmt_JNIEnv *env, size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmm_malloc_ndebug (size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  _svmf_mdebug_add_alloc (tmp, size);
  _svmf_mdebug_print2log ("malloc", func, file, line, size, NULL, tmp);

  *ptr = tmp;
  return JNI_OK;
}

#else

svm_static jint
_svmh_gmalloc_$1 (_svmt_JNIEnv *env, size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmm_malloc (size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gmfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static void
_svmh_gmfree_$1 (const char *file, const char *func, int line, $2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free_ndebug (*ptr);
  _svmf_mdebug_remove_alloc (*ptr);
  _svmf_mdebug_print2log ("free", func, file, line, 0, *ptr, NULL);

  *ptr = NULL;
}

#else

svm_static void
_svmh_gmfree_$1 ($2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free (*ptr);
  *ptr = NULL;
}

#endif

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zmalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zmalloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_zmalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzmalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static jint
_svmh_gzmalloc_$1 (const char *file, const char *func, int line,
		   _svmt_JNIEnv *env, size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmm_calloc_ndebug (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  _svmf_mdebug_add_alloc (tmp, size);
  _svmf_mdebug_print2log ("calloc", func, file, line, size, NULL, tmp);

  *ptr = tmp;
  return JNI_OK;
}

#else

svm_static jint
_svmh_gzmalloc_$1 (_svmt_JNIEnv *env, size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmm_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

#endif

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzmfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

svm_static void SVM_UNUSED
_svmh_gzmfree_$1 (const char *file, const char *func, int line, $2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free_ndebug (*ptr);
  _svmf_mdebug_remove_alloc (*ptr);
  _svmf_mdebug_print2log ("free", func, file, line, 0, *ptr, NULL);

  *ptr = NULL;
}

#else

svm_static void SVM_UNUSED
_svmh_gzmfree_$1 ($2 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmm_free (*ptr);
  *ptr = NULL;
}

#endif

m4svm_define_end v = ":])";
