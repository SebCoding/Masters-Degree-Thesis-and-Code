/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <types.h>

/* on Linux/Intel, we'll need to put FPU into double precision mode */
#if defined(__i386__) && defined(__linux__)
#include <fpu_control.h>
#endif

#if defined(_SABLEVM_METHOD_INLINING)

svm_static jboolean
(*_svmf_mi_inlined_lookupswitch_default__key_is_default_ptr)
(_svmt_JNIEnv *, _svmt_code *, jint, _svmt_code **) =
&_svmf_mi_inlined_lookupswitch_default__key_is_default;

#if defined(_SABLEVM_INLINED_THREADED_INTERPRETER)

svm_static void (*_svmf_printf_ptr)
  (_svmt_JNIEnv *, FILE *, const char *, ...) = &_svmf_printf;

svm_static jint
(*_svmf_enter_object_monitor_ptr) 
     (_svmt_JNIEnv *, _svmt_object_instance *) = &_svmf_enter_object_monitor;

svm_static jint
(*_svmf_exit_object_monitor_ptr) (_svmt_JNIEnv *, 
				  _svmt_object_instance *) = 
&_svmf_exit_object_monitor;

svm_static void
(*_svmf_periodic_check_ptr) (_svmt_JNIEnv *) = &_svmf_periodic_check;

svm_static void SVM_UNUSED
(*_svmf_error_IllegalMonitorStateException_ptr) (_svmt_JNIEnv *) = 
 &_svmf_error_IllegalMonitorStateException;

#ifndef NDEBUG
svm_static void (*_svmf_mi_debug_on_dispatch_ptr)
  (_svmt_JNIEnv *, jint, _svmt_code *, const char *) =
  &_svmf_mi_debug_on_dispatch;

svm_static void (*_svmf_print_method_name_ptr)
  (_svmt_JNIEnv *, FILE *, _svmt_method_info *,
   const char *) = &_svmf_print_method_name;

svm_static void
(*_svmf_verbose_methods_enter_ptr) (_svmt_JNIEnv *) = &_svmf_verbose_methods_enter;

svm_static void
(*_svmf_verbose_methods_exit_ptr) (_svmt_JNIEnv *) = &_svmf_verbose_methods_exit;

svm_static jint
(*_svmf_mi_print_super_instruction_ptr) (_svmt_JNIEnv *, FILE *,
					 const void *) = &_svmf_mi_print_super_instruction;

svm_static void
(*_svmf_dump_stack_trace_ptr) (_svmt_JNIEnv *) = &_svmf_dump_stack_trace;

svm_static void
(*_svmf_mi_print_bytecode_count_ptr) (_svmt_JNIEnv *, _svmt_code *, const char*, jint) = &_svmf_mi_print_bytecode_count;

#endif /* NDEBUG */

#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */
#endif /* _SABLEVM_METHOD_INLINING */


#ifdef  _SABLEVM_VERBOSE_INSTRUCTIONS_INLINED

/*
----------------------------------------------------------------------
_svmf_verbose_instructions_inlined
----------------------------------------------------------------------
*/

svm_static void
_svmf_verbose_instructions_inlined (_svmt_JNIEnv *env, _svmt_code *pc,
				    const char *name)
{
  if (env->vm->verbose_instructions == JNI_TRUE)
    {
      _svmf_printf (env, stderr,
		    "T%d: [verbose instructions: executing @%p %s]\n",
		    env->thread.id, (void *) (pc - 1), name);
      fflush (NULL);
    }
}


void (*_svmf_verbose_instructions_inlined_ptr) (_svmt_JNIEnv *, _svmt_code *,
						const char *);

#define _svmm_verbose_instructions_inlined(a,b,c) \
	_svmf_verbose_instructions_inlined_ptr(a,b,c)

#else

#define _svmm_verbose_instructions_inlined(a,b,c)

#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
#define _svmm_fmod(x,y) _svmf_fmod_ptr(x,y)
#else
#define _svmm_fmod(x,y) fmod(x,y)
#endif



/*
----------------------------------------------------------------------
_svmf_interpreter
----------------------------------------------------------------------
*/

