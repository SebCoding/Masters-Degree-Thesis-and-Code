/* This file has been automatically generated from "instructions.m4.c" */

/*
----------------------------------------------------------------------
BIPUSH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BIPUSH:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p BIPUSH]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "BIPUSH");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
SIPUSH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SIPUSH:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p SIPUSH]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "SIPUSH");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDC_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_W:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDC_W]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDC_W");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDC2_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC2_W:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDC2_W]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDC2_W");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
WIDE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_WIDE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p WIDE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "WIDE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GOTO_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO_W:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GOTO_W]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GOTO_W");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
JSR_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR_W:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p JSR_W]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "JSR_W");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NOP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NOP:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NOP]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NOP");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ACONST_NULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ACONST_NULL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ACONST_NULL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].reference = NULL;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ACONST_NULL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ICONST_M1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_M1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ICONST_M1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = -1;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ICONST_M1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ICONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ICONST_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = 0;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ICONST_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ICONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ICONST_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = 1;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ICONST_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ICONST_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ICONST_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ICONST_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ICONST_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ICONST_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = 3;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ICONST_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ICONST_4
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_4:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ICONST_4]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = 4;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ICONST_4");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ICONST_5
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_5:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ICONST_5]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = 5;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ICONST_5");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCONST_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LCONST_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jlong *) (void *) &stack[stack_size]) = 0;
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LCONST_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCONST_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LCONST_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jlong *) (void *) &stack[stack_size]) = 1;
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LCONST_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FCONST_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jfloat = 0;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FCONST_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FCONST_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jfloat = 1;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FCONST_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FCONST_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FCONST_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jfloat = 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FCONST_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCONST_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DCONST_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jdouble *) (void *) &stack[stack_size]) = 0;
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DCONST_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCONST_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DCONST_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jdouble *) (void *) &stack[stack_size]) = 1;
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DCONST_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDC_INTEGER
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_INTEGER:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDC_INTEGER]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = (pc++)->jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDC_INTEGER");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDC_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jfloat = (pc++)->jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDC_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDC_STRING
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_STRING:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDC_STRING]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	stack[stack_size++].reference = *((pc++)->jobject);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL ||
		strcmp (stack[stack_size - 1].reference->magic,
			"SableVM") == 0);
#endif

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDC_STRING");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDC_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jlong *) (void *) &stack[stack_size]) = *((pc++)->pjlong);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDC_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDC_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jdouble *) (void *) &stack[stack_size]) = *((pc++)->pjdouble);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDC_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ILOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ILOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].jint = locals[indx].jint;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ILOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LLOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  *((jlong *) (void *) &stack[stack_size]) =
	    *((jlong *) (void *) &locals[indx]);
	  stack_size += 2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LLOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FLOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].jfloat = locals[indx].jfloat;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FLOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DLOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  *((jdouble *) (void *) &stack[stack_size]) =
	    *((jdouble *) (void *) &locals[indx]);
	  stack_size += 2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DLOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ILOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ILOAD_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = locals[0].jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ILOAD_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ILOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ILOAD_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = locals[1].jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ILOAD_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ILOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ILOAD_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = locals[2].jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ILOAD_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ILOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ILOAD_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jint = locals[3].jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ILOAD_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LLOAD_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jlong *) (void *) &stack[stack_size]) =
	  *((jlong *) (void *) &locals[0]);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LLOAD_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LLOAD_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jlong *) (void *) &stack[stack_size]) =
	  *((jlong *) (void *) &locals[1]);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LLOAD_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LLOAD_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jlong *) (void *) &stack[stack_size]) =
	  *((jlong *) (void *) &locals[2]);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LLOAD_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LLOAD_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jlong *) (void *) &stack[stack_size]) =
	  *((jlong *) (void *) &locals[3]);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LLOAD_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FLOAD_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jfloat = locals[0].jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FLOAD_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FLOAD_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jfloat = locals[1].jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FLOAD_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FLOAD_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jfloat = locals[2].jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FLOAD_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FLOAD_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].jfloat = locals[3].jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FLOAD_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DLOAD_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jdouble *) (void *) &stack[stack_size]) =
	  *((jdouble *) (void *) &locals[0]);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DLOAD_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DLOAD_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jdouble *) (void *) &stack[stack_size]) =
	  *((jdouble *) (void *) &locals[1]);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DLOAD_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DLOAD_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jdouble *) (void *) &stack[stack_size]) =
	  *((jdouble *) (void *) &locals[2]);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DLOAD_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DLOAD_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	*((jdouble *) (void *) &stack[stack_size]) =
	  *((jdouble *) (void *) &locals[3]);
	stack_size += 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DLOAD_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].jint = _svmf_get_int_array_element (array, indx);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  if (indx < 0 || indx >= size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    _svmf_get_long_array_element (array, indx);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].jfloat = _svmf_get_float_array_element (array, indx);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  if (indx < 0 || indx >= size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  *((jdouble *) (void *) &stack[stack_size - 2]) =
	    _svmf_get_double_array_element (array, indx);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
CALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p CALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].jint = _svmf_get_char_array_element (array, indx);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "CALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
SALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p SALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].jint = _svmf_get_short_array_element (array, indx);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "SALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].reference = locals[indx].reference;
	}

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ALOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ALOAD_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].reference = locals[0].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ALOAD_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ALOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ALOAD_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].reference = locals[1].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ALOAD_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ALOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ALOAD_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].reference = locals[2].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ALOAD_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ALOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ALOAD_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size++].reference = locals[3].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ALOAD_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
AALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_AALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p AALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "AALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
BALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BALOAD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p BALOAD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "BALOAD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ISTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ISTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  locals[indx].jint = stack[--stack_size].jint;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ISTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LSTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  stack_size -= 2;
	  *((jlong *) (void *) &locals[indx]) =
	    *((jlong *) (void *) &stack[stack_size]);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LSTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FSTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  locals[indx].jfloat = stack[--stack_size].jfloat;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FSTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DSTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  stack_size -= 2;
	  *((jdouble *) (void *) &locals[indx]) =
	    *((jdouble *) (void *) &stack[stack_size]);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DSTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  locals[indx].reference = stack[--stack_size].reference;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ISTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ISTORE_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[0].jint = stack[--stack_size].jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ISTORE_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ISTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ISTORE_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[1].jint = stack[--stack_size].jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ISTORE_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ISTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ISTORE_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[2].jint = stack[--stack_size].jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ISTORE_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ISTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ISTORE_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[3].jint = stack[--stack_size].jint;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ISTORE_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LSTORE_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;
	*((jlong *) (void *) &locals[0]) =
	  *((jlong *) (void *) &stack[stack_size]);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LSTORE_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LSTORE_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;
	*((jlong *) (void *) &locals[1]) =
	  *((jlong *) (void *) &stack[stack_size]);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LSTORE_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LSTORE_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;
	*((jlong *) (void *) &locals[2]) =
	  *((jlong *) (void *) &stack[stack_size]);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LSTORE_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LSTORE_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;
	*((jlong *) (void *) &locals[3]) =
	  *((jlong *) (void *) &stack[stack_size]);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LSTORE_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FSTORE_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[0].jfloat = stack[--stack_size].jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FSTORE_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FSTORE_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[1].jfloat = stack[--stack_size].jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FSTORE_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FSTORE_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[2].jfloat = stack[--stack_size].jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FSTORE_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FSTORE_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[3].jfloat = stack[--stack_size].jfloat;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FSTORE_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DSTORE_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;
	*((jdouble *) (void *) &locals[0]) =
	  *((jdouble *) (void *) &stack[stack_size]);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DSTORE_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DSTORE_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;
	*((jdouble *) (void *) &locals[1]) =
	  *((jdouble *) (void *) &stack[stack_size]);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DSTORE_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DSTORE_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;
	*((jdouble *) (void *) &locals[2]) =
	  *((jdouble *) (void *) &stack[stack_size]);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DSTORE_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DSTORE_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;
	*((jdouble *) (void *) &locals[3]) =
	  *((jdouble *) (void *) &stack[stack_size]);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DSTORE_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[0].reference = stack[--stack_size].reference;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[1].reference = stack[--stack_size].reference;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[2].reference = stack[--stack_size].reference;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	locals[3].reference = stack[--stack_size].reference;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value = stack[--stack_size].jint;
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_int_array_element (array, indx, value);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value = *((jlong *) (void *) &stack[(stack_size -= 2)]);
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_long_array_element (array, indx, value);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value = stack[--stack_size].jfloat;
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_float_array_element (array, indx, value);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_double_array_element (array, indx, value);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
CASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p CASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jchar value = stack[--stack_size].jint;
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_char_array_element (array, indx, value);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "CASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
SASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p SASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jshort value = stack[--stack_size].jint;
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_short_array_element (array, indx, value);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "SASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
BASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p BASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "BASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
AASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_AASTORE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p AASTORE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "AASTORE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
POP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_POP:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p POP]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size--;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "POP");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
POP2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_POP2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p POP2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack_size -= 2;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "POP2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DUP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DUP]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	stack[stack_size] = stack[stack_size - 1];
	stack_size++;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DUP");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DUP_X1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP_X1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DUP_X1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value2;
	  stack[stack_size] = value1;
	  stack_size++;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DUP_X1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DUP_X2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP_X2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DUP_X2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DUP_X2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DUP2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DUP2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size++] = value2;
	  stack[stack_size++] = value1;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DUP2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DUP2_X1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2_X1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DUP2_X1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DUP2_X1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DUP2_X2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2_X2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DUP2_X2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DUP2_X2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
SWAP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SWAP:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p SWAP]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "SWAP");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IADD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IADD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 + value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IADD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LADD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LADD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 + value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LADD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FADD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FADD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = value1 + value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FADD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DADD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DADD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) = value1 + value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DADD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ISUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISUB:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ISUB]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 - value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ISUB");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSUB:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LSUB]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 - value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LSUB");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSUB:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FSUB]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = value1 - value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FSUB");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSUB:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DSUB]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) = value1 - value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DSUB");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IMUL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IMUL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 * value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IMUL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LMUL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LMUL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 * value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LMUL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FMUL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FMUL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = value1 * value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FMUL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DMUL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DMUL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) = value1 * value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DMUL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FDIV:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FDIV]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = value1 / value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FDIV");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DDIV:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DDIV]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) = value1 / value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DDIV");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INEG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INEG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = - value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INEG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LNEG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LNEG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value = *((jlong *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jlong *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = - value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LNEG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FNEG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FNEG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value = stack[stack_size - 1].jfloat;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jfloat = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jfloat = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jfloat = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jfloat = - value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FNEG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DNEG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DNEG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value = *((jdouble *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jdouble *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = - value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DNEG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IAND
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IAND:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IAND]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 & value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IAND");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LAND
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LAND:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LAND]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 & value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LAND");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IOR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IOR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 | value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IOR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LOR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 | value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LOR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IXOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IXOR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IXOR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 ^ value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IXOR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LXOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LXOR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LXOR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 ^ value2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LXOR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
I2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2L:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p I2L]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "I2L");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
I2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2F:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p I2F]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jfloat = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jfloat = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jfloat = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jfloat =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "I2F");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
I2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2D:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p I2D]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "I2D");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
L2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2I:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p L2I]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value = *((jlong *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "L2I");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
L2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2F:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p L2F]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value = *((jlong *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jfloat = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jfloat = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jfloat = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jfloat =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "L2F");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
L2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2D:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p L2D]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value = *((jlong *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jdouble *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "L2D");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
F2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2I:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p F2I]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value = stack[stack_size - 1].jfloat;
/* SVM__MAX is never defined. */
#ifdef SVM_JINT_MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM_JINT_MAX)
	    {
	      stack[stack_size - 1].jint = SVM_JINT_MAX;
	    }
	  else if (value <= SVM_JINT_MIN)
	    {
	      stack[stack_size - 1].jint = SVM_JINT_MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "F2I");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
