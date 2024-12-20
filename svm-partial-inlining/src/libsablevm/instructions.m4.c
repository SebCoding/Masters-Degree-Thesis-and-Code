/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* m4svm_file_name */
/*
----------------------------------------------------------------------
instructions
----------------------------------------------------------------------
*/
void
dummy ()
{
  switch (dummy)
    {
    case dummy:
      {

/*
----------------------------------------------------------------------
UNUSED BYTECODES
----------------------------------------------------------------------
*/
	/* m4_define([:m4svm_instruction_unused:], [: */
	m4svm_instruction_head ($1, $2);

	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_unused(BIPUSH, 1) */
	/* m4svm_instruction_unused(SIPUSH, 2) */
	/* m4svm_instruction_unused(LDC, 1) */
	/* m4svm_instruction_unused(LDC_W, 2) */
	/* m4svm_instruction_unused(LDC2_W, 2) */
	/* m4svm_instruction_unused(GETSTATIC, 2) */
	/* m4svm_instruction_unused(PUTSTATIC, 2) */
	/* m4svm_instruction_unused(GETFIELD, 2) */
	/* m4svm_instruction_unused(PUTFIELD, 2) */
	/* m4svm_instruction_unused(NEWARRAY, 1) */
	/* m4svm_instruction_unused(WIDE, -1) */
	/* m4svm_instruction_unused(GOTO_W, 4) */
	/* m4svm_instruction_unused(JSR_W, 4) */

	/* m4_undefine([:m4svm_instruction_unused:]) */

/*
----------------------------------------------------------------------
NOP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NOP, 0);

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ACONST_NULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ACONST_NULL, 0);

	stack[stack_size++].reference = NULL;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<I/F/L/D>CONST_<X> 
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_if_const_x:], [: */
	m4svm_instruction_head ($1CONST_$3, 0);

	stack[stack_size++].$2 = $4;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_const_x:], [: */
	m4svm_instruction_head ($1CONST_$3, 0);

	*(($2 *) (void *) &stack[stack_size]) = $4;
	stack_size += 2;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_if_const_x(I, jint, M1, -1)
	 * m4svm_instruction_if_const_x(I, jint, 0, 0)
	 * m4svm_instruction_if_const_x(I, jint, 1, 1)
	 * m4svm_instruction_if_const_x(I, jint, 2, 2)
	 * m4svm_instruction_if_const_x(I, jint, 3, 3)
	 * m4svm_instruction_if_const_x(I, jint, 4, 4)
	 * m4svm_instruction_if_const_x(I, jint, 5, 5)
	 * m4svm_instruction_ld_const_x(L, jlong, 0, 0)
	 * m4svm_instruction_ld_const_x(L, jlong, 1, 1)
	 * m4svm_instruction_if_const_x(F, jfloat, 0, 0)
	 * m4svm_instruction_if_const_x(F, jfloat, 1, 1)
	 * m4svm_instruction_if_const_x(F, jfloat, 2, 2)
	 * m4svm_instruction_ld_const_x(D, jdouble, 0, 0)
	 * m4svm_instruction_ld_const_x(D, jdouble, 1, 1) */

	/* m4_undefine([:m4svm_instruction_if_const_x:])
	 * m4_undefine([:m4svm_instruction_ld_const_x:]) */


/*
----------------------------------------------------------------------
LDC_INTEGER
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_INTEGER, -1);

	stack[stack_size++].jint = (pc++)->jint;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDC_FLOAT
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_FLOAT, -1);

	stack[stack_size++].jfloat = (pc++)->jfloat;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDC_STRING
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_STRING, -1);

	stack[stack_size++].reference = *((pc++)->jobject);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL ||
		strcmp (stack[stack_size - 1].reference->magic,
			"SableVM") == 0);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDC_LONG
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_LONG, -1);

	*((jlong *) (void *) &stack[stack_size]) = *((pc++)->pjlong);
	stack_size += 2;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDC_DOUBLE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_DOUBLE, -1);

	*((jdouble *) (void *) &stack[stack_size]) = *((pc++)->pjdouble);
	stack_size += 2;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<X>LOAD<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_if_load:], [: */
	m4svm_instruction_head ($1LOAD, 1);

	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].$2 = locals[indx].$2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_load:], [: */
	m4svm_instruction_head ($1LOAD, 1);

	{
	  jint indx = (pc++)->jint;
	  *(($2 *) (void *) &stack[stack_size]) =
	    *(($2 *) (void *) &locals[indx]);
	  stack_size += 2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_if_load(I, jint)
	 * m4svm_instruction_ld_load(L, jlong)
	 * m4svm_instruction_if_load(F, jfloat)
	 * m4svm_instruction_ld_load(D, jdouble) */

	/* m4_undefine([:m4svm_instruction_if_load:])
	 * m4_undefine([:m4svm_instruction_ld_load:]) */

	/* m4_define([:m4svm_instruction_if_load_x:], [: */
	m4svm_instruction_head ($1LOAD_$3, 0);

	stack[stack_size++].$2 = locals[$3].$2;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_load_x:], [: */
	m4svm_instruction_head ($1LOAD_$3, 0);

	*(($2 *) (void *) &stack[stack_size]) =
	  *(($2 *) (void *) &locals[$3]);
	stack_size += 2;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_if_load_x(I, jint, 0)
	 * m4svm_instruction_if_load_x(I, jint, 1)
	 * m4svm_instruction_if_load_x(I, jint, 2)
	 * m4svm_instruction_if_load_x(I, jint, 3)
	 * m4svm_instruction_ld_load_x(L, jlong, 0)
	 * m4svm_instruction_ld_load_x(L, jlong, 1)
	 * m4svm_instruction_ld_load_x(L, jlong, 2)
	 * m4svm_instruction_ld_load_x(L, jlong, 3)
	 * m4svm_instruction_if_load_x(F, jfloat, 0)
	 * m4svm_instruction_if_load_x(F, jfloat, 1)
	 * m4svm_instruction_if_load_x(F, jfloat, 2)
	 * m4svm_instruction_if_load_x(F, jfloat, 3)
	 * m4svm_instruction_ld_load_x(D, jdouble, 0)
	 * m4svm_instruction_ld_load_x(D, jdouble, 1)
	 * m4svm_instruction_ld_load_x(D, jdouble, 2)
	 * m4svm_instruction_ld_load_x(D, jdouble, 3) */

	/* m4_undefine([:m4svm_instruction_if_load_x:])
	 * m4_undefine([:m4svm_instruction_ld_load_x:]) */

	/* m4_define([:m4svm_instruction_ifcs_aload:], [: */
	m4svm_instruction_head ($1ALOAD, 0);

	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].$3 = _svmf_get_$2_array_element (array, indx);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_aload:], [: */
	m4svm_instruction_head ($1ALOAD, 0);

	{
	  jint indx = stack[stack_size - 1].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_size - 2].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  if (indx < 0 || indx >= size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  *(($3 *) (void *) &stack[stack_size - 2]) =
	    _svmf_get_$2_array_element (array, indx);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_ifcs_aload(I, int, jint)
	 * m4svm_instruction_ld_aload(L, long, jlong)
	 * m4svm_instruction_ifcs_aload(F, float, jfloat)
	 * m4svm_instruction_ld_aload(D, double, jdouble)
	 * m4svm_instruction_ifcs_aload(C, char, jint)
	 * m4svm_instruction_ifcs_aload(S, short, jint) */

	/* m4_undefine([:m4svm_instruction_ifcs_aload:])
	 * m4_undefine([:m4svm_instruction_ld_aload:]) */

/*
----------------------------------------------------------------------
ALOAD<X>
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ALOAD, 1);

	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].reference = locals[indx].reference;
	}

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	m4svm_instruction_tail ();

	/* m4_define([:m4svm_instruction_a_load_x:], [: */
	m4svm_instruction_head (ALOAD_$1, 0);

	stack[stack_size++].reference = locals[$1].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif
	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_a_load_x(0)
	 * m4svm_instruction_a_load_x(1)
	 * m4svm_instruction_a_load_x(2)
	 * m4svm_instruction_a_load_x(3) */

	/* m4_undefine([:m4svm_instruction_a_load:]) */

/*
----------------------------------------------------------------------
AALOAD
----------------------------------------------------------------------
*/
	m4svm_instruction_head (AALOAD, 0);

/* 	_svmf_printf_ptr(env, stderr, "AALOAD: 0 stack_size[%d]\n", stack_size); */

	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint size;

/* 	_svmf_printf_ptr(env, stderr, "AALOAD: 1\n"); */

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

/* 	_svmf_printf_ptr(env, stderr, "AALOAD: 2 array[%p]\n", array); */

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

/* 	_svmf_printf_ptr(env, stderr, "AALOAD: 3\n"); */

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }


/* 	_svmf_printf_ptr(env, stderr, "AALOAD: 4\n"); */

	  stack[stack_top].reference =
	    _svmf_get_reference_array_element (array, indx);
	}

#if defined (MAGIC)
	assert (stack[stack_size - 1].reference == NULL ||
		strcmp (stack[stack_size - 1].reference->magic,
			"SableVM") == 0);
#endif

/* 	_svmf_printf_ptr(env, stderr, "AALOAD: 5\n"); */

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
BALOAD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (BALOAD, 0);

	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint base_type;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  base_type = _svmf_cast_array (array->vtable->type)->base_type;

	  switch (base_type)
	    {
	    case SVM_TYPE_BYTE:
	      {
		stack[stack_top].jint =
		  _svmf_get_byte_array_element (array, indx);
	      }
	      break;

	    case SVM_TYPE_BOOLEAN:
	      {
		stack[stack_top].jint =
		  _svmf_get_boolean_array_element (array, indx);
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<X>STORE<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_ifa_store:], [: */
	m4svm_instruction_head ($1STORE, 1);

	{
	  jint indx = (pc++)->jint;
	  locals[indx].$2 = stack[--stack_size].$2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_store:], [: */
	m4svm_instruction_head ($1STORE, 1);

	{
	  jint indx = (pc++)->jint;
	  stack_size -= 2;
	  *(($2 *) (void *) &locals[indx]) =
	    *(($2 *) (void *) &stack[stack_size]);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_ifa_store(I, jint)
	 * m4svm_instruction_ld_store(L, jlong)
	 * m4svm_instruction_ifa_store(F, jfloat)
	 * m4svm_instruction_ld_store(D, jdouble)
	 * m4svm_instruction_ifa_store(A, reference) */

	/* m4_undefine([:m4svm_instruction_ifa_store:])
	 * m4_undefine([:m4svm_instruction_ld_store:]) */

	/* m4_define([:m4svm_instruction_ifa_store_x:], [: */
	m4svm_instruction_head ($1STORE_$3, 0);

	locals[$3].$2 = stack[--stack_size].$2;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_store_x:], [: */
	m4svm_instruction_head ($1STORE_$3, 0);

	stack_size -= 2;
	*(($2 *) (void *) &locals[$3]) =
	  *(($2 *) (void *) &stack[stack_size]);

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_ifa_store_x(I, jint, 0)
	 * m4svm_instruction_ifa_store_x(I, jint, 1)
	 * m4svm_instruction_ifa_store_x(I, jint, 2)
	 * m4svm_instruction_ifa_store_x(I, jint, 3)
	 * m4svm_instruction_ld_store_x(L, jlong, 0)
	 * m4svm_instruction_ld_store_x(L, jlong, 1)
	 * m4svm_instruction_ld_store_x(L, jlong, 2)
	 * m4svm_instruction_ld_store_x(L, jlong, 3)
	 * m4svm_instruction_ifa_store_x(F, jfloat, 0)
	 * m4svm_instruction_ifa_store_x(F, jfloat, 1)
	 * m4svm_instruction_ifa_store_x(F, jfloat, 2)
	 * m4svm_instruction_ifa_store_x(F, jfloat, 3)
	 * m4svm_instruction_ld_store_x(D, jdouble, 0)
	 * m4svm_instruction_ld_store_x(D, jdouble, 1)
	 * m4svm_instruction_ld_store_x(D, jdouble, 2)
	 * m4svm_instruction_ld_store_x(D, jdouble, 3)
	 * m4svm_instruction_ifa_store_x(A, reference, 0)
	 * m4svm_instruction_ifa_store_x(A, reference, 1)
	 * m4svm_instruction_ifa_store_x(A, reference, 2)
	 * m4svm_instruction_ifa_store_x(A, reference, 3) */

	/* m4_undefine([:m4svm_instruction_ifa_store_x:])
	 * m4_undefine([:m4svm_instruction_ld_store_x:]) */

	/* m4_define([:m4svm_instruction_ifcs_astore:], [: */
	m4svm_instruction_head ($1ASTORE, 0);

	{
	  $4 value = stack[--stack_size].$3;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_$2_array_element (array, indx, value);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_astore:], [: */
	m4svm_instruction_head ($1ASTORE, 0);

	{
	  $4 value = *(($3 *) (void *) &stack[(stack_size -= 2)]);
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_$2_array_element (array, indx, value);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_ifcs_astore(I, int, jint, jint)
	 * m4svm_instruction_ld_astore(L, long, jlong, jlong)
	 * m4svm_instruction_ifcs_astore(F, float, jfloat, jfloat)
	 * m4svm_instruction_ld_astore(D, double, jdouble, jdouble)
	 * m4svm_instruction_ifcs_astore(C, char, jint, jchar)
	 * m4svm_instruction_ifcs_astore(S, short, jint, jshort) */

	/* m4_undefine([:m4svm_instruction_ifcs_astore:])
	 * m4_undefine([:m4svm_instruction_ld_astore:]) */

/*
----------------------------------------------------------------------
BASTORE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (BASTORE, 0);

	{
	  jint value = stack[--stack_size].jint;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint base_type;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  if (indx < 0 || indx >= size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  base_type = _svmf_cast_array (array->vtable->type)->base_type;

	  switch (base_type)
	    {
	    case SVM_TYPE_BYTE:
	      {
		_svmf_set_byte_array_element (array, indx, value);
	      }
	      break;

	    case SVM_TYPE_BOOLEAN:
	      {
		_svmf_set_boolean_array_element (array, indx, value);
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
AASTORE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (AASTORE, 0);

	{
	  _svmt_object_instance *value = stack[--stack_size].reference;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  if (_svmf_set_reference_array_element_no_exception
	      (env, array, indx, value) != JNI_OK)
	    {			/* TODO: how to get into here using BTF ?! */
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arraystoreexception_handler);
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
POP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (POP, 0);

	stack_size--;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
POP2
----------------------------------------------------------------------
*/

	m4svm_instruction_head (POP2, 0);

	stack_size -= 2;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP, 0);

	stack[stack_size] = stack[stack_size - 1];
	stack_size++;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP_X1
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP_X1, 0);

	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value2;
	  stack[stack_size] = value1;
	  stack_size++;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP_X2
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP_X2, 0);

	{
	  _svmt_stack_value value3 = stack[stack_size - 3];
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 3] = value1;
	  stack[stack_size - 2] = value3;
	  stack[stack_size - 1] = value2;
	  stack[stack_size] = value1;
	  stack_size++;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP2
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP2, 0);

	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size++] = value2;
	  stack[stack_size++] = value1;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP2_X1
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP2_X1, 0);

	{
	  _svmt_stack_value value3 = stack[stack_size - 3];
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 3] = value2;
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value3;
	  stack[stack_size++] = value2;
	  stack[stack_size++] = value1;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP2_X2
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP2_X2, 0);

	{
	  _svmt_stack_value value4 = stack[stack_size - 4];
	  _svmt_stack_value value3 = stack[stack_size - 3];
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 4] = value2;
	  stack[stack_size - 3] = value1;
	  stack[stack_size - 2] = value4;
	  stack[stack_size - 1] = value3;
	  stack[stack_size++] = value2;
	  stack[stack_size++] = value1;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
SWAP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (SWAP, 0);

	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value2;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
OPERATORS
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_operator_111:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value1 = stack[stack_size - 2].$2;
	  $3 value2 = stack[--stack_size].$3;
	  stack[stack_size - 1].$4 = value1 $5 value2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_222:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value1 = *(($2 *) (void *) &stack[stack_size - 4]);
	  $3 value2 = *(($3 *) (void *) &stack[(stack_size -= 2)]);
	  *(($4 *) (void *) &stack[stack_size - 2]) = value1 $5 value2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_11:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value = stack[stack_size - 1].$2;