svm_static jint
_svmf_interpreter (_svmt_JNIEnv *_env)
{
  _svmt_JNIEnv *volatile env = _env;
  register _svmt_stack_value *stack = NULL;
  register _svmt_stack_value *locals = NULL;
  register _svmt_code *pc = NULL;
  register jint stack_size = 0;

  /* exception addresses 
   *
   * The idea is that normal gotos/calls might be compiled to relative
   * jumps, preventing their usage in inlined-threaded code. Using a
   * goto is an elegant way to avoid using method calls in ATHROW
   * (necessary to create a new null pointer exception).
   * [ NOTE: fatal_error_handler_ptr is currently not used because for GCC ]
   * [ 3.x we needed arch-specific assembly implementation of goto anyway. ]
   * [ But it's kept here in case it was useful with other compilers and   ]
   * [ as a well documented and neat idea that once was implemented.       ]
   *
   * A last note:We must guard against a too clever compiler that
   * would detect a unique value in a variable; we do this by
   * initializing goto address variable to NULL, and changing its
   * value to the correct one when initializing the instruction array.
   * Ahh! So many little details to get right for things to work...
   */

#ifdef _SABLEVM_INLINABILITY_TESTING

  static _svmt_code *(*no_inlining_increment_pc) (_svmt_JNIEnv *,
						  _svmt_word, _svmt_code *) =
    NULL;

#endif


#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined (_SABLEVM_INLINABILITY_TESTING)

  sigjmp_buf *volatile previous_signal_handler = env->signal_handler;
  sigjmp_buf signal_handler;

#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
/*  static void *fatal_error_handler_ptr = NULL; */
  double (*_svmf_fmod_ptr) (double x, double y) = &fmod;
#endif

#ifdef  _SABLEVM_VERBOSE_INSTRUCTIONS_INLINED
  _svmf_verbose_instructions_inlined_ptr =
    &_svmf_verbose_instructions_inlined;
#endif

#ifdef _SABLEVM_INLINABILITY_TESTING
  env->inlinability_testing.sigsegv_expected = JNI_FALSE;
#endif

  assert (*(env->throwable) == NULL);

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined (_SABLEVM_INLINABILITY_TESTING)

  /* set signal handler */
  if (sigsetjmp (signal_handler, 1))
    {
      jint signal_code = env->signal_code;

#ifndef NDEBUG
      env->signal_code = SVM_SIGNAL_NONE;
#endif

      switch (signal_code)
	{

#if defined(_SABLEVM_INLINABILITY_TESTING)
	case SVM_SIGNAL_INLINING_FAILURE:
	  {
	    /* note failed bytecode test if we know which one was that */
	    _svmt_method_info *method =
	      env->stack.current_frame->method_frame_info->method;
	    int byname = _svmf_get_bytecode_by_method_name (env,
							    DREF (method->
								  name,
								  value));

	    if (byname >= 0)
	      {
		_svmf_printf (env, stderr,
			      "REGISTERING failed bytecode: %s\n",
			      env->vm->instructions[byname].name);
		env->inlinability_testing.bytecode_inlinability[byname]
		  |= SVM_BCI_FAILING;
	      }
	    else
	      {
		_svmf_printf (env, stderr,
			      "UNABLE to find which bytecode failed!\n");
	      }

	    _svmf_printf (env, stderr,
			  "UNEXPECTED SIGNAL CAUGHT Class: %s - REVERSED BACKTRACE FOLLOWS:\n",
			  env->stack.current_frame->method_frame_info->
			  method->class_info->name);

	    _svmf_no_inlining (env, 0, SVM_IS_INLINED_GET_BACKTRACE);

	    {
	      /* pop stack frame */
	      _svmt_stack_frame *frame = env->stack.current_frame;
	      env->stack.current_frame = (_svmt_stack_frame *)
		(((char *) frame) - frame->previous_offset);

	      /* is method synchronized? */
	      if (method->synchronized)
		{
		  /* release monitor */
		  if (_svmf_exit_object_monitor (env, frame->this) != JNI_OK)
		    {
		      goto exception_handler;
		    }
		}

	      assert (*(env->throwable) == NULL);

	      goto inliningexception_handler;
	    }
	  }
	  break;
#endif

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS)
	case SVM_SIGNAL_NULL_POINTER_EXCEPTION:
	  {
	    /* if initializing this vm, we store into _svmv_codes
	       the address of the initialized static local array */
	    if (env->stack.current_frame == NULL)
	      {
		goto initialize_instructions;
	      }
	    else
	      {
		goto nullpointerexception_handler;
	      }
	  }
	  break;
#endif

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined (_SABLEVM_INLINABILITY_TESTING)
/* Exceptionally - even in inlinability testing mode w/o signals_for_excpetions
 * we want this signal to be catched or else - it'd kill JVM.
 * Most important goal is to let the *inlinability* tests be completed.
 * And we'll clearly indicate that these bytecodes need to be fixed.
 */
	case SVM_SIGNAL_ARITHMETIC_EXCEPTION:
	  {
#if (!defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS)) && defined (_SABLEVM_INLINABILITY_TESTING)
	    /* note failed bytecode test if we know which one was that */
	    _svmt_method_info *method =
	      env->stack.current_frame->method_frame_info->method;
	    int byname = _svmf_get_bytecode_by_method_name (env,
							    DREF (method->
								  name,
								  value));

	    if (byname >= 0)
	      env->inlinability_testing.bytecode_inlinability[byname]
		|= SVM_BCI_SIGFPE;
#endif
	    goto arithmeticexception_handler;
	  }
	  break;
#endif
	default:
	  {
#if defined (_SABLEVM_INLINABILITY_TESTING)
	    _svmf_printf (env, stderr,
			  "KILLER ERROR: imposible control flow; signal_code is %i\n",
			  signal_code);
	    fflush (NULL);
	    goto inliningexception_handler;
#endif
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;
	}
    }

  env->signal_handler = &signal_handler;

#endif
#if !defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS)

  if (env->stack.current_frame == NULL)
    {
      goto initialize_instructions;
    }

#endif /* ! _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

  {
    /* When _SABLEVM_SIGNALS_FOR_EXCEPTIONS is defined, the following code
       causes a sigfault at the time of initialization of vm->instructions,
       as env->stack.current_frame is NULL at that point.

       The advantage of using this weird control flow on initialization is
       to eliminate "initialization test" overhead from normal _svmf_interpreter
       execution path.  Not a thing you should teach cs-101 students ;-)
     */

    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_method_frame_info *frame_info = frame->method_frame_info;

    locals =
      (_svmt_stack_value *) (void *) (((char *) frame) -
				      frame_info->start_offset);
    stack =
      (_svmt_stack_value *) (void *) (((char *) frame) + _svmv_stack_offset);

    assert (env->stack.current_frame->this != NULL);
    assert (env->stack.current_frame->stack_size == 0);

    /* check */
    _svmf_periodic_check (env);
  }

/* on Linux/Intel, put FPU into double precision mode */
#if defined(__i386__) && defined(__linux__)
/*
  This puts the X86 FPU in 64-bit precision mode as opposed to the default
  80-bit mode (used by Linux). For more explanations see:
       http://www.srware.com/linux_numerics.txt
  Originally it was put into lib_init.c but apparently some code executed
  later resets the flag so we set it to "right" value on each interpreter
  invocation. TODO: find out where/what exacly resets the flag.
 */
  {
    fpu_control_t fpu_control;
    _FPU_GETCW (fpu_control);
    fpu_control &= ~_FPU_EXTENDED;
    fpu_control |= _FPU_DOUBLE;
    _FPU_SETCW (fpu_control);
  }
#endif /* i386 && linux */

#if !defined(NDEBUG)

  _svmf_verbose_methods_enter (env);

#endif

  pc = env->stack.current_frame->pc;
  stack_size = 0;

#if defined(_SABLEVM_INLINED_THREADED_INTERPRETER) || defined(_SABLEVM_DIRECT_THREADED_INTERPRETER)

  goto *((pc++)->implementation);

#else

dispatch:

  assert (*(env->throwable) == NULL);

  assert (stack_size >= 0);

  assert (stack_size == 0 ||
	  env->stack.current_frame->method_frame_info->method ==
	  &env->vm->internal_call_method
	  || env->stack.current_frame->method_frame_info->method ==
	  &env->vm->vm_initiated_call_method
	  || stack_size <=
	  env->stack.current_frame->method_frame_info->method->data.
	  code_attribute->max_stack);

  switch ((pc++)->jint)
    {

#include "instructions_switch.c"

    default:
      {
/* 	_svmf_printf(env, stderr, "\nEND OF INSTRUCTION SWITCH:\n"); */
/* 	_svmf_mi_print_bytecode_count(env, pc); */

/* 	_svmf_dump_stack_trace(env); */


/* 	_svmf_printf(env, stderr, "\npc[%p] inst[%d]\n", pc, (pc-1)->jint); */

/* 	_svmf_print_method_name(env, stderr, */
/* 				env->stack.current_frame->method_frame_info->method, ""); */
	_svmm_fatal_error ("impossible control flow");
      }
      break;
    }

#endif /* defined(_SABLEVM_INLINED_THREADED_INTERPRETER) || defined(_SABLEVM_DIRECT_THREADED_INTERPRETER) */

  _svmm_fatal_error ("impossible control flow");

athrow_handler:
  if (*(env->throwable) == NULL)
    {
      goto nullpointerexception_handler;
    }
  goto exception_handler;

arithmeticexception_handler:
  _svmf_error_ArithmeticException (env);
  goto exception_handler;

classcastexception_handler:
  _svmf_error_ClassCastException (env);
  goto exception_handler;

nullpointerexception_handler:
  _svmf_error_NullPointerException (env);
  goto exception_handler;

#if defined(_SABLEVM_INLINABILITY_TESTING)

inliningexception_handler:
  _svmf_error_InliningException (env);
  goto exception_handler;

#endif

arrayindexoutofboundsexception_handler:
  _svmf_error_ArrayIndexOutOfBoundsException (env);
  goto exception_handler;

arraystoreexception_handler:
  _svmf_error_ArrayStoreException (env);
  goto exception_handler;

abstractmethoderror_handler:
  _svmf_error_AbstractMethodError (env);
  goto exception_handler;

exception_handler:

  assert (*(env->throwable) != NULL);

  assert (_svmf_is_assignable_from
	  (env, (*(env->throwable))->vtable->type,
	   _svmf_cast_type_class (env->vm->class_loading.boot_loader.classes.
				  jlthrowable)));

#if !defined(NDEBUG)
  /* dump stack trace on exception */
  if (env->vm->verbose_exceptions)
    {
      _svmf_printf (env, stderr,
		    "** thrown on thread %d: instance of type %s\n",
		    env->thread.id, (*(env->throwable))->vtable->type->name);
      _svmf_dump_stack_trace (env);
    }
#endif

#ifdef COMMENT
  if (strcmp
      ((*(env->throwable))->vtable->type->name,
       "java/lang/ClassNotFoundException") != 0
      && strcmp ((*(env->throwable))->vtable->type->name,
		 "java/lang/NoClassDefFoundError") != 0)
    {
      _svmf_printf (env, stderr, "** (on thread %d) exception: %s\n",
		    env->thread.id, (*(env->throwable))->vtable->type->name);
      _svmf_dump_stack_trace (env);
    }
#endif

  {
    jint i;
    jint table_length;
    _svmt_exception_table *table;
    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_method_frame_info *frame_info = frame->method_frame_info;
    _svmt_method_info *method = frame_info->method;

#ifdef _SABLEVM_METHOD_INLINING
    jboolean in_inlined_method = JNI_FALSE;
    _svmt_stack_frame *calling_method_frame = NULL;
#endif

  exception_loop:

    pc = frame->pc;
    frame->stack_size = 0;

    if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
      {
	assert (method == &env->vm->internal_call_method ||
		method == &env->vm->vm_initiated_call_method);

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined (_SABLEVM_INLINABILITY_TESTING)
	env->signal_handler = previous_signal_handler;
#endif
	return JNI_ERR;
      }

    assert (!_svmf_is_set_flag (method->access_flags, SVM_ACC_NATIVE));

#if !defined (_SABLEVM_METHOD_INLINING)

    table_length = method->data.code_attribute->exception_table_length;
    table = method->data.code_attribute->exception_table;

#else

    /* normal case not profilining and not in inlined code */
    if ((method->frame_info->profiling_status != SVM_METHOD_PROFILING_STARTED)
	&& (pc >= method->frame_info->code)
	&& (pc <
	    (method->frame_info->code + method->frame_info->code_length)))
      {
	table_length = method->data.code_attribute->exception_table_length;
	table = method->data.code_attribute->exception_table;
	in_inlined_method = JNI_FALSE;
      }
    /* if we are in profiling mode and not in inlined code */
    else
      if ((method->frame_info->profiling_status ==
	   SVM_METHOD_PROFILING_STARTED) && (pc >= method->frame_info->code)
	  && (pc <
	      (method->frame_info->code +
	       method->frame_info->profiling_code_length)))
      {
	table_length = method->data.code_attribute->exception_table_length;
	table = method->data.code_attribute->exception_table;
	in_inlined_method = JNI_FALSE;
      }
    /* we are not profiling and in inlined code */
    else
      {
	calling_method_frame = frame;
	in_inlined_method = JNI_TRUE;

	/* find calling method that contains exception table for this inlined method */
	do
	  {
	    calling_method_frame =
	      (_svmt_stack_frame *) (void *) (((char *) calling_method_frame)
					      -
					      calling_method_frame->
					      previous_offset);
	  }
	while ((pc < calling_method_frame->method_frame_info->code) &&
	       (pc >= (calling_method_frame->method_frame_info->code +
		       calling_method_frame->method_frame_info->
		       code_length)));

	/* exception entries for all inlined methods are included in the calling method's
	   exception table */
	table_length =
	  calling_method_frame->method_frame_info->method->data.
	  code_attribute->exception_table_length;
	table =
	  calling_method_frame->method_frame_info->method->data.
	  code_attribute->exception_table;
      }
#endif

    for (i = 0; i < table_length; i++)
      {
	if ((pc >= table[i].normal_start && pc <= table[i].normal_end) ||
	    (pc >= table[i].prepare_start && pc <= table[i].prepare_end))
	  {
	    /* resolve and link type, if necessary */
	    if (CAN_DREF (table[i].catch_type))
	      {
		jobject pending_throwable;

		if (_svmm_new_native_local (env, pending_throwable) != JNI_OK)
		  {
		    /* to avoid infinite loops! */
		    goto pop_stack_frame;
		  }

		/* save throwable aside, so that we can run Java code
		   (i.e. java/lang/Class.<init>) if necessary */
		*pending_throwable = *(env->throwable);
		*(env->throwable) = NULL;

		if (_svmf_resolve_CONSTANT_Class
		    (env,
		     env->stack.current_frame->method_frame_info->method->
		     class_info, *(table[i].catch_type)) != JNI_OK)
		  {
		    _svmm_free_native_local (env, pending_throwable);
		    goto pop_stack_frame;
		  }

		if (_svmf_link_type (env, DREF (table[i].catch_type, type)) !=
		    JNI_OK)
		  {
		    _svmm_free_native_local (env, pending_throwable);
		    goto pop_stack_frame;
		  }

		/* restore pending throwable */
		*(env->throwable) = *pending_throwable;

		_svmm_free_native_local (env, pending_throwable);
		frame = env->stack.current_frame;
		assert (method == frame->method_frame_info->method);
	      }

	    /* if "any" (null)  or matching type */
	    if (CANNOT_DREF (table[i].catch_type) ||
		_svmf_is_assignable_from
		(env, (*(env->throwable))->vtable->type,
		 DREF (table[i].catch_type, type)))
	      {

#ifdef _SABLEVM_METHOD_INLINING

		if (in_inlined_method)
		  {
		    frame = env->stack.current_frame;

		    /* find the frame corresponding to the handler */
		    while ((table[i].handler <
			    frame->method_frame_info->method->frame_info->
			    code)
			   || (table[i].handler >=
			       (frame->method_frame_info->method->frame_info->
				code +
				frame->method_frame_info->method->frame_info->
				code_length)))
		      {
			/* pop frame */
			env->stack.current_frame =
			  (_svmt_stack_frame *) (void *) (((char *) frame) -
							  frame->
							  previous_offset);
			frame = env->stack.current_frame;
		      }

		    method = frame->method_frame_info->method;
		    frame_info = frame->method_frame_info;
		  }

/* 		_svmf_printf(env, stderr, */
/* 			     "Exception occured at pc=%p handled by %p ", */
/* 			     pc, table[i].handler); */

/* 		if (CAN_DREF (table[i].catch_type)) */
/* 		  _svmf_printf (env, stderr, "%s\n", */
/* 				DREF (DREF (table[i].catch_type, name), value)); */
/* 		else */
/* 		  _svmf_printf (env, stderr, "\n"); */

#endif
		locals = (_svmt_stack_value *) (void *)
		  (((char *) frame) - frame_info->start_offset);

		stack = (_svmt_stack_value *) (void *)
		  (((char *) frame) + _svmv_stack_offset);

/* 		_svmf_printf(env, stderr,"EXCEP HAND: pc[%p] dest[%p] ", pc, table[i].handler); */
/* 		_svmf_print_method_name(env, stderr, method, ""); */

		pc = table[i].handler;

		stack_size = 1;
		stack[0].reference = *(env->throwable);

		*(env->throwable) = NULL;

#if defined(_SABLEVM_INLINED_THREADED_INTERPRETER) || defined(_SABLEVM_DIRECT_THREADED_INTERPRETER)

		goto *((pc++)->implementation);

#else

		goto dispatch;

#endif
	      }
	  }
      }

#ifdef _SABLEVM_METHOD_INLINING

    if (in_inlined_method)
      {
	frame = env->stack.current_frame;

	/* pop all the frames of inlined methods */
	while (frame != calling_method_frame)
	  {
	    /* pop frame */
	    env->stack.current_frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);
	    frame = env->stack.current_frame;

	    /* structured locking */
	    if (frame->lock_count != 0 && env->vm->enforce_structured_locking)
	      {
		_svmf_error_IllegalMonitorStateException (env);
		goto exception_handler;
	      }
	  }

	/* pop calling method frame */
	env->stack.current_frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
	frame = env->stack.current_frame;
	in_inlined_method = JNI_FALSE;

	/* structured locking */
	if (frame->lock_count != 0 && env->vm->enforce_structured_locking)
	  {
	    _svmf_error_IllegalMonitorStateException (env);
	    goto exception_handler;
	  }
	method = frame->method_frame_info->method;

	goto exception_loop;
      }
#endif

    /* structured locking */
    if (env->stack.current_frame->lock_count != 0
	&& env->vm->enforce_structured_locking)
      {
	/* pop stack frame */
	frame = env->stack.current_frame;
	env->stack.current_frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);

	_svmf_error_IllegalMonitorStateException (env);
	goto exception_handler;
      }