F2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2L:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p F2L]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value = stack[stack_size - 1].jfloat;
/* SVM__MAX is never defined. */
#ifdef SVM_JLONG_MAX
	  if (value != value)
	    {			/* NaN */
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM_JLONG_MAX)
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = SVM_JLONG_MAX;
	    }
	  else if (value <= SVM_JLONG_MIN)
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = SVM_JLONG_MIN;
	    }
	  else
#endif
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "F2L");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
F2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2D:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p F2D]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value = stack[stack_size - 1].jfloat;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "F2D");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
D2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2I:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p D2I]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value = *((jdouble *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM_JINT_MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM_JINT_MAX)
	    {
	      stack[stack_size - 1].jint = SVM_JINT_MAX;
	    }
	  else if (value <= SVM_JINT_MIN)
	    {
	      stack[stack_size - 1].jint = SVM_JINT_MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "D2I");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
D2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2L:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p D2L]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value = *((jdouble *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM_JLONG_MAX
	  if (value != value)
	    {			/* NaN */
	      *((jlong *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM_JLONG_MAX)
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = SVM_JLONG_MAX;
	    }
	  else if (value <= SVM_JLONG_MIN)
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = SVM_JLONG_MIN;
	    }
	  else
#endif
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "D2L");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
D2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2F:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p D2F]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value = *((jdouble *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jfloat = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jfloat = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jfloat = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jfloat =  value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "D2F");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
I2B
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2B:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p I2B]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = (jbyte) value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "I2B");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
I2C
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2C:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p I2C]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = (jchar) value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "I2C");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
I2S
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2S:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p I2S]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = (jshort) value;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "I2S");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IDIV:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IDIV]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IDIV");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDIV:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LDIV]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LDIV");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IREM:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IREM]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IREM");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LREM:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LREM]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LREM");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FREM:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FREM]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = _svmm_fmod (value1, value2);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FREM");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DREM:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DREM]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) =
	    _svmm_fmod (value1, value2);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DREM");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ISHL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISHL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ISHL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 << (value2 & 0x1f);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ISHL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LSHL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSHL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LSHL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    value1 << (value2 & 0x3f);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LSHL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ISHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISHR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ISHR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ISHR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSHR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LSHR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LSHR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IUSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IUSHR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IUSHR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint =
	    ((_svmt_u32) value1) >> (value2 & 0x1f);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IUSHR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LUSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LUSHR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LUSHR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    ((_svmt_u64) value1) >> (value2 & 0x3f);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LUSHR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LCMP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCMP:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LCMP]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[stack_size - 2]);
	  stack[(stack_size -= 3) - 1].jint =
	    (value1 > value2) - (value1 < value2);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LCMP");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FCMPL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCMPL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FCMPL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FCMPL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FCMPG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCMPG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FCMPG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FCMPG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DCMPL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCMPL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DCMPL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DCMPL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DCMPG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCMPG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DCMPG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DCMPG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IINC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IINC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IINC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  jint constant = (pc++)->jint;
	  locals[indx].jint +=constant;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IINC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value == 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value != 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFLT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value < 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFLT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value <= 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFGT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value > 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFGT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFGE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value >= 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFGE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 == value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 != value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPLT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 < value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPLT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 <= value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPGT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 > value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPGT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPGE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 >= value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPGE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ACMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ACMPEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 == ref2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ACMPEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ACMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ACMPNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 != ref2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ACMPNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value == 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value != 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFLT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value < 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFLT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFLE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value <= 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFLE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFGT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value > 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFGT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFGE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value >= 0)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFGE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 == value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 != value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPLT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 < value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPLT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPLE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 <= value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPLE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPGT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 > value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPGT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ICMPGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ICMPGE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 >= value2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ICMPGE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ACMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ACMPEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (ref1 == ref2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ACMPEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IF_ACMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IF_ACMPNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (ref1 != ref2)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IF_ACMPNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GOTO
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GOTO]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	pc = pc->addr;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GOTO");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GOTO_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GOTO_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GOTO_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
JSR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p JSR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  stack[stack_size++].addr = pc;
	  pc = destination;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "JSR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