/* SVM__MAX is never defined. */
#ifdef SVM_$5_MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].$3 = 0;
	    }
	  else if (value >= SVM_$5_MAX)
	    {
	      stack[stack_size - 1].$3 = SVM_$5_MAX;
	    }
	  else if (value <= SVM_$5_MIN)
	    {
	      stack[stack_size - 1].$3 = SVM_$5_MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].$3 = $4 value;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_22:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value = *(($2 *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM_$5_MAX
	  if (value != value)
	    {			/* NaN */
	      *(($3 *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM_$5_MAX)
	    {
	      *(($3 *) (void *) &stack[stack_size - 2]) = SVM_$5_MAX;
	    }
	  else if (value <= SVM_$5_MIN)
	    {
	      *(($3 *) (void *) &stack[stack_size - 2]) = SVM_$5_MIN;
	    }
	  else
#endif
	    {
	      *(($3 *) (void *) &stack[stack_size - 2]) = $4 value;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_12:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value = stack[stack_size - 1].$2;
/* SVM__MAX is never defined. */
#ifdef SVM_$5_MAX
	  if (value != value)
	    {			/* NaN */
	      *(($3 *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM_$5_MAX)
	    {
	      *(($3 *) (void *) &stack[stack_size++ - 1]) = SVM_$5_MAX;
	    }
	  else if (value <= SVM_$5_MIN)
	    {
	      *(($3 *) (void *) &stack[stack_size++ - 1]) = SVM_$5_MIN;
	    }
	  else
#endif
	    {
	      *(($3 *) (void *) &stack[stack_size++ - 1]) = $4 value;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_21:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value = *(($2 *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM_$5_MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].$3 = 0;
	    }
	  else if (value >= SVM_$5_MAX)
	    {
	      stack[stack_size - 1].$3 = SVM_$5_MAX;
	    }
	  else if (value <= SVM_$5_MIN)
	    {
	      stack[stack_size - 1].$3 = SVM_$5_MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].$3 = $4 value;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_operator_111(IADD, jint, jint, jint, +)
	 * m4svm_instruction_operator_222(LADD, jlong, jlong, jlong, +)
	 * m4svm_instruction_operator_111(FADD, jfloat, jfloat, jfloat, +)
	 * m4svm_instruction_operator_222(DADD, jdouble, jdouble, jdouble, +)
	 * m4svm_instruction_operator_111(ISUB, jint, jint, jint, -)
	 * m4svm_instruction_operator_222(LSUB, jlong, jlong, jlong, -)
	 * m4svm_instruction_operator_111(FSUB, jfloat, jfloat, jfloat, -)
	 * m4svm_instruction_operator_222(DSUB, jdouble, jdouble, jdouble, -)
	 * m4svm_instruction_operator_111(IMUL, jint, jint, jint, *)
	 * m4svm_instruction_operator_222(LMUL, jlong, jlong, jlong, *)
	 * m4svm_instruction_operator_111(FMUL, jfloat, jfloat, jfloat, *)
	 * m4svm_instruction_operator_222(DMUL, jdouble, jdouble, jdouble, *)
	 * m4svm_instruction_operator_111(FDIV, jfloat, jfloat, jfloat, /)
	 * m4svm_instruction_operator_222(DDIV, jdouble, jdouble, jdouble, /)
	 * m4svm_instruction_operator_11(INEG, jint, jint, -)
	 * m4svm_instruction_operator_22(LNEG, jlong, jlong, -)
	 * m4svm_instruction_operator_11(FNEG, jfloat, jfloat, -)
	 * m4svm_instruction_operator_22(DNEG, jdouble, jdouble, -)
	 * m4svm_instruction_operator_111(IAND, jint, jint, jint, &)
	 * m4svm_instruction_operator_222(LAND, jlong, jlong, jlong, &)
	 * m4svm_instruction_operator_111(IOR, jint, jint, jint, |)
	 * m4svm_instruction_operator_222(LOR, jlong, jlong, jlong, |)
	 * m4svm_instruction_operator_111(IXOR, jint, jint, jint, ^)
	 * m4svm_instruction_operator_222(LXOR, jlong, jlong, jlong, ^)
	 * m4svm_instruction_operator_12(I2L, jint, jlong)
	 * m4svm_instruction_operator_11(I2F, jint, jfloat)
	 * m4svm_instruction_operator_12(I2D, jint, jdouble)
	 * m4svm_instruction_operator_21(L2I, jlong, jint)
	 * m4svm_instruction_operator_21(L2F, jlong, jfloat)
	 * m4svm_instruction_operator_22(L2D, jlong, jdouble)
	 * m4svm_instruction_operator_11(F2I, jfloat, jint, , JINT)
	 * m4svm_instruction_operator_12(F2L, jfloat, jlong, , JLONG)
	 * m4svm_instruction_operator_12(F2D, jfloat, jdouble)
	 * m4svm_instruction_operator_21(D2I, jdouble, jint, , JINT)
	 * m4svm_instruction_operator_22(D2L, jdouble, jlong, , JLONG)
	 * m4svm_instruction_operator_21(D2F, jdouble, jfloat)
	 * m4svm_instruction_operator_11(I2B, jint, jint, (jbyte))
	 * m4svm_instruction_operator_11(I2C, jint, jint, (jchar))
	 * m4svm_instruction_operator_11(I2S, jint, jint, (jshort)) */

	/* m4_undefine([:m4svm_instruction_operator_111:])
	 * m4_undefine([:m4svm_instruction_operator_222:])
	 * m4_undefine([:m4svm_instruction_operator_11:])
	 * m4_undefine([:m4svm_instruction_operator_22:])
	 * m4_undefine([:m4svm_instruction_operator_12:])
	 * m4_undefine([:m4svm_instruction_operator_21:]) */

/*
----------------------------------------------------------------------
IDIV
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IDIV, 0);

	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;


#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && \
  !(defined(__hppa__) || defined(__ia64__) || defined(__powerpc__))

#ifndef NDEBUG

	  if (value2 == 0)
	    {
	      env->sigfpe_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (value2 == 0)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arithmeticexception_handler);
	    }
#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */


#if defined(__i386__) || defined(__powerpc__) || defined(__s390__)
	  /*
	   * i386 arch is broken and will cause a *FLOAT* point error signal on
	   * division of MIN_INT / -1 - so we have to fix it by hand
	   * 
	   * On s390 this also seem to cause an unexpected signal.
	   * 
	   * On PowerPC no exception is raised but the result is undefined.
	   *
	   */
	  if ((value1 == (jint) 0x80000000) && (value2 == -1))
	    {
	      stack[stack_size - 1].jint = value1;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = value1 / value2;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDIV
----------------------------------------------------------------------
*/

	/* Note: GCC's generated code seems to include a function call
	   or some other kind of branch statement which unfortunately
	   precludes inlining this instruction. */

	m4svm_instruction_head (LDIV, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && \
  !(defined(__hppa__) || defined(__ia64__) || defined(__powerpc__) || defined(__s390__))

#ifndef NDEBUG

	  if (value2 == 0L)
	    {
	      env->sigfpe_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (value2 == 0L)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arithmeticexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 / value2;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IREM
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IREM, 0);

	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;


#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && \
  !(defined(__hppa__) || defined(__ia64__) || defined(__powerpc__))

#ifndef NDEBUG

	  if (value2 == 0)
	    {
	      env->sigfpe_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (value2 == 0)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arithmeticexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

#if defined(__i386__) || defined(__powerpc__) || defined(__s390__)
	  /*
	   * i386 arch is broken and will cause a *FLOAT* point error signal on
	   * modulo of MIN_INT / -1 - so we have to fix it by hand
	   * 
	   * We assumed problem exists on s390 and PowerPC just as for IDIV
	   * 
	   */
	  if ((value1 == (jint) 0x80000000) && (value2 == -1))
	    {
	      stack[stack_size - 1].jint = 0;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = value1 % value2;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LREM
----------------------------------------------------------------------
*/

	/* Note: GCC's generated code seems to include a function call
	   or some other kind of branch statement which unfortunately
	   precludes inlining this instruction. */

	m4svm_instruction_head (LREM, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && \
  !(defined(__hppa__) || defined(__ia64__) || defined(__powerpc__) || defined(__s390__))

#ifndef NDEBUG

	  if (value2 == 0L)
	    {
	      env->sigfpe_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (value2 == 0L)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arithmeticexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 % value2;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
FREM
----------------------------------------------------------------------
*/

	m4svm_instruction_head (FREM, 0);

	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = _svmm_fmod (value1, value2);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DREM
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DREM, 0);

	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) =
	    _svmm_fmod (value1, value2);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ISHL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ISHL, 0);

	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 << (value2 & 0x1f);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LSHL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LSHL, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    value1 << (value2 & 0x3f);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ISHR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ISHR, 0);

	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
#if defined(SVM_SIGNED_SHR)
	  stack[stack_size - 1].jint = value1 >> (value2 & 0x1f);
#elif defined(SVM_UNSIGNED_SHR)
	  jint sign = value1 >> 31;
	  /* unsigned shift */
	  jint result = value1 >> (value2 & 0x1f);
	  /* add leading 1s if necessary */
	  result |= (-1 * sign) << (0x20 - (value2 & 0x1f));
	  stack[stack_size - 1].jint = result;
#endif
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LSHR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LSHR, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;

#if defined(SVM_SIGNED_SHR)
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    value1 >> (value2 & 0x3f);
#elif defined(SVM_UNSIGNED_SHR)
	  jlong sign = value1 >> 63;
	  /* unsigned shift */
	  jlong result = value1 >> (value2 & 0x3f);
	  /* add leading 1s if necessary */
	  result |= (-1L * sign) << (0x40 - (value2 & 0x3f));
	  *((jlong *) (void *) &stack[stack_size - 2]) = result;
#endif

	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IUSHR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IUSHR, 0);

	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint =
	    ((_svmt_u32) value1) >> (value2 & 0x1f);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LUSHR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LUSHR, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    ((_svmt_u64) value1) >> (value2 & 0x3f);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LCMP
----------------------------------------------------------------------
*/

	/* Note: GCC's uses branch statements to compare values. */

	m4svm_instruction_head (LCMP, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[stack_size - 2]);
	  stack[(stack_size -= 3) - 1].jint =
	    (value1 > value2) - (value1 < value2);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
FCMPL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (FCMPL, 0);

	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;

	  if (value1 != value1 || value2 != value2)
	    {
	      /* NaN */
	      stack[stack_size - 1].jint = -1;
	    }
	  else
	    {
	      stack[stack_size - 1].jint =
		(value1 > value2) - (value1 < value2);
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
FCMPG
----------------------------------------------------------------------
*/

	m4svm_instruction_head (FCMPG, 0);

	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;

	  if (value1 != value1 || value2 != value2)
	    {
	      /* NaN */
	      stack[stack_size - 1].jint = 1;
	    }
	  else
	    {
	      stack[stack_size - 1].jint =
		(value1 > value2) - (value1 < value2);
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DCMPL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DCMPL, 0);

	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[stack_size - 2]);

	  if (value1 != value1 || value2 != value2)
	    {
	      /* NaN */
	      stack[(stack_size -= 3) - 1].jint = -1;
	    }
	  else
	    {
	      stack[(stack_size -= 3) - 1].jint =
		(value1 > value2) - (value1 < value2);
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DCMPG
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DCMPG, 0);

	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[stack_size - 2]);

	  if (value1 != value1 || value2 != value2)
	    {
	      /* NaN */
	      stack[(stack_size -= 3) - 1].jint = 1;
	    }
	  else
	    {
	      stack[(stack_size -= 3) - 1].jint =
		(value1 > value2) - (value1 < value2);
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IINC
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IINC, 2);

	{
	  jint indx = (pc++)->jint;
	  jint constant = (pc++)->jint;
	  locals[indx].jint +=constant;
	}

	m4svm_instruction_tail ();
/*
----------------------------------------------------------------------
IF<X>(_CHECK)
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_if_x:], [: */
	m4svm_instruction_head (IF$1, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value $2 0)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_x_check:], [: */
	m4svm_instruction_head (IF$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value $2 0)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_icmpx:], [: */
	m4svm_instruction_head (IF_ICMP$1, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 $2 value2)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_icmpx_check:], [: */
	m4svm_instruction_head (IF_ICMP$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 $2 value2)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_acmpx:], [: */
	m4svm_instruction_head (IF_ACMP$1, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 $2 ref2)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_acmpx_check:], [: */
	m4svm_instruction_head (IF_ACMP$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 $2 ref2)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_if_x(EQ, ==)
	 * m4svm_instruction_if_x(NE, !=)
	 * m4svm_instruction_if_x(LT, <)
	 * m4svm_instruction_if_x(LE, <=)
	 * m4svm_instruction_if_x(GT, >)
	 * m4svm_instruction_if_x(GE, >=)
	 * m4svm_instruction_if_icmpx(EQ, ==)
	 * m4svm_instruction_if_icmpx(NE, !=)
	 * m4svm_instruction_if_icmpx(LT, <)
	 * m4svm_instruction_if_icmpx(LE, <=)
	 * m4svm_instruction_if_icmpx(GT, >)
	 * m4svm_instruction_if_icmpx(GE, >=)
	 * m4svm_instruction_if_acmpx(EQ, ==)
	 * m4svm_instruction_if_acmpx(NE, !=) */

	/* m4svm_instruction_if_x_check(EQ, ==)
	 * m4svm_instruction_if_x_check(NE, !=)
	 * m4svm_instruction_if_x_check(LT, <)
	 * m4svm_instruction_if_x_check(LE, <=)
	 * m4svm_instruction_if_x_check(GT, >)
	 * m4svm_instruction_if_x_check(GE, >=)
	 * m4svm_instruction_if_icmpx_check(EQ, ==)
	 * m4svm_instruction_if_icmpx_check(NE, !=)
	 * m4svm_instruction_if_icmpx_check(LT, <)
	 * m4svm_instruction_if_icmpx_check(LE, <=)
	 * m4svm_instruction_if_icmpx_check(GT, >)
	 * m4svm_instruction_if_icmpx_check(GE, >=)
	 * m4svm_instruction_if_acmpx_check(EQ, ==)
	 * m4svm_instruction_if_acmpx_check(NE, !=) */

	/* m4_undefine([:m4svm_instruction_if_x:])
	 * m4_undefine([:m4svm_instruction_if_icmpx:])
	 * m4_undefine([:m4svm_instruction_if_acmpx:]) */

	/* m4_undefine([:m4svm_instruction_if_x_check:])
	 * m4_undefine([:m4svm_instruction_if_icmpx_check:])
	 * m4_undefine([:m4svm_instruction_if_acmpx_check:]) */

/*
----------------------------------------------------------------------
GOTO
----------------------------------------------------------------------
*/

	m4svm_instruction_head (GOTO, 2);

	pc = pc->addr;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
GOTO_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (GOTO_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	pc = pc->addr;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
JSR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (JSR, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  stack[stack_size++].addr = pc;
	  pc = destination;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
JSR_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (JSR_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	{
	  _svmt_code *destination = (pc++)->addr;
	  stack[stack_size++].addr = pc;
	  pc = destination;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
RET
----------------------------------------------------------------------
*/

	m4svm_instruction_head (RET, 1);

	{
	  jint indx = pc->jint;
	  pc = locals[indx].addr;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
TABLESWITCH
----------------------------------------------------------------------
*/

	m4svm_instruction_head (TABLESWITCH, -1);

	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint low = (pc++)->jint;
	  jint high = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint indx = stack[--stack_size].jint;

	  if (indx < low || indx > high)
	    {
	      pc = default_dest;
	    }
	  else
	    {
	      pc = table[indx - low].addr;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
TABLESWITCH_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (TABLESWITCH_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint low = (pc++)->jint;
	  jint high = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint indx = stack[--stack_size].jint;

	  if (indx < low || indx > high)
	    {
	      pc = default_dest;
	    }
	  else
	    {
	      pc = table[indx - low].addr;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LOOKUPSWITCH
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LOOKUPSWITCH, -1);

	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint npairs = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint key = stack[--stack_size].jint;

	  jint low = 0;
	  jint high = npairs - 1;

	  while (high >= low)
	    {
	      jint middle = (low + high) / 2;
	      jint match = table[middle * 2].jint;

	      if (key == match)
		{
		  pc = table[middle * 2 + 1].addr;
		  break;
		}

	      if (key > match)
		{
		  low = middle + 1;
		}
	      else
		{
		  high = middle - 1;
		}
	    }

	  if (high < low)
	    {
	      pc = default_dest;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LOOKUPSWITCH_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LOOKUPSWITCH_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint npairs = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint key = stack[--stack_size].jint;

	  jint low = 0;
	  jint high = npairs - 1;

	  while (high >= low)
	    {
	      jint middle = (low + high) / 2;
	      jint match = table[middle * 2].jint;

	      if (key == match)
		{
		  pc = table[middle * 2 + 1].addr;
		  break;
		}

	      if (key > match)
		{
		  low = middle + 1;
		}
	      else
		{
		  high = middle - 1;
		}
	    }

	  if (high < low)
	    {
	      pc = default_dest;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<X>RETURN
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_xreturn:], [: */
	m4svm_instruction_head ($1RETURN, 0);

	/* structured locking */
	if (env->stack.current_frame->lock_count != 0
	    && env->vm->enforce_structured_locking)
	  {
	    /* pop stack frame */
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    env->stack.current_frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);

	    _svmf_error_IllegalMonitorStateException (env);
	    _svmm_goto_label (exception_handler);
	  }

#if !defined(NDEBUG)

	_svmf_verbose_methods_exit (env);

#endif

	{
	  _svmt_stack_frame *frame;
	  _svmt_method_frame_info *caller_frame_info;
	  _svmt_method_frame_info *callee_frame_info;
	  _svmt_method_info *caller_method;
	  _svmt_method_info *callee_method;
	  _svmt_object_instance *this;

	  frame = env->stack.current_frame;
	  callee_frame_info = frame->method_frame_info;
	  callee_method = callee_frame_info->method;
	  this = frame->this;

#ifndef NDEBUG

	  if (stack[stack_size - 1].reference != NULL &&
	      (DREF (callee_method->descriptor, value)[1] == 'L'
	       || DREF (callee_method->descriptor, value)[1] == '['))
	    {
	      /* check return value type */

	      const char *pdesc = DREF (callee_method->descriptor, value) + 1;
	      jint arg = 0;
	      _svmt_type_info *t;

	      while (*pdesc++ != /* to keep m4 happy: '(' */ ')');

	      /* save state */
	      env->stack.current_frame->pc = pc;
	      env->stack.current_frame->stack_size = 0;	/* artificially empty stack */

	      {
		jobject value;

		if (_svmm_new_native_local (env, value) != JNI_OK)
		  {
		    _svmm_fatal_error ("unsupported failure while debugging");
		  }

		*value = stack[stack_size - 1].reference;

		t =
		  _svmm_get_type_from_within_descriptor (env, callee_method,
							 pdesc, arg);

		env->stack.current_frame->stack_size = stack_size;	/* recover stack */

		/* in case stack was moved around  */
		frame = env->stack.current_frame;
		locals = (_svmt_stack_value *) (void *)
		  (((char *) frame) - callee_frame_info->start_offset);
		stack =
		  (_svmt_stack_value *) (void *) (((char *) frame) +
						  _svmv_stack_offset);
		this = frame->this;

#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
		stack[stack_size - 1].reference = *value;

		_svmm_free_native_local (env, value);
	      }

	      if (t != NULL)
		{
		  if (env->vm->verbose_instructions == JNI_TRUE)
		    {
		      _svmf_printf (env, stderr,
				    "** T%d: t = %s\n", env->thread.id,
				    t->name);

		      fflush (stderr);
		    }

		  if (!_svmf_is_assignable_from
		      (env, stack[stack_size - 1].reference->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}
	    }

#endif

	  frame =
	    (_svmt_stack_frame *) (void *) (((char *) frame) -
					    frame->previous_offset);
	  env->stack.current_frame = frame;
	  caller_frame_info = frame->method_frame_info;
	  caller_method = caller_frame_info->method;
	  m4svm_$1return_assign;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + m4svm_$1return_size;
	  pc = frame->pc;

/* 	  if(strcmp("$1", "A") == 0) */
/* 	    { */
/* 	      if ((env->vm->mi_info.inst_count_times >= 146) && */
/* 		  (env->vm->mi_info.inst_count >= 26125569 )) */
/* 		{ */
/* 		  _svmf_printf(env, stderr, "$1RETURN: resuming caller at[%p]\n", pc); */
/* 		} */
/* 	    } */

	  /* is method synchronized? */
	  if (callee_method->synchronized)
	    {
	      /* release monitor */
	      if (_svmf_exit_object_monitor (env, this) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}
	    }
	}

#if defined (_SABLEVM_METHOD_INLINING) && !defined (NDEBUG)
/* 	env->vm->show_instructions = JNI_FALSE; */
#endif

	m4svm_instruction_tail ();
	/* :]) */

/*
m4_define([:m4svm_return_assign:],[:[:m4_:]dnl:])m4_dnl
m4_define([:m4svm_Ireturn_assign:],[:locals[0].jint = stack[stack_size - 1].jint:])m4_dnl
m4_define([:m4svm_Freturn_assign:],[:locals[0].jfloat = stack[stack_size - 1].jfloat:])m4_dnl
m4_define([:m4svm_Areturn_assign:],[:locals[0].reference = stack[stack_size - 1].reference:])m4_dnl
m4_define([:m4svm_Lreturn_assign:],[:*((jlong *) (void *) &locals[0]) = *((jlong *) (void *) &stack[stack_size - 2]):])m4_dnl
m4_define([:m4svm_Dreturn_assign:],[:*((jdouble *) (void *) &locals[0]) = *((jdouble *) (void *) &stack[stack_size - 2]):])m4_dnl
m4_define([:m4svm_return_size:],[:0:])m4_dnl
m4_define([:m4svm_Ireturn_size:],[:1:])m4_dnl
m4_define([:m4svm_Freturn_size:],[:1:])m4_dnl
m4_define([:m4svm_Areturn_size:],[:1:])m4_dnl
m4_define([:m4svm_Lreturn_size:],[:2:])m4_dnl
m4_define([:m4svm_Dreturn_size:],[:2:])m4_dnl
m4svm_instruction_xreturn(I)
m4svm_instruction_xreturn(L)
m4svm_instruction_xreturn(F)
m4svm_instruction_xreturn(D)
m4svm_instruction_xreturn(A)
m4svm_instruction_xreturn()
m4_undefine([:m4svm_instruction_xreturn:])
m4_undefine([:m4svm_return_assign:])
m4_undefine([:m4svm_Ireturn_assign:])
m4_undefine([:m4svm_Freturn_assign:])
m4_undefine([:m4svm_Areturn_assign:])
m4_undefine([:m4svm_Lreturn_assign:])
m4_undefine([:m4svm_Dreturn_assign:])
m4_undefine([:m4svm_return_size:])
m4_undefine([:m4svm_Ireturn_size:])
m4_undefine([:m4svm_Freturn_size:])
m4_undefine([:m4svm_Areturn_size:])
m4_undefine([:m4svm_Lreturn_size:])
m4_undefine([:m4svm_Dreturn_size:])
*/

/*
----------------------------------------------------------------------
INVOKEVIRTUAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INVOKEVIRTUAL, 2);

	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  goto exception_handler;
		}

#ifdef _SABLEVM_METHOD_INLINING
	      /* refresh pc */
	      pc = env->stack.current_frame->pc;
#endif
	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

#ifdef _SABLEVM_METHOD_INLINING
	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame_info->nb_executions++;
#else
	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      goto exception_handler;
	    }
#endif

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
	  }

#endif
	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INVOKESPECIAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INVOKESPECIAL, 2);

	if (env->vm->mi_info.inst_count_times >= 13)
	  {
	    _svmf_print_method_name(env, stderr, 
				    env->stack.current_frame->method_frame_info->method, "\n");
	    _svmf_mi_print_bytecode_count(env, pc, "INVOKESPECIAL", 0);
	    _svmf_printf(env, stderr, "INVOKESPECIAL: %p[%p]\n", pc, pc->addr);
	    _svmf_printf(env, stderr, "INVOKESPECIAL: %p[%d]\n", pc+1, pc[1].jint);
	    _svmf_printf(env, stderr, "INVOKESPECIAL: %p[%p] frame_info[%p]\n", 
			 pc+2, pc[2].method_info,
			 pc[2].method_info->frame_info);
	    _svmf_printf(env, stderr, "INVOKESPECIAL: class_info[%p]\n",
			 pc[2].method_info->class_info);
	    _svmf_printf(env, stderr, "INVOKESPECIAL: %p[%p]\n", pc+3, pc[3].stack_gc_map);
	  }	  


	pc++;			/* skip preparation address */
	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  frame_info = method->frame_info;

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  _svmf_printf(env, stderr, "INVOKESPECIAL: instance[%p] instance->vtable->type[%p]\n",
		       instance, instance->vtable->type);

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

#ifdef _SABLEVM_METHOD_INLINING
	      /* refresh pc */
	      pc = env->stack.current_frame->pc;
#endif
	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

#ifdef _SABLEVM_METHOD_INLINING
	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }
	  frame_info->nb_executions++;
#else
	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }
#endif

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

#if !defined(NDEBUG)

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);
		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
	  }

#endif
	}

#if !defined(NDEBUG)
	_svmf_verbose_methods_enter (env);
#endif
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INVOKESTATIC
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INVOKESTATIC, 2);

	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  frame_info = method->frame_info;
	  stack_size -= args_count;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor
		  (env, *(method->class_info->class_instance)) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

#ifdef _SABLEVM_METHOD_INLINING
	      /* refresh pc */
	      pc = env->stack.current_frame->pc;
#endif
	      frame->stack_size = stack_size;
	    }

#ifdef _SABLEVM_METHOD_INLINING
	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }
	  frame_info->nb_executions++;
#else
	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

#endif
	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = *(method->class_info->class_instance);
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 0;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
	  }

#endif

	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INVOKEINTERFACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INVOKEINTERFACE, 4);

	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

#ifdef _SABLEVM_METHOD_INLINING
	      /* refresh pc */
	      pc = env->stack.current_frame->pc;
#endif
	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

#ifdef _SABLEVM_METHOD_INLINING
	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame_info->nb_executions++;
#else
	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }
#endif

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
#ifdef _SABLEVM_METHOD_INLINING
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
#endif
	  }

#endif

	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
NEW
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NEW, 2);

	pc++;			/* skip preparation address */

	{
	  _svmt_class_info *class_info = (pc++)->class_info;
	  _svmt_object_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmm_new_object_instance (env, class_info, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }
	  
#ifdef _SABLEVM_METHOD_INLINING
	  /* refresh pc */
	  pc = env->stack.current_frame->pc;
#endif
	  stack[stack_size++].reference = instance;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ARRAYLENGTH
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ARRAYLENGTH, 0);

	{
	  _svmt_array_instance *array = (_svmt_array_instance *)
	    stack[stack_size - 1].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  assert (array == NULL || array->vtable->type->is_array);

	  m4svm_expect_sigsegv ();

	  /* can cause sigsegv on NULL array ref */
	  stack[stack_size - 1].jint = array->size;

	  m4svm_dont_expect_sigsegv ();

	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ATHROW
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ATHROW, 0);

	{
	  *(env->throwable) = stack[stack_size - 1].reference;

	  env->stack.current_frame->pc = pc;

	  _svmm_goto_label (athrow_handler);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
CHECKCAST
----------------------------------------------------------------------
*/

	m4svm_instruction_head (CHECKCAST, 2);

	pc++;			/* skip preparation address */

	{
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;
	  _svmt_type_info *T = (pc++)->type_info;

	  if (instance != NULL)
	    {
	      _svmt_type_info *S = instance->vtable->type;

	      if (!_svmf_is_assignable_from (env, S, T))
		{
		  env->stack.current_frame->pc = pc;
		  _svmm_goto_label (classcastexception_handler);
		}
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INSTANCEOF
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INSTANCEOF, 2);

	pc++;			/* skip preparation address */

	{
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;
	  _svmt_type_info *T = (pc++)->type_info;

	  if (instance != NULL)
	    {
	      _svmt_type_info *S = instance->vtable->type;

	      if (_svmf_is_assignable_from (env, S, T))
		{
		  stack[stack_size - 1].jint = 1;
		}
	      else
		{
		  stack[stack_size - 1].jint = 0;
		}
	    }
	  else
	    {
	      stack[stack_size - 1].jint = 0;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
MONITORENTER
----------------------------------------------------------------------
*/

	m4svm_instruction_head (MONITORENTER, 0);

	{
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

#ifdef _SABLEVM_METHOD_INLINING
	  /* refresh pc */
	  pc = env->stack.current_frame->pc;
#endif
	  --stack_size;

	  /* structured locking */
	  env->stack.current_frame->lock_count++;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
MONITOREXIT
----------------------------------------------------------------------
*/

	m4svm_instruction_head (MONITOREXIT, 0);

	{
	  _svmt_object_instance *instance = stack[--stack_size].reference;

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  /* structured locking */
	  if (--(env->stack.current_frame->lock_count) < 0
	      && env->vm->enforce_structured_locking)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmf_error_IllegalMonitorStateException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmf_exit_object_monitor (env, instance) != JNI_OK)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (exception_handler);
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IFNULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IFNULL, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IFNULL_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IFNULL_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IFNONNULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IFNONNULL, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IFNONNULL_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IFNONNULL_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LINK_NATIVE_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LINK_NATIVE_METHOD, -1);

	{
	  _svmt_method_info *method =
	    env->stack.current_frame->method_frame_info->method;
	  _svmt_stack_frame *frame;
	  _svmt_method_frame_info *frame_info;

	  if (_svmf_bind_native_method (env, method) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  frame_info = frame->method_frame_info;
	  method = frame_info->method;

	  locals =
	    (_svmt_stack_value *) (void *) (((char *) frame) -
					    frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);

	  pc = frame_info->code;
	  stack_size = 0;

	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ABSTRACT_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ABSTRACT_METHOD, -1);

	_svmm_goto_label (abstractmethoderror_handler);

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
NATIVE_STATIC_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NATIVE_STATIC_METHOD, -1);

	{
	  _svmt_method_info *method;
	  _svmt_stack_frame *frame;
	  _svmt_method_frame_info *frame_info;

	  if (_svmf_invoke_native_static (env) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  frame_info = frame->method_frame_info;
	  method = frame_info->method;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size;
	  pc = frame->pc;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
NATIVE_NONSTATIC_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NATIVE_NONSTATIC_METHOD, -1);

	{
	  _svmt_method_info *method;
	  _svmt_stack_frame *frame;
	  _svmt_method_frame_info *frame_info;

	  if (_svmf_invoke_native_nonstatic (env) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  frame_info = frame->method_frame_info;
	  method = frame_info->method;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size;
	  pc = frame->pc;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<GET/PUT><FIELD/STATIC>_<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_getfield_x:], [: */
	m4svm_instruction_head (GETFIELD_$1, -1);

	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  stack[stack_size - 1].$2 =
	    *(($3 *) (void *) (((char *) instance) + offset));

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_getfield_x2:], [: */
	m4svm_instruction_head (GETFIELD_$1, -1);

	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  *(($2 *) (void *) &stack[stack_size++ - 1]) =
	    *(($2 *) (void *) (((char *) instance) + offset));

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_getfield_x(BYTE, jint, jbyte)
	 * m4svm_instruction_getfield_x(SHORT, jint, jshort)
	 * m4svm_instruction_getfield_x(CHAR, jint, jchar)
	 * m4svm_instruction_getfield_x(INT, jint, jint)
	 * m4svm_instruction_getfield_x2(LONG, jlong)
	 * m4svm_instruction_getfield_x(FLOAT, jfloat, jfloat)
	 * m4svm_instruction_getfield_x2(DOUBLE, jdouble)
	 * m4svm_instruction_getfield_x(REFERENCE, reference, _svmt_object_instance *) */

	/* m4_undefine([:m4svm_instruction_getfield_x:])
	 * m4_undefine([:m4svm_instruction_getfield_x2:]) */

	/* m4_define([:m4svm_instruction_putfield_x:], [: */
	m4svm_instruction_head (PUTFIELD_$1, -1);

	{
	  size_t offset = (pc++)->offset;
	  $3 value = stack[--stack_size].$2;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_$1_FIELD)
	  _svmf_put_$1_field (env, instance, offset, value);
#else
	  _svmf_put_$1_field (instance, offset, value);
#endif /* SVM_PUT_$1_FIELD */

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_putfield_x2:], [: */
	m4svm_instruction_head (PUTFIELD_$1, -1);

	{
	  size_t offset = (pc++)->offset;
	  $2 value = *(($2 *) (void *) &stack[(stack_size -= 2)]);
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  *(($2 *) (void *) (((char *) instance) + offset)) = value;

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_putfield_x(BYTE, jint, jbyte)
	 * m4svm_instruction_putfield_x(SHORT, jint, jshort)
	 * m4svm_instruction_putfield_x(CHAR, jint, jchar)
	 * m4svm_instruction_putfield_x(INT, jint, jint)
	 * m4svm_instruction_putfield_x2(LONG, jlong)
	 * m4svm_instruction_putfield_x(FLOAT, jfloat, jfloat)
	 * m4svm_instruction_putfield_x2(DOUBLE, jdouble)
	 * m4svm_instruction_putfield_x(REFERENCE, reference, _svmt_object_instance *) */

	/* m4_undefine([:m4svm_instruction_putfield_x:])
	 * m4_undefine([:m4svm_instruction_putfield_x2:]) */

	/* m4_define([:m4svm_instruction_getstatic_x:], [: */
	m4svm_instruction_head (GETSTATIC_$1, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].$2 = pvalue->$3;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_getstatic_x2:], [: */
	m4svm_instruction_head (GETSTATIC_$1, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *(($2 *) (void *) &stack[stack_size]) = pvalue->$3;
	  stack_size += 2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_getstatic_x(BOOLEAN, jint, z)
	 * m4svm_instruction_getstatic_x(BYTE, jint, b)
	 * m4svm_instruction_getstatic_x(SHORT, jint, s)
	 * m4svm_instruction_getstatic_x(CHAR, jint, c)
	 * m4svm_instruction_getstatic_x(INT, jint, i)
	 * m4svm_instruction_getstatic_x2(LONG, jlong, j)
	 * m4svm_instruction_getstatic_x(FLOAT, jfloat, f)
	 * m4svm_instruction_getstatic_x2(DOUBLE, jdouble, d) */

	/* m4_undefine([:m4svm_instruction_getstatic_x:])
	 * m4_undefine([:m4svm_instruction_getstatic_x2:]) */

	/* m4_define([:m4svm_instruction_putstatic_x:],  [: */
	m4svm_instruction_head (PUTSTATIC_$1, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->$3 = stack[--stack_size].$2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_putstatic_x2:], [: */
	m4svm_instruction_head (PUTSTATIC_$1, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->$3 = *(($2 *) (void *) &stack[(stack_size -= 2)]);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_putstatic_x(BOOLEAN, jint, z)
	 * m4svm_instruction_putstatic_x(BYTE, jint, b)
	 * m4svm_instruction_putstatic_x(SHORT, jint, s)
	 * m4svm_instruction_putstatic_x(CHAR, jint, c)
	 * m4svm_instruction_putstatic_x(INT, jint, i)
	 * m4svm_instruction_putstatic_x2(LONG, jlong, j)
	 * m4svm_instruction_putstatic_x(FLOAT, jfloat, f)
	 * m4svm_instruction_putstatic_x2(DOUBLE, jdouble, d)

	 /* m4_undefine([:m4svm_instruction_putstatic_x:])
	 * m4_undefine([:m4svm_instruction_putstatic_x2:]) */

/*
----------------------------------------------------------------------
GETFIELD_BOOLEAN
----------------------------------------------------------------------
*/

	m4svm_instruction_head (GETFIELD_BOOLEAN, -1);

	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  stack[stack_size - 1].jint =
	    (((_svmt_u8 *) instance)[offset / 8] >> (offset % 8)) & 1;

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PUTFIELD_BOOLEAN
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PUTFIELD_BOOLEAN, -1);

	{
	  size_t offset = (pc++)->offset;
	  _svmt_u8 value = 0x01 & stack[--stack_size].jint;
	  _svmt_u8 nvalue = 0x01 ^ value;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* to avoid conditional jumps we use boolean arithmetic */
	  ((_svmt_u8 *) instance)[offset / 8] |= (value << (offset % 8));
	  ((_svmt_u8 *) instance)[offset / 8] &= ~(nvalue << (offset % 8));

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
GETSTATIC_REFERENCE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (GETSTATIC_REFERENCE, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].reference = *(pvalue->l);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	  assert (stack[stack_size - 1].reference == NULL ||
		  strcmp (stack[stack_size - 1].reference->magic,
			  "SableVM") == 0);
#endif
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PUTSTATIC_REFERENCE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PUTSTATIC_REFERENCE, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *(pvalue->l) = stack[--stack_size].reference;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	  _svmf_write_barrier (env, (_svmt_object_instance **) pvalue->l);
#endif /* _SABLEVM_GC_WRITE_BARRIER */
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ASTORE_RET
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ASTORE_RET, 1);

	{
	  jint indx = (pc++)->jint;
	  locals[indx].addr = stack[--stack_size].addr;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ASTORE_RET_<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_astore_ret_x:], [: */
	m4svm_instruction_head (ASTORE_RET_$1, -1);

	{
	  locals[$1].addr = stack[--stack_size].addr;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_astore_ret_x(0)
	 * m4svm_instruction_astore_ret_x(1)
	 * m4svm_instruction_astore_ret_x(2)
	 * m4svm_instruction_astore_ret_x(3) */

	/* m4_undefine([:m4svm_instruction_astore_ret_x:]) */

/*
----------------------------------------------------------------------
NEXT
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NEXT, -1);

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

	_svmf_goto ((pc++)->implementation);
	    
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
NEWARRAY_<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_newarray_x:], [: */
	m4svm_instruction_head (NEWARRAY_$1, -1);

	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.$2_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

#ifdef _SABLEVM_METHOD_INLINING
	  /* refresh pc */
	  pc = env->stack.current_frame->pc;
#endif
	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_newarray_x(BOOLEAN, boolean)
	 * m4svm_instruction_newarray_x(BYTE, byte)
	 * m4svm_instruction_newarray_x(SHORT, short)
	 * m4svm_instruction_newarray_x(CHAR, char)
	 * m4svm_instruction_newarray_x(INT, int)
	 * m4svm_instruction_newarray_x(LONG, long)
	 * m4svm_instruction_newarray_x(FLOAT, float)
	 * m4svm_instruction_newarray_x(DOUBLE, double) */

	/* m4_undefine([:m4svm_instruction_newarray_x:]) */

/*
----------------------------------------------------------------------
ANEWARRAY
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ANEWARRAY, 2);

	pc++;			/* skip preparation address */

	{
	  _svmt_array_info *array_info = (pc++)->array_info;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, array_info, count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

#ifdef _SABLEVM_METHOD_INLINING
	  /* refresh pc */
	  pc = env->stack.current_frame->pc;
#endif
	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
MULTIANEWARRAY
----------------------------------------------------------------------
*/

	m4svm_instruction_head (MULTIANEWARRAY, 3);

	pc++;			/* skip preparation address */

	{
	  _svmt_array_info *array_info = (pc++)->array_info;
	  jint dimensions = (pc++)->jint;
	  _svmt_array_instance *instance;

	  stack_size -= dimensions;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmm_multianewarray
	      (env, array_info, dimensions, stack[stack_size],
	       instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ERROR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ERROR, -1);

	_svmm_fatal_error ("grave internal VM error");

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INTERNAL_CALL_END
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INTERNAL_CALL_END, -1);

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)
	env->signal_handler = previous_signal_handler;
#endif
	
	return (*(env->throwable) == NULL) ? JNI_OK : JNI_ERR;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
SKIP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (SKIP, -1);

	pc++;			/* skip preparation address */

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
REPLACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (REPLACE, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_code code = *(pc++);

	  *addr = code;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_METHOD, -1);

	{
	  _svmt_stack_frame *frame = env->stack.current_frame;
	  _svmt_method_info *method = frame->method_frame_info->method;
	  _svmt_method_frame_info *frame_info;

	  if (_svmf_prepare_code (env, method) != JNI_OK)
	    {
	      goto exception_handler;
	    }

#ifdef _SABLEVM_METHOD_INLINING
	  method->frame_info->nb_executions++;
#endif
	  frame = env->stack.current_frame;
	  frame_info = frame->method_frame_info;
	  method = frame_info->method;

	  locals =
	    (_svmt_stack_value *) (void *) (((char *) frame) -
					    frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);

	  pc = frame_info->code;
	  stack_size = 0;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_LDC_STRING
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_LDC_STRING, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_String_info *stringref_info = (pc++)->stringref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_String (env, stringref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->jobject = stringref_info->value;

	  /* execute bytecode */
	  stack[stack_size++].reference = *(stringref_info->value);
	}

#if defined (MAGIC)
	assert (stack[stack_size - 1].reference == NULL ||
		strcmp (stack[stack_size - 1].reference->magic,
			"SableVM") == 0);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_<GET/PUT><FIELD/STATIC>_<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_getfield_x:], [: */
	m4svm_instruction_head (PREPARE_GETFIELD_$1, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    stack[stack_size - 1].$2 = _svmf_get_$1_field (instance, offset);
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_getfield_x2:], [: */
	m4svm_instruction_head (PREPARE_GETFIELD_$1, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    *(($2 *) (void *) &stack[stack_size++ - 1]) =
	      _svmf_get_$1_field (instance, offset);
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_getfield_x(BOOLEAN, jint)
	 * m4svm_instruction_getfield_x(BYTE, jint)
	 * m4svm_instruction_getfield_x(SHORT, jint)
	 * m4svm_instruction_getfield_x(CHAR, jint)
	 * m4svm_instruction_getfield_x(INT, jint)
	 * m4svm_instruction_getfield_x2(LONG, jlong)
	 * m4svm_instruction_getfield_x(FLOAT, jfloat)
	 * m4svm_instruction_getfield_x2(DOUBLE, jdouble)
	 * m4svm_instruction_getfield_x(REFERENCE, reference) */

	/* m4_undefine([:m4svm_instruction_getfield_x:])
	 * m4_undefine([:m4svm_instruction_getfield_x2:]) */

	/* m4_define([:m4svm_instruction_putfield_x:], [: */
	m4svm_instruction_head (PREPARE_PUTFIELD_$1, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    $3 value = stack[--stack_size].$2;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_$1_FIELD)
	    _svmf_put_$1_field (env, instance, offset, value);
#else
	    _svmf_put_$1_field (instance, offset, value);
#endif /* SVM_PUT_$1_FIELD */

	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_putfield_x2:], [: */
	m4svm_instruction_head (PREPARE_PUTFIELD_$1, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    $2 value = *(($2 *) (void *) &stack[(stack_size -= 2)]);
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_$1_FIELD)
	    _svmf_put_$1_field (env, instance, offset, value);
#else
	    _svmf_put_$1_field (instance, offset, value);
#endif /* SVM_PUT_$1_FIELD */
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_putfield_x(BOOLEAN, jint, jboolean)
	 * m4svm_instruction_putfield_x(BYTE, jint, jbyte)
	 * m4svm_instruction_putfield_x(SHORT, jint, jshort)
	 * m4svm_instruction_putfield_x(CHAR, jint, jchar)
	 * m4svm_instruction_putfield_x(INT, jint, jint)
	 * m4svm_instruction_putfield_x2(LONG, jlong)
	 * m4svm_instruction_putfield_x(FLOAT, jfloat, jfloat)
	 * m4svm_instruction_putfield_x2(DOUBLE, jdouble)
	 * m4svm_instruction_putfield_x(REFERENCE, reference, _svmt_object_instance *) */

	/* m4_undefine([:m4svm_instruction_putfield_x:])
	 * m4_undefine([:m4svm_instruction_putfield_x2:]) */

	/* m4_define([:m4svm_instruction_getstatic_x:], [: */
	m4svm_instruction_head (PREPARE_GETSTATIC_$1, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    stack[stack_size++].$2 = _svmf_get_$1_static (pvalue);
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_getstatic_x2:], [: */
	m4svm_instruction_head (PREPARE_GETSTATIC_$1, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    *(($2 *) (void *) &stack[stack_size]) =
	      _svmf_get_$1_static (pvalue);
	    stack_size += 2;
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_getstatic_x(BOOLEAN, jint)
	 * m4svm_instruction_getstatic_x(BYTE, jint)
	 * m4svm_instruction_getstatic_x(SHORT, jint)
	 * m4svm_instruction_getstatic_x(CHAR, jint)
	 * m4svm_instruction_getstatic_x(INT, jint)
	 * m4svm_instruction_getstatic_x2(LONG, jlong)
	 * m4svm_instruction_getstatic_x(FLOAT, jfloat)
	 * m4svm_instruction_getstatic_x2(DOUBLE, jdouble)
	 * m4svm_instruction_getstatic_x(REFERENCE, reference) */

	/* m4_undefine([:m4svm_instruction_getstatic_x:])
	 * m4_undefine([:m4svm_instruction_getstatic_x2:]) */

	/* m4_define([:m4svm_instruction_putstatic_x:],  [: */
	m4svm_instruction_head (PREPARE_PUTSTATIC_$1, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_$1_static (pvalue, stack[--stack_size].$2);
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_putstatic_x2:], [: */
	m4svm_instruction_head (PREPARE_PUTSTATIC_$1, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_$1_static (pvalue,
				 *(($2 *) (void *)
				   &stack[(stack_size -= 2)]));
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_putstatic_x(BOOLEAN, jint)
	 * m4svm_instruction_putstatic_x(BYTE, jint)
	 * m4svm_instruction_putstatic_x(SHORT, jint)
	 * m4svm_instruction_putstatic_x(CHAR, jint)
	 * m4svm_instruction_putstatic_x(INT, jint)
	 * m4svm_instruction_putstatic_x2(LONG, jlong)
	 * m4svm_instruction_putstatic_x(FLOAT, jfloat)
	 * m4svm_instruction_putstatic_x2(DOUBLE, jdouble)
	 * m4svm_instruction_putstatic_x(REFERENCE, reference) */

	/* m4_undefine([:m4svm_instruction_putstatic_x:])
	 * m4_undefine([:m4svm_instruction_putstatic_x2:]) */

/*
----------------------------------------------------------------------
PREPARE_CHECKCAST
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_CHECKCAST, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->type_info = classref_info->type;

	  /* execute bytecode */
	  {
	    _svmt_type_info *T = classref_info->type;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance != NULL)
	      {
		_svmt_type_info *S = instance->vtable->type;

		if (!_svmf_is_assignable_from (env, S, T))
		  {
		    goto classcastexception_handler;
		  }
	      }
	  }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INSTANCEOF
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INSTANCEOF, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 3)->addr;
#endif
	  addr->type_info = classref_info->type;

	  /* execute bytecode */
	  {
	    _svmt_type_info *T = classref_info->type;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance != NULL)
	      {
		_svmt_type_info *S = instance->vtable->type;

		if (_svmf_is_assignable_from (env, S, T))
		  {
		    stack[stack_size - 1].jint = 1;
		  }
		else
		  {
		    stack[stack_size - 1].jint = 0;
		  }
	      }
	    else
	      {
		stack[stack_size - 1].jint = 0;
	      }
	  }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_NEW
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_NEW, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, _svmf_cast_class (classref_info->type)) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	  /* code array might have changed */
	    pc = env->stack.current_frame->pc;
	    addr = (pc - 3)->addr;
#endif	  
	    addr->class_info = _svmf_cast_class (classref_info->type);

	  /* execute bytecode */
	  {
	    _svmt_class_info *class_info =
	      _svmf_cast_class (classref_info->type);
	    _svmt_object_instance *instance;

	    if (_svmm_new_object_instance
		(env, class_info, instance) != JNI_OK)
	      {
		goto exception_handler;
	      }

#ifdef _SABLEVM_METHOD_INLINING
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
#endif
	    stack[stack_size++].reference = instance;
	  }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_ANEWARRAY
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_ANEWARRAY, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;
	  _svmt_type_info *type;
	  _svmt_array_info *array_type;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  type = classref_info->type;

	  if (_svmm_create_array
	      (env,
	       type->class_loader_info, type->array_type_name,
	       array_type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_array (env, array_type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

#ifdef _SABLEVM_METHOD_INLINING
	    /* code array might have changed */
	    pc = env->stack.current_frame->pc;
	    addr = (pc - 3)->addr;
#endif
	    addr->array_info = array_type;

	  /* execute bytecode */
	  {
	    _svmt_array_info *array_info = array_type;
	    jint count = stack[--stack_size].jint;
	    _svmt_array_instance *instance;

	    if (count < 0)
	      {
		_svmf_error_NegativeArraySizeException (env);
		goto exception_handler;
	      }

	    if (_svmm_new_array_instance
		(env, array_info, count, instance) != JNI_OK)
	      {
		goto exception_handler;
	      }

#ifdef _SABLEVM_METHOD_INLINING
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
#endif
	    stack[stack_size++].reference =
	      _svmf_cast_object_instance (instance);
	  }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_MULTIANEWARRAY
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_MULTIANEWARRAY, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;
	  jint dimensions = (pc++)->jint;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }
	  
#ifdef _SABLEVM_METHOD_INLINING
	    /* code array might have changed */
	  pc = env->stack.current_frame->pc;
	  addr = (pc - 4)->addr;
#endif
	  addr->array_info = _svmf_cast_array (classref_info->type);
	  
	  /* execute bytecode */
	  {
	    _svmt_array_info *array_info =
	      _svmf_cast_array (classref_info->type);
	    _svmt_array_instance *instance;

	    stack_size -= dimensions;

	    if (_svmm_multianewarray
		(env, array_info, dimensions, stack[stack_size],
		 instance) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    stack[stack_size++].reference =
	      _svmf_cast_object_instance (instance);
	  }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INVOKEVIRTUAL, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Methodref_info *methodref_info =
	    (pc++)->methodref_info;

	  jint args_count;
	  size_t offset;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Methodref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, methodref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);

#ifdef _SABLEVM_METHOD_INLINING
	    {
	      jint inst;
	      
	      /* in case code array has changed (if inlining has been done) */
	      pc = env->stack.current_frame->pc;
	      addr = (pc - 3)->addr;
	      
#ifndef NDEBUG
	      if (frame_info->code == frame_info->normal_code)
		{
		  assert ((addr >= frame_info->normal_code) &&
			  (addr <
			   frame_info->code + frame_info->code_length));
		}
	      else
		{
		  assert ((addr >= frame_info->profiling_code) &&
			  (addr <
			   frame_info->code +
			   frame_info->profiling_code_length));
		}
#endif /* NDEBUG */

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
	      inst = addr[-2].jint;
#endif
	      
#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
	      inst = _svmf_mi_get_instruction_int_code (env,
							addr[-2].
							implementation);
#endif
	      
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      {
		_svmt_mi_sequence_node_info *sequence;
		
		if ((sequence =
		     _svmf_mi_get_sequence_by_implementation (env,
							      addr[-2].
							      implementation))
		    == NULL)
		  {
		    _svmm_fatal_error ("invalid sequence");
		  }
		
		inst = sequence->instructions[0];
	      }
#endif
	      
	      assert ((inst >= 0) && (inst < SVM_INSTRUCTION_COUNT));
	      
#endif /* _SABLEVM_METHOD_INLINING */
	      
	      args_count = methodref_info->method->java_args_count;
	      
	      /*
	       * _svmf_resolve_CONSTANT_Methodref() may return an
	       * interface method in certain situations (e.g., virtually
	       * invoking a method on an abstract class, when this method
	       * is inherited from an interface and not implemented in the
	       * abstact class).
	       */
	      if (_svmf_is_set_flag
		  (methodref_info->method->class_info->access_flags,
		   SVM_ACC_INTERFACE))
		{
		  offset =
		    -((1 + methodref_info->method->method_id) *
		      sizeof (_svmt_method_info *));
		}
	      else
		{
		  offset =
		    sizeof (_svmt_vtable) +
		    (methodref_info->method->method_id *
		     sizeof (_svmt_method_info *));
		}
	      
#ifdef _SABLEVM_METHOD_INLINING
	      /* only if the job has not already been done and if no */
	      /* inlining of this invoke has took place */
	      if (inst == SVM_INSTRUCTION_GOTO)
		{
		  addr[0].jint = args_count;
		  addr[1].offset = offset;
		  
		  if(frame_info->code == frame_info->profiling_code)
		    {
		      jint offset_tmp;
		      
		      if ((offset_tmp =
			   _svmf_mp_get_old_offset (frame_info->method, addr)) < 0)
			{
			  _svmm_fatal_error("invalid address");
			}
		      
		      addr = frame_info->normal_code + offset_tmp;
		      
		      /* we must update normal_code too */
		      addr[0].jint = args_count;
		      addr[1].offset = offset;
		    }
		}
	    }
	  }
#else
	}
	      addr[0].jint = args_count;
	      addr[1].offset = offset;
	      
#endif /* _SABLEVM_METHOD_INLINING */
	  
	  /* execute bytecode */
	  {
	    size_t method_offset = offset;
	    _svmt_object_instance *instance =
	      stack[(stack_size -= args_count)].reference;
	    _svmt_method_info *method;
	    _svmt_method_frame_info *frame_info;
	    _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	    if (instance == NULL)
	      {
		env->sigsegv_expected = JNI_TRUE;
	      }

#endif /* NOT NDEBUG */

	    /* save pc in case exception is raised */
	    env->stack.current_frame->pc = pc;

#else

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	    /* the following can cause a segfault */
	    method =
	      *((_svmt_method_info **) (void *)
		(((char *) instance->vtable) + method_offset));

	    assert (_svmf_is_assignable_from
		    (env, instance->vtable->type,
		     _svmf_cast_type_class (method->class_info)));

	    assert (strcmp
		    (DREF (method->name, value),
		     DREF (DREF (methodref_info->name_and_type, name),
			   value)) == 0
		    && strcmp (DREF (method->descriptor, value),
			       DREF (DREF
				     (methodref_info->name_and_type,
				      descriptor), value)) == 0);

	    frame_info = method->frame_info;

	    /* store return pc & stack size */
	    frame = env->stack.current_frame;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    /* syncronized? */
	    if (method->synchronized)
	      {
		/* preserve references on the stack across GC */
		frame->stack_size = stack_size + args_count;

		if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		  {
		    goto exception_handler;
		  }

#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
		frame->stack_size = stack_size;
		instance = stack[stack_size].reference;
	      }

	    if (_svmf_ensure_stack_capacity
		(env, frame_info->java_invoke_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    frame = env->stack.current_frame;
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    locals = &stack[stack_size];

	    /* initialize reference locals to null */
	    {
	      jint max = frame_info->non_parameter_ref_locals_count;
	      jint java_args_count = method->java_args_count;
	      jint i;

	      for (i = 0; i < max; i++)
		{
		  locals[java_args_count + i].reference = NULL;
		}
	    }

	    /* setup callee frame */
	    frame =
	      (_svmt_stack_frame *) (void *)
	      (((char *) locals) + frame_info->start_offset);
	    stack =
	      (_svmt_stack_value *) (void *) (((char *) frame) +
					      _svmv_stack_offset);
	    pc = frame_info->code;
	    stack_size = 0;

	    frame->previous_offset =
	      ((char *) frame) - ((char *) env->stack.current_frame);
	    frame->end_offset = frame_info->end_offset;
	    frame->method_frame_info = frame_info;
	    frame->stack_trace_element = NULL;
	    frame->lock_count = 0;
	    frame->this = instance;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    env->stack.current_frame = frame;

	    /* check */
	    _svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

#ifndef NDEBUG

	    {
	      /* check argument types */

	      jint arg_count = method->java_args_count;
	      const char *pdesc = DREF (method->descriptor, value) + 1;
	      jint arg = 1;

	      while (arg < arg_count)
		{
		  jint old_arg = arg;

		  if (locals[old_arg].reference != NULL)
		    {
		      _svmt_type_info *t =
			_svmm_get_type_from_within_descriptor (env, method,
							       pdesc, arg);

		      /* in case stack was moved around  */
		      frame = env->stack.current_frame;
		      locals = (_svmt_stack_value *) (void *)
			(((char *) frame) - frame_info->start_offset);
		      stack = (_svmt_stack_value *) (void *)
			(((char *) frame) + _svmv_stack_offset);

		      if (t != NULL)
			{
			  if (!_svmf_is_assignable_from
			      (env, locals[old_arg].reference->vtable->type,
			       t))
			    {
			      _svmf_dump_stack_trace (env);
			      _svmm_fatal_error
				("argument type bug detected");
			    }
			}
		    }
		  else
		    {
		      _svmm_skip_type_within_descriptor (pdesc, arg);
		    }
		}
#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
	    }

#endif

	  }
	}

#if !defined(NDEBUG)
	_svmf_verbose_methods_enter (env);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INVOKESPECIAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INVOKESPECIAL, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Methodref_info *methodref_info =
	    (pc++)->methodref_info;

	  jint args_count;
	  _svmt_method_info *selected_method;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Methodref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, methodref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  /* select the appropriate method */
	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;
	    _svmt_method_info *method = frame_info->method;

#ifdef _SABLEVM_METHOD_INLINING
	    jint inst;

	    /* in case code array has changed (if inlining has been done) */
	    pc = env->stack.current_frame->pc;
	    addr = (pc - 3)->addr;

#ifndef NDEBUG
	    if (frame_info->code == frame_info->normal_code)
	      {
		assert ((addr >= frame_info->normal_code) &&
			(addr < frame_info->code + frame_info->code_length));
	      }
	    else
	      {
		assert ((addr >= frame_info->profiling_code) &&
			(addr <
			 frame_info->code +
			 frame_info->profiling_code_length));
	      }
#endif

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
	    inst = addr[-2].jint;
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
	    inst = _svmf_mi_get_instruction_int_code (env,
						      addr[-2].
						      implementation);
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	    {
	      _svmt_mi_sequence_node_info *sequence;

	      if ((sequence =
		   _svmf_mi_get_sequence_by_implementation (env,
							    addr[-2].
							    implementation))
		  == NULL)
		{
		  _svmm_fatal_error ("invalid sequence");
		}

	      inst = sequence->instructions[0];
	    }
#endif

	    assert ((inst >= 0) && (inst < SVM_INSTRUCTION_COUNT));

#endif /* _SABLEVM_METHOD_INLINING */

	    if (_svmf_is_set_flag
		(method->class_info->access_flags, SVM_ACC_SUPER)
		&& _svmf_is_super_class (methodref_info->method->class_info,
					 method->class_info)
		&& DREF (methodref_info->method->name, value)[0] != '<')
	      {
		selected_method =
		  _svmf_resolve_special_method (_svmf_cast_class
						(DREF
						 (method->class_info->
						  super_class, type)),
						DREF (methodref_info->method->
						      name, value),
						DREF (methodref_info->method->
						      descriptor, value));

		args_count = selected_method->java_args_count;
	      }
	    else
	      {
		selected_method = methodref_info->method;
		args_count = selected_method->java_args_count;
	      }

#ifdef _SABLEVM_METHOD_INLINING

	    /* only if the job has not already been done and if no */
	    /* inlining of this invoke has took place */
	    if (inst == SVM_INSTRUCTION_GOTO)
	      {
		addr[0].jint = args_count;
		addr[1].method_info = selected_method;
		
		if(frame_info->code == frame_info->profiling_code)
		  {
		    jint offset_tmp;
		    
		    if ((offset_tmp =
			 _svmf_mp_get_old_offset (frame_info->method, addr)) < 0)
		      {
			_svmm_fatal_error("invalid address");
		      }
		    
		    addr = frame_info->normal_code + offset_tmp;
		    
		    /* we must update normal_code too */
		    addr[0].jint = args_count;
		    addr[1].method_info = selected_method;
		  }
	      }
#else
	    addr[0].jint = args_count;
	    addr[1].method_info = selected_method;
#endif
	  }

	  /* execute bytecode */
	  {
	    _svmt_method_info *method = selected_method;
	    _svmt_object_instance *instance =
	      stack[(stack_size -= args_count)].reference;
	    _svmt_method_frame_info *frame_info;
	    _svmt_stack_frame *frame;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    assert (_svmf_is_assignable_from
		    (env, instance->vtable->type,
		     _svmf_cast_type_class (method->class_info)));

	    assert (strcmp
		    (DREF (method->name, value),
		     DREF (DREF (methodref_info->name_and_type, name),
			   value)) == 0
		    && strcmp (DREF (method->descriptor, value),
			       DREF (DREF
				     (methodref_info->name_and_type,
				      descriptor), value)) == 0);

	    frame_info = method->frame_info;

	    frame = env->stack.current_frame;
/* 	    frame->pc = pc; */

	    /* store stack size */
	    frame->stack_size = stack_size;

	    /* syncronized? */
	    if (method->synchronized)
	      {
		/* preserve references on the stack across GC */
		frame->stack_size = stack_size + args_count;

		if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		  {
		    goto exception_handler;
		  }

#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
		frame->stack_size = stack_size;
		instance = stack[stack_size].reference;
	      }

#ifdef _SABLEVM_METHOD_INLINING
	    if (_svmf_ensure_stack_capacity
		(env,
		 frame_info->java_invoke_frame_size +
		 frame_info->extra_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }
#else
	    if (_svmf_ensure_stack_capacity
		(env, frame_info->java_invoke_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }
#endif
	    frame = env->stack.current_frame;
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    locals = &stack[stack_size];

	    /* initialize reference locals to null */
	    {
	      jint max = frame_info->non_parameter_ref_locals_count;
	      jint java_args_count = method->java_args_count;
	      jint i;

	      for (i = 0; i < max; i++)
		{
		  locals[java_args_count + i].reference = NULL;
		}
	    }

	    /* setup callee frame */
	    frame =
	      (_svmt_stack_frame *) (void *)
	      (((char *) locals) + frame_info->start_offset);
	    stack =
	      (_svmt_stack_value *) (void *) (((char *) frame) +
					      _svmv_stack_offset);
	    pc = frame_info->code;
	    stack_size = 0;

	    frame->previous_offset =
	      ((char *) frame) - ((char *) env->stack.current_frame);
	    frame->end_offset = frame_info->end_offset;
	    frame->method_frame_info = frame_info;
	    frame->stack_trace_element = NULL;
	    frame->lock_count = 0;
	    frame->this = instance;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    env->stack.current_frame = frame;

	    /* check */
	    _svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

#ifndef NDEBUG

	    {
	      /* check argument types */

	      jint arg_count = method->java_args_count;
	      const char *pdesc = DREF (method->descriptor, value) + 1;
	      jint arg = 1;

	      while (arg < arg_count)
		{
		  jint old_arg = arg;

		  if (locals[old_arg].reference != NULL)
		    {
		      _svmt_type_info *t =
			_svmm_get_type_from_within_descriptor (env, method,
							       pdesc, arg);

		      /* in case stack was moved around  */
		      frame = env->stack.current_frame;
		      locals = (_svmt_stack_value *) (void *)
			(((char *) frame) - frame_info->start_offset);
		      stack = (_svmt_stack_value *) (void *)
			(((char *) frame) + _svmv_stack_offset);

		      if (t != NULL)
			{
			  if (!_svmf_is_assignable_from
			      (env, locals[old_arg].reference->vtable->type,
			       t))
			    {
			      _svmf_dump_stack_trace (env);
			      _svmm_fatal_error
				("argument type bug detected");
			    }
			}
		    }
		  else
		    {
		      _svmm_skip_type_within_descriptor (pdesc, arg);
		    }
		}
#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
	    }

#endif

	  }
	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INVOKESTATIC
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INVOKESTATIC, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Methodref_info *methodref_info =
	    (pc++)->methodref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Methodref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, methodref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, methodref_info->method->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);

#ifdef _SABLEVM_METHOD_INLINING
	    {
	      jint inst;

	      /* in case code array has changed (if inlining has been done) */
	      pc = env->stack.current_frame->pc;
	      addr = (pc - 3)->addr;

#ifndef NDEBUG
	      if (frame_info->code == frame_info->normal_code)
		{
		  assert ((addr >= frame_info->normal_code) &&
			  (addr <
			   frame_info->code + frame_info->code_length));
		}
	      else
		{
		  assert ((addr >= frame_info->profiling_code) &&
			  (addr <
			   frame_info->code +
			   frame_info->profiling_code_length));
		}
#endif

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
	      inst = addr[-2].jint;
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
	      inst = _svmf_mi_get_instruction_int_code (env,
							addr[-2].
							implementation);
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      {
		_svmt_mi_sequence_node_info *sequence;

		if ((sequence =
		     _svmf_mi_get_sequence_by_implementation (env,
							      addr[-2].
							      implementation))
		    == NULL)
		  {
		    _svmm_fatal_error ("invalid sequence");
		  }

		inst = sequence->instructions[0];
	      }
#endif

/* 	      _svmf_printf(env, stderr, "addr[%p] addr-2[%p]\n", addr, addr-2); */

/* 	      _svmf_print_method_name(env, stderr, */
/* 				      frame_info->method,  */
/* 				      "PREP_INVOKESTATIC: in "); */

/* 	      if((inst < 0) || (inst >= SVM_INSTRUCTION_COUNT)) */
/* 		{ */
/* 		  _svmf_mi_print_bytecode_count(env, pc); */
/* 		  exit(1); */
/* 		} */


	      assert ((inst >= 0) && (inst < SVM_INSTRUCTION_COUNT));

	      /* only if the job has not already been done and if no */
	      /* inlining of this invoke has took place */
	      if (inst == SVM_INSTRUCTION_GOTO)
		{
		  addr[0].jint = methodref_info->method->java_args_count;
		  addr[1].method_info = methodref_info->method;
		  
		  if(frame_info->code == frame_info->profiling_code)
		    {
		      jint offset_tmp;
		      
		      if ((offset_tmp =
			   _svmf_mp_get_old_offset (frame_info->method, addr)) < 0)
			{
			  _svmm_fatal_error("invalid address");
			}
		      
		      addr = frame_info->normal_code + offset_tmp;
		      
		      /* we must update normal_code too */
		      addr[0].jint = methodref_info->method->java_args_count;
		      addr[1].method_info = methodref_info->method;
		    }
		}
	    }
	  }
#else /* _SABLEVM_METHOD_INLINING */

	  }

	  addr[0].jint = methodref_info->method->java_args_count;
	  addr[1].method_info = methodref_info->method;
#endif

/* 	  _svmf_printf(env, stderr, "returned in PREPARE_INVOKESTATIC of method[%s] current_frame->pc[%p] pc[%p]\n", */
/* 		       DREF (methodref_info->method->name, value), env->stack.current_frame->pc, pc); */

	  /* execute bytecode */
	  {
	    jint args_count = methodref_info->method->java_args_count;
	    _svmt_method_info *method = methodref_info->method;
	    _svmt_method_frame_info *frame_info;
	    _svmt_stack_frame *frame;

	    assert (strcmp
		    (DREF (method->name, value),
		     DREF (DREF (methodref_info->name_and_type, name),
			   value)) == 0
		    && strcmp (DREF (method->descriptor, value),
			       DREF (DREF
				     (methodref_info->name_and_type,
				      descriptor), value)) == 0);

	    frame_info = method->frame_info;
	    stack_size -= args_count;

	    frame = env->stack.current_frame;
/* 	    frame->pc = pc; */

	    /* store stack size */
	    frame->stack_size = stack_size;

	    /* syncronized? */
	    if (method->synchronized)
	      {
		/* preserve references on the stack across GC */
		frame->stack_size = stack_size + args_count;

		if (_svmf_enter_object_monitor
		    (env, *(method->class_info->class_instance)) != JNI_OK)
		  {
		    goto exception_handler;
		  }

#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
		frame->stack_size = stack_size;
	      }

#ifdef _SABLEVM_METHOD_INLINING
	    if (_svmf_ensure_stack_capacity
		(env,
		 frame_info->java_invoke_frame_size +
		 frame_info->extra_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }
#else
	    if (_svmf_ensure_stack_capacity
		(env, frame_info->java_invoke_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }
#endif

	    frame = env->stack.current_frame;
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    locals = &stack[stack_size];

	    /* initialize reference locals to null */
	    {
	      jint max = frame_info->non_parameter_ref_locals_count;
	      jint java_args_count = method->java_args_count;
	      jint i;

	      for (i = 0; i < max; i++)
		{
		  locals[java_args_count + i].reference = NULL;
		}
	    }

	    /* setup callee frame */
	    frame =
	      (_svmt_stack_frame *) (void *)
	      (((char *) locals) + frame_info->start_offset);
	    stack =
	      (_svmt_stack_value *) (void *) (((char *) frame) +
					      _svmv_stack_offset);
	    pc = frame_info->code;
	    stack_size = 0;

	    frame->previous_offset =
	      ((char *) frame) - ((char *) env->stack.current_frame);
	    frame->end_offset = frame_info->end_offset;
	    frame->method_frame_info = frame_info;
	    frame->stack_trace_element = NULL;
	    frame->lock_count = 0;
	    frame->this = *(method->class_info->class_instance);
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    env->stack.current_frame = frame;

	    /* check */
	    _svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

/* 	    _svmf_printf(env, stderr, "[%d] PREPARE_INVOKESTATIC [%s.%s()] in [%s.%s()] callee_method_pc[%p]\n", */
/* 			 env->thread.id, */
/* 			 method->class_info->name, */
/* 			 DREF (method->name, value), */
/* 			 env->stack.current_frame->method_frame_info->method->class_info->name, */
/* 			 DREF (env->stack.current_frame->method_frame_info->method->name, value), pc); */


#ifndef NDEBUG

	    {
	      /* check argument types */

	      jint arg_count = method->java_args_count;
	      const char *pdesc = DREF (method->descriptor, value) + 1;
	      jint arg = 0;

	      while (arg < arg_count)
		{
		  jint old_arg = arg;

		  if (locals[old_arg].reference != NULL)
		    {
		      _svmt_type_info *t =
			_svmm_get_type_from_within_descriptor (env, method,
							       pdesc, arg);

		      /* in case stack was moved around  */
		      frame = env->stack.current_frame;
		      locals = (_svmt_stack_value *) (void *)
			(((char *) frame) - frame_info->start_offset);
		      stack = (_svmt_stack_value *) (void *)
			(((char *) frame) + _svmv_stack_offset);

		      if (t != NULL)
			{
			  if (!_svmf_is_assignable_from
			      (env, locals[old_arg].reference->vtable->type,
			       t))
			    {
			      _svmf_dump_stack_trace (env);
			      _svmm_fatal_error
				("argument type bug detected");
			    }
			}
		    }
		  else
		    {
		      _svmm_skip_type_within_descriptor (pdesc, arg);
		    }
		}
#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
	    }

#endif

	  }
	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INVOKEINTERFACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INVOKEINTERFACE, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_InterfaceMethodref_info *imethodref_info =
	    (pc++)->imethodref_info;

	  jint args_count;
	  size_t offset;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_InterfaceMethodref
	      (env,
	       env->stack.current_frame->method_frame_info->method->
	       class_info, imethodref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_frame_info *frame_info = frame->method_frame_info;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);

#ifdef _SABLEVM_METHOD_INLINING
	    {
	      jint inst;
#endif
	      args_count = imethodref_info->method->java_args_count;
	      offset = -((1 + imethodref_info->method->method_id) *
			 sizeof (_svmt_method_info *));
	      
#ifdef _SABLEVM_METHOD_INLINING
	      
	      /* in case code array has changed (if inlining has been done) */
	      pc = env->stack.current_frame->pc;
	      addr = (pc - 3)->addr;
	      
#ifndef NDEBUG
	      if (frame_info->code == frame_info->normal_code)
		{
		  assert ((addr >= frame_info->normal_code) &&
			  (addr <
			   frame_info->code + frame_info->code_length));
		}
	      else
		{
		  assert ((addr >= frame_info->profiling_code) &&
			  (addr <
			   frame_info->code +
			   frame_info->profiling_code_length));
		}
#endif /* NDEBUG */
	      
#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
	      inst = addr[-2].jint;
#endif
	      
#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
	      inst = _svmf_mi_get_instruction_int_code (env,
							addr[-2].
							implementation);
#endif
	      
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      {
		_svmt_mi_sequence_node_info *sequence;
		
		if ((sequence =
		     _svmf_mi_get_sequence_by_implementation (env,
							      addr[-2].
							      implementation))
		    == NULL)
		  {
		    _svmm_fatal_error ("invalid sequence");
		  }
		
		inst = sequence->instructions[0];
	      }
#endif
	      
	      assert ((inst >= 0) && (inst < SVM_INSTRUCTION_COUNT));
	      
	      if (inst == SVM_INSTRUCTION_GOTO)
		{
		  addr[0].jint = args_count;
		  addr[1].offset = offset;
		  
		  if(frame_info->code == frame_info->profiling_code)
		    {
		      jint offset_tmp;
		      
		      if ((offset_tmp =
			   _svmf_mp_get_old_offset (frame_info->method, addr)) < 0)
			{
			  _svmm_fatal_error("invalid address");
			}
		      
		      addr = frame_info->normal_code + offset_tmp;
		      
		      /* we must update normal_code too */
		      addr[0].jint = args_count;
		      addr[1].offset = offset;
		    }
		}
	    }
	  }
#else
	}
	    addr[0].jint = args_count;
	    addr[1].offset = offset;
#endif /* _SABLEVM_METHOD_INLINING */

	  /* execute bytecode */
	  {
	    size_t method_offset = offset;
	    _svmt_object_instance *instance =
	      stack[(stack_size -= args_count)].reference;
	    _svmt_method_info *method;
	    _svmt_method_frame_info *frame_info;
	    _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	    if (instance == NULL)
	      {
		env->sigsegv_expected = JNI_TRUE;
	      }

#endif /* NOT NDEBUG */

	    /* save pc in case exception is raised */
	    env->stack.current_frame->pc = pc;

#else

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	    /* the following can cause a segfault */
	    method =
	      *((_svmt_method_info **) (void *)
		(((char *) instance->vtable) + method_offset));

	    assert (_svmf_is_assignable_from
		    (env, instance->vtable->type,
		     _svmf_cast_type_class (method->class_info)));

	    assert (strcmp
		    (DREF (method->name, value),
		     DREF (DREF (imethodref_info->name_and_type, name),
			   value)) == 0
		    && strcmp (DREF (method->descriptor, value),
			       DREF (DREF
				     (imethodref_info->name_and_type,
				      descriptor), value)) == 0);

	    frame_info = method->frame_info;

	    /* store return pc & stack size */
	    frame = env->stack.current_frame;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    /* syncronized? */
	    if (method->synchronized)
	      {
		/* preserve references on the stack across GC */
		frame->stack_size = stack_size + args_count;

		if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		  {
		    goto exception_handler;
		  }

#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
		frame->stack_size = stack_size;
		instance = stack[stack_size].reference;
	      }

	    if (_svmf_ensure_stack_capacity
		(env, frame_info->java_invoke_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    frame = env->stack.current_frame;
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    locals = &stack[stack_size];

	    /* initialize reference locals to null */
	    {
	      jint max = frame_info->non_parameter_ref_locals_count;
	      jint java_args_count = method->java_args_count;
	      jint i;

	      for (i = 0; i < max; i++)
		{
		  locals[java_args_count + i].reference = NULL;
		}
	    }

	    /* setup callee frame */
	    frame =
	      (_svmt_stack_frame *) (void *)
	      (((char *) locals) + frame_info->start_offset);
	    stack =
	      (_svmt_stack_value *) (void *) (((char *) frame) +
					      _svmv_stack_offset);
	    pc = frame_info->code;
	    stack_size = 0;

	    frame->previous_offset =
	      ((char *) frame) - ((char *) env->stack.current_frame);
	    frame->end_offset = frame_info->end_offset;
	    frame->method_frame_info = frame_info;
	    frame->stack_trace_element = NULL;
	    frame->lock_count = 0;
	    frame->this = instance;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    env->stack.current_frame = frame;

	    /* check */
	    _svmf_periodic_check (env);

#ifdef _SABLEVM_METHOD_INLINING
	/* refresh pc */
	pc = env->stack.current_frame->pc;
#endif

#ifndef NDEBUG

	    {
	      /* check argument types */

	      jint arg_count = method->java_args_count;
	      const char *pdesc = DREF (method->descriptor, value) + 1;
	      jint arg = 1;

	      while (arg < arg_count)
		{
		  jint old_arg = arg;

		  if (locals[old_arg].reference != NULL)
		    {
		      _svmt_type_info *t =
			_svmm_get_type_from_within_descriptor (env, method,
							       pdesc, arg);

		      /* in case stack was moved around  */
		      frame = env->stack.current_frame;
		      locals = (_svmt_stack_value *) (void *)
			(((char *) frame) - frame_info->start_offset);
		      stack = (_svmt_stack_value *) (void *)
			(((char *) frame) + _svmv_stack_offset);

		      if (t != NULL)
			{
			  if (!_svmf_is_assignable_from
			      (env, locals[old_arg].reference->vtable->type,
			       t))
			    {
			      _svmf_dump_stack_trace (env);
			      _svmm_fatal_error
				("argument type bug detected");
			    }
			}
		    }
		  else
		    {
		      _svmm_skip_type_within_descriptor (pdesc, arg);
		    }
		}
#ifdef _SABLEVM_METHOD_INLINING
		/* refresh pc */
		pc = env->stack.current_frame->pc;
#endif
	    }

#endif

	  }
	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	m4svm_instruction_tail ();

/* ----------------------------------------------------------------------------------- */

m4svm_on(0)
#ifdef _SABLEVM_METHOD_INLINING
m4svm_off()
/*
----------------------------------------------------------------------
INITIAL_INVOKESTATIC
----------------------------------------------------------------------
*/
	  m4svm_instruction_head (INITIAL_INVOKESTATIC, -1);

	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_method_frame_info *frame_info = method->frame_info;
	  _svmt_stack_frame *frame;

	  if ((frame_info->inlinable == JNI_TRUE) && 
	      (env->stack.current_frame->method_frame_info->nb_instructions <= 
	       env->vm->mi_info.max_calling_method_length))
	    {
	      _svmt_method_frame_info *calling_method_frame_info =
		env->stack.current_frame->method_frame_info;
	      _svmt_code *normal_code =
		calling_method_frame_info->normal_code;

	      /* we are in profiling code array */
	      if (calling_method_frame_info->code ==
		  calling_method_frame_info->profiling_code)
		{
		  jint index =
		    _svmf_mp_get_old_offset (calling_method_frame_info->
					     method, pc - 3);

		  assert (index > 0);

		  pc[-3].addr =
		    calling_method_frame_info->normal_code + index;
		  pc[-4] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_PROFILING_INVOKESTATIC].code;

		  /* Method has been prepared. We replace the GOTO or the INITIAL_INVOKE */
		  normal_code[index + 1].jint = args_count;
		  normal_code[index + 2].method_info = method;

		  /* No need for synchronization nobody is using normal code at the moment */
		  normal_code[index - 1] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_COUNTING_INVOKESTATIC].code;
		  normal_code[index].size_t = 2;
		}
	      /* we are in the normal code array */
	      else if ((pc >= normal_code)
		       && (pc <
			   (normal_code +
			    calling_method_frame_info->code_length)))
		{
		  pc[-3].size_t = 2;	/* invoke site count */
		  pc[-4] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_COUNTING_INVOKESTATIC].code;
		}
	      /* we are in inlined code so we don't want imbricated inlining */
	      else
		{
		  pc[-4] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKESTATIC].code;
		}
	    }
	  else
	    {
	      pc[-4] =
		env->vm->instructions[SVM_INSTRUCTION_INVOKESTATIC].code;
	    }

	  stack_size -= args_count;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  frame_info->nb_executions++;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor
		  (env, *(method->class_info->class_instance)) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

	      frame->stack_size = stack_size;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = *(method->class_info->class_instance);
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 0;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }
#endif

	}

#if !defined(NDEBUG)
	_svmf_verbose_methods_enter (env);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INITIAL_INVOKESPECIAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INITIAL_INVOKESPECIAL, -1);

	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_frame_info *frame_info = method->frame_info;
	  _svmt_stack_frame *frame;

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  if ((frame_info->inlinable == JNI_TRUE) && 
	      (env->stack.current_frame->method_frame_info->nb_instructions <= 
	       env->vm->mi_info.max_calling_method_length))
	    
	    {
	      _svmt_method_frame_info *calling_method_frame_info =
		env->stack.current_frame->method_frame_info;
	      _svmt_code *normal_code =
		calling_method_frame_info->normal_code;

	      /* we are in profiling code array */
	      if (calling_method_frame_info->code ==
		  calling_method_frame_info->profiling_code)
		{
		  jint index =
		    _svmf_mp_get_old_offset (calling_method_frame_info->
					     method, pc - 3);

		  assert (index > 0);

		  pc[-3].addr =
		    calling_method_frame_info->normal_code + index;
		  pc[-4] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_PROFILING_INVOKESPECIAL].
		    code;

		  /* Method has been prepared. We replace the GOTO or the INITIAL_INVOKE */
		  normal_code[index + 1].jint = args_count;
		  normal_code[index + 2].method_info = method;

		  /* No need for synchronization noboby is using normal code at the moment */
		  normal_code[index - 1] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_COUNTING_INVOKESPECIAL].code;
		  normal_code[index].size_t = 2;
		}
	      /* we are in the normal code array */
	      else if ((pc >= normal_code)
		       && (pc <
			   (normal_code +
			    calling_method_frame_info->code_length)))
		{
		  pc[-3].size_t = 2;	/* invoke site count */
		  pc[-4] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_COUNTING_INVOKESPECIAL].code;
		}
	      /* we are in inlined code so we don't want imbricated inlining */
	      else
		{
		  pc[-4] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKESPECIAL].code;
		}
	    }
	  else
	    {
	      pc[-4] =
		env->vm->instructions[SVM_INSTRUCTION_INVOKESPECIAL].code;
	    }

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  frame_info->nb_executions++;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#if !defined(NDEBUG)

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);
		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif
	}

#if !defined(NDEBUG)
	_svmf_verbose_methods_enter (env);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INITIAL_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INITIAL_INVOKEVIRTUAL, -1);

	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  if ((frame_info->inlinable == JNI_TRUE) && 
	      (env->stack.current_frame->method_frame_info->nb_instructions <= 
	       env->vm->mi_info.max_calling_method_length))
	    {
	      _svmt_mi_invoke_info *invoke_info;
	      _svmt_method_frame_info *calling_method_frame_info =
		env->stack.current_frame->method_frame_info;
	      _svmt_code *normal_code =
		calling_method_frame_info->normal_code;

	      if (_svmm_cl_zalloc_mi_invoke_info
		  (env, method->class_info->class_loader_info,
		   invoke_info) != JNI_OK)
		{
		  _svmm_fatal_error
		    ("unable to allocated memory fo _svmt_mi_invoke_info");
		}

	      invoke_info->count = 2;
	      invoke_info->last_method = method;

	      /* we are in profiling code array */
	      if (calling_method_frame_info->code ==
		  calling_method_frame_info->profiling_code)
		{
		  jint index =
		    _svmf_mp_get_old_offset (calling_method_frame_info->
					     method, pc - 3);

		  assert (index > 0);

		  pc[-3].invoke_info = invoke_info;
		  pc[-4] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL].
		    code;

		  /* Method has been prepared. We replace the GOTO or the INITIAL_INVOKE */
		  normal_code[index + 1].jint = args_count;
		  normal_code[index + 2].offset = method_offset;

		  /* No need for synchronization nobody is using normal code at the moment */
		  normal_code[index - 1] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL].code;
		  normal_code[index].invoke_info = invoke_info;
		}
	      /* we are in the normal code array */
	      else if ((pc >= normal_code)
		       || (pc <
			   (normal_code +
			    calling_method_frame_info->code_length)))
		{
		  pc[-3].invoke_info = invoke_info;	/* invoke site count */
		  pc[-4] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL].code;
		}
	      /* we are in inlined code so we don't want imbricated inlining */
	      else
		{
		  pc[-4] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKEVIRTUAL].code;
		}
	    }
	  else
	    {
	      pc[-4] =
		env->vm->instructions[SVM_INSTRUCTION_INVOKEVIRTUAL].code;
	    }

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  frame_info->nb_executions++;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  goto exception_handler;
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif
	}