#if !defined(NDEBUG)

    _svmf_verbose_methods_exit (env);

#endif

  pop_stack_frame:

    /* pop stack frame */
    frame = env->stack.current_frame;
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* is method synchronized? */
    if (method->synchronized)
      {
	/* release monitor */
	if (_svmf_exit_object_monitor (env, frame->this) != JNI_OK)
	  {
	    goto exception_handler;
	  }
      }

    frame = env->stack.current_frame;
    frame_info = frame->method_frame_info;
    method = frame_info->method;

    goto exception_loop;
  }

  _svmm_fatal_error ("impossible control flow");

#ifdef COMMENT
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
fatal_error_handler:
  _svmm_fatal_error ("impossible control flow");
  return JNI_ERR;
#endif
#endif /* COMMENT */

initialize_instructions:

  {
    jint instr;

    for (instr = 0; instr < SVM_INSTRUCTION_COUNT; instr++)
      {
	switch (instr)
	  {

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
#include "instructions_preparation_inlined_threaded.c"
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
#include "instructions_preparation_direct_threaded.c"
#endif

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
#include "instructions_preparation_switch_threaded.c"
#endif

	  case SVM_INSTRUCTION_UNDEFINED_186:
	    {
	      _svmm_zero_memory (env->vm->instructions[instr]);
	    }
	    break;

	  default:
	    {
#if defined (_SABLEVM_METHOD_INLINING) && !defined (NDEBUG)
	      printf ("instr[%d]\n", instr);
	      fflush (NULL);
#endif
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    /* initialize goto/call addresses */
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
/*    fatal_error_handler_ptr = &&fatal_error_handler; */
    if (!_svmv_true)
      {
	/* we have to play this trick to assure this won't get optimized somewhere under way */
	_svmf_fmod_ptr = NULL;

#ifdef _SABLEVM_METHOD_INLINING

	_svmf_printf_ptr = NULL;
	_svmf_periodic_check_ptr = NULL;

	_svmf_enter_object_monitor_ptr = NULL;
	_svmf_exit_object_monitor_ptr = NULL;

	_svmf_error_IllegalMonitorStateException_ptr = NULL;
	_svmf_mi_inlined_lookupswitch_default__key_is_default_ptr = NULL;

#ifndef NDEBUG
	_svmf_mi_debug_on_dispatch_ptr = NULL;
	_svmf_print_method_name_ptr = NULL;

	_svmf_verbose_methods_enter_ptr = NULL;
	_svmf_verbose_methods_exit_ptr = NULL;
	_svmf_mi_print_super_instruction_ptr = NULL;
	_svmf_dump_stack_trace_ptr = NULL;
	_svmf_mi_print_bytecode_count_ptr = NULL;
#endif

#endif


#ifdef _SABLEVM_VERBOSE_INSTRUCTIONS_INLINED
	_svmf_verbose_instructions_inlined_ptr = NULL;
#endif
      }
#endif

#ifdef _SABLEVM_INLINABILITY_TESTING

    no_inlining_increment_pc = &_svmf_no_inlining_increment_pc;

#endif

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

    env->signal_handler = previous_signal_handler;

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

    return JNI_OK;
  }
}