JSR_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p JSR_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "JSR_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
RET
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_RET:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p RET]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = pc->jint;
	  pc = locals[indx].addr;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "RET");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
TABLESWITCH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_TABLESWITCH:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p TABLESWITCH]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "TABLESWITCH");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
TABLESWITCH_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p TABLESWITCH_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "TABLESWITCH_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LOOKUPSWITCH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOOKUPSWITCH:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LOOKUPSWITCH]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LOOKUPSWITCH");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LOOKUPSWITCH_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LOOKUPSWITCH_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LOOKUPSWITCH_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IRETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IRETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	  locals[0].jint = stack[stack_size - 1].jint;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 1;
	  pc = frame->pc;

/* 	  if(strcmp("I", "A") == 0) */
/* 	    { */
/* 	      if ((env->vm->mi_info.inst_count_times >= 146) && */
/* 		  (env->vm->mi_info.inst_count >= 26125569 )) */
/* 		{ */
/* 		  _svmf_printf(env, stderr, "IRETURN: resuming caller at[%p]\n", pc); */
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IRETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LRETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LRETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	  *((jlong *) (void *) &locals[0]) = *((jlong *) (void *) &stack[stack_size - 2]);

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 2;
	  pc = frame->pc;

/* 	  if(strcmp("L", "A") == 0) */
/* 	    { */
/* 	      if ((env->vm->mi_info.inst_count_times >= 146) && */
/* 		  (env->vm->mi_info.inst_count >= 26125569 )) */
/* 		{ */
/* 		  _svmf_printf(env, stderr, "LRETURN: resuming caller at[%p]\n", pc); */
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LRETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
FRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FRETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p FRETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	  locals[0].jfloat = stack[stack_size - 1].jfloat;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 1;
	  pc = frame->pc;