#if !defined(NDEBUG)
	_svmf_verbose_methods_enter (env);
#endif
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INITIAL_INVOKEINTERFACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INITIAL_INVOKEINTERFACE, -1);

	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  if ((frame_info->inlinable == JNI_TRUE) && 
	      (env->stack.current_frame->method_frame_info->nb_instructions <= 
	       env->vm->mi_info.max_calling_method_length))
	    {
	      _svmt_mi_invoke_info *invoke_info;
	      _svmt_method_frame_info *calling_method_frame_info =
		env->stack.current_frame->method_frame_info;
	      _svmt_code *normal_code =
		calling_method_frame_info->normal_code;

	      if (_svmm_cl_zalloc_mi_invoke_info
		  (env, method->class_info->class_loader_info,
		   invoke_info) != JNI_OK)
		{
		  _svmm_fatal_error
		    ("unable to allocated memory fo _svmt_mi_invoke_info");
		}

	      invoke_info->count = 2;
	      invoke_info->last_method = method;

	      /* we are in profiling code array */
	      if (calling_method_frame_info->code ==
		  calling_method_frame_info->profiling_code)
		{
		  jint index =
		    _svmf_mp_get_old_offset (calling_method_frame_info->
					     method, pc - 3);

		  assert (index > 0);

		  pc[-3].invoke_info = invoke_info;
		  pc[-4] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE].
		    code;

		  /* Method has been prepared. We replace the GOTO or the INITIAL_INVOKE */
		  normal_code[index + 1].jint = args_count;
		  normal_code[index + 2].offset = method_offset;

		  /* No need for synchronization nobody is using normal code at the moment */
		  normal_code[index - 1] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE].
		    code;
		  normal_code[index].invoke_info = invoke_info;
		}
	      /* we are in the normal code array */
	      else if ((pc >= normal_code)
		       || (pc <
			   (normal_code +
			    calling_method_frame_info->code_length)))
		{
		  pc[-3].invoke_info = invoke_info;	/* invoke site count */
		  pc[-4] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE].
		    code;
		}
	      /* we are in inlined code we don't want imbricated inlining */
	      else
		{
		  pc[-4] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKEINTERFACE].
		    code;
		}
	    }
	  else
	    {
	      pc[-4] =
		env->vm->instructions[SVM_INSTRUCTION_INVOKEINTERFACE].code;
	    }

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  frame_info->nb_executions++;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif

	}

