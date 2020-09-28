/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (HAS_SYSTEM_CLEAR_CACHE)

/* A clever hack to avoid time consuming writing of an optimized
 * cache flush instruction for every architecture in the world.
 * Unfotunatelly it won't work w/o GCC (GBP) */
extern void __clear_cache (char *beg, char *end);

#endif /* defined (HAS_SYSTEM_CLEAR_CACHE) */

/* Beware: Architecture-specific pieces are in *alphabetical* order */
#if (( defined (__sparc__) || defined (__ia64__) || defined (__alpha__) \
    || defined (__i386__) || defined (__powerpc__) || defined (__s390__) \
    || defined (__hppa__) || defined (__arm__) || defined (__m68k__) \
    || defined (__mc68000__) || defined (__mips__) || defined (__mipsel__) \
    || defined (__x86_64__) || defined (_POWER)  \
     ) && defined (__GNUC__))

/*
----------------------------------------------------------------------
_svmf_iflush
----------------------------------------------------------------------
*/

/* This function updates the word "*pword" (pointed to by pword) in
   the INSTRUCTION cache, on processors with separate data and
   instruction caches.  This a requirement for getting the
   inline-threading engine to work on such relatively common
   processors. */

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
svm_static inline void
_svmf_iflush (_svmt_word *pword SVM_UNUSED)
{
#if defined (__i386__)

  /* do nothing */

#elif defined (HAS_SYSTEM_CLEAR_CACHE)
  __clear_cache ((char *) pword, (char *) (pword + 1));
#else
#error "SableVM is not prepared to run the inlined threaded interpreter on this kind of a system."
#endif /* defined (HAS_SYSTEM_CLEAR_CACHE) */
}
#endif /* defined (_SABLEVM_INLINED_THREADED_INTERPRETER) */

/*
----------------------------------------------------------------------
_svmh_compare_and_swap
----------------------------------------------------------------------
*/

#define _svmm_compare_and_swap(word, old_value, new_value) \
_svmh_compare_and_swap (&word, old_value, new_value)

/* this function ATOMICALLY does the following:

   if (*pword == old_value)
     {
       *pword = new_value;
       return 1;
     }
   else
     {
       return 0;
     }
*/

svm_static inline jboolean
_svmh_compare_and_swap (volatile _svmt_word *pword, _svmt_word old_value,
			_svmt_word new_value)
{
  /* Yes, some inline assembly source code... Unfortunaltely, this
     cannot be expressed in C. */

#if defined (__alpha__)
  register _svmt_word result, tmp;

/* *INDENT-OFF* */
  __asm__ __volatile__ ("1:  mb\n\t"			/* make sure */
			"    ldq_l      %1,%4\n\t"	/* load *pword into tmp (reg,<= mem) */
			"    cmpeq      %1,%5,%0\n\t"	/* result = (*pword == tmp) */
			"    beq        %0,3f\n\t"	/* nothing to do if they differ(0) - jump away */
			"    mov        %3,%1\n\t"	/* copy tmp<=new so that we didnt lose it */
			"    stq_c      %1,%4\n\t"	/* *pword = new_value (reg,=> mem) */
			"    beq        %1,2f\n\t"	/* store could fail! (%1 overwritten!) */
			"    mb\n\t"			/* make sure */
			"    br         3f\n\t"		/* were done */
			"2:  br         1b\n\t"		/* goto "again" */
			"3:  nop"
			:"=&r" (result), "=&r" (tmp), "=m" (*pword)
			:"r" (new_value), "m" (*pword), "r" (old_value));
/* *INDENT-ON* */

#elif defined (__hppa__)

  /* The only atomic insn available on hppa is "load and clear";
   * locks are initialized to 1 on hppa. In this simple implementation
   * we use a global lock to make compare-and-swap atomic
   */

#define __ldcw(a) ({ \
    unsigned int __ret; \
    __asm__ __volatile__("ldcw 0(%1),%0" : "=r" (__ret) : "r" (a)); \
    __ret; \
  })

  static struct
  {
    volatile unsigned int __attribute__ ((aligned (16))) lock;
  } lock;

  static int lock_initialized = 0;
  int result;

  if (!lock_initialized)
    {
      lock.lock = 1;
    }

  /* spinlock */
  while (__ldcw (&lock.lock) == 0);
  if (*pword == old_value)
    {
      *pword = new_value;
      result = 1;
    }
  else
    {
      result = 0;
    }
  /* unlock */
  lock.lock = 1;
  /* Prevent reordering */
  __asm__ __volatile__ ("":::"memory");

#elif defined (__i386__)

  /* On the ia32, cmpxchgl has a side effect.  When swapping fails,
     the following variable contains the value that is currently in
     *pword (presumably different from old_value). */

  _svmt_word current_value;
  _svmt_u8 result;