/* 	  if(strcmp("F", "A") == 0) */
/* 	    { */
/* 	      if ((env->vm->mi_info.inst_count_times >= 146) && */
/* 		  (env->vm->mi_info.inst_count >= 26125569 )) */
/* 		{ */
/* 		  _svmf_printf(env, stderr, "FRETURN: resuming caller at[%p]\n", pc); */
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "FRETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
DRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DRETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p DRETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	  *((jdouble *) (void *) &locals[0]) = *((jdouble *) (void *) &stack[stack_size - 2]);

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 2;
	  pc = frame->pc;

/* 	  if(strcmp("D", "A") == 0) */
/* 	    { */
/* 	      if ((env->vm->mi_info.inst_count_times >= 146) && */
/* 		  (env->vm->mi_info.inst_count >= 26125569 )) */
/* 		{ */
/* 		  _svmf_printf(env, stderr, "DRETURN: resuming caller at[%p]\n", pc); */
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "DRETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ARETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ARETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ARETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	  locals[0].reference = stack[stack_size - 1].reference;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 1;
	  pc = frame->pc;

/* 	  if(strcmp("A", "A") == 0) */
/* 	    { */
/* 	      if ((env->vm->mi_info.inst_count_times >= 146) && */
/* 		  (env->vm->mi_info.inst_count >= 26125569 )) */
/* 		{ */
/* 		  _svmf_printf(env, stderr, "ARETURN: resuming caller at[%p]\n", pc); */
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ARETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
RETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_RETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p RETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	  
	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 0;
	  pc = frame->pc;

/* 	  if(strcmp("", "A") == 0) */
/* 	    { */
/* 	      if ((env->vm->mi_info.inst_count_times >= 146) && */
/* 		  (env->vm->mi_info.inst_count >= 26125569 )) */
/* 		{ */
/* 		  _svmf_printf(env, stderr, "RETURN: resuming caller at[%p]\n", pc); */
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "RETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKEVIRTUAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INVOKEVIRTUAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INVOKEVIRTUAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKESPECIAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INVOKESPECIAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  _svmf_printf(env, stderr, "INVOKESPECIAL: instance->vtable->type[%p]\n",
		       instance->vtable->type);

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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INVOKESPECIAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKESTATIC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INVOKESTATIC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INVOKESTATIC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKEINTERFACE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INVOKEINTERFACE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INVOKEINTERFACE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEW:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEW]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEW");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ARRAYLENGTH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ARRAYLENGTH:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ARRAYLENGTH]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* can cause sigsegv on NULL array ref */
	  stack[stack_size - 1].jint = array->size;

	  
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ARRAYLENGTH");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ATHROW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ATHROW:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ATHROW]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  *(env->throwable) = stack[stack_size - 1].reference;

	  env->stack.current_frame->pc = pc;

	  _svmm_goto_label (athrow_handler);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ATHROW");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
CHECKCAST
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CHECKCAST:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p CHECKCAST]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "CHECKCAST");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INSTANCEOF
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INSTANCEOF:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INSTANCEOF]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INSTANCEOF");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
MONITORENTER
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MONITORENTER:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p MONITORENTER]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "MONITORENTER");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
MONITOREXIT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MONITOREXIT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p MONITOREXIT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "MONITOREXIT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNULL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFNULL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFNULL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNULL_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFNULL_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFNULL_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFNONNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNONNULL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFNONNULL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      pc = destination;
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFNONNULL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
IFNONNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNONNULL_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p IFNONNULL_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "IFNONNULL_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
LINK_NATIVE_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LINK_NATIVE_METHOD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p LINK_NATIVE_METHOD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "LINK_NATIVE_METHOD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ABSTRACT_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ABSTRACT_METHOD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ABSTRACT_METHOD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	_svmm_goto_label (abstractmethoderror_handler);

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ABSTRACT_METHOD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NATIVE_STATIC_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NATIVE_STATIC_METHOD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NATIVE_STATIC_METHOD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NATIVE_STATIC_METHOD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NATIVE_NONSTATIC_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NATIVE_NONSTATIC_METHOD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NATIVE_NONSTATIC_METHOD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NATIVE_NONSTATIC_METHOD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  stack[stack_size - 1].jint =
	    *((jbyte *) (void *) (((char *) instance) + offset));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  stack[stack_size - 1].jint =
	    *((jshort *) (void *) (((char *) instance) + offset));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  stack[stack_size - 1].jint =
	    *((jchar *) (void *) (((char *) instance) + offset));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  stack[stack_size - 1].jint =
	    *((jint *) (void *) (((char *) instance) + offset));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  *((jlong *) (void *) &stack[stack_size++ - 1]) =
	    *((jlong *) (void *) (((char *) instance) + offset));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  stack[stack_size - 1].jfloat =
	    *((jfloat *) (void *) (((char *) instance) + offset));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  *((jdouble *) (void *) &stack[stack_size++ - 1]) =
	    *((jdouble *) (void *) (((char *) instance) + offset));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_REFERENCE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_REFERENCE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  stack[stack_size - 1].reference =
	    *((_svmt_object_instance * *) (void *) (((char *) instance) + offset));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_REFERENCE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  size_t offset = (pc++)->offset;
	  jbyte value = stack[--stack_size].jint;
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

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_BYTE_FIELD)
	  _svmf_put_BYTE_field (env, instance, offset, value);