#if !defined(NDEBUG)
	_svmf_verbose_methods_enter (env);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
COUNTING_INVOKESTATIC
----------------------------------------------------------------------
*/
	m4svm_instruction_head (COUNTING_INVOKESTATIC, -1);

	/* invoke site counter */
	pc->size_t ++;
	pc++;

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_method_frame_info *frame_info = method->frame_info;
	  _svmt_stack_frame *frame = env->stack.current_frame;
	  _svmt_code *invoke_ptr = pc - 4;
	  jboolean inlining_succeeded = JNI_FALSE;

	  assert (env->stack.current_frame->method_frame_info->
		  profiling_status != SVM_METHOD_PROFILING_STARTED);

	  pc++;			/* skip gc map */

	  /* store return pc before possible profiling or inlining */
	  frame->pc = pc;

/* 	  printf ("COUNTING_INVOKESTATIC\n"); */

	  /* check if we need to start the profiling of the method */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_NOT_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_start_threshold))
	    {
	      if (_svmf_mp_start_profiling (env, method) != JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;

		  /* We will not inline this invoke */
		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKESTATIC].code;

#ifndef NDEBUG
		  if (env->vm->verbose_method_profiling)
		    {
		      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
		      _svmf_print_method_name (env, stderr, method,
					       "PROFILING FAILED: ");
		    }
#endif
/* 		  _svmf_printf(env, stderr, "[%p]\n", pc-5); */
		}
	    }
	  /* check if we need to stop the profiling of the method */
	  else
	    if ((frame_info->profiling_status == SVM_METHOD_PROFILING_STARTED)
		&& (frame_info->nb_executions >=
		    env->vm->mi_info.method_profiling_stop_threshold))
	    {
	      _svmf_mp_stop_profiling (env, method);
	    }
	  
	  /* refresh pc */
	  pc = frame->pc;

	  /* check if we are ready to inline this invoke site */
	  if ((frame_info->profiling_status == SVM_METHOD_PROFILING_FINISHED)
	      && (invoke_ptr[1].size_t >=env->vm->mi_info.
		  invoke_inlining_threshold))
	    {
#if 1
	      if (_svmf_mi_inline_method (env, method, invoke_ptr,
					  SVM_INSTRUCTION_COUNTING_INVOKESTATIC)
		  == JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;
		  
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER		
		  _svmf_goto (env->stack.current_frame->resuming_implementation);
#endif
		  inlining_succeeded = JNI_TRUE;
		}
	      else
		{
		  /* refresh pc */
		  pc = frame->pc;

		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKESTATIC].code;

#if defined (_SABLEVM_METHOD_INLINING_STATS)
		  env->vm->mi_info.total_inlined_invokestatic_failed++;
#endif

		}
