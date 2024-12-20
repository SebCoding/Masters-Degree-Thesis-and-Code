/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (_SABLEVM_GENCOPY_GC)
#include "gc_gencopy.h"

/*
----------------------------------------------------------------------
_svmf_heap_init_defaults
----------------------------------------------------------------------
*/

static void
_svmf_heap_init_defaults (_svmt_JavaVM *vm)
{
  vm->heap.global_gc = 0;
  vm->heap.nursery_size = SVM_HEAP_DEFAULT_NURSERY_SIZE;
  vm->heap.large_object_size = SVM_HEAP_DEFAULT_LARGE_OBJECT_SIZE;
  vm->heap.min_size = SVM_HEAP_DEFAULT_MIN_SIZE;
  vm->heap.max_size = SVM_HEAP_DEFAULT_MAX_SIZE;
  vm->heap.allocation_increment = SVM_HEAP_DEFAULT_ALLOCATION_INCREMENT;

  /* Ensure remember set is cleared */
  memset (&vm->heap.remember_set, 0, sizeof (_svmt_remember_set));
}

/*
----------------------------------------------------------------------
_svmf_heap_init
----------------------------------------------------------------------
*/

static jint
_svmf_heap_init (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (_svmm_validate_min_max_increment
      (vm->heap.min_size, vm->heap.max_size,
       vm->heap.allocation_increment) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Special case: No nursery, act as semi-space copying collector */
  if (vm->heap.nursery_size == 0)
    {
      vm->heap.large_object_size = 0;
    }

  if (vm->heap.nursery_size < 2 * vm->heap.large_object_size ||
      vm->heap.min_size <= 2 * vm->heap.nursery_size)
    {
      return JNI_ERR;
    }

  if (vm->heap.nursery_size)
    {
      /* Allocate Nursery */
      vm->heap.nursery_start = _svmm_malloc (vm->heap.nursery_size);

      if (vm->heap.nursery_start == NULL)
	{
	  return JNI_ERR;
	}
    }
  else
    {
      vm->heap.nursery_start = 0;
    }

  /* Allocate Mature Space */
  if (vm->heap.allocation_increment == 0)
    {
      if (vm->verbose_gc)
	{
	  _svmf_printf (env, stderr,
			"[verbose gc: allocating fixed size heap (%d + 2 * %d bytes)]\n",
			vm->heap.nursery_size, vm->heap.min_size);
	}
      vm->heap.start = _svmm_malloc (2 * vm->heap.min_size);
    }
  else
    {
      if (vm->verbose_gc)
	{
	  _svmf_printf (env, stderr,
			"[verbose gc: allocating initial heap (%d + %d bytes)]\n",
			vm->heap.nursery_size, vm->heap.min_size);
	}

      vm->heap.start = _svmm_malloc (vm->heap.min_size);
    }

  if (vm->heap.start == NULL)
    {
      return JNI_ERR;
    }

  vm->heap.nursery_alloc = vm->heap.nursery_start;
  vm->heap.nursery_end =
    (char *) vm->heap.nursery_start + vm->heap.nursery_size;

  vm->heap.alloc = vm->heap.start;
  vm->heap.end = (char *) vm->heap.start + vm->heap.min_size;

  vm->heap.hashcode_base_nursery = 0 - (size_t) vm->heap.nursery_start;
  vm->heap.hashcode_base = 0 - (size_t) vm->heap.start;
  vm->heap.next_heap = vm->heap.end;
  vm->heap.suggested_next_heap_size = vm->heap.min_size;

  if (vm->verbose_gc)
    {
      _svmf_printf (env, stderr, "Nursery Start: %x  Nursery End: %x\n",
		    vm->heap.nursery_start, vm->heap.nursery_end);
      _svmf_printf (env, stderr, "Mature Start: %x  Mature End: %x\n",
		    vm->heap.start, vm->heap.end);
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_copy_object
----------------------------------------------------------------------
*/

/* This function copies the object pointed to by obj to to_space. obj
 * may be NULL or pointing to an already copied object.  In all cases,
 * this function returns a pointer to the to_space copy (or NULL).
 */

inline static _svmt_object_instance *
_svmf_copy_object (_svmt_JNIEnv *env, _svmt_object_instance *obj,
		   void **pto_space_tail)
{
  _svmt_word lockword;

  /* NULL */
  if (obj == NULL)
    {
      return NULL;
    }

  assert (_svmf_in_heap (env, obj));

  lockword = obj->lockword;

  /* forward pointer */
  if (_svmf_lockword_is_forward_reference (lockword))
    {
      assert (((void *) lockword) < *pto_space_tail);
      assert (obj->vtable == ((_svmt_object_instance *) lockword)->vtable);

      return (_svmt_object_instance *) lockword;
    }

  /* we must copy the object */
#if defined (MAGIC)
  assert (strcmp (obj->magic, "SableVM") == 0);
#endif

  if (_svmf_lockword_is_array (lockword))
    {
      /* it's actually an array */
      _svmt_array_instance *array = (_svmt_array_instance *) obj;
      jint size = array->size;
      size_t instance_size =
	_svmf_aligned_size_t (sizeof (_svmt_array_instance));
      _svmt_word array_type = _svmf_lockword_get_array_type (array->lockword);
      _svmt_object_instance *result;

      assert (array->vtable->type->is_array);

      switch (array_type)
	{
	case SVM_TYPE_BOOLEAN:
	  {
	    instance_size += (((size_t) size) + 7) / 8;
	  }
	  break;

	case SVM_TYPE_BYTE:
	  {
	    instance_size += ((size_t) size);
	  }
	  break;

	case SVM_TYPE_SHORT:
	  {
	    instance_size += ((size_t) size) * 2;
	  }
	  break;

	case SVM_TYPE_CHAR:
	  {
	    instance_size += ((size_t) size) * 2;
	  }
	  break;

	case SVM_TYPE_INT:
	  {
	    instance_size += ((size_t) size) * 4;
	  }
	  break;

	case SVM_TYPE_LONG:
	  {
	    instance_size += ((size_t) size) * 8;
	  }
	  break;

	case SVM_TYPE_FLOAT:
	  {
	    instance_size += ((size_t) size) * 4;
	  }
	  break;

	case SVM_TYPE_DOUBLE:
	  {
	    instance_size += ((size_t) size) * 8;
	  }
	  break;

	case SVM_TYPE_REFERENCE:
	  {
	    instance_size += ((size_t) size) * sizeof (void *);
	  }
	  break;

	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;
	}

      instance_size = _svmf_aligned_size_t (instance_size);

#if defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

      memcpy (*pto_space_tail, array, instance_size);
      result = (_svmt_object_instance *) *pto_space_tail;

#elif defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

      /* if elements preceed object header, adjust head pointer
       * accordignly */
      if (array_type == SVM_TYPE_REFERENCE)
	{
	  size_t offset =
	    _svmf_aligned_size_t (((size_t) size) * sizeof (void *));

	  memcpy (*pto_space_tail, ((char *) array) - offset, instance_size);
	  result =
	    (_svmt_object_instance *) (((char *) *pto_space_tail) + offset);
	}
      else
	{
	  memcpy (*pto_space_tail, array, instance_size);
	  result = (_svmt_object_instance *) *pto_space_tail;
	}

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

      /* update to_space_tail */
      *pto_space_tail = ((char *) *pto_space_tail) + instance_size;

      /* set forward pointer */
      *((_svmt_object_instance **) array) = result;

#if defined (MAGIC)
      array->magic[0] = 0;
#endif

      /* we're done */
      return result;
    }

  /* it's a normal object */

  assert (!(obj->vtable->type->is_array));

  {
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

    size_t end_offset = _svmf_lockword_object_get_end_offset (lockword);
    size_t start_offset = _svmf_lockword_object_get_start_offset (lockword);
    size_t instance_size;
    _svmt_object_instance *result;

    if (end_offset == SVM_LOCKWORD_END_OVERFLOW_OFFSET)
      {
	end_offset = obj->vtable->next_offset_no_hashcode;
      }

    if (start_offset == SVM_LOCKWORD_START_OVERFLOW_OFFSET)
      {
	start_offset = obj->vtable->start_offset;
      }

    instance_size = start_offset + end_offset;

    switch (_svmf_lockword_get_hashstate (lockword))
      {
      case SVM_HASH_NONE:
	{
	  memcpy (*pto_space_tail, ((char *) obj) - start_offset,
		  instance_size);
	  result =
	    (_svmt_object_instance *) (((char *) *pto_space_tail) +
				       start_offset);
	}
	break;

      case SVM_HASH_NOT_MOVED:
	{
	  memcpy (*pto_space_tail, ((char *) obj) - start_offset,
		  instance_size);
	  result =
	    (_svmt_object_instance *) (((char *) *pto_space_tail) +
				       start_offset);

	  instance_size += SVM_ALIGNMENT;
	  _svmm_lockword_set_hashstate (result->lockword, SVM_HASH_MOVED);
	  if (_svmf_in_nursery (env, obj))
	    _svmf_put_INT_field (result, end_offset, (jint)
				 (env->vm->heap.hashcode_base_nursery +
				  (size_t) obj));
	  else
	    _svmf_put_INT_field (result, end_offset, (jint)
				 (env->vm->heap.hashcode_base -
				  (size_t) obj));
	}
	break;

      case SVM_HASH_MOVED:
	{
	  instance_size += SVM_ALIGNMENT;
	  memcpy (*pto_space_tail, ((char *) obj) - start_offset,
		  instance_size);
	  result =
	    (_svmt_object_instance *) (((char *) *pto_space_tail) +
				       start_offset);
	}
	break;

      default:
	{
	  result = NULL;
	  _svmm_fatal_error ("impossible control flow");
	}
	break;
      }

    /* update to_space_tail */
    *pto_space_tail = ((char *) *pto_space_tail) + instance_size;

    /* set forward pointer */
    *((_svmt_object_instance **) obj) = result;

#if defined (MAGIC)
    obj->magic[0] = 0;
#endif

    /* we're done */
    return result;

#elif defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

    size_t end_offset = _svmf_lockword_object_get_end_offset (lockword);
    size_t instance_size;
    _svmt_object_instance *result = NULL;

    if (_svmf_lockword_object_is_info_in_header (lockword))
      {
	end_offset = _svmf_lockword_object_get_end_offset (lockword);
      }
    else
      {
	end_offset = obj->vtable->next_offset_no_hashcode;
      }

    instance_size = end_offset;

    switch (_svmf_lockword_get_hashstate (lockword))
      {
      case SVM_HASH_NONE:
	{
	  memcpy (*pto_space_tail, obj, instance_size);
	  result = (_svmt_object_instance *) *pto_space_tail;
	}
	break;

      case SVM_HASH_NOT_MOVED:
	{
	  memcpy (*pto_space_tail, obj, instance_size);
	  result = (_svmt_object_instance *) *pto_space_tail;

	  instance_size += SVM_ALIGNMENT;
	  _svmm_lockword_set_hashstate (result->lockword, SVM_HASH_MOVED);
	  if (_svmf_in_nursery (env, obj))
	    _svmf_put_INT_field (result, end_offset, (jint)
				 (env->vm->heap.hashcode_base_nursery +
				  (size_t) obj));
	  else
	    _svmf_put_INT_field (result, end_offset, (jint)
				 (env->vm->heap.hashcode_base -
				  (size_t) obj));
	}
	break;

      case SVM_HASH_MOVED:
	{
	  instance_size += SVM_ALIGNMENT;
	  memcpy (*pto_space_tail, obj, instance_size);
	  result = (_svmt_object_instance *) *pto_space_tail;
	}
	break;

      default:
	{
	  _svmm_fatal_error ("impossible control flow");
	}
	break;
      }

    /* update to_space_tail */
    *pto_space_tail = ((char *) *pto_space_tail) + instance_size;

    /* set forward pointer */
    *((_svmt_object_instance **) obj) = result;

#if defined (MAGIC)
    obj->magic[0] = 0;
#endif

    /* we're done */
    return result;

#endif
  }
}

/*
----------------------------------------------------------------------
_svmf_trace_native_ref_list
----------------------------------------------------------------------
*/

static void
_svmf_trace_native_ref_list (_svmt_JNIEnv *env,
			     _svmt_native_ref *native_list,
			     void **pto_space_tail)
{
  if (env->vm->heap.global_gc)
    while (native_list != NULL)
      {
	native_list->ref =
	  _svmf_copy_object (env, native_list->ref, pto_space_tail);
	native_list = native_list->next;
      }
  else
    while (native_list != NULL)
      {
	if (_svmf_in_nursery (env, native_list->ref))
	  native_list->ref =
	    _svmf_copy_object (env, native_list->ref, pto_space_tail);
	native_list = native_list->next;
      }
}

/*
----------------------------------------------------------------------
_svmf_trace_stack
----------------------------------------------------------------------
*/

static void
_svmf_trace_stack (_svmt_JNIEnv *env, _svmt_JNIEnv *thread,
		   void **pto_space_tail)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *frame = thread->stack.current_frame;
  _svmt_method_frame_info *frame_info = frame->method_frame_info;
  _svmt_method_info *method = frame_info->method;

  while (method != &vm->stack_bottom_method)
    {
      if (!_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	{
	  _svmt_stack_value *locals = (_svmt_stack_value *)
	    (((char *) frame) - frame_info->start_offset);
	  _svmt_gc_map_node *parameters_gc_map = method->parameters_gc_map;
	  jint non_parameter_ref_locals_count =
	    frame_info->non_parameter_ref_locals_count;

	  _svmt_stack_value *stack = (_svmt_stack_value *)
	    (((char *) frame) + _svmv_stack_offset);
	  jint stack_size = frame->stack_size;
	  _svmt_gc_map_node *stack_gc_map =
	    (stack_size == 0) ? NULL : (frame->pc - 1)->stack_gc_map;

	  /* trace pointers embeded in the stack frame */
	  if (vm->heap.global_gc || _svmf_in_nursery (env, frame->this))
	    frame->this =
	      _svmf_copy_object (env, frame->this, pto_space_tail);
	  if (vm->heap.global_gc
	      || _svmf_in_nursery (env, frame->stack_trace_element))
	    frame->stack_trace_element =
	      _svmf_copy_object (env, frame->stack_trace_element,
				 pto_space_tail);

	  /* method formal parameters */
	  {
	    jint i;
	    jint count = parameters_gc_map->size;

	    if (vm->heap.global_gc)
	      for (i = 0; i < count; i++)
		{
		  if (_svmf_get_bit (parameters_gc_map->bits, i))
		    {
		      locals[i].reference =
			_svmf_copy_object (env, locals[i].reference,
					   pto_space_tail);
		    }
		}
	    else
	      for (i = 0; i < count; i++)
		{
		  if (_svmf_get_bit (parameters_gc_map->bits, i))
		    {
		      if (_svmf_in_nursery (env, locals[i].reference))
			locals[i].reference =
			  _svmf_copy_object (env, locals[i].reference,
					     pto_space_tail);
		    }
		}
	  }

	  /* other ref locals */
	  {
	    jint i;
	    jint start = method->java_args_count;
	    jint end = start + non_parameter_ref_locals_count;

	    if (vm->heap.global_gc)
	      for (i = start; i < end; i++)
		{
		  locals[i].reference =
		    _svmf_copy_object (env, locals[i].reference,
				       pto_space_tail);
		}
	    else
	      for (i = start; i < end; i++)
		{
		  if (_svmf_in_nursery (env, locals[i].reference))
		    locals[i].reference =
		      _svmf_copy_object (env, locals[i].reference,
					 pto_space_tail);
		}
	  }

	  /* stack */
	  if (stack_size > 0)
	    {
	      jint i;
	      jint max = _svmf_min_jint (stack_size, stack_gc_map->size);

	      if (vm->heap.global_gc)
		for (i = 0; i < max; i++)
		  {
		    if (_svmf_get_bit (stack_gc_map->bits, i))
		      {
			stack[i].reference =
			  _svmf_copy_object (env, stack[i].reference,
					     pto_space_tail);
		      }
		  }
	      else
		for (i = 0; i < max; i++)
		  {
		    if (_svmf_get_bit (stack_gc_map->bits, i))
		      {
			if (_svmf_in_nursery (env, stack[i].reference))
			  stack[i].reference =
			    _svmf_copy_object (env, stack[i].reference,
					       pto_space_tail);
		      }
		  }
	    }
	}

      frame = (_svmt_stack_frame *)
	(((char *) frame) - frame->previous_offset);
      frame_info = frame->method_frame_info;
      method = frame_info->method;
    }
}

/*
----------------------------------------------------------------------
_svmf_trace_remember_set
----------------------------------------------------------------------
*/

static void
_svmf_trace_remember_set (_svmt_JNIEnv *env, _svmt_remember_set * remset,
			  void **pto_space_tail)
{
  int i, j;

  for (i = 0; i < SVM_HEAP_REMSET_BUCKET_NUM; i++)
    {
      for (j = 0; j < SVM_HEAP_REMSET_BUCKET_SIZE; j++)
	{
	  if (remset->ref_hash[i][j] == NULL)
	    break;
	  else
	    {
	      if (_svmf_in_nursery
		  (env, *(_svmt_object_instance **) remset->ref_hash[i][j]))
		{
		  *(_svmt_object_instance **) remset->ref_hash[i][j] =
		    _svmf_copy_object
		    (env, *(_svmt_object_instance **) remset->ref_hash[i][j],
		     pto_space_tail);
		}
	      /* clear the remember set as we go */
	      remset->ref_hash[i][j] = NULL;
	    }
	}
    }
  if (remset->next != NULL)
    _svmf_trace_remember_set (env, remset->next, pto_space_tail);
}

/*
----------------------------------------------------------------------
_svmf_remember_set_add
----------------------------------------------------------------------
*/

static void
_svmf_remember_set_add (_svmt_remember_set * remset,
			_svmt_object_instance **reference)
{
  int i = (((int) reference >> 2) & (SVM_HEAP_REMSET_BUCKET_NUM - 1));
  int j;

  for (j = 0; j < SVM_HEAP_REMSET_BUCKET_SIZE; j++)
    {
      if (remset->ref_hash[i][j] == reference)
	return;
      else if (remset->ref_hash[i][j] == NULL)
	{
	  remset->ref_hash[i][j] = reference;
	  return;
	}
    }

  /* if haven't returned, this remset is full, add reference to next */
  if (remset->next == NULL)
    {
      remset->next = _svmm_malloc (sizeof (_svmt_remember_set));
      if (remset->next == NULL)
	_svmm_fatal_error ("Could not allocate additional remember set.");
      memset (remset->next, 0, sizeof (_svmt_remember_set));
    }
  _svmf_remember_set_add (remset->next, reference);
}

/*
----------------------------------------------------------------------
_svmf_remember_set_clear
----------------------------------------------------------------------        
*/

static void
_svmf_remember_set_clear (_svmt_remember_set * remset)
{
  int i, j;

  for (i = 0; i < SVM_HEAP_REMSET_BUCKET_NUM; i++)
    {
      for (j = 0; j < SVM_HEAP_REMSET_BUCKET_SIZE; j++)
	{
	  if (remset->ref_hash[i][j] == NULL)
	    break;
	  else
	    remset->ref_hash[i][j] = NULL;
	}
    }

  if (remset->next != NULL)
    _svmf_remember_set_clear (remset->next);
}

/*
----------------------------------------------------------------------
_svmf_gencopy_gc_internal
----------------------------------------------------------------------
*/

/* IMPORTANT: The world must be stopped prior to calling this
   function. */

static jint
_svmf_gencopy_gc_internal (_svmt_JNIEnv *env, size_t requested_size)
{
  _svmt_JavaVM *vm = env->vm;
  size_t increment = vm->heap.allocation_increment;

  void *to_space;
  size_t to_space_size;

  _svmt_word *to_space_head;
  void *to_space_tail;

  struct timeval starttime;
  struct timeval endtime;

  vm->heap.global_gc =
    (((size_t) ((char *) vm->heap.end - (char *) vm->heap.alloc) <
      vm->heap.nursery_size)
     || requested_size >= vm->heap.large_object_size) ? JNI_TRUE : JNI_FALSE;

  if (vm->heap.global_gc)
    {
      if (increment == 0)
	{
	  to_space = vm->heap.next_heap;
	  to_space_size = vm->heap.min_size;
	}
      else
	{
	  size_t current_heap_size =
	    ((char *) vm->heap.alloc) - ((char *) vm->heap.start) +
	    ((char *) vm->heap.nursery_alloc) -
	    ((char *) vm->heap.nursery_start);
	  size_t hash_code_size =
	    (vm->heap.hashed_notmoved +
	     vm->heap.hashed_notmoved_nursery) * SVM_ALIGNMENT;

	  size_t strict_min_size = _svmf_aligned_to_increment
	    (current_heap_size + hash_code_size, increment);

	  size_t min_size = _svmf_aligned_to_increment
	    (current_heap_size + hash_code_size + requested_size, increment);

	  size_t suggested_size = vm->heap.suggested_next_heap_size;

	  size_t ideal_size =
	    (suggested_size > min_size) ? suggested_size : min_size;

	  if ((to_space = _svmm_malloc (ideal_size)) != NULL)
	    {
	      to_space_size = ideal_size;
	    }
	  else if ((to_space = _svmm_malloc (min_size)) != NULL)
	    {
	      to_space_size = min_size;
	    }
	  else if ((to_space = _svmm_malloc (strict_min_size)) != NULL)
	    {
	      to_space_size = strict_min_size;
	    }
	  else
	    {
	      return JNI_ERR;
	    }
	}
    }
  else				/* Local GC */
    {
      to_space = vm->heap.alloc;
      to_space_size = (size_t) vm->heap.end - (size_t) vm->heap.alloc;
    }

  to_space_head = to_space;
  to_space_tail = to_space;

  if (vm->verbose_gc)
    {
      _svmf_printf (env, stderr, "[verbose gc: ");
      gettimeofday (&starttime, NULL);
    }

  /* trace stack & native refs */
  _svmf_trace_native_ref_list (env, vm->native_globals.list, &to_space_tail);

  {
    _svmt_JNIEnv *thread;

    for (thread = vm->threads.user; thread != NULL; thread = thread->next)
      {
	_svmf_trace_native_ref_list (env, thread->native_locals.list,
				     &to_space_tail);
	_svmf_trace_stack (env, thread, &to_space_tail);
      }

    for (thread = vm->threads.system; thread != NULL; thread = thread->next)
      {
	_svmf_trace_native_ref_list (env, thread->native_locals.list,
				     &to_space_tail);
	_svmf_trace_stack (env, thread, &to_space_tail);
      }
  }

  /* trace remember set on local gc */
  if (!vm->heap.global_gc)
    {
      _svmf_trace_remember_set (env, &vm->heap.remember_set, &to_space_tail);
    }
  else
    {
      _svmf_remember_set_clear (&vm->heap.remember_set);
    }

  /* trace tospace */
  while (((void *) to_space_head) < to_space_tail)
    {
      _svmt_word word = *to_space_head;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

      if (_svmf_word_is_reference (word))
	{
	  _svmt_object_instance *obj = ((_svmt_object_instance *) word);

	  assert ((((void *) obj) == NULL)
		  || _svmf_in_heap (env, obj)
		  || (((void *) obj) >= to_space
		      && (((void *) obj) < to_space_tail)));

	  if (vm->heap.global_gc || _svmf_in_nursery (env, obj))
	    {
	      *((_svmt_object_instance **) (to_space_head++)) =
		_svmf_copy_object (env, obj, &to_space_tail);
	    }
	  else
	    to_space_head++;
	  continue;
	}
#endif

      /* to_space_head is pointing to an object header */
      assert (!_svmf_word_is_reference (word));

      if (_svmf_lockword_is_array (word))
	{
	  /* it's actually an array */
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) to_space_head;
	  jint size = array->size;
	  size_t instance_size =
	    _svmf_aligned_size_t (sizeof (_svmt_array_instance));
	  _svmt_word array_type = _svmf_lockword_get_array_type (word);

	  switch (array_type)
	    {
	    case SVM_TYPE_BOOLEAN:
	      {
		instance_size += (((size_t) size) + 7) / 8;
		instance_size = _svmf_aligned_size_t (instance_size);
	      }
	      break;

	    case SVM_TYPE_BYTE:
	      {
		instance_size += ((size_t) size);
		instance_size = _svmf_aligned_size_t (instance_size);
	      }
	      break;

	    case SVM_TYPE_SHORT:
	      {
		instance_size += ((size_t) size) * 2;
		instance_size = _svmf_aligned_size_t (instance_size);
	      }
	      break;

	    case SVM_TYPE_CHAR:
	      {
		instance_size += ((size_t) size) * 2;
		instance_size = _svmf_aligned_size_t (instance_size);
	      }
	      break;

	    case SVM_TYPE_INT:
	      {
		instance_size += ((size_t) size) * 4;
		instance_size = _svmf_aligned_size_t (instance_size);
	      }
	      break;

	    case SVM_TYPE_LONG:
	      {
		instance_size += ((size_t) size) * 8;
		instance_size = _svmf_aligned_size_t (instance_size);
	      }
	      break;

	    case SVM_TYPE_FLOAT:
	      {
		instance_size += ((size_t) size) * 4;
		instance_size = _svmf_aligned_size_t (instance_size);
	      }
	      break;

	    case SVM_TYPE_DOUBLE:
	      {
		instance_size += ((size_t) size) * 8;
		instance_size = _svmf_aligned_size_t (instance_size);
	      }
	      break;

	    case SVM_TYPE_REFERENCE:
	      {
#if defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

		instance_size += ((size_t) size) * sizeof (void *);
		instance_size = _svmf_aligned_size_t (instance_size);

#endif
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }

#if defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

	  if (array_type == SVM_TYPE_REFERENCE)
	    {
	      /* trace references */
	      jint i;
	      _svmt_object_instance **elements = (_svmt_object_instance **)
		(((char *) array) +
		 _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

	      if (vm->heap.global_gc)
		for (i = 0; i < size; i++)
		  {
		    elements[i] =
		      _svmf_copy_object (env, elements[i], &to_space_tail);
		  }
	      else
		for (i = 0; i < size; i++)
		  {
		    if (_svmf_in_nursery (env, elements[i]))
		      elements[i] =
			_svmf_copy_object (env, elements[i], &to_space_tail);
		  }
	    }

#endif

	  /* skip to next object */
	  to_space_head = (_svmt_word *) (((char *) array) + instance_size);

	  continue;
	}

      /* it's a normal object */
      {
	_svmt_object_instance *obj = (_svmt_object_instance *) to_space_head;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

	size_t end_offset = _svmf_lockword_object_get_end_offset (word);

	if (end_offset == SVM_LOCKWORD_END_OVERFLOW_OFFSET)
	  {
	    end_offset = obj->vtable->next_offset_no_hashcode;
	  }

	switch (_svmf_lockword_get_hashstate (word))
	  {
	  case SVM_HASH_NONE:
	    {
	      /* do nothing */
	    }
	    break;

	  case SVM_HASH_MOVED:
	    {
	      end_offset += SVM_ALIGNMENT;
	    }
	    break;

	  case SVM_HASH_NOT_MOVED:
	    {
	      /* do nothing */
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }

	/* skip to next object */
	to_space_head = (_svmt_word *) (((char *) obj) + end_offset);

	continue;

#elif defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

	if (_svmf_lockword_object_is_info_in_header (word))
	  {
	    _svmt_word ref_layout =
	      _svmf_lockword_object_get_ref_layout (word);
	    size_t end_offset = _svmf_lockword_object_get_end_offset (word);
	    _svmt_object_instance **references = (_svmt_object_instance **)
	      (((char *) obj) +
	       _svmf_aligned_size_t (sizeof (_svmt_object_instance)));
	    jint i = 0;

	    /* trace reference fields */
	    if (vm->heap.global_gc)
	      while (ref_layout != 0)
		{
		  if ((ref_layout & 0x01) != 0)
		    {
		      references[i] =
			_svmf_copy_object (env, references[i],
					   &to_space_tail);
		    }

		  i++;
		  ref_layout = ref_layout >> 1;
		}
	    else
	      while (ref_layout != 0)
		{
		  if ((ref_layout & 0x01) != 0)
		    {
		      if (_svmf_in_nursery (env, references[i]))
			references[i] =
			  _svmf_copy_object (env, references[i],
					     &to_space_tail);
		    }

		  i++;
		  ref_layout = ref_layout >> 1;
		}

	    switch (_svmf_lockword_get_hashstate (word))
	      {
	      case SVM_HASH_NONE:
		{
		  /* do nothing */
		}
		break;

	      case SVM_HASH_MOVED:
		{
		  end_offset += SVM_ALIGNMENT;
		}
		break;

	      case SVM_HASH_NOT_MOVED:
	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

	    /* skip to next object */
	    to_space_head = (_svmt_word *) (((char *) obj) + end_offset);

	    continue;
	  }

	/* info is in vtable */
	{
	  jint count = obj->vtable->ref_field_count;
	  size_t *offsets = obj->vtable->ref_field_offsets;
	  size_t end_offset = obj->vtable->next_offset_no_hashcode;
	  jint i;

	  /* trace reference fields */
	  if (vm->heap.global_gc)
	    for (i = 0; i < count; i++)
	      {
		_svmt_object_instance **reference = (_svmt_object_instance **)
		  (((char *) obj) + offsets[i]);

		*reference =
		  _svmf_copy_object (env, *reference, &to_space_tail);
	      }
	  else
	    for (i = 0; i < count; i++)
	      {
		_svmt_object_instance **reference = (_svmt_object_instance **)
		  (((char *) obj) + offsets[i]);

		if (_svmf_in_nursery (env, *reference))
		  *reference =
		    _svmf_copy_object (env, *reference, &to_space_tail);
	      }

	  switch (_svmf_lockword_get_hashstate (word))
	    {
	    case SVM_HASH_NONE:
	      {
		/* do nothing */
	      }
	      break;

	    case SVM_HASH_MOVED:
	      {
		end_offset += SVM_ALIGNMENT;
	      }
	      break;

	    case SVM_HASH_NOT_MOVED:
	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }

	  /* skip to next object */
	  to_space_head = (_svmt_word *) (((char *) obj) + end_offset);

	  continue;
	}

#endif

      }
    }

  if (vm->verbose_gc)
    {
      gettimeofday (&endtime, NULL);
      if (vm->heap.global_gc)
	_svmf_printf (env, stderr,
		      "Global GC: current residency is %d of %d bytes, ",
		      ((char *) to_space_tail) - ((char *) to_space),
		      ((char *) vm->heap.end) - ((char *) vm->heap.start));
      else
	_svmf_printf (env, stderr,
		      "Local GC: %d bytes survived, %d mature space used, ",
		      ((char *) to_space_tail) - ((char *) to_space),
		      ((char *) to_space_tail) - ((char *) vm->heap.start));
    }

  assert (to_space_head == to_space_tail);

  if (vm->heap.global_gc)
    {
      vm->heap.hashed_notmoved = 0;
      vm->heap.hashcode_base -=
	((char *) vm->heap.alloc) - ((char *) vm->heap.start);

      if (increment != 0)
	{
	  size_t suggested_size;

	  _svmm_free (vm->heap.start);
	  vm->heap.start = to_space;
	  vm->heap.end = ((char *) to_space) + to_space_size;
	  vm->heap.alloc = to_space_head;

	  suggested_size = _svmf_aligned_to_increment
	    (3 * ((((char *) vm->heap.alloc) - ((char *) vm->heap.start)) +
		  requested_size), increment);

	  if (suggested_size < vm->heap.min_size)
	    {
	      suggested_size = vm->heap.min_size;
	    }

	  if (vm->heap.max_size != 0 && suggested_size > vm->heap.max_size)
	    {
	      suggested_size = vm->heap.max_size;
	    }

	  vm->heap.suggested_next_heap_size = vm->heap.max_size;

	  /* reduce new heap size if it's bigger than next suggested size */
	  {
	    char *suggestion = ((char *) vm->heap.start) + suggested_size;

	    if ((suggestion >= (((char *) vm->heap.alloc) + requested_size))
		&& (suggestion < (char *) vm->heap.end))
	      {
		vm->heap.end = suggestion;
	      }
	  }
	}
      else
	{
	  vm->heap.next_heap = vm->heap.start;
	  vm->heap.start = to_space;
	  vm->heap.end = ((char *) to_space) + vm->heap.min_size;
	}
    }
  else
    {
      vm->heap.hashcode_base_nursery +=
	((char *) vm->heap.nursery_alloc - (char *) vm->heap.nursery_start);
      vm->heap.hashed_notmoved -= vm->heap.hashed_notmoved_nursery;
    }

  vm->heap.hashed_notmoved_nursery = 0;
  vm->heap.alloc = to_space_tail;
  vm->heap.nursery_alloc = vm->heap.nursery_start;

  assert (to_space_tail < vm->heap.end);

  if (vm->verbose_gc)
    {
      long secs = endtime.tv_sec - starttime.tv_sec;
      long usecs = endtime.tv_usec - starttime.tv_usec;

      if (usecs < 0)
	{
	  usecs += 1000000;
	  secs -= 1;
	}

      _svmf_printf (env, stderr,
		    "gc time = %ld sec %ld usec]\n", secs, usecs);

      vm->heap.total_gc_secs += secs;
      vm->heap.total_gc_usecs += usecs;

      if (vm->heap.total_gc_usecs > 999999)
	{
	  vm->heap.total_gc_usecs -= 1000000;
	  vm->heap.total_gc_secs += 1;
	}
    }

  if (vm->heap.global_gc &&
      (vm->heap.suggested_next_heap_size -
       ((char *) vm->heap.alloc - (char *) vm->heap.start))
      < vm->heap.nursery_size)
    {
      return JNI_ERR;		/* Out of Heap Space. */
    }

  if (requested_size <=
      (size_t) (((char *) vm->heap.end) -
		((char *) vm->heap.alloc))
      || requested_size < vm->heap.large_object_size)
    {
      return JNI_OK;
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_gencopy_gc
----------------------------------------------------------------------
*/

/* IMPORTANT: The calling thread should hold the lock on
   vm->global_mutex when calling this function. */

static jint
_svmf_gencopy_gc_no_exception (_svmt_JNIEnv *env, size_t requested_size)
{
  _svmt_JavaVM *vm = env->vm;
  jint status;

  _svmf_stop_the_world (env);

  pthread_mutex_unlock (&vm->global_mutex);

  status = _svmf_gencopy_gc_internal (env, requested_size);

  pthread_mutex_lock (&vm->global_mutex);

  _svmf_resume_the_world (env);

  return status;
}

/*
----------------------------------------------------------------------
_svmf_gc_new_instance
----------------------------------------------------------------------
*/

static jint
_svmf_gc_new_instance (_svmt_JNIEnv *env, size_t instance_size,
		       void **pinstance)
{
  _svmt_JavaVM *vm = env->vm;
  void *result = NULL;
  jint status = JNI_OK;

  _svmm_mutex_lock (vm->global_mutex);

  _svmf_halt_if_requested (env);

  if (instance_size >= vm->heap.large_object_size)
    {
      if (((instance_size <= (size_t) ((char *) vm->heap.end -
				       (char *) vm->heap.alloc))
	   && (vm->heap.suggested_next_heap_size -
	       ((char *) vm->heap.end - (char *) vm->heap.start) +
	       ((char *) vm->heap.end - (char *) vm->heap.alloc)) >
	   (vm->heap.nursery_size + instance_size))
	  || ((status = _svmf_gencopy_gc_no_exception (env, instance_size))
	      == JNI_OK))
	{
	  result = vm->heap.alloc;
	  vm->heap.alloc = ((char *) vm->heap.alloc) + instance_size;
	}
    }
  else if ((instance_size <=
	    (size_t) (((char *) vm->heap.nursery_end) -
		      ((char *) vm->heap.nursery_alloc)))
	   || ((status = _svmf_gencopy_gc_no_exception (env, instance_size))
	       == JNI_OK))
    {
      result = vm->heap.nursery_alloc;
      vm->heap.nursery_alloc = ((char *) vm->heap.nursery_alloc) +
	instance_size;
    }

  _svmm_mutex_unlock ();

  if (status != JNI_OK)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  memset ((void *) result, 0, instance_size);

  *pinstance = result;

  return JNI_OK;
}

#endif /* defined (_SABLEVM_GENCOPY_GC) */