#else
	  _svmf_put_BYTE_field (instance, offset, value);
#endif /* SVM_PUT_BYTE_FIELD */

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  size_t offset = (pc++)->offset;
	  jshort value = stack[--stack_size].jint;
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

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_SHORT_FIELD)
	  _svmf_put_SHORT_field (env, instance, offset, value);
#else
	  _svmf_put_SHORT_field (instance, offset, value);
#endif /* SVM_PUT_SHORT_FIELD */

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  size_t offset = (pc++)->offset;
	  jchar value = stack[--stack_size].jint;
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

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_CHAR_FIELD)
	  _svmf_put_CHAR_field (env, instance, offset, value);
#else
	  _svmf_put_CHAR_field (instance, offset, value);
#endif /* SVM_PUT_CHAR_FIELD */

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  size_t offset = (pc++)->offset;
	  jint value = stack[--stack_size].jint;
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

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_INT_FIELD)
	  _svmf_put_INT_field (env, instance, offset, value);
#else
	  _svmf_put_INT_field (instance, offset, value);
#endif /* SVM_PUT_INT_FIELD */

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  size_t offset = (pc++)->offset;
	  jlong value = *((jlong *) (void *) &stack[(stack_size -= 2)]);
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

	  
	  *((jlong *) (void *) (((char *) instance) + offset)) = value;

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  size_t offset = (pc++)->offset;
	  jfloat value = stack[--stack_size].jfloat;
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

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_FLOAT_FIELD)
	  _svmf_put_FLOAT_field (env, instance, offset, value);
#else
	  _svmf_put_FLOAT_field (instance, offset, value);
#endif /* SVM_PUT_FLOAT_FIELD */

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  size_t offset = (pc++)->offset;
	  jdouble value = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
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

	  
	  *((jdouble *) (void *) (((char *) instance) + offset)) = value;

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_REFERENCE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_REFERENCE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance * value = stack[--stack_size].reference;
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

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_REFERENCE_FIELD)
	  _svmf_put_REFERENCE_field (env, instance, offset, value);
#else
	  _svmf_put_REFERENCE_field (instance, offset, value);
#endif /* SVM_PUT_REFERENCE_FIELD */

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_REFERENCE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->z;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->b;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->s;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->c;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->i;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *((jlong *) (void *) &stack[stack_size]) = pvalue->j;
	  stack_size += 2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jfloat = pvalue->f;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *((jdouble *) (void *) &stack[stack_size]) = pvalue->d;
	  stack_size += 2;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->z = stack[--stack_size].jint;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->b = stack[--stack_size].jint;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->s = stack[--stack_size].jint;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->c = stack[--stack_size].jint;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->i = stack[--stack_size].jint;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->j = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->f = stack[--stack_size].jfloat;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->d = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETFIELD_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  stack[stack_size - 1].jint =
	    (((_svmt_u8 *) instance)[offset / 8] >> (offset % 8)) & 1;

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETFIELD_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTFIELD_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
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

	  
	  /* to avoid conditional jumps we use boolean arithmetic */
	  ((_svmt_u8 *) instance)[offset / 8] |= (value << (offset % 8));
	  ((_svmt_u8 *) instance)[offset / 8] &= ~(nvalue << (offset % 8));

	  	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTFIELD_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
GETSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_REFERENCE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p GETSTATIC_REFERENCE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].reference = *(pvalue->l);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	  assert (stack[stack_size - 1].reference == NULL ||
		  strcmp (stack[stack_size - 1].reference->magic,
			  "SableVM") == 0);
#endif
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "GETSTATIC_REFERENCE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PUTSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_REFERENCE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PUTSTATIC_REFERENCE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	
	pc++;			/* skip preparation address */
 	 
	
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *(pvalue->l) = stack[--stack_size].reference;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	  _svmf_write_barrier (env, (_svmt_object_instance **) pvalue->l);
#endif /* _SABLEVM_GC_WRITE_BARRIER */
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PUTSTATIC_REFERENCE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_RET
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_RET]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = (pc++)->jint;
	  locals[indx].addr = stack[--stack_size].addr;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_RET");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_RET_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_0:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_RET_0]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  locals[0].addr = stack[--stack_size].addr;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_RET_0");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_RET_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_RET_1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  locals[1].addr = stack[--stack_size].addr;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_RET_1");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_RET_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_2:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_RET_2]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  locals[2].addr = stack[--stack_size].addr;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_RET_2");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ASTORE_RET_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_3:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ASTORE_RET_3]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  locals[3].addr = stack[--stack_size].addr;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ASTORE_RET_3");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEXT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEXT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEXT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

	_svmf_goto ((pc++)->implementation);
	    