#endif
	    }

	  /* normal invokation of the callee method not inlined */
	  if (inlining_succeeded == JNI_FALSE)
	    {
/* 	      if(frame_info->profiling_status == SVM_METHOD_PROFILING_STARTED) */
/* 		{ */
/* 		  _svmf_dump_stack_trace(env); */
/* 		  _svmf_mi_output_code_array (env, */
/* 					      stdout, */
/* 					      frame_info->profiling_code, */
/* 					      frame_info->profiling_code_length, */
/* 					      "\nPROFILING CODE\n"); */
/* 		} */

	      frame_info->nb_executions++;
	      stack_size -= args_count;
	      frame->stack_size = stack_size;

	      /* syncronized? */
	      if (method->synchronized)
		{
		  /* preserve references on the stack across GC */
		  frame->stack_size = stack_size + args_count;

		  if (_svmf_enter_object_monitor
		      (env, *(method->class_info->class_instance)) != JNI_OK)
		    {
		      _svmm_goto_label (exception_handler);
		    }

		  /* refresh pc */
		  pc = env->stack.current_frame->pc;

		  frame->stack_size = stack_size;
		}

	      if (_svmf_ensure_stack_capacity
		  (env,
		   frame_info->java_invoke_frame_size +
		   frame_info->extra_frame_size) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      frame = env->stack.current_frame;
	      stack = (_svmt_stack_value *) (void *)
		(((char *) frame) + _svmv_stack_offset);
	      locals = &stack[stack_size];

	      /* initialize reference locals to null */
	      {
		jint max = frame_info->non_parameter_ref_locals_count;
		jint java_args_count = method->java_args_count;
		jint i;

		for (i = 0; i < max; i++)
		  {
		    locals[java_args_count + i].reference = NULL;
		  }
	      }

	      /* setup callee frame */
	      frame =
		(_svmt_stack_frame *) (void *)
		(((char *) locals) + frame_info->start_offset);
	      stack =
		(_svmt_stack_value *) (void *) (((char *) frame) +
						_svmv_stack_offset);
	      pc = frame_info->code;

	      stack_size = 0;

	      frame->previous_offset =
		((char *) frame) - ((char *) env->stack.current_frame);
	      frame->end_offset = frame_info->end_offset;
	      frame->method_frame_info = frame_info;
	      frame->stack_trace_element = NULL;
	      frame->lock_count = 0;
	      frame->this = *(method->class_info->class_instance);
	      frame->pc = pc;
	      frame->stack_size = stack_size;

	      env->stack.current_frame = frame;

	      /* check */
	      _svmf_periodic_check (env);

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

#ifndef NDEBUG

	      {
		/* check argument types */

		jint arg_count = method->java_args_count;
		const char *pdesc = DREF (method->descriptor, value) + 1;
		jint arg = 0;

		while (arg < arg_count)
		  {
		    jint old_arg = arg;

		    if (locals[old_arg].reference != NULL)
		      {
			_svmt_type_info *t =
			  _svmm_get_type_from_within_descriptor (env, method,
								 pdesc, arg);
			/* in case stack was moved around  */
			frame = env->stack.current_frame;
			locals = (_svmt_stack_value *) (void *)
			  (((char *) frame) -
			   method->frame_info->start_offset);
			stack =
			  (_svmt_stack_value *) (void *) (((char *) frame) +
							  _svmv_stack_offset);

			if (t != NULL)
			  {
			    if (!_svmf_is_assignable_from
				(env, locals[old_arg].reference->vtable->type,
				 t))
			      {
				_svmf_dump_stack_trace (env);
				_svmm_fatal_error
				  ("argument type bug detected");
			      }
			  }
		      }
		    else
		      {
			_svmm_skip_type_within_descriptor (pdesc, arg);
		      }
		  }
		/* refresh pc */
		pc = env->stack.current_frame->pc;
	      }
#endif

#if !defined(NDEBUG)
	      _svmf_verbose_methods_enter (env);
#endif

	    }
	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
COUNTING_INVOKESPECIAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (COUNTING_INVOKESPECIAL, -1);

	/* invoke site counter */
	pc->size_t ++;
	pc++;

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_object_instance *instance =
	    stack[(stack_size - args_count)].reference;
	  _svmt_method_frame_info *frame_info = method->frame_info;
	  _svmt_stack_frame *frame = env->stack.current_frame;

	  jboolean inlining_succeeded = JNI_FALSE;

/* 	  _svmf_mi_print_bytecode_count(env, pc); */

	  assert (env->stack.current_frame->method_frame_info->
		  profiling_status != SVM_METHOD_PROFILING_STARTED);

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  pc++;			/* skip gc map */

	  /* store return pc */
	  frame->pc = pc;

/* 	  _svmf_printf(env, stderr, "frame[%p]\n", frame); */

/* 	  _svmf_print_method_name(env, stderr, method, "calling: "); */

/* 	  if (env->vm->mi_info.inst_count_times >= 14) */
/* 	  _svmf_printf(env, stderr, "[T%d] COUNTING_INVOKESPECIAL: 1\n", env->thread.id); */

	  /* check if we need to start the profiling of the method */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_NOT_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_start_threshold))
	    {
	      if (_svmf_mp_start_profiling (env, method) != JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;

		  /* We will not inline this invoke */
		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKESPECIAL].code;

#ifndef NDEBUG
		  if (env->vm->verbose_method_profiling)
		    {
		      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
		      _svmf_print_method_name (env, stderr, method,
					       "PROFILING FAILED: ");
		    }
#endif
		}
	    }
	  /* check if we need to stop the profiling of the method */
	  else
	    if ((frame_info->profiling_status == SVM_METHOD_PROFILING_STARTED)
		&& (frame_info->nb_executions >=
		    env->vm->mi_info.method_profiling_stop_threshold))
	    {
	      _svmf_mp_stop_profiling (env, method);
	    }
	  
	  /* refresh pc */
	  pc = frame->pc;
	  