/* *INDENT-OFF* */
  __asm__ __volatile__ ("lock\n\t"
			"cmpxchgl %3, %1\n\t"
			"sete %0"
			:"=q" (result), "=m" (*pword), "=a" (current_value)
			:"r" (new_value), "m" (*pword), "a" (old_value)
			:"memory");
/* *INDENT-ON* */

#elif defined (__ia64__)

#include <ia64intrin.h>

  jboolean result;
  result = __sync_bool_compare_and_swap (pword, old_value, new_value);

#elif defined (__x86_64__)

  _svmt_word current_value;
  _svmt_u8 result;

/* *INDENT-OFF* */
  __asm__ __volatile__ ("lock\n\t"
                        "cmpxchgq %3, %1\n\t"
                        "sete %0"
                        :"=q" (result), "=m" (*pword), "=a" (current_value)
                        :"r" (new_value), "m" (*pword), "a" (old_value)
                        :"memory");
/* *INDENT-ON* */

#else
#error "SableVM is not prepared to run on this kind of a system; no atomic compare&swap defined."
#endif /* defined (__alpha__) */

  return result ? JNI_TRUE : JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmh_malloc
----------------------------------------------------------------------
*/

/* must return aligned memory */

#ifdef _SABLEVM_MEMORY_DEBUGGING

static void *
_svmh_malloc (const char *file, const char *func, int line, size_t size)
{
  void *tmp = malloc (size);

  if (tmp != NULL)
    {
      _svmf_mdebug_add_alloc (tmp, size);
      _svmf_mdebug_print2log ("malloc", func, file, line, size, NULL, tmp);
    }

  return tmp;
}

#else

static void *
_svmh_malloc (size_t size)
{
  return malloc (size);
}
#endif

/*
----------------------------------------------------------------------
_svmh_calloc
----------------------------------------------------------------------
*/

/* must return aligned memory */

#ifdef _SABLEVM_MEMORY_DEBUGGING

static void *
_svmh_calloc (const char *file, const char *func, int line, size_t nmemb,
	      size_t size)
{
  void *tmp = calloc (nmemb, size);

  if (tmp != NULL)
    {
      _svmf_mdebug_add_alloc (tmp, nmemb * size);
      _svmf_mdebug_print2log ("calloc", func, file, line, nmemb * size, NULL,
			      tmp);
    }

  return tmp;
}

#else

static void *
_svmh_calloc (size_t nmemb, size_t size)
{
  return calloc (nmemb, size);
}
#endif

/*
----------------------------------------------------------------------
_svmh_realloc
----------------------------------------------------------------------
*/

/* must return aligned memory */

#ifdef _SABLEVM_MEMORY_DEBUGGING

static void *
_svmh_realloc (const char *file, const char *func, int line, void *ptr,
	       size_t size)
{
  void *tmp = realloc (ptr, size);

  if (tmp != NULL)
    {
      _svmf_mdebug_remove_alloc (ptr);
      _svmf_mdebug_add_alloc (tmp, size);
      _svmf_mdebug_print2log ("realloc", func, file, line, size, ptr, tmp);
    }

  return tmp;
}

#else

static void *
_svmh_realloc (void *ptr, size_t size)
{
  return realloc (ptr, size);
}
#endif

/*
----------------------------------------------------------------------
_svmh_free
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

static void
_svmh_free (const char *file, const char *func, int line, void *ptr)
{
  free (ptr);
  _svmf_mdebug_remove_alloc (ptr);
  _svmf_mdebug_print2log ("free", func, file, line, 0, ptr, NULL);
}

#else

static void
_svmh_free (void *ptr)
{
  free (ptr);
}
#endif


#ifdef _SABLEVM_MEMORY_DEBUGGING

/* No logging of allocations and liberations */

/*
----------------------------------------------------------------------
_svmh_malloc_ndebug 
----------------------------------------------------------------------
*/

static void *
_svmh_malloc_ndebug (size_t size)
{
  return malloc (size);
}

/*
----------------------------------------------------------------------
_svmh_calloc_ndebug 
----------------------------------------------------------------------
*/

static void *
_svmh_calloc_ndebug (size_t nmemb, size_t size)
{
  return calloc (nmemb, size);
}

/*
----------------------------------------------------------------------
_svmh_realloc_ndebug 
----------------------------------------------------------------------
*/

#if 0
static void *
_svmh_realloc_ndebug (void *ptr, size_t size)
{
  return realloc (ptr, size);
}
#endif

/*
----------------------------------------------------------------------
_svmh_free_ndebug 
----------------------------------------------------------------------
*/

static void
_svmh_free_ndebug (void *ptr)
{
  free (ptr);
}
#endif /* ifdef _SABLEVM_MEMORY_DEBUGGING */