#endif

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEXT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	      (env, vm->class_loading.boot_loader.classes.boolean_array,
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	      (env, vm->class_loading.boot_loader.classes.byte_array,
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	      (env, vm->class_loading.boot_loader.classes.short_array,
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	      (env, vm->class_loading.boot_loader.classes.char_array,
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	      (env, vm->class_loading.boot_loader.classes.int_array,
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	      (env, vm->class_loading.boot_loader.classes.long_array,
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	      (env, vm->class_loading.boot_loader.classes.float_array,
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
NEWARRAY_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p NEWARRAY_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	      (env, vm->class_loading.boot_loader.classes.double_array,
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "NEWARRAY_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ANEWARRAY:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ANEWARRAY]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ANEWARRAY");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
MULTIANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MULTIANEWARRAY:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p MULTIANEWARRAY]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "MULTIANEWARRAY");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
ERROR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ERROR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p ERROR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	_svmm_fatal_error ("grave internal VM error");

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "ERROR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INTERNAL_CALL_END
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INTERNAL_CALL_END:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INTERNAL_CALL_END]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)
	env->signal_handler = previous_signal_handler;
#endif
	
	return (*(env->throwable) == NULL) ? JNI_OK : JNI_ERR;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INTERNAL_CALL_END");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
SKIP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SKIP:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p SKIP]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	pc++;			/* skip preparation address */

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "SKIP");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
REPLACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_REPLACE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p REPLACE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_code code = *(pc++);

	  *addr = code;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "REPLACE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_METHOD:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_METHOD]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_METHOD");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_LDC_STRING
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_LDC_STRING:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_LDC_STRING]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_LDC_STRING");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    stack[stack_size - 1].jint = _svmf_get_BOOLEAN_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    stack[stack_size - 1].jint = _svmf_get_BYTE_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    stack[stack_size - 1].jint = _svmf_get_SHORT_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    stack[stack_size - 1].jint = _svmf_get_CHAR_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    stack[stack_size - 1].jint = _svmf_get_INT_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    *((jlong *) (void *) &stack[stack_size++ - 1]) =
	      _svmf_get_LONG_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    stack[stack_size - 1].jfloat = _svmf_get_FLOAT_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    *((jdouble *) (void *) &stack[stack_size++ - 1]) =
	      _svmf_get_DOUBLE_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_REFERENCE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_REFERENCE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	    stack[stack_size - 1].reference = _svmf_get_REFERENCE_field (instance, offset);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETFIELD_REFERENCE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    jboolean value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_BOOLEAN_FIELD)
	    _svmf_put_BOOLEAN_field (env, instance, offset, value);
#else
	    _svmf_put_BOOLEAN_field (instance, offset, value);
#endif /* SVM_PUT_BOOLEAN_FIELD */

	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    jbyte value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_BYTE_FIELD)
	    _svmf_put_BYTE_field (env, instance, offset, value);
#else
	    _svmf_put_BYTE_field (instance, offset, value);
#endif /* SVM_PUT_BYTE_FIELD */

	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    jshort value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_SHORT_FIELD)
	    _svmf_put_SHORT_field (env, instance, offset, value);
#else
	    _svmf_put_SHORT_field (instance, offset, value);
#endif /* SVM_PUT_SHORT_FIELD */

	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    jchar value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_CHAR_FIELD)
	    _svmf_put_CHAR_field (env, instance, offset, value);
#else
	    _svmf_put_CHAR_field (instance, offset, value);
#endif /* SVM_PUT_CHAR_FIELD */

	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    jint value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_INT_FIELD)
	    _svmf_put_INT_field (env, instance, offset, value);
#else
	    _svmf_put_INT_field (instance, offset, value);
#endif /* SVM_PUT_INT_FIELD */

	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    jlong value = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_LONG_FIELD)
	    _svmf_put_LONG_field (env, instance, offset, value);
#else
	    _svmf_put_LONG_field (instance, offset, value);
#endif /* SVM_PUT_LONG_FIELD */
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    jfloat value = stack[--stack_size].jfloat;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_FLOAT_FIELD)
	    _svmf_put_FLOAT_field (env, instance, offset, value);
#else
	    _svmf_put_FLOAT_field (instance, offset, value);
#endif /* SVM_PUT_FLOAT_FIELD */

	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    jdouble value = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_DOUBLE_FIELD)
	    _svmf_put_DOUBLE_field (env, instance, offset, value);
#else
	    _svmf_put_DOUBLE_field (instance, offset, value);
#endif /* SVM_PUT_DOUBLE_FIELD */
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_REFERENCE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_REFERENCE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmt_object_instance * value = stack[--stack_size].reference;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_REFERENCE_FIELD)
	    _svmf_put_REFERENCE_field (env, instance, offset, value);
#else
	    _svmf_put_REFERENCE_field (instance, offset, value);