/* 	  if (env->vm->mi_info.inst_count_times >= 14) */
/* 	    _svmf_printf(env, stderr, "[T%d] COUNTING_INVOKESPECIAL: 2\n", env->thread.id); */
	  
	  /* check if we are ready to inline this invoke site */
	  if ((frame_info->profiling_status == SVM_METHOD_PROFILING_FINISHED)
	      && (pc[-4].size_t >=env->vm->mi_info.
		  invoke_inlining_threshold))
	    {
#if 1
	      if (_svmf_mi_inline_method (env, method, pc-5,
					  SVM_INSTRUCTION_COUNTING_INVOKESPECIAL) 
		  == JNI_OK)
		{		  
		  /* refresh pc */
		  pc = frame->pc;
		  
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER		
		  _svmf_goto (env->stack.current_frame->resuming_implementation);
#endif
		  inlining_succeeded = JNI_TRUE;
		}
	      else
		{
		  /* refresh pc */
		  pc = frame->pc;

		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKESPECIAL].code;

#if defined (_SABLEVM_METHOD_INLINING_STATS)
		  env->vm->mi_info.total_inlined_invokespecial_failed++;
#endif
		}
#endif
	    }

/* 	  if (env->vm->mi_info.inst_count_times >= 14) */
/* 	  _svmf_printf(env, stderr, "[T%d] COUNTING_INVOKESPECIAL: 3\n", env->thread.id); */

	  /* normal invokation of the callee method not inlined */
	  if (inlining_succeeded == JNI_FALSE)
	    {
	      if (frame_info->profiling_status ==
		  SVM_METHOD_PROFILING_STARTED)
		{
/* 		  _svmf_dump_stack_trace(env); */
/* 		  _svmf_mi_output_code_array (env, */
/* 					      stdout, */
/* 					      frame_info->profiling_code, */
/* 					      frame_info->profiling_code_length, */
/* 					      "\nCOUNTING INVOKESPECIAL: PROFILING CODE\n"); */
		}

	      frame_info->nb_executions++;
	      stack_size -= args_count;
	      frame->stack_size = stack_size;

	      /* syncronized? */
	      if (method->synchronized)
		{
		  /* preserve references on the stack across GC */
		  frame->stack_size = stack_size + args_count;

		  if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		    {
		      _svmm_goto_label (exception_handler);
		    }

		  /* refresh pc */
/* 		  pc = env->stack.current_frame->pc; */

		  frame->stack_size = stack_size;
		  instance = stack[stack_size].reference;
		}

/* 	      if (env->vm->mi_info.inst_count_times >= 14) */
/* 	      _svmf_printf(env, stderr, "[T%d] COUNTING_INVOKESPECIAL: 4\n", env->thread.id); */

	      if (_svmf_ensure_stack_capacity
		  (env,
		   frame_info->java_invoke_frame_size +
		   frame_info->extra_frame_size) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      frame = env->stack.current_frame;
	      stack = (_svmt_stack_value *) (void *)
		(((char *) frame) + _svmv_stack_offset);
	      locals = &stack[stack_size];

	      /* initialize reference locals to null */
	      {
		jint max = frame_info->non_parameter_ref_locals_count;
		jint java_args_count = method->java_args_count;
		jint i;

		for (i = 0; i < max; i++)
		  {
		    locals[java_args_count + i].reference = NULL;
		  }
	      }

	      /* setup callee frame */
	      frame =
		(_svmt_stack_frame *) (void *)
		(((char *) locals) + frame_info->start_offset);
	      stack =
		(_svmt_stack_value *) (void *) (((char *) frame) +
						_svmv_stack_offset);
	      pc = frame_info->code;
	      stack_size = 0;

	      frame->previous_offset =
		((char *) frame) - ((char *) env->stack.current_frame);
	      frame->end_offset = frame_info->end_offset;
	      frame->method_frame_info = frame_info;
	      frame->stack_trace_element = NULL;
	      frame->lock_count = 0;
	      frame->this = instance;
	      frame->pc = pc;
	      frame->stack_size = stack_size;

	      env->stack.current_frame = frame;

	      /* check */
	      _svmf_periodic_check (env);

/* 	      if (env->vm->mi_info.inst_count_times >= 14) */
/* 	      _svmf_printf(env, stderr, "[T%d] COUNTING_INVOKESPECIAL: 5\n", env->thread.id); */

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

#if !defined(NDEBUG)

	      {
		/* check argument types */

		jint arg_count = method->java_args_count;
		const char *pdesc = DREF (method->descriptor, value) + 1;
		jint arg = 1;

		while (arg < arg_count)
		  {
		    jint old_arg = arg;

		    if (locals[old_arg].reference != NULL)
		      {
			_svmt_type_info *t =
			  _svmm_get_type_from_within_descriptor (env, method,
								 pdesc, arg);
			/* in case stack was moved around  */
			frame = env->stack.current_frame;
			locals = (_svmt_stack_value *) (void *)
			  (((char *) frame) - frame_info->start_offset);
			stack = (_svmt_stack_value *) (void *)
			  (((char *) frame) + _svmv_stack_offset);

			if (t != NULL)
			  {
			    if (!_svmf_is_assignable_from
				(env, locals[old_arg].reference->vtable->type,
				 t))
			      {
				_svmf_dump_stack_trace (env);
				_svmm_fatal_error
				  ("argument type bug detected");
			      }
			  }
		      }
		    else
		      {
			_svmm_skip_type_within_descriptor (pdesc, arg);
		      }
		  }

		/* refresh pc */
		pc = env->stack.current_frame->pc;
	      }

#endif
/* 	      if (env->vm->mi_info.inst_count_times >= 14) */
/* 	      _svmf_printf(env, stderr, "[T%d] COUNTING_INVOKESPECIAL: 6\n", env->thread.id); */

#if !defined(NDEBUG)
	      _svmf_verbose_methods_enter (env);
#endif

	    }
	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
COUNTING_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (COUNTING_INVOKEVIRTUAL, -1);

	{
	  _svmt_mi_invoke_info *invoke_info = (pc++)->invoke_info;

	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[stack_size - args_count].reference;

	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame = env->stack.current_frame;

	  _svmt_code *invoke_ptr = pc - 4;
	  jboolean inlining_succeeded = JNI_FALSE;

	  assert (env->stack.current_frame->method_frame_info->
		  profiling_status != SVM_METHOD_PROFILING_STARTED);

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else
	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  pc++;			/* skip gc map */

	  /* store return pc */
	  frame->pc = pc;

/* 	  _svmf_printf (env, stderr, "COUNTING_INVOKEVIRTUAL\n"); */

	  /* check if we need to start the profiling of the method */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_NOT_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_start_threshold))
	    {
	      if (_svmf_mp_start_profiling (env, method) != JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;

		  /* We will not inline this invoke */
		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKEVIRTUAL].
		    code;
		  
#ifndef NDEBUG
		  if (env->vm->verbose_method_profiling)
		    {
		      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
		      _svmf_print_method_name (env, stderr, method,
					       "PROFILING FAILED: ");
		    }
#endif
		}
	    }
	  /* check if we need to stop the profiling of the method */
	  else
	    if ((frame_info->profiling_status ==
		 SVM_METHOD_PROFILING_STARTED)
		&& (frame_info->nb_executions >=
		    env->vm->mi_info.method_profiling_stop_threshold))
	      {
		_svmf_mp_stop_profiling (env, method);
	      }
	  
	  /* refresh pc */
	  pc = frame->pc;
	  
	  /* check if we are ready to inline this invoke site */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_FINISHED)
	      && (invoke_info->count >=
		  env->vm->mi_info.invoke_inlining_threshold))
	    {
#if 1
	      if (_svmf_mi_inline_method (env, method, invoke_ptr,
					  SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL)
		  == JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;
		  
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER		
		  _svmf_goto (env->stack.current_frame->resuming_implementation);
#endif
		  inlining_succeeded = JNI_TRUE;
		}
	      else
		{
		  /* refresh pc */
		  pc = frame->pc;

		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKEVIRTUAL].
		    code;
		  
#if defined (_SABLEVM_METHOD_INLINING_STATS)
		  env->vm->mi_info.total_inlined_invokevirtual_failed++;
#endif
		}
#endif
	    }
	  	  
	  /* normal invokation of the callee method not inlined */
	  if (inlining_succeeded == JNI_FALSE)
	    {
	      invoke_info->count++;
	      frame_info->nb_executions++;

	      /* we keep the last inlinable method for inlining */
	      if (frame_info->inlinable)
		invoke_info->last_method = method;

	      stack_size -= args_count;
	      frame->stack_size = stack_size;

	      /* syncronized? */
	      if (method->synchronized)
		{
		  /* preserve references on the stack across GC */
		  frame->stack_size = stack_size + args_count;

		  if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		    {
		      goto exception_handler;
		    }

		  /* refresh pc */
		  pc = env->stack.current_frame->pc;

		  frame->stack_size = stack_size;
		  instance = stack[stack_size].reference;
		}

	      if (_svmf_ensure_stack_capacity
		  (env,
		   frame_info->java_invoke_frame_size +
		   frame_info->extra_frame_size) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      frame = env->stack.current_frame;
	      stack = (_svmt_stack_value *) (void *)
		(((char *) frame) + _svmv_stack_offset);
	      locals = &stack[stack_size];

	      /* initialize reference locals to null */
	      {
		jint max = frame_info->non_parameter_ref_locals_count;
		jint java_args_count = method->java_args_count;
		jint i;

		for (i = 0; i < max; i++)
		  {
		    locals[java_args_count + i].reference = NULL;
		  }
	      }

	      /* setup callee frame */
	      frame =
		(_svmt_stack_frame *) (void *)
		(((char *) locals) + frame_info->start_offset);
	      stack =
		(_svmt_stack_value *) (void *) (((char *) frame) +
						_svmv_stack_offset);
	      pc = frame_info->code;
	      stack_size = 0;

	      frame->previous_offset =
		((char *) frame) - ((char *) env->stack.current_frame);
	      frame->end_offset = frame_info->end_offset;
	      frame->method_frame_info = frame_info;
	      frame->stack_trace_element = NULL;
	      frame->lock_count = 0;
	      frame->this = instance;
	      frame->pc = pc;
	      frame->stack_size = stack_size;

	      env->stack.current_frame = frame;

	      /* check */
	      _svmf_periodic_check (env);

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;
		
#ifndef NDEBUG

	      {
		/* check argument types */

		jint arg_count = method->java_args_count;
		const char *pdesc = DREF (method->descriptor, value) + 1;
		jint arg = 1;

		while (arg < arg_count)
		  {
		    jint old_arg = arg;

		    if (locals[old_arg].reference != NULL)
		      {
			_svmt_type_info *t =
			  _svmm_get_type_from_within_descriptor (env, method,
								 pdesc, arg);

			/* in case stack was moved around  */
			frame = env->stack.current_frame;
			locals = (_svmt_stack_value *) (void *)
			  (((char *) frame) -
			   method->frame_info->start_offset);
			stack =
			  (_svmt_stack_value *) (void *) (((char *) frame) +
							  _svmv_stack_offset);

			if (t != NULL)
			  {
			    if (!_svmf_is_assignable_from
				(env, locals[old_arg].reference->vtable->type,
				 t))
			      {
				_svmf_dump_stack_trace (env);
				_svmm_fatal_error
				  ("argument type bug detected");
			      }
			  }
		      }
		    else
		      {
			_svmm_skip_type_within_descriptor (pdesc, arg);
		      }
		  }
		/* refresh pc */
		pc = env->stack.current_frame->pc;
	      }

#endif
	    }

#if !defined(NDEBUG)
	  _svmf_verbose_methods_enter (env);
#endif

	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
COUNTING_INVOKEINTERFACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (COUNTING_INVOKEINTERFACE, -1);

	{
	  _svmt_mi_invoke_info *invoke_info = (pc++)->invoke_info;

	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[(stack_size - args_count)].reference;

	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame = env->stack.current_frame;

	  _svmt_code *invoke_ptr = pc - 4;
	  jboolean inlining_succeeded = JNI_FALSE;

	  assert (env->stack.current_frame->method_frame_info->
		  profiling_status != SVM_METHOD_PROFILING_STARTED);

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  pc++;			/* skip gc map */

	  /* store return pc */
	  frame->pc = pc;

/* 	  _svmf_printf (env, stderr, "COUNTING_INVOKEINTERFACE\n"); */

	  /* check if we need to start the profiling of the method */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_NOT_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_start_threshold))
	    {
	      if (_svmf_mp_start_profiling (env, method) != JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;

		  /* We will not inline this invoke */
		  pc[-5] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_INVOKEINTERFACE].code;
		  
#ifndef NDEBUG
		  if (env->vm->verbose_method_profiling)
		    {
		      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
		      _svmf_print_method_name (env, stderr, method,
					       "PROFILING FAILED: ");
		    }
#endif
		}
	    }
	  /* check if we need to stop the profiling of the method */
	  else
	    if ((frame_info->profiling_status ==
		 SVM_METHOD_PROFILING_STARTED)
		&& (frame_info->nb_executions >=
		    env->vm->mi_info.method_profiling_stop_threshold))
	      {
		_svmf_mp_stop_profiling (env, method);
	      }

	  /* refresh pc */
	  pc = frame->pc;

	  /* check if we are ready to inline this invoke site */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_FINISHED)
	      && (invoke_info->count >=
		  env->vm->mi_info.invoke_inlining_threshold))
	    {
#if 1
	      if (_svmf_mi_inline_method (env, method, invoke_ptr,
					  SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE)
		  == JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;
		  
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER		
		  _svmf_goto (env->stack.current_frame->resuming_implementation);
#endif
		  inlining_succeeded = JNI_TRUE;
		}
	      else
		{
		  /* refresh pc */
		  pc = frame->pc;

		  pc[-5] =
		    env->vm->
		    instructions[SVM_INSTRUCTION_INVOKEINTERFACE].code;
		  
#if defined (_SABLEVM_METHOD_INLINING_STATS)
		  env->vm->mi_info.total_inlined_invokeinterface_failed++;
#endif
		}
#endif
	    }

	  /* normal invokation of the callee method not inlined */
	  if (inlining_succeeded == JNI_FALSE)
	    {
	      invoke_info->count++;
	      frame_info->nb_executions++;

	      /* we keep the last inlinable method for inlining */
	      if (frame_info->inlinable)
		invoke_info->last_method = method;
	      
	      stack_size -= args_count;
	      frame->stack_size = stack_size;

	      /* syncronized? */
	      if (method->synchronized)
		{
		  /* preserve references on the stack across GC */
		  frame->stack_size = stack_size + args_count;
		  
		  if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		    {
		      _svmm_goto_label (exception_handler);
		    }

		  /* refresh pc */
		  pc = env->stack.current_frame->pc;
		  
		  frame->stack_size = stack_size;
		  instance = stack[stack_size].reference;
		}

	      if (_svmf_ensure_stack_capacity
		  (env,
		   frame_info->java_invoke_frame_size +
		   frame_info->extra_frame_size) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}
	      
	      frame = env->stack.current_frame;
	      stack = (_svmt_stack_value *) (void *)
		(((char *) frame) + _svmv_stack_offset);
	      locals = &stack[stack_size];
	      
	      /* initialize reference locals to null */
	      {
		jint max = frame_info->non_parameter_ref_locals_count;
		jint java_args_count = method->java_args_count;
		jint i;
		
		for (i = 0; i < max; i++)
		  {
		    locals[java_args_count + i].reference = NULL;
		  }
	      }

	      /* setup callee frame */
	      frame =
		(_svmt_stack_frame *) (void *)
		(((char *) locals) + frame_info->start_offset);
	      stack =
		(_svmt_stack_value *) (void *) (((char *) frame) +
						_svmv_stack_offset);
	      pc = frame_info->code;
	      stack_size = 0;
	      
	      frame->previous_offset =
		((char *) frame) - ((char *) env->stack.current_frame);
	      frame->end_offset = frame_info->end_offset;
	      frame->method_frame_info = frame_info;
	      frame->stack_trace_element = NULL;
	      frame->lock_count = 0;
	      frame->this = instance;
	      frame->pc = pc;
	      frame->stack_size = stack_size;
	      
	      env->stack.current_frame = frame;
	      
	      /* check */
	      _svmf_periodic_check (env);

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;
	      
#ifndef NDEBUG
	      
	      {
		/* check argument types */

		jint arg_count = method->java_args_count;
		const char *pdesc = DREF (method->descriptor, value) + 1;
		jint arg = 1;

		while (arg < arg_count)
		  {
		    jint old_arg = arg;

		    if (locals[old_arg].reference != NULL)
		      {
			_svmt_type_info *t =
			  _svmm_get_type_from_within_descriptor (env, method,
								 pdesc, arg);

			/* in case stack was moved around  */
			frame = env->stack.current_frame;
			locals = (_svmt_stack_value *) (void *)
			  (((char *) frame) - frame_info->start_offset);
			stack = (_svmt_stack_value *) (void *)
			  (((char *) frame) + _svmv_stack_offset);

			if (t != NULL)
			  {
			    if (!_svmf_is_assignable_from
				(env, locals[old_arg].reference->vtable->type,
				 t))
			      {
				_svmf_dump_stack_trace (env);
				_svmm_fatal_error
				  ("argument type bug detected");
			      }
			  }
		      }
		    else
		      {
			_svmm_skip_type_within_descriptor (pdesc, arg);
		      }
		  }
		/* refresh pc */
		pc = env->stack.current_frame->pc;
	      }

#endif
	    }

#if !defined(NDEBUG)
	  _svmf_verbose_methods_enter (env);
#endif
	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_INVOKESTATIC
----------------------------------------------------------------------
*/
	m4svm_instruction_head (PROFILING_INVOKESTATIC, -1);

	/* invoke site counter */
	*(pc->addr)++;
	pc++;

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_method_frame_info *frame_info = method->frame_info;
	  _svmt_stack_frame *frame = env->stack.current_frame;

	  assert (env->stack.current_frame->method_frame_info->
		  profiling_status == SVM_METHOD_PROFILING_STARTED);

	  pc++;			/* skip gc map */

	  /* store return pc before possible profiling */
	  frame->pc = pc;

	  /* check if we need to start the profiling of the method */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_NOT_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_start_threshold))
	    {
	      if (_svmf_mp_start_profiling (env, method) != JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;

		  /* We will not inline this invoke */
		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKESTATIC].code;

#ifndef NDEBUG
		  if (env->vm->verbose_method_profiling)
		    {
		      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
		      _svmf_print_method_name (env, stderr, method,
					       "PROFILING FAILED: ");
		    }
#endif
/* 		  _svmf_printf(env, stderr, "[%p]\n", pc-5); */
		}
	    }
	  /* check if we need to stop the profiling of the method */
	  else
	    if ((frame_info->profiling_status == SVM_METHOD_PROFILING_STARTED)
		&& (frame_info->nb_executions >=
		    env->vm->mi_info.method_profiling_stop_threshold))
	    {
	      _svmf_mp_stop_profiling (env, method);
	    }

	  frame_info->nb_executions++;
	  stack_size -= args_count;

	  /* store stack size */
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor
		  (env, *(method->class_info->class_instance)) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

	      frame->stack_size = stack_size;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;

	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = *(method->class_info->class_instance);
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 0;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);
		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }
#endif

#if !defined(NDEBUG)
	  _svmf_verbose_methods_enter (env);
#endif

	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_INVOKESPECIAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_INVOKESPECIAL, -1);

	/* invoke site counter */
	*(pc->addr)++;
	pc++;

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

/* 	  _svmf_printf_ptr(env, stderr, "PROFILING_INVOKESPECIAL\n"); */
	  
	  assert (env->stack.current_frame->method_frame_info->
		  profiling_status == SVM_METHOD_PROFILING_STARTED);

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  frame_info = method->frame_info;
	  frame_info->nb_executions++;

	  /* check if we need to start the profiling of the method */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_NOT_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_start_threshold))
	    {
	      if (_svmf_mp_start_profiling (env, method) != JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;

		  /* We will not inline this invoke */
		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKESPECIAL].code;

#ifndef NDEBUG
		  if (env->vm->verbose_method_profiling)
		    {
		      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
		      _svmf_print_method_name (env, stderr, method,
					       "PROFILING FAILED: ");
		    }
#endif
		}
	    }
	  /* check if we need to stop the profiling of the method */
	  else
	    if ((frame_info->profiling_status == SVM_METHOD_PROFILING_STARTED)
		&& (frame_info->nb_executions >=
		    env->vm->mi_info.method_profiling_stop_threshold))
	    {
	      _svmf_mp_stop_profiling (env, method);
	    }

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;
	    