/*
----------------------------------------------------------------------
_svmf_prepare_class_lockword
----------------------------------------------------------------------
*/

/* lockword layout (high to low bits):
     1  : fat(1) / thin(0)
     15 :
       thin:
         10 : thread ID (min value = 0x0001, max value = 0x03ff)
	      (value = 0 means that the object is unlocked)
         5  : recursion count (min value = 0x000, max value = 0x01f)
       fat:
         15 : lock ID (min value = 0x00000, max value = 0x07fff)

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

     6 : start offset div alignment (overflow value = 0x03f)
     6 : end offset div alignment (overflow value = 0x03f) [add 1 if hash_moved]
     2 : no-hash(0x00) / hash-notmoved (0x01) / hash-moved (0x02)
     1 : non-array(0x0)
     1 : always 1 (to deferentiate header word from ptr)

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

     1 : unused (0)
     3 : end offset div alignment [add 1 if hash_moved]
     7 : reference fields bit layout
     1 : info in header (0) / overflow (1)
     2 : no-hash(0x00) / hash-notmoved (0x01) / hash-moved (0x02)
     1 : non-array(0x0)
     1 : always 1 (to deferentiate header word from ptr)

So, if a class type has a maximum of 12 words of fields, the layout of
reference fields is embedded in the object header.

#endif / * defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) * /

*/

svm_static void
_svmf_prepare_class_lockword (_svmt_class_info *class)
{
  _svmt_word lockword = 0;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)
  _svmt_word start = class->data.noninterface.start_offset / SVM_ALIGNMENT;
  _svmt_word end =
    (class->data.noninterface.next_offset_no_hashcode - _svmf_aligned_size_t
     (sizeof (_svmt_object_instance))) / SVM_ALIGNMENT;

  if (start > SVM_LOCKWORD_START_OVERFLOW)
    {
      start = SVM_LOCKWORD_START_OVERFLOW;
    }

  if (end > SVM_LOCKWORD_END_OVERFLOW)
    {
      end = SVM_LOCKWORD_END_OVERFLOW;
    }

  lockword = start << 10;
  lockword |= end << 4;
  lockword |= 0x01;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  _svmt_word end =
    (class->data.noninterface.next_offset_no_hashcode - _svmf_aligned_size_t
     (sizeof (_svmt_object_instance))) / sizeof (void *);
  _svmt_word offsets = 0;
  const size_t head_size =
    _svmf_aligned_size_t (sizeof (_svmt_object_instance));
  jint i;
  jint ref_field_count = class->data.noninterface.ref_field_count;
  size_t *ref_field_offsets = class->data.noninterface.ref_field_offsets;
  jboolean overflow = JNI_FALSE;

  if (end > 7)
    {
      overflow = JNI_TRUE;
    }
  else
    {
      for (i = 0; i < ref_field_count; i++)
	{
	  size_t bit = (ref_field_offsets[i] - head_size) / sizeof (void *);

	  assert (bit < 7);

	  offsets |= ((_svmt_word) 1) << bit;
	}
    }

  if (overflow)
    {
      lockword = 1 << 4;
    }
  else
    {
      lockword = end << 12;
      lockword |= offsets << 5;
    }

  lockword |= 0x01;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */

  assert (!_svmf_is_set_flag (class->access_flags, SVM_ACC_INTERFACE));

  class->data.noninterface.initial_lockword = lockword;
}

/*
----------------------------------------------------------------------
_svmf_prepare_array_lockword
----------------------------------------------------------------------
*/

/* lockword layout (high to low bits):
     1  : fat(1) / thin(0)
     15 :
       thin:
         10 : thread ID
         5  : recursion count
       fat:
         15 : lock ID

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

    10 : unused (0)
     4 : SVM_TYPE_XXX (base type)
     1 : array(0x1)
     1 : always 1 (to deferentiate header word from ptr)

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

    10 : unused (0)
     4 : SVM_TYPE_XXX (base type)
     1 : array(0x1)
     1 : always 1 (to deferentiate header word from ptr)

#endif / * defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) * /

*/

svm_static void
_svmf_prepare_array_lockword (_svmt_array_info *array)
{
  _svmt_word lockword = 0;
  _svmt_word type =
    (array->dimensions == 1) ? array->base_type : SVM_TYPE_REFERENCE;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  lockword |= type << 2;
  lockword |= 0x01 << 1;
  lockword |= 0x01;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  lockword |= type << 2;
  lockword |= 0x01 << 1;
  lockword |= 0x01;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */

  array->initial_lockword = lockword;
}

/*
----------------------------------------------------------------------
_svmf_initialize_thinlock_id
----------------------------------------------------------------------
*/