#endif /* SVM_PUT_REFERENCE_FIELD */

	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTFIELD_REFERENCE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    stack[stack_size++].jint = _svmf_get_BOOLEAN_static (pvalue);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    stack[stack_size++].jint = _svmf_get_BYTE_static (pvalue);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    stack[stack_size++].jint = _svmf_get_SHORT_static (pvalue);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    stack[stack_size++].jint = _svmf_get_CHAR_static (pvalue);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    stack[stack_size++].jint = _svmf_get_INT_static (pvalue);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    *((jlong *) (void *) &stack[stack_size]) =
	      _svmf_get_LONG_static (pvalue);
	    stack_size += 2;
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    stack[stack_size++].jfloat = _svmf_get_FLOAT_static (pvalue);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    *((jdouble *) (void *) &stack[stack_size]) =
	      _svmf_get_DOUBLE_static (pvalue);
	    stack_size += 2;
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_REFERENCE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_REFERENCE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    stack[stack_size++].reference = _svmf_get_REFERENCE_static (pvalue);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_GETSTATIC_REFERENCE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BOOLEAN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_BOOLEAN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_BOOLEAN_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_BOOLEAN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BYTE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_BYTE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_BYTE_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_BYTE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_SHORT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_SHORT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_SHORT_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_SHORT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_CHAR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_CHAR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_CHAR_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_CHAR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_INT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_INT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_INT_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_INT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_LONG:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_LONG]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_LONG_static (pvalue,
				 *((jlong *) (void *)
				   &stack[(stack_size -= 2)]));
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_LONG");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_FLOAT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_FLOAT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_FLOAT_static (pvalue, stack[--stack_size].jfloat);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_FLOAT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_DOUBLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_DOUBLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_DOUBLE_static (pvalue,
				 *((jdouble *) (void *)
				   &stack[(stack_size -= 2)]));
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_DOUBLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_REFERENCE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_REFERENCE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    _svmf_put_REFERENCE_static (pvalue, stack[--stack_size].reference);
	  }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_PUTSTATIC_REFERENCE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_CHECKCAST
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_CHECKCAST:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_CHECKCAST]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_CHECKCAST");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_INSTANCEOF
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_INSTANCEOF]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_INSTANCEOF");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_NEW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_NEW:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_NEW]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_NEW");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_ANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_ANEWARRAY]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_ANEWARRAY");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_MULTIANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_MULTIANEWARRAY]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_MULTIANEWARRAY");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_INVOKEVIRTUAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_INVOKEVIRTUAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_INVOKESPECIAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_INVOKESPECIAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_INVOKESTATIC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_INVOKESTATIC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PREPARE_INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PREPARE_INVOKEINTERFACE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PREPARE_INVOKEINTERFACE");
#endif
	/* dispatch */
	goto dispatch;
      }


#ifdef _SABLEVM_METHOD_INLINING