#if !defined(NDEBUG)

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);
		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif

#if !defined(NDEBUG)
	  _svmf_verbose_methods_enter (env);
#endif
	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_INVOKEVIRTUAL, -1);

	{
	  _svmt_mi_invoke_info *invoke_info = (pc++)->invoke_info;
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[stack_size -= args_count].reference;
	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  assert (env->stack.current_frame->method_frame_info->
		  profiling_status == SVM_METHOD_PROFILING_STARTED);

	  invoke_info->count++;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else
	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  frame_info = method->frame_info;
	  frame_info->nb_executions++;
	  invoke_info->last_method = method;

	  /* check if we need to start the profiling of the method */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_NOT_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_start_threshold))
	    {
	      if (_svmf_mp_start_profiling (env, method) != JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;

		  /* We will not inline this invoke */
		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKEVIRTUAL].code;

#ifndef NDEBUG
		  if (env->vm->verbose_method_profiling)
		    {
		      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
		      _svmf_print_method_name (env, stderr, method,
					       "PROFILING FAILED: ");
		    }
#endif
/* 		  _svmf_printf(env, stderr, "[%p]\n", pc-5); */
		}
	    }
	  /* check if we need to stop the profiling of the method */
	  else
	    if ((frame_info->profiling_status == SVM_METHOD_PROFILING_STARTED)
		&& (frame_info->nb_executions >=
		    env->vm->mi_info.method_profiling_stop_threshold))
	    {
	      _svmf_mp_stop_profiling (env, method);
	    }

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  goto exception_handler;
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif

#if !defined(NDEBUG)
	  _svmf_verbose_methods_enter (env);
#endif

	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_INVOKEINTERFACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_INVOKEINTERFACE, -1);

	{
	  _svmt_mi_invoke_info *invoke_info = (pc++)->invoke_info;
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  assert (env->stack.current_frame->method_frame_info->
		  profiling_status == SVM_METHOD_PROFILING_STARTED);

	  invoke_info->count++;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  frame_info = method->frame_info;
	  frame_info->nb_executions++;
	  invoke_info->last_method = method;

	  /* check if we need to start the profiling of the method */
	  if ((frame_info->profiling_status ==
	       SVM_METHOD_PROFILING_NOT_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_start_threshold))
	    {
	      if (_svmf_mp_start_profiling (env, method) != JNI_OK)
		{
		  /* refresh pc */
		  pc = frame->pc;

		  /* We will not inline this invoke */
		  pc[-5] =
		    env->vm->instructions[SVM_INSTRUCTION_INVOKEINTERFACE].code;

#ifndef NDEBUG
		  if (env->vm->verbose_method_profiling)
		    {
		      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
		      _svmf_print_method_name (env, stderr, method,
					       "PROFILING FAILED: ");
		    }
#endif
/* 		  _svmf_printf(env, stderr, "[%p]\n", pc-5); */
		}
	    }
	  else /* check if we need to stop the profiling of the method */
	  if ((frame_info->profiling_status == SVM_METHOD_PROFILING_STARTED)
	      && (frame_info->nb_executions >=
		  env->vm->mi_info.method_profiling_stop_threshold))
	    {
	      _svmf_mp_stop_profiling (env, method);
	    }

/* 	  if (frame_info->nb_executions >=  env->vm->mi_info.method_profiling_stop_threshold) */
/* 	    { */
/* 	      _svmf_mp_stop_profiling (env, method); */
/* 	    } */

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env,
	       frame_info->java_invoke_frame_size +
	       frame_info->extra_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif

	}

#if !defined(NDEBUG)
	_svmf_verbose_methods_enter (env);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_INVOKESTATIC
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_INVOKESTATIC, -1);

	{

	  jint inlined_code_length = (pc++)->jint;
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;

	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  frame_info = method->frame_info;
	  stack_size -= args_count;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	  assert (_svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC));
#endif

/* 	  _svmf_printf(env, stderr, */
/* 		       "[%d]INLINED_INVOKESTATIC IN inlined method [%s.%s] called from [%s.%s]\n", */
/* 		       env->thread.id, */
/* 		       method->class_info->name, */
/* 		       DREF (method->name, value), */
/* 		       env->stack.current_frame->method_frame_info->method->class_info->name, */
/* 		       DREF (env->stack.current_frame->method_frame_info->method->name, value)); */

	  /* skip stack_gc_map */
	  pc++;

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;

	  /* inlined-threaded: must be offset to the next_seq */
	  frame->pc = pc + inlined_code_length;
	  frame->stack_size = stack_size;

/* 	  _svmf_printf_ptr(env, stderr, "(STATIC): return pc = %p\n", frame->pc); */

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;	

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      if (_svmf_enter_object_monitor_ptr
		  (env, *(method->class_info->class_instance)) != JNI_OK)
#else
	      if (_svmf_enter_object_monitor
		  (env, *(method->class_info->class_instance)) != JNI_OK)
#endif
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc - inlined_code_length;

	      frame->stack_size = stack_size;
	    }

	  /* already done during inlining step or at creation of the calling stack_frame */
#if 0
	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }
#endif
	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);


	  /* No need to adjust pc method is inlined */
	  /* old version: pc = frame_info->code; */

	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame_info->execution_is_in_caller_inlined_code = JNI_TRUE;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = *(method->class_info->class_instance);
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
#if defined(_SABLEVM_METHOD_INLINING) && defined(_SABLEVM_INLINED_THREADED_INTERPRETER)
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#if !defined (NDEBUG) && !defined(_SABLEVM_INLINED_THREADED_INTERPRETER)

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 0;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }	   
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }
#endif

#ifdef _SABLEVM_METHOD_INLINING_STATS
	  env->vm->mi_info.total_inlined_invokestatic_used++;
#endif

/* 	  _svmf_printf(env, stderr, */
/* 		       "[%d]INLINED_INVOKESTATIC OUT inlined method [%s.%s] pc[%p]\n", */
/* 		       env->thread.id, */
/* 		       method->class_info->name, */
/* 		       DREF (method->name, value), */
/* 		       pc); */

	}

#ifndef NDEBUG

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_verbose_methods_enter_ptr (env);
#else
	_svmf_verbose_methods_enter (env);
#endif

#endif

/* 	env->vm->mi_info.show_instructions = JNI_TRUE; */

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_INVOKESPECIAL
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_INVOKESPECIAL, -1);

/* 	_svmf_printf_ptr(env, stderr,"\nINLINED_INVOKESPECIAL: IN\n"); */

	{
	  jint inlined_code_length = (pc++)->jint;
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;

	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

/* 	  _svmf_printf(env, stdout, */
/* 		       "[%d]INLINED_INVOKESPECIAL IN inlined method [%s.%s] in [%s.%s]\n", */
/* 		       env->thread.id, */
/* 		       method->class_info->name, */
/* 		       DREF (method->name, value), */
/* 		       env->stack.current_frame->method_frame_info->method->class_info->name, */
/* 		       DREF (env->stack.current_frame->method_frame_info->method->name, value)); */

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));
#endif

	  frame_info = method->frame_info;

	  /* gc map to skip */
	  pc++;

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;

	  /* inlined-threaded: must be offset to the next_seq */
	  frame->pc = pc + inlined_code_length;
	  frame->stack_size = stack_size;

/* 	  _svmf_printf_ptr(env, stderr, "INLINED_INVOKESPECIAL: return pc = %p\n", frame->pc); */

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;
	      
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      if (_svmf_enter_object_monitor_ptr (env, instance) != JNI_OK)
#else
		
	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
#endif
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc  - inlined_code_length;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  /* already done during inlining step or at creation of the calling stack_frame */
#if 0
	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }
#endif
	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);

	  /* No need to adjust pc method is inlined */

	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame_info->execution_is_in_caller_inlined_code = JNI_TRUE;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  _svmf_periodic_check_ptr (env);
#else
	  _svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#if !defined (NDEBUG) && !defined(_SABLEVM_INLINED_THREADED_INTERPRETER)

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif


#if defined (_SABLEVM_METHOD_INLINING_STATS)
	  env->vm->mi_info.total_inlined_invokespecial_used++;
#endif

/* 	  _svmf_printf(env, stdout, */
/* 		       "[%d]INLINED_INVOKESPECIAL OUT inlined method [%s.%s] in [%s.%s]\n", */
/* 		       env->thread.id, */
/* 		       method->class_info->name, */
/* 		       DREF (method->name, value), */
/* 		       env->stack.current_frame->method_frame_info->method->class_info->name, */
/* 		       DREF (env->stack.current_frame->method_frame_info->method->name, value)); */

	}

#if !defined(NDEBUG)

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_verbose_methods_enter_ptr (env);
#else
	_svmf_verbose_methods_enter (env);
#endif

#endif

/* 	env->vm->mi_info.show_instructions = JNI_TRUE; */

/* 	_svmf_printf_ptr(env, stderr,"\nINLINED_INVOKESPECIAL: OUT\n"); */

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_INVOKEVRTUAL
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_INVOKEVIRTUAL, -1);

/*         _svmf_printf_ptr(env, stderr, "INLINED_INVOKEVIRTUAL: 1\n", pc); */

	{
	  jint inlined_code_length = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;

	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  _svmt_method_info *method_check;
	  jboolean wrong_method_inlined = JNI_FALSE;
	  
/* 	  _svmf_printf_ptr(env, stderr, "INLINED_INVOKEVIRTUAL: 2\n", pc); */

/* 	  _svmf_printf_ptr (env, stderr, */
/* 			"[%d]INLINED_INVOKEVIRTUAL IN inlined method [%s.%s] in [%s.%s]\n", */
/* 			env->thread.id, */
/* 			method->class_info->name, */
/* 			DREF (method->name, value), */
/* 			env->stack.current_frame->method_frame_info->method-> */
/* 			class_info->name, */
/* 			DREF (env->stack.current_frame->method_frame_info-> */
/* 			      method->name, value)); */
/* 	  _svmf_mi_print_bytecode_count(env, pc); */

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS


#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

/* 	  _svmf_printf_ptr(env, stderr, "INLINED_INVOKEVIRTUAL: 3\n", pc); */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method_check =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

/* 	  _svmf_printf_ptr(env, stderr, "INLINED_INVOKEVIRTUAL: 4\n", pc); */

	  /* check if the inlined method is the right one */
	  if (method_check != method)
	    {
	      wrong_method_inlined = JNI_TRUE;
	      method = method_check;
	    }

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));
#endif

/* 	  _svmf_printf_ptr(env, stderr, "INLINED_INVOKEVIRTUAL: 5\n", pc); */

	  frame_info = method->frame_info;

	  /* gc map to skip */
	  pc++;

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc + inlined_code_length;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      if (_svmf_enter_object_monitor_ptr (env, instance) != JNI_OK)
#else
	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
#endif
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc - inlined_code_length;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  /* already done during inlining step or at creation of the calling stack_frame */
#if 0
	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }
#endif

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);


	  if (wrong_method_inlined)
	    {
	      pc = frame_info->code;
	    }
	  else
	    {
	      /* No need to adjust pc method is inlined */
	    }

	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame_info->execution_is_in_caller_inlined_code = JNI_TRUE;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  _svmf_periodic_check_ptr (env);
#else
	  _svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#if !defined (NDEBUG) && !defined(_SABLEVM_INLINED_THREADED_INTERPRETER)

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif


#if defined (_SABLEVM_METHOD_INLINING_STATS)
	  env->vm->mi_info.total_inlined_invokevirtual_used++;
#endif

/* 	  _svmf_printf_ptr(env, stderr, */
/* 		       "[%d]INLINED_INVOKEVIRTUAL OUT inlined method [%s.%s] in [%s.%s]\n", */
/* 		       env->thread.id, */
/* 		       method->class_info->name, */
/* 		       DREF (method->name, value), */
/* 		       env->stack.current_frame->method_frame_info->method->class_info->name, */
/* 		       DREF (env->stack.current_frame->method_frame_info->method->name, value)); */

#if !defined(NDEBUG)

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_verbose_methods_enter_ptr (env);
#else
	_svmf_verbose_methods_enter (env);
#endif

#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  if (wrong_method_inlined)
	    {
	      /* inlined method is not the right one */
	      /* jump to correct method */
	      _svmf_goto ((pc++)->implementation);
	    }
#endif

/* 	env->vm->show_instructions = JNI_TRUE; */

	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_INVOKEINTERFACE
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_INVOKEINTERFACE, -1);
	{
	  jint inlined_code_length = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;

	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  _svmt_method_info *method_check;
	  jboolean wrong_method_inlined = JNI_FALSE;

/* 	  _svmf_printf_ptr(env, stdout, */
/* 		       "[%d]INLINED_INVOKEINTERFACE IN inlined method [%s.%s] in [%s.%s]\n", */
/* 		       env->thread.id, */
/* 		       method->class_info->name, */
/* 		       DREF (method->name, value), */
/* 		       env->stack.current_frame->method_frame_info->method->class_info->name, */
/* 		       DREF (env->stack.current_frame->method_frame_info->method->name, value)); */

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method_check =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

	  /* check if the inlined method is the right one */
	  if (method_check != method)
	    {
	      wrong_method_inlined = JNI_TRUE;
	      method = method_check;
	    }

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));
#endif

	  frame_info = method->frame_info;

	  /* gc map to skip */
	  pc++;

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc + inlined_code_length;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      if (_svmf_enter_object_monitor_ptr (env, instance) != JNI_OK)
#else
	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
#endif
		{
		  _svmm_goto_label (exception_handler);
		}

	      /* refresh pc */
	      pc = env->stack.current_frame->pc  - inlined_code_length;

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  /* already done during inlining step or at creation of the calling stack_frame */

/* 	  if (_svmf_ensure_stack_capacity */
/* 	      (env, frame_info->java_invoke_frame_size) != JNI_OK) */
/* 	    { */
/* 	      _svmm_goto_label (exception_handler); */
/* 	    } */

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);


	  if (wrong_method_inlined)
	    {
	      pc = frame_info->code;
	    }
	  else
	    {
	      /* No need to adjust pc method is inlined */
	    }

	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame_info->execution_is_in_caller_inlined_code = JNI_TRUE;
	  frame->method_frame_info = frame_info;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  _svmf_periodic_check_ptr (env);
#else
	  _svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

#if !defined (NDEBUG) && !defined(_SABLEVM_INLINED_THREADED_INTERPRETER)
	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	    /* refresh pc */
	    pc = env->stack.current_frame->pc;
	  }

#endif

#if defined (_SABLEVM_METHOD_INLINING_STATS)
	  env->vm->mi_info.total_inlined_invokeinterface_used++;
#endif

/* 	  _svmf_printf_ptr(env, stdout, */
/* 		       "[%d]INLINED_INVOKEINTERFACE OUT inlined method [%s.%s] in [%s.%s]\n", */
/* 		       env->thread.id, */
/* 		       method->class_info->name, */
/* 		       DREF (method->name, value), */
/* 		       env->stack.current_frame->method_frame_info->method->class_info->name, */
/* 		       DREF (env->stack.current_frame->method_frame_info->method->name, value)); */

#if !defined(NDEBUG)

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_verbose_methods_enter_ptr (env);
#else
	_svmf_verbose_methods_enter (env);
#endif

#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  if (wrong_method_inlined)
	    {
	      /* inlined method is not the right one */
	      /* jump to correct method */
	      _svmf_goto ((pc++)->implementation);
	    }
#endif

/* 	env->vm->show_instructions = JNI_TRUE; */

	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_<X>RETURN
----------------------------------------------------------------------
*/
	/* m4_define([:m4svm_instruction_inlined_xreturn:], [: */
	m4svm_instruction_head (INLINED_$1RETURN, -1);

	/* skip stack_gc_map */
	pc++;

	{

/* 	  env->vm->show_instructions = JNI_FALSE; */

	  /* structured locking */
	  if (env->stack.current_frame->lock_count != 0
	      && env->vm->enforce_structured_locking)
	    {
	      /* pop stack frame */
	      _svmt_stack_frame *frame = env->stack.current_frame;
	      env->stack.current_frame = (_svmt_stack_frame *) (void *)
		(((char *) frame) - frame->previous_offset);

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      _svmf_error_IllegalMonitorStateException_ptr (env);
#else
	      _svmf_error_IllegalMonitorStateException (env);
#endif
	      _svmm_goto_label (exception_handler);
	    }
	  
#ifndef NDEBUG

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  _svmf_verbose_methods_exit_ptr (env);
#else
	  _svmf_verbose_methods_exit (env);
#endif

#endif
	  {
	    _svmt_stack_frame *frame;
	    _svmt_method_info *caller_method;
	    _svmt_method_info *callee_method;
	    _svmt_object_instance *this;

	    frame = env->stack.current_frame;
	    callee_method = frame->method_frame_info->method;
	    this = frame->this;

	    frame->method_frame_info->execution_is_in_caller_inlined_code =
	      JNI_FALSE;

#if !defined (NDEBUG) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (stack[stack_size - 1].reference != NULL &&
		(DREF (callee_method->descriptor, value)[1] == 'L'
		 || DREF (callee_method->descriptor, value)[1] == '['))
	      {
		/* check return value type */

		const char *pdesc =
		  DREF (callee_method->descriptor, value) + 1;
		jint arg = 0;
		_svmt_type_info *t;

		while (*pdesc++ != /* to keep m4 happy: '(' */ ')');

		/* save state */
		env->stack.current_frame->pc = pc;
		env->stack.current_frame->stack_size = 0;	/* artificially empty stack */

		{
		  jobject value;

		  if (_svmm_new_native_local (env, value) != JNI_OK)
		    {
		      _svmm_fatal_error
			("unsupported failure while debugging");
		    }

		  *value = stack[stack_size - 1].reference;

		  t =
		    _svmm_get_type_from_within_descriptor (env, callee_method,
							   pdesc, arg);

		  env->stack.current_frame->stack_size = stack_size;	/* recover stack */

		  /* in case stack was moved around  */
		  frame = env->stack.current_frame;
		  locals = (_svmt_stack_value *) (void *)
		    (((char *) frame) -
		     callee_method->frame_info->start_offset);
		  stack =
		    (_svmt_stack_value *) (void *) (((char *) frame) +
						    _svmv_stack_offset);
		  this = frame->this;

		  /* refresh pc */
		  pc = env->stack.current_frame->pc;

		  stack[stack_size - 1].reference = *value;

		  _svmm_free_native_local (env, value);
		}

		if (t != NULL)
		  {
		    if (env->vm->verbose_instructions == JNI_TRUE)
		      {
			_svmf_printf (env, stderr,
				      "** T%d: t = %s\n", env->thread.id,
				      t->name);

			fflush (stderr);
		      }

		    if (!_svmf_is_assignable_from
			(env, stack[stack_size - 1].reference->vtable->type,
			 t))
		      {
			_svmf_dump_stack_trace (env);
			_svmm_fatal_error ("argument type bug detected");
		      }
		  }
	      }

#endif
	    frame =
	      (_svmt_stack_frame *) (void *) (((char *) frame) -
					      frame->previous_offset);
	    env->stack.current_frame = frame;
	    caller_method = frame->method_frame_info->method;
	    m4svm_inlined_$1return_assign;

	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - caller_method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    stack_size = frame->stack_size + m4svm_inlined_$1return_size;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	    assert (pc == frame->pc);
#endif

/* 	    _svmf_printf_ptr(env, stderr, "frame[%p] stack[%p] locals[%p] stack_size[%d]\n",  */
/* 			     frame, stack, locals, stack_size); */
/* 	    _svmf_printf_ptr(env, stderr, "returning to  pc = %p\n", pc); */

	    /* Adjust pc to resume execution of the caller method */
	    /* pc = frame->pc; */

	    /* is method synchronized? */
	    if (callee_method->synchronized)
	      {
		/* release monitor */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		if (_svmf_exit_object_monitor_ptr (env, this) != JNI_OK)
#else
		if (_svmf_exit_object_monitor (env, this) != JNI_OK)
#endif
		  {
		    _svmm_goto_label (exception_handler);
		  }
	      }

/* 	    env->vm->show_instructions = JNI_FALSE; */

/* 	    _svmf_printf_ptr(env, stdout, "OUT INLINED_<X>RETURN\n"); */

/* 	    _svmf_printf (env, stdout, */
/* 			  "[%d]INLINED_<X>RETURN OUT inlined method [%s.%s] called from [%s.%s]\n", */
/* 			  env->thread.id, */
/* 			  callee_method->class_info->name, */
/* 			  DREF (callee_method->name, value), */
/* 			  caller_method->class_info->name, */
/* 			  DREF (caller_method->name, value)); */
	  }
	}
	m4svm_instruction_tail ();
	/* :]) */