static inline void
_svmf_initialize_thinlock_id (_svmt_JNIEnv *env)
{
  assert (env->thread.id < 0x03ff);

  env->thread.thinlock_id = env->thread.id << 21;
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_extra_bits
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_get_extra_bits (_svmt_word lockword)
{
  return lockword & 0x0ffff;
}

/*
----------------------------------------------------------------------
_svmf_lockword_is_thin
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_lockword_is_thin (_svmt_word lockword)
{
  return (lockword & 0x80000000) == 0;
}

/*
----------------------------------------------------------------------
_svmf_lockword_is_forward_reference
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_lockword_is_forward_reference (_svmt_word lockword)
{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (lockword & 0x01) == 0;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (lockword & 0x01) == 0;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_thinlock_id
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_get_thinlock_id (_svmt_word lockword)
{
  return lockword & 0x7fe00000;
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_thread_id
----------------------------------------------------------------------
*/

inline static jint
_svmf_lockword_get_thread_id (_svmt_word lockword)
{
  return (lockword & 0x7fe00000) >> 21;
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_fatlockindex
----------------------------------------------------------------------
*/

inline static jint
_svmf_lockword_get_fatlock_index (_svmt_word lockword)
{
  return (lockword & 0x7fff0000) >> 16;
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_recursive_count
----------------------------------------------------------------------
*/

inline static jint
_svmf_lockword_get_thinlock_recursive_count (_svmt_word lockword)
{
  return (lockword & 0x001f0000) >> 16;
}

/*
----------------------------------------------------------------------
_svmf_lockword_thinlock
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_thinlock (_svmt_word thinlock_id, jint recursive_count,
			 _svmt_word extra_bits)
{
  return thinlock_id | (((_svmt_word) recursive_count) << 16) | extra_bits;
}

/*
----------------------------------------------------------------------
_svmf_lockword_fatlock
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_fatlock (_svmt_word fatlock_id, _svmt_word extra_bits)
{
  return (1 << 31) | (fatlock_id << 16) | extra_bits;
}

/*
----------------------------------------------------------------------
_svmf_lockword_is_array
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_lockword_is_array (_svmt_word lockword)
{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (lockword >> 1) & 0x01;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (lockword >> 1) & 0x01;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_array_type
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_get_array_type (_svmt_word lockword)
{
  assert (_svmf_lockword_is_array (lockword));

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (lockword >> 2) & 0x0f;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (lockword >> 2) & 0x0f;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_hashstate
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_get_hashstate (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (lockword >> 2) & 0x03;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (lockword >> 2) & 0x03;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */
}

/*
----------------------------------------------------------------------
_svmm_lockword_set_hashstate
----------------------------------------------------------------------
*/

#define _svmm_lockword_set_hashstate(lockword, state) \
_svmh_lockword_set_hashstate (&lockword, state)

inline static void
_svmh_lockword_set_hashstate (_svmt_word *plockword, _svmt_word state)
{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  *plockword = (*plockword & 0xFFFFFFF3) | (state << 2);

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  *plockword = (*plockword & 0xFFFFFFF3) | (state << 2);

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */
}

/*
----------------------------------------------------------------------
_svmf_lockword_object_get_end_offset
----------------------------------------------------------------------
*/

inline static size_t
_svmf_lockword_object_get_end_offset (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (((lockword >> 4) & 0x03f) * (size_t) SVM_ALIGNMENT) +
    _svmf_aligned_size_t (sizeof (_svmt_object_instance));

#elif defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (((lockword >> 12) & 0x07) * (size_t) SVM_ALIGNMENT) +
    _svmf_aligned_size_t (sizeof (_svmt_object_instance));

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */
}

/*
----------------------------------------------------------------------
_svmf_lockword_object_get_start_offset
----------------------------------------------------------------------
*/

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

inline static size_t
_svmf_lockword_object_get_start_offset (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

  return (((lockword >> 10) & 0x03f) * (size_t) SVM_ALIGNMENT);
}

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */

/*
----------------------------------------------------------------------
_svmf_lockword_object_is_info_in_header
----------------------------------------------------------------------
*/

#if defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

inline static jboolean
_svmf_lockword_object_is_info_in_header (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

  return ((lockword >> 4) & 0x01) == 0;
}

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

/*
----------------------------------------------------------------------
_svmf_lockword_object_get_ref_layout
----------------------------------------------------------------------
*/

#if defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

inline static _svmt_word
_svmf_lockword_object_get_ref_layout (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

  return (lockword >> 5) & 0x07f;
}

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

/*
----------------------------------------------------------------------
_svmf_word_is_reference
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_word_is_reference (_svmt_word word)
{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (word & 0x01) == 0;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (word & 0x01) == 0;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */
}

#endif /* (( defined (__sparc__) || ...) && defined (__GNUC__)) */