/*
----------------------------------------------------------------------
INITIAL_INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INITIAL_INVOKESTATIC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INITIAL_INVOKESTATIC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INITIAL_INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INITIAL_INVOKESPECIAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INITIAL_INVOKESPECIAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INITIAL_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INITIAL_INVOKEVIRTUAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INITIAL_INVOKEVIRTUAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INITIAL_INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INITIAL_INVOKEINTERFACE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INITIAL_INVOKEINTERFACE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
COUNTING_INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p COUNTING_INVOKESTATIC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "COUNTING_INVOKESTATIC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
COUNTING_INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p COUNTING_INVOKESPECIAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "COUNTING_INVOKESPECIAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
COUNTING_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p COUNTING_INVOKEVIRTUAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "COUNTING_INVOKEVIRTUAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
COUNTING_INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p COUNTING_INVOKEINTERFACE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "COUNTING_INVOKEINTERFACE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_INVOKESTATIC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_INVOKESTATIC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_INVOKESTATIC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_INVOKESPECIAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_INVOKESPECIAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_INVOKESPECIAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_INVOKEVIRTUAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_INVOKEVIRTUAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_INVOKEINTERFACE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_INVOKEINTERFACE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_INVOKESTATIC]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_INVOKESTATIC");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_INVOKESPECIAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_INVOKESPECIAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_INVOKEVIRTUAL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  
	  /* the following can cause a segfault */
	  method_check =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_INVOKEVIRTUAL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_INVOKEINTERFACE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
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

	  
	  /* the following can cause a segfault */
	  method_check =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_INVOKEINTERFACE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IRETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IRETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    locals[0].jint = stack[stack_size - 1].jint;

	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - caller_method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    stack_size = frame->stack_size + 1;

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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IRETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_LRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_LRETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_LRETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    *((jlong *) (void *) &locals[0]) = *((jlong *) (void *) &stack[stack_size - 2]);

	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - caller_method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    stack_size = frame->stack_size + 2;

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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_LRETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_FRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_FRETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_FRETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    locals[0].jfloat = stack[stack_size - 1].jfloat;

	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - caller_method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    stack_size = frame->stack_size + 1;

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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_FRETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_DRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_DRETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_DRETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    *((jdouble *) (void *) &locals[0]) = *((jdouble *) (void *) &stack[stack_size - 2]);

	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - caller_method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    stack_size = frame->stack_size + 2;

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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_DRETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_ARETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_ARETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_ARETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    locals[0].reference = stack[stack_size - 1].reference;

	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - caller_method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    stack_size = frame->stack_size + 1;

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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_ARETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_RETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_RETURN:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_RETURN]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	    
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - caller_method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    stack_size = frame->stack_size + 0;

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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_RETURN");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value = stack[--stack_size].jint;

	  if (value == 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value = stack[--stack_size].jint;

	  if (value != 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFLT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFLT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value = stack[--stack_size].jint;

	  if (value < 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFLT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value = stack[--stack_size].jint;

	  if (value <= 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFGT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFGT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value = stack[--stack_size].jint;

	  if (value > 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFGT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFGE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFGE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value = stack[--stack_size].jint;

	  if (value >= 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFGE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 == value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 != value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPLT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPLT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 < value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPLT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 <= value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPGT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPGT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 > value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPGT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPGE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPGE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 >= value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPGE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ACMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ACMPEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ACMPEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 == ref2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ACMPEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ACMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ACMPNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ACMPNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 != ref2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ACMPNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value == 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value != 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFLT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFLT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value < 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFLT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFLE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFLE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value <= 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFLE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFGT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFGT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value > 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFGT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFGE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFGE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value >= 0)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFGE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 == value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 != value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPLT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPLT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 < value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPLT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPLE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPLE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 <= value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPLE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPGT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPGT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 > value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPGT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ICMPGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ICMPGE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ICMPGE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 >= value2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ICMPGE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ACMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ACMPEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ACMPEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (ref1 == ref2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ACMPEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IF_ACMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IF_ACMPNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IF_ACMPNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (ref1 != ref2)
	    {
	      pc = destination;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      /* jump back to original code */
	      _svmf_goto ((pc++)->implementation);
#endif
	    }
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IF_ACMPNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFNULL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFNULL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFNULL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFNULL_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFNULL_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFNULL_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFNONNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFNONNULL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFNONNULL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFNONNULL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_IFNONNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_IFNONNULL_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_IFNONNULL_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_IFNONNULL_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_JSR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_JSR:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_JSR]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr->addr;
	  stack[stack_size++].addr = destination;
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_JSR");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_JSR_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_JSR_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_JSR_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_JSR_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_RET
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_RET:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_RET]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  jint indx = pc->jint;
	  pc = locals[indx].addr;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  /* jump back to original code */
	  _svmf_goto ((pc++)->implementation);
#endif
	}

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_RET");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_GOTO
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_GOTO:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_GOTO]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	pc = pc->addr->addr;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	/* jump back to original code */
	_svmf_goto ((pc++)->implementation);
#endif

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_GOTO");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_GOTO_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_GOTO_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_GOTO_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_TABLESWITCH_CASE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_TABLESWITCH_CASE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_TABLESWITCH_CASE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_TABLESWITCH_DEFAULT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_TABLESWITCH_DEFAULT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_TABLESWITCH_DEFAULT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_LOOKUPSWITCH_CASE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_LOOKUPSWITCH_CASE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_LOOKUPSWITCH_CASE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_LOOKUPSWITCH_DEFAULT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_LOOKUPSWITCH_DEFAULT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
		
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_LOOKUPSWITCH_DEFAULT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_TABLESWITCH_CASE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_TABLESWITCH_CASE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_TABLESWITCH_CASE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_TABLESWITCH_DEFAULT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_TABLESWITCH_DEFAULT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_TABLESWITCH_DEFAULT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_LOOKUPSWITCH_CASE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_LOOKUPSWITCH_CASE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_LOOKUPSWITCH_CASE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
INLINED_LOOKUPSWITCH_DEFAULT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_LOOKUPSWITCH_DEFAULT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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
	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_LOOKUPSWITCH_DEFAULT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value == 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value != 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFLT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFLT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value < 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFLT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value <= 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFGT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFGT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value > 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFGT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFGE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFGE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value >= 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFGE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 == value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 != value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPLT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPLT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 < value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPLT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPLE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPLE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 <= value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPLE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPGT:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPGT]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 > value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPGT");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPGE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPGE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 >= value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPGE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ACMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ACMPEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ACMPEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 == ref2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ACMPEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ACMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ACMPNE:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ACMPNE]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 != ref2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ACMPNE");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value == 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value != 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFLT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFLT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value < 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFLT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFLE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFLE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value <= 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFLE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFGT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFGT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value > 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFGT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFGE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFGE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value >= 0)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFGE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 == value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 != value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPLT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPLT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 < value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPLT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPLE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPLE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 <= value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPLE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPGT_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPGT_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 > value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPGT_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ICMPGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ICMPGE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ICMPGE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (value1 >= value2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ICMPGE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ACMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ACMPEQ_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ACMPEQ_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (ref1 == ref2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ACMPEQ_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IF_ACMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IF_ACMPNE_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IF_ACMPNE_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	  if (ref1 != ref2)
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IF_ACMPNE_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFNULL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFNULL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFNULL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFNULL_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFNULL_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFNULL_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFNONNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFNONNULL:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFNONNULL]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFNONNULL");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_IFNONNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_IFNONNULL_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_IFNONNULL_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_IFNONNULL_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_TABLESWITCH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_TABLESWITCH:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_TABLESWITCH]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_TABLESWITCH");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_TABLESWITCH_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_TABLESWITCH_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_TABLESWITCH_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_LOOKUPSWITCH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_LOOKUPSWITCH]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_LOOKUPSWITCH");
#endif
	/* dispatch */
	goto dispatch;
      }


/*
----------------------------------------------------------------------
PROFILING_LOOKUPSWITCH_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p PROFILING_LOOKUPSWITCH_CHECK]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
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

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "PROFILING_LOOKUPSWITCH_CHECK");
#endif
	/* dispatch */
	goto dispatch;
      }


#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

/*
----------------------------------------------------------------------
INLINED_JMP_OVER_NEXT_SEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p INLINED_JMP_OVER_NEXT_SEQ]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	 	 
	
        pc = pc->addr;

	 
#if defined (_SABLEVM_METHOD_INLINING) && !defined(NDEBUG)
	_svmf_mi_debug_on_dispatch (env, stack_size, pc, "INLINED_JMP_OVER_NEXT_SEQ");
#endif
	/* dispatch */
	goto dispatch;
      }


#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */

#endif /* _SABLEVM_METHOD_INLINING */