/*
m4_define([:m4svm_inlined_return_assign:],[:[:m4_:]dnl:])m4_dnl
m4_define([:m4svm_inlined_Ireturn_assign:],[:locals[0].jint = stack[stack_size - 1].jint:])m4_dnl
m4_define([:m4svm_inlined_Freturn_assign:],[:locals[0].jfloat = stack[stack_size - 1].jfloat:])m4_dnl
m4_define([:m4svm_inlined_Areturn_assign:],[:locals[0].reference = stack[stack_size - 1].reference:])m4_dnl
m4_define([:m4svm_inlined_Lreturn_assign:],[:*((jlong *) (void *) &locals[0]) = *((jlong *) (void *) &stack[stack_size - 2]):])m4_dnl
m4_define([:m4svm_inlined_Dreturn_assign:],[:*((jdouble *) (void *) &locals[0]) = *((jdouble *) (void *) &stack[stack_size - 2]):])m4_dnl
m4_define([:m4svm_inlined_return_size:],[:0:])m4_dnl
m4_define([:m4svm_inlined_Ireturn_size:],[:1:])m4_dnl
m4_define([:m4svm_inlined_Freturn_size:],[:1:])m4_dnl
m4_define([:m4svm_inlined_Areturn_size:],[:1:])m4_dnl
m4_define([:m4svm_inlined_Lreturn_size:],[:2:])m4_dnl
m4_define([:m4svm_inlined_Dreturn_size:],[:2:])m4_dnl
m4svm_instruction_inlined_xreturn(I)
m4svm_instruction_inlined_xreturn(L)
m4svm_instruction_inlined_xreturn(F)
m4svm_instruction_inlined_xreturn(D)
m4svm_instruction_inlined_xreturn(A)
m4svm_instruction_inlined_xreturn()
m4_undefine([:m4svm_instruction_inlined_xreturn:])
m4_undefine([:m4svm_inlined_return_assign:])
m4_undefine([:m4svm_inlined_Ireturn_assign:])
m4_undefine([:m4svm_inlined_Freturn_assign:])
m4_undefine([:m4svm_inlined_Areturn_assign:])
m4_undefine([:m4svm_inlined_Lreturn_assign:])
m4_undefine([:m4svm_inlined_Dreturn_assign:])
m4_undefine([:m4svm_inlined_return_size:])
m4_undefine([:m4svm_inlined_Ireturn_size:])
m4_undefine([:m4svm_inlined_Freturn_size:])
m4_undefine([:m4svm_inlined_Areturn_size:])
m4_undefine([:m4svm_inlined_Lreturn_size:])
m4_undefine([:m4svm_inlined_Dreturn_size:])
*/

/*
----------------------------------------------------------------------
INLINED_IF<X>(_CHECK)
----------------------------------------------------------------------
*/
	/* m4_define([:m4svm_instruction_special_if_x:], [: */
	m4svm_instruction_head (INLINED_IF$1, -1);

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value = stack[--stack_size].jint;

	  if (value $2 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_special_if_x_check:], [: */
	m4svm_instruction_head (INLINED_IF$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

          /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value = stack[--stack_size].jint;

	  if (value $2 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_special_if_icmpx:], [: */
	m4svm_instruction_head (INLINED_IF_ICMP$1, -1);

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 $2 value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_special_if_icmpx_check:], [: */
	m4svm_instruction_head (INLINED_IF_ICMP$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 $2 value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_special_if_acmpx:], [: */
	m4svm_instruction_head (INLINED_IF_ACMP$1, -1);

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 $2 ref2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_special_if_acmpx_check:], [: */
	m4svm_instruction_head (INLINED_IF_ACMP$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 $2 ref2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_special_if_x(EQ, ==)
	 * m4svm_instruction_special_if_x(NE, !=)
	 * m4svm_instruction_special_if_x(LT, <)
	 * m4svm_instruction_special_if_x(LE, <=)
	 * m4svm_instruction_special_if_x(GT, >)
	 * m4svm_instruction_special_if_x(GE, >=)
	 * m4svm_instruction_special_if_icmpx(EQ, ==)
	 * m4svm_instruction_special_if_icmpx(NE, !=)
	 * m4svm_instruction_special_if_icmpx(LT, <)
	 * m4svm_instruction_special_if_icmpx(LE, <=)
	 * m4svm_instruction_special_if_icmpx(GT, >)
	 * m4svm_instruction_special_if_icmpx(GE, >=)
	 * m4svm_instruction_special_if_acmpx(EQ, ==)
	 * m4svm_instruction_special_if_acmpx(NE, !=) */

	/* m4svm_instruction_special_if_x_check(EQ, ==)
	 * m4svm_instruction_special_if_x_check(NE, !=)
	 * m4svm_instruction_special_if_x_check(LT, <)
	 * m4svm_instruction_special_if_x_check(LE, <=)
	 * m4svm_instruction_special_if_x_check(GT, >)
	 * m4svm_instruction_special_if_x_check(GE, >=)
	 * m4svm_instruction_special_if_icmpx_check(EQ, ==)
	 * m4svm_instruction_special_if_icmpx_check(NE, !=)
	 * m4svm_instruction_special_if_icmpx_check(LT, <)
	 * m4svm_instruction_special_if_icmpx_check(LE, <=)
	 * m4svm_instruction_special_if_icmpx_check(GT, >)
	 * m4svm_instruction_special_if_icmpx_check(GE, >=)
	 * m4svm_instruction_special_if_acmpx_check(EQ, ==)
	 * m4svm_instruction_special_if_acmpx_check(NE, !=) */

	/* m4_undefine([:m4svm_instruction_special_if_x:])
	 * m4_undefine([:m4svm_instruction_special_if_icmpx:])
	 * m4_undefine([:m4svm_instruction_special_if_acmpx:]) */

	/* m4_undefine([:m4svm_instruction_special_if_x_check:])
	 * m4_undefine([:m4svm_instruction_special_if_icmpx_check:])
	 * m4_undefine([:m4svm_instruction_special_if_acmpx_check:]) */

/*
----------------------------------------------------------------------
INLINED_IFNULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_IFNULL, -1);

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_IFNULL_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_IFNULL_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_IFNONNULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_IFNONNULL, -1);

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_IFNONNULL_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_IFNONNULL_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_JSR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_JSR, -1);

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  stack[stack_size++].addr = destination;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_JSR_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_JSR_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  stack[stack_size++].addr = destination;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_RET
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_RET, -1);

	{
	  jint indx = pc->jint;
	  pc = locals[indx].addr;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  /* jump back to original code */
	  _svmf_goto ((pc++)->implementation);
#endif
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_GOTO
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_GOTO, -1);

	pc = pc->addr->addr;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	/* jump back to original code */
	_svmf_goto ((pc++)->implementation);
#endif

	m4svm_instruction_tail ();
/*
----------------------------------------------------------------------
INLINED_GOTO_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_GOTO_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

        /* refresh pc */
	pc = env->stack.current_frame->pc;

	pc = pc->addr->addr;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	/* jump back to original code */
	_svmf_goto ((pc++)->implementation);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_TABLESWITCH_CASE
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_TABLESWITCH_CASE, -1);

/* 	_svmf_printf_ptr(env, stderr,"\nINLINED_TABLESWITCH_CASE: IN\n"); */

	{
	  _svmt_code *table = (pc++)->addr->addr;	/* original table */
	  jint inlined_case = (pc++)->jint;
	  jint value = stack[--stack_size].jint;

	  /* The case inlined is not the right one */
	  /* branch to correct target in original code */
	  if (inlined_case != value)
	    {
	      jint low = table[-2].jint;
	      jint high = table[-1].jint;

	      if (value < low || value > high)
		{
		  pc = table[-3].addr;	/* default dest. */
		}
	      else
		{
		  pc = table[value - low].addr;
		}

/* 	      _svmf_printf_ptr(env, stderr, */
/* 			       "INLINED_TABLESWITCH_CASE [%d]: value[%d] exiting inlined code to %p\n", */
/* 			       inlined_case, value, pc); */
	      
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	  else
	    {
/* 	      _svmf_printf_ptr(env, stderr, */
/* 			       "INLINED_TABLESWITCH_CASE [%d]: continuing inlined code\n", */
/* 			       inlined_case); */
	    }
	}

/* 	_svmf_printf_ptr(env, stderr,"INLINED_TABLESWITCH_CASE: OUT\n"); */

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_TABLESWITCH_DEFAULT
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_TABLESWITCH_DEFAULT, -1);
	{
	  _svmt_code *table = (pc++)->addr->addr;	/* original table */
	  jint low = (pc++)->jint;
	  jint high = (pc++)->jint;
	  jint value = stack[--stack_size].jint;

	  /* We should use one of the normal cases and not the default case. */
	  /* Branch to the correct target in original code */
	  if (value >= low && value <= high)
	    {
	      pc = table[value - low].addr;
/* 	      _svmf_printf(env, stderr, "INLINED_TABLESWITCH_DEFAULT: exiting inlined code\n"); */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	  else
	    {
/* 	      _svmf_printf(env, stderr, "INLINED_TABLESWITCH_DEFAULT: continuing inlined code\n"); */
	    }
	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_LOOKUPSWITCH_CASE
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_LOOKUPSWITCH_CASE, -1);
	{
	  _svmt_code *table = (pc++)->addr->addr;	/* original table */
	  jint inlined_case = (pc++)->jint;
	  jint key = stack[--stack_size].jint;

/* 	  _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_CASE [%d]: in key[%d]\n", inlined_case, key); */

	  /* The inlined case is not the right one branch at the correct */
	  /* target in the original code */
	  if (inlined_case != key)
	    {
	      _svmt_code *default_dest = table[-2].addr;
	      jint npairs = table[-1].jint;

	      jint low = 0;
	      jint high = npairs - 1;

	      while (high >= low)
		{
		  jint middle = (low + high) / 2;
		  jint match = table[middle * 2].jint;

		  if (key == match)
		    {
		      pc = table[middle * 2 + 1].addr;
		      break;
		    }

		  if (key > match)
		    {
		      low = middle + 1;
		    }
		  else
		    {
		      high = middle - 1;
		    }
		}

	      if (high < low)
		{
		  pc = default_dest;

/* 		  _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_CASE: out\n"); */
		}


/* 	      _svmf_printf_ptr(env, stderr, */
/* 			       "INLINED_LOOKUPSWITCH_CASE [%d]: exiting inlined code\n", */
/* 			       inlined_case); */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		  /* jump back to original code */
		  _svmf_goto ((pc++)->implementation);
#endif

	    }
	  else
	    {
/* 	      _svmf_printf(env, stderr,  */
/* 			   "INLINED_LOOKUPSWITCH_CASE [%d]: continuing inlined code\n", */
/* 			   inlined_case); */
	    }
/* 	  _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_CASE [%d]: out\n", inlined_case); */
	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_LOOKUPSWITCH_DEFAULT
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INLINED_LOOKUPSWITCH_DEFAULT, -1);
	
/* 	_svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: in\n"); */
	
	{
	  _svmt_code *table = (pc++)->addr->addr; /* original table */
	  jint key = stack[--stack_size].jint;
	  _svmt_code *tmp = pc;

	  /* cheating to keep inlinability of this bytecode */	  
	  if(_svmf_mi_inlined_lookupswitch_default__key_is_default_ptr(env, table, key, &tmp)
	     != JNI_TRUE)
	    {
	      /* go back to original code */
	      pc = tmp;
	      
/* 	      _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: out\n"); */
	      
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}
	m4svm_instruction_tail ();
	
/*
----------------------------------------------------------------------
INLINED_TABLESWITCH_CASE_CHECK
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_TABLESWITCH_CASE_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *table = (pc++)->addr->addr;	/* original table */
	  jint inlined_case = (pc++)->jint;
	  jint value = stack[--stack_size].jint;

	  /* The case inlined is not the right one */
	  /* branch to correct target in original code */
	  if (inlined_case != value)
	    {
	      jint low = table[-2].jint;
	      jint high = table[-1].jint;

	      if (value < low || value > high)
		{
		  pc = table[-3].addr;	/* default dest. */
		}
	      else
		{
		  pc = table[value - low].addr;
		}
	      /* 	      _svmf_printf(env, stderr,  */
/* 			   "INLINED_TABLESWITCH_CASE_CHECK [%d]: exiting inlined code\n", */
/* 			   inlined_case); */
	      
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		  /* jump back to original code */
		  _svmf_goto ((pc++)->implementation);
#endif
	    }
	  else
	    {
/* 	      _svmf_printf(env, stderr,  */
/* 			   "INLINED_TABLESWITCH_CASE_CHECK [%d]: continuing inlined code\n", */
/* 			   inlined_case); */
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_TABLESWITCH_DEFAULT_CHECK
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_TABLESWITCH_DEFAULT_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *table = (pc++)->addr->addr;	/* original table */
	  jint low = (pc++)->jint;
	  jint high = (pc++)->jint;
	  jint value = stack[--stack_size].jint;

	  /* We should use one of the normal cases and not the default case. */
	  /* Branch to the correct target in original code */
	  if (value >= low && value <= high)
	    {
	      pc = table[value - low].addr;
/* 	      _svmf_printf(env, stderr, "INLINED_TABLESWITCH_DEFAULT_CHECK: exiting inlined code\n"); */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	  else
	    {
/* 	      _svmf_printf(env, stderr, "INLINED_TABLESWITCH_DEFAULT_CHECK: continuing inlined code\n"); */
	    }
	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_LOOKUPSWITCH_CASE_CHECK
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_LOOKUPSWITCH_CASE_CHECK, -1);

/* 	_svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_CASE_CHECK: in\n"); */

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *table = (pc++)->addr->addr;	/* original table */
	  jint inlined_case = (pc++)->jint;
	  jint key = stack[--stack_size].jint;

	  /* The inlined case is not the right one  branch at the correct */
	  /* target in the original code */
	  if (inlined_case != key)
	    {
	      _svmt_code *default_dest = table[-2].addr;
	      jint npairs = table[-1].jint;

	      jint low = 0;
	      jint high = npairs - 1;

	      while (high >= low)
		{
		  jint middle = (low + high) / 2;
		  jint match = table[middle * 2].jint;

		  if (key == match)
		    {
		      pc = table[middle * 2 + 1].addr;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		      /* jump back to original code */
		      _svmf_goto ((pc++)->implementation);
#endif
		      break;
		    }

		  if (key > match)
		    {
		      low = middle + 1;
		    }
		  else
		    {
		      high = middle - 1;
		    }
		}

	      if (high < low)
		{
		  pc = default_dest;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
/* 	_svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_CASE_CHECK: out\n"); */

		  /* jump back to original code */
		  _svmf_goto ((pc++)->implementation);
#endif
		}
/* 	      _svmf_printf(env, stderr,  */
/* 			   "INLINED_LOOKUPSWITCH_CASE_CHECK [%d]: exiting inlined code\n", */
/* 			   inlined_case); */
	    }
	  else
	    {
/* 	      _svmf_printf(env, stderr,  */
/* 			   "INLINED_LOOKUPSWITCH_CASE_CHECK [%d]: continuing inlined code\n", */
/* 			   inlined_case); */
	    }
	}
/* 	_svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_CASE_CHECK: out\n"); */

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INLINED_LOOKUPSWITCH_DEFAULT_CHECK
----------------------------------------------------------------------
*/
	m4svm_instruction_head (INLINED_LOOKUPSWITCH_DEFAULT_CHECK, -1);

/* 	_svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT_CHECK: in\n"); */

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *table = (pc++)->addr->addr;	/* original table */
	  jint key = stack[--stack_size].jint;
	  _svmt_code *tmp = pc;
	  
	  /* cheating to keep inlinability of this bytecode */	  
	  if(_svmf_mi_inlined_lookupswitch_default__key_is_default_ptr(env, table, key, &tmp)
	     != JNI_TRUE)
	    {
	      /* go back to original code */
	      pc = tmp;
	      
/* 	      _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: out\n"); */
	      
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}
	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_IF<X>(_CHECK)
----------------------------------------------------------------------
*/
	/* m4_define([:m4svm_instruction_profiling_if_x:], [: */
	m4svm_instruction_head (PROFILING_IF$1, -1);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value $2 0)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_profiling_if_x_check:], [: */
	m4svm_instruction_head (PROFILING_IF$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value $2 0)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_profiling_if_icmpx:], [: */
	m4svm_instruction_head (PROFILING_IF_ICMP$1, -1);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 $2 value2)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_profiling_if_icmpx_check:], [: */
	m4svm_instruction_head (PROFILING_IF_ICMP$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 $2 value2)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_profiling_if_acmpx:], [: */
	m4svm_instruction_head (PROFILING_IF_ACMP$1, -1);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 $2 ref2)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_profiling_if_acmpx_check:], [: */
	m4svm_instruction_head (PROFILING_IF_ACMP$1_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 $2 ref2)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_profiling_if_x(EQ, ==)
	 * m4svm_instruction_profiling_if_x(NE, !=)
	 * m4svm_instruction_profiling_if_x(LT, <)
	 * m4svm_instruction_profiling_if_x(LE, <=)
	 * m4svm_instruction_profiling_if_x(GT, >)
	 * m4svm_instruction_profiling_if_x(GE, >=)
	 * m4svm_instruction_profiling_if_icmpx(EQ, ==)
	 * m4svm_instruction_profiling_if_icmpx(NE, !=)
	 * m4svm_instruction_profiling_if_icmpx(LT, <)
	 * m4svm_instruction_profiling_if_icmpx(LE, <=)
	 * m4svm_instruction_profiling_if_icmpx(GT, >)
	 * m4svm_instruction_profiling_if_icmpx(GE, >=)
	 * m4svm_instruction_profiling_if_acmpx(EQ, ==)
	 * m4svm_instruction_profiling_if_acmpx(NE, !=) */

	/* m4svm_instruction_profiling_if_x_check(EQ, ==)
	 * m4svm_instruction_profiling_if_x_check(NE, !=)
	 * m4svm_instruction_profiling_if_x_check(LT, <)
	 * m4svm_instruction_profiling_if_x_check(LE, <=)
	 * m4svm_instruction_profiling_if_x_check(GT, >)
	 * m4svm_instruction_profiling_if_x_check(GE, >=)
	 * m4svm_instruction_profiling_if_icmpx_check(EQ, ==)
	 * m4svm_instruction_profiling_if_icmpx_check(NE, !=)
	 * m4svm_instruction_profiling_if_icmpx_check(LT, <)
	 * m4svm_instruction_profiling_if_icmpx_check(LE, <=)
	 * m4svm_instruction_profiling_if_icmpx_check(GT, >)
	 * m4svm_instruction_profiling_if_icmpx_check(GE, >=)
	 * m4svm_instruction_profiling_if_acmpx_check(EQ, ==)
	 * m4svm_instruction_profiling_if_acmpx_check(NE, !=) */

	/* m4_undefine([:m4svm_instruction_profiling_if_x:])
	 * m4_undefine([:m4svm_instruction_profiling_if_icmpx:])
	 * m4_undefine([:m4svm_instruction_profiling_if_acmpx:]) */

	/* m4_undefine([:m4svm_instruction_profiling_if_x_check:])
	 * m4_undefine([:m4svm_instruction_profiling_if_icmpx_check:])
	 * m4_undefine([:m4svm_instruction_profiling_if_acmpx_check:]) */

/*
----------------------------------------------------------------------
PROFILING_IFNULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_IFNULL, -1);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_IFNULL_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_IFNULL_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_IFNONNULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_IFNONNULL, -1);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }

	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_IFNONNULL_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_IFNONNULL_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      (pc->jint) ++;
	      pc = destination;
	    }
	  else
	    {
	      (pc->jint) --;
	      pc++;		/* skip profiling counter */
	    }

	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_TABLESWITCH
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_TABLESWITCH, -1);
	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint low = (pc++)->jint;
	  jint high = (pc++)->jint;
	  jint index = stack[--stack_size].jint;

	  if (index < low || index > high)
	    {
	      (pc->jint) ++;
	      pc = default_dest;
	    }
	  else
	    {
	      jint ind = (index - low) * 2;

	      pc++;		/* skip default case counter */

	      (pc[ind + 1].jint) ++;
	      pc = pc[ind].addr;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_TABLESWITCH_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_TABLESWITCH_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint low = (pc++)->jint;
	  jint high = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint index = stack[--stack_size].jint;

	  if (index < low || index > high)
	    {
	      (pc->jint) ++;
	      pc = default_dest;
	    }
	  else
	    {
	      jint ind = index - low;

	      pc++;		/* skip default case counter */

	      (pc[ind + 1].jint) ++;
	      pc = table[ind].addr;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_LOOKUPSWITCH
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_LOOKUPSWITCH, -1);
	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint npairs = (pc++)->jint;
	  jint key = stack[--stack_size].jint;

	  jint low = 0;
	  jint high = npairs - 1;

	  /* skip default case counter */
	  pc++;

	  while (high >= low)
	    {
	      jint middle = (low + high) / 2;
	      jint match = pc[middle * 3].jint;

	      if (key == match)
		{
		  jint ind = middle * 3;

		  (pc[ind + 2].jint) ++;
		  pc = pc[ind + 1].addr;
		  break;
		}

	      if (key > match)
		{
		  low = middle + 1;
		}
	      else
		{
		  high = middle - 1;
		}
	    }

	  if (high < low)
	    {
	      (pc[-1].jint) ++;
	      pc = default_dest;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PROFILING_LOOKUPSWITCH_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PROFILING_LOOKUPSWITCH_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	_svmf_periodic_check_ptr (env);
#else
	_svmf_periodic_check (env);
#endif

	  /* refresh pc */
	  pc = env->stack.current_frame->pc;

	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint npairs = (pc++)->jint;
	  jint key = stack[--stack_size].jint;

	  jint low = 0;
	  jint high = npairs - 1;

	  /* skip default case counter */
	  pc++;

	  while (high >= low)
	    {
	      jint middle = (low + high) / 2;
	      jint match = pc[middle * 3].jint;

	      if (key == match)
		{
		  jint ind = middle * 3;

		  (pc[ind + 2].jint) ++;
		  pc = pc[ind + 1].addr;
		  break;
		}

	      if (key > match)
		{
		  low = middle + 1;
		}
	      else
		{
		  high = middle - 1;
		}
	    }

	  if (high < low)
	    {
	      (pc[-1].jint) ++;
	      pc = default_dest;
	    }
	}

	m4svm_instruction_tail ();

m4svm_on(0)
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
m4svm_off()

/*
----------------------------------------------------------------------
INLINED_JMP_OVER_NEXT_SEQ
----------------------------------------------------------------------
*/

        m4svm_instruction_head (INLINED_JMP_OVER_NEXT_SEQ, -1);

        pc = pc->addr;

	m4svm_instruction_tail ();

m4svm_on(0)
#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */
m4svm_off()


m4svm_on(0)
#endif /* _SABLEVM_METHOD_INLINING */
m4svm_off()
/*
----------------------------------------------------------------------
End of instructions
----------------------------------------------------------------------
*/
      }
    }
}
