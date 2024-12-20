/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef NDEBUG

#define SVM_PRINT_METHOD_DESCRIPTORS 0
#define SVM_PRINT_METHOD_NB_BYTECODES 0

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER

inline svm_static jint
_svmf_mi_get_instruction_int_code (_svmt_JNIEnv *, const void *);

#endif /* _SABLEVM_DIRECT_THREADED_INTERPRETER */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

#define _svmm_tree_find_sequence_by_implementation(root, value) \
_svmh_tree_find_sequence_by_implementation (&root, value)

svm_static _svmt_mi_sequence_node_info *
_svmh_tree_find_sequence_by_implementation (_svmt_mi_sequence_node_info **,
					       _svmt_mi_sequence_node_info *);

inline svm_static _svmt_mi_sequence_node_info
  * _svmf_mi_get_sequence_by_implementation (_svmt_JNIEnv *, const void *);

#define _svmm_mp_is_preparation_sequence(a, b, c, d) \
_svmh_mp_is_preparation_sequence(a, b, c, &d)

svm_static jboolean
_svmh_mp_is_preparation_sequence (_svmt_JNIEnv *,
				  _svmt_code *, _svmt_code *,
				  _svmt_mi_sequence_node_info **);


#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */

/*
  ----------------------------------------------------------------------
  _svmf_mi_print_bytecode_count
  ----------------------------------------------------------------------
*/
svm_static void SVM_UNUSED
_svmf_mi_print_bytecode_count (_svmt_JNIEnv *env, _svmt_code *pc, 
			       const char *codename, jint stack_size)
{
  _svmf_printf (env, stderr, "\n[T%d]: inst_count[%u]",
		env->thread.id, env->vm->mi_info.inst_count_times);
  _svmf_printf (env, stderr, "[%u] ", env->vm->mi_info.inst_count);
  _svmf_printf (env, stderr, " pc[%p] [%s] stack_size[%d]\n", pc, 
		codename, stack_size);
}


/*
  ----------------------------------------------------------------------
  _svmf_mi_segfault
  ----------------------------------------------------------------------
*/
svm_static void SVM_UNUSED
_svmf_mi_segfault (void)
{
  jint *ptr = malloc (sizeof (jint));

  while (1)
    {
      *ptr = 999;
      ptr++;
    }
}

/*
  ----------------------------------------------------------------------
  _svmf_print_method_name
  ----------------------------------------------------------------------
*/
svm_static void SVM_UNUSED
_svmf_print_method_name (_svmt_JNIEnv *env, FILE *out,
			 _svmt_method_info *method, const char *msg)
{
#if SVM_PRINT_METHOD_DESCRIPTORS

#if SVM_PRINT_METHOD_NB_BYTECODES
  _svmf_printf (env, out,
		"%s[%s.%s%s] [%d]\n", msg,
		method->class_info->name,
		DREF (method->name, value), DREF (method->descriptor, value),
		method->frame_info->nb_instructions);
#else
  _svmf_printf (env, out,
		"%s[%s.%s%s]\n", msg,
		method->class_info->name,
		DREF (method->name, value), DREF (method->descriptor, value));
#endif

#else

#if SVM_PRINT_METHOD_NB_BYTECODES
  _svmf_printf (env, out,
		"%s[%s.%s] [%d]\n", msg,
		method->class_info->name, DREF (method->name, value),
		method->frame_info->nb_instructions);
#else
  _svmf_printf (env, out,
		"%s[%s.%s]\n", msg,
		method->class_info->name, DREF (method->name, value));
#endif

#endif
}

/*
  ----------------------------------------------------------------------
  _svmf_print_method_name_and_caller
  ----------------------------------------------------------------------
*/
svm_static void SVM_UNUSED
_svmf_print_method_name_and_caller (_svmt_JNIEnv *env, FILE *out,
				    _svmt_method_info *calling,
				    _svmt_method_info *callee,
				    const char *msg)
{
  /*   jint i; */
  /*   jint end = strlen(msg) + 2; */

#if SVM_PRINT_METHOD_DESCRIPTORS

#if SVM_PRINT_METHOD_NB_BYTECODES
  _svmf_printf (env, out,
		"%s[%s.%s%s] [%d] in ", msg,
		callee->class_info->name,
		DREF (callee->name, value), DREF (callee->descriptor, value),
		callee->frame_info->nb_instructions);
#else
  _svmf_printf (env, out,
		"%s[%s.%s%s] in ", msg,
		callee->class_info->name,
		DREF (callee->name, value), DREF (callee->descriptor, value));
#endif

#else

#if SVM_PRINT_METHOD_NB_BYTECODES
  _svmf_printf (env, out,
		"%s[%s.%s] [%d] in ", msg,
		callee->class_info->name,
		DREF (callee->name, value),
		callee->frame_info->nb_instructions);
#else
  _svmf_printf (env, out,
		"%s[%s.%s] in ", msg,
		callee->class_info->name,
		DREF (callee->name, value));
#endif

#endif

  /*   for(i = 0 ; i < end ; i++) */
  /*     _svmf_printf (env, out, " "); */

#if SVM_PRINT_METHOD_DESCRIPTORS

#if SVM_PRINT_METHOD_NB_BYTECODES
  _svmf_printf (env, out, "[%s.%s%s] [%d]\n",
		calling->class_info->name,
		DREF (calling->name, value),
		DREF (calling->descriptor, value),
		callee->frame_info->nb_instructions);
#else
  _svmf_printf (env, out, "[%s.%s%s]\n",
		calling->class_info->name,
		DREF (calling->name, value),
		DREF (calling->descriptor, value));
#endif

#else

#if SVM_PRINT_METHOD_NB_BYTECODES
  _svmf_printf (env, out, "[%s.%s] [%d]\n",
		calling->class_info->name, DREF (calling->name, value),
		calling->frame_info->nb_instructions);
#else
  _svmf_printf (env, out, "[%s.%s]\n",
		calling->class_info->name, DREF (calling->name, value));
#endif

#endif
}

/*
  ----------------------------------------------------------------------
  _svmf_mi_method_is
  ----------------------------------------------------------------------
*/
svm_static jboolean SVM_UNUSED
_svmf_mi_method_is (_svmt_method_info *method,
		    const char *class_name, const char *method_name)
{
  return (strcmp (method->class_info->name, class_name) == 0) &&
    (strcmp (DREF (method->name, value), method_name) == 0);
}

/*
  ----------------------------------------------------------------------
  _svmf_mi_output_exception_table
  ----------------------------------------------------------------------
*/
svm_static void SVM_UNUSED
_svmf_mi_output_exception_table (_svmt_JNIEnv *env, FILE *out,
				 jint table_length,
				 _svmt_exception_table *table,
				 const char *msg)
{
  jint i;

  if (table_length <= 0)
    return;

  _svmf_printf (env, out, "Exception Table: %s size[%d]\n", msg,
		table_length);
  _svmf_printf (env, out, "     %-12s %-12s %-13s %-12s %-12s %s\n",
		"pc_start", "pc_end", "prepare_start", "prepare_end",
		"handler", "type");

  for (i = 0; i < table_length; i++)
    {
      _svmf_printf (env, out, "%-2d)  %-12p %-12p %-13p %-12p %-12p",
		    i + 1,
		    table[i].normal_start,
		    table[i].normal_end,
		    table[i].prepare_start,
		    table[i].prepare_end, table[i].handler);
      if (CANNOT_DREF (table[i].catch_type))
	_svmf_printf (env, out, "NULL\n");
      else
	_svmf_printf (env, out, "%s\n",
		      DREF (DREF (table[i].catch_type, name), value));
    }
  _svmf_printf (env, out, "\n");
}


#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
svm_static jint
_svmf_mi_print_super_instruction (_svmt_JNIEnv *env, FILE *out,
				  const void *implementation)
{
  size_t i;
  _svmt_mi_sequence_node_info *sequence;
  _svmt_mi_sequence_node_info sequence_to_find;

  sequence_to_find.implementation = (void *) implementation;

  sequence =
    _svmm_tree_find_sequence_by_implementation (env->vm->class_loading.
						sequence_tree_by_implementation,
						&sequence_to_find);
  assert (sequence != NULL);

  _svmf_printf (env, out, "[");
  /*   _svmf_printf (env, out, "(%p) ", sequence->implementation); */

  if (sequence->starts_with_skip)
    _svmf_printf (env, out, "SKIP, ");

  for (i = 0; i < sequence->instructions_length; i++)
    _svmf_printf (env, out, "%s, ",
		  env->vm->instructions[sequence->instructions[i]].name);

#if 1
  _svmf_printf (env, out, " {%p} ]", sequence->implementation);
#else
  _svmf_printf (env, out, " ]");
#endif

  return JNI_OK;
}
#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */

/*
  ---------------------------------------------------------------------------
  _svmf_mi_output_exception_table
  For debugging purposes. Outputs a code array to the 'out' file descriptor.
  ---------------------------------------------------------------------------
*/
svm_static void SVM_UNUSED
_svmf_mi_output_code_array (_svmt_JNIEnv *env, FILE *out, _svmt_code *code,
			    size_t length, const char *name, 
			    SVM_UNUSED _svmt_code *code2, SVM_UNUSED size_t length2)
{
  _svmt_code *curr = code;
  _svmt_code *end = code + length;
  jint curr_instruction;
  jboolean in_inlined_code = JNI_FALSE;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  size_t i;
  jint *instructions;
  size_t instructions_length;
  _svmt_mi_sequence_node_info *sequence;
#endif

  /*   _svmf_printf(env, stderr, "start[%p] length[%d] end[%p]\n", curr, length, end); */

  _svmf_printf (env, out, "%s Code Array size[%d]:\n", name, length);

  /*   _svmf_printf(env, stderr, "---\n", curr_instruction); */

#if 0
  {
    size_t v;

    for (v = 0; v < length; v++)
      _svmf_printf (env, out, "%d) %p [%p | %d]\n", v, code + v,
		    code[v].addr, code[v].jint);
    _svmf_printf (env, out, "-------------------\n");
  }
#endif

  while (curr < end)
    {

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
      curr_instruction = curr->jint;

      _svmf_printf (env, out, "%p [%s]\n", curr,
		    env->vm->instructions[curr_instruction].name);
      curr++;
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
      curr_instruction =
	_svmf_mi_get_instruction_int_code (env, curr->implementation);

      _svmf_printf (env, out, "%p [%s]\n", curr,
		    env->vm->instructions[curr_instruction].name);
      curr++;
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

/*       _svmf_printf(env, out, "output_code_array: %p [%d | %p]\n",  */
/* 		   curr, curr->jint, curr->implementation); */

      sequence =
	_svmf_mi_get_sequence_by_implementation (env, curr->implementation);

      assert (sequence != NULL);

      instructions = sequence->instructions;
      instructions_length = sequence->instructions_length;

      /* print super instruction bytecodes */
      _svmf_printf (env, out, "%p ", curr);
      _svmf_mi_print_super_instruction (env, out, curr->implementation);
      _svmf_printf (env, out, "\n");

      curr++;

    process_params:

      if (sequence->starts_with_skip)
	{
	  _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
	  curr++;
	}

      for (i = 0; i < instructions_length; i++)
	{
	  curr_instruction = instructions[i];
#endif

	  assert ((curr_instruction >= 0)
		  && (curr_instruction < SVM_INSTRUCTION_COUNT));

	  switch (curr_instruction)
	    {
	    case SVM_INSTRUCTION_ILOAD:
	    case SVM_INSTRUCTION_FLOAD:
	    case SVM_INSTRUCTION_ISTORE:
	    case SVM_INSTRUCTION_FSTORE:
	    case SVM_INSTRUCTION_ASTORE_RET:
	    case SVM_INSTRUCTION_LLOAD:
	    case SVM_INSTRUCTION_DLOAD:
	    case SVM_INSTRUCTION_LSTORE:
	    case SVM_INSTRUCTION_DSTORE:
	    case SVM_INSTRUCTION_ALOAD:
	    case SVM_INSTRUCTION_ASTORE:
	    case SVM_INSTRUCTION_LDC_INTEGER:
	    case SVM_INSTRUCTION_BIPUSH:
	    case SVM_INSTRUCTION_SIPUSH:
	      {
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_RET:
	      {
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_IINC:
	      {
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_IFEQ:
	    case SVM_INSTRUCTION_INLINED_IFNE:
	    case SVM_INSTRUCTION_INLINED_IFLT:
	    case SVM_INSTRUCTION_INLINED_IFGE:
	    case SVM_INSTRUCTION_INLINED_IFGT:
	    case SVM_INSTRUCTION_INLINED_IFLE:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPEQ:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPNE:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPLT:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPGE:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPGT:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPLE:
	    case SVM_INSTRUCTION_INLINED_IF_ACMPEQ:
	    case SVM_INSTRUCTION_INLINED_IF_ACMPNE:
	    case SVM_INSTRUCTION_INLINED_IFNULL:
	    case SVM_INSTRUCTION_INLINED_IFNONNULL:
	    case SVM_INSTRUCTION_INLINED_JSR:
	      {
		_svmf_printf (env, out, "%p [%p, ", curr, curr->addr);

		/* TO CHANGE */
#if 1
		_svmf_printf (env, out, "%p]\n", curr->addr->addr);
#else
		_svmf_printf (env, out, "%d]\n", curr->jint);
#endif
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_RET:
	      {
		_svmf_printf (env, out, "%p [%d]\n", curr->jint);
		curr++;

		_svmf_printf (env, out,
			      "%p [%p] stack_gc_map at end end of inlined code\n",
			      curr, curr->addr);
		curr++;
		
		in_inlined_code = JNI_FALSE;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_GOTO:
	      {
		_svmf_printf (env, out, "%p [%p, ", curr, curr->addr);

		/* TO CHANGE */
#if 1
		_svmf_printf (env, out, "%p]\n", curr->addr->addr);
#else
		_svmf_printf (env, out, "%d]\n", curr->jint);
#endif
		curr++;

		_svmf_printf (env, out,
			      "%p [%p] stack_gc_map at end end of inlined code\n",
			      curr, curr->addr);
		curr++;
		
		in_inlined_code = JNI_FALSE;
	      }
	      break;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER	      
	    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;
#endif
	      
	    case SVM_INSTRUCTION_IFEQ:
	    case SVM_INSTRUCTION_IFNE:
	    case SVM_INSTRUCTION_IFLT:
	    case SVM_INSTRUCTION_IFGE:
	    case SVM_INSTRUCTION_IFGT:
	    case SVM_INSTRUCTION_IFLE:
	    case SVM_INSTRUCTION_IF_ICMPEQ:
	    case SVM_INSTRUCTION_IF_ICMPNE:
	    case SVM_INSTRUCTION_IF_ICMPLT:
	    case SVM_INSTRUCTION_IF_ICMPGE:
	    case SVM_INSTRUCTION_IF_ICMPGT:
	    case SVM_INSTRUCTION_IF_ICMPLE:
	    case SVM_INSTRUCTION_IF_ACMPEQ:
	    case SVM_INSTRUCTION_IF_ACMPNE:
	    case SVM_INSTRUCTION_JSR:
	    case SVM_INSTRUCTION_IFNULL:
	    case SVM_INSTRUCTION_IFNONNULL:
	    case SVM_INSTRUCTION_LDC_DOUBLE:
	    case SVM_INSTRUCTION_MONITORENTER:
	    case SVM_INSTRUCTION_NEWARRAY_BOOLEAN:
	    case SVM_INSTRUCTION_NEWARRAY_CHAR:
	    case SVM_INSTRUCTION_NEWARRAY_FLOAT:
	    case SVM_INSTRUCTION_NEWARRAY_DOUBLE:
	    case SVM_INSTRUCTION_NEWARRAY_BYTE:
	    case SVM_INSTRUCTION_NEWARRAY_SHORT:
	    case SVM_INSTRUCTION_NEWARRAY_INT:
	    case SVM_INSTRUCTION_NEWARRAY_LONG:
	    case SVM_INSTRUCTION_LDC_LONG:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_PROFILING_IFEQ:
	    case SVM_INSTRUCTION_PROFILING_IFNE:
	    case SVM_INSTRUCTION_PROFILING_IFLT:
	    case SVM_INSTRUCTION_PROFILING_IFGE:
	    case SVM_INSTRUCTION_PROFILING_IFGT:
	    case SVM_INSTRUCTION_PROFILING_IFLE:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPEQ:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPNE:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPLT:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPGE:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPGT:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPLE:
	    case SVM_INSTRUCTION_PROFILING_IF_ACMPEQ:
	    case SVM_INSTRUCTION_PROFILING_IF_ACMPNE:
	    case SVM_INSTRUCTION_PROFILING_IFNULL:
	    case SVM_INSTRUCTION_PROFILING_IFNONNULL:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_GOTO:
	    case SVM_INSTRUCTION_GOTO_CHECK:
	      {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		jint dest_instruction;
		
		if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
		  {
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		  }

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);


#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
		dest_instruction = curr->addr->jint;
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
		dest_instruction =
		  _svmf_mi_get_instruction_int_code
		  (env, curr->addr->implementation);
#endif
		
		/* goto preparation sequence */
		if ((dest_instruction < SVM_INSTRUCTION_COUNT) &&
		    (dest_instruction > 0) &&
		    (strstr
		     (env->vm->instructions[dest_instruction].name,
		      "PREPARE") != NULL))
		  {
		    /* all the INVOKEs */
		    if (strstr (env->vm->instructions[dest_instruction].name,
				"INVOKE") != NULL)
		      {
			curr++;
			_svmf_printf (env, out, "%p [%d]\n", curr,
				      curr->jint);
			curr++;
			_svmf_printf (env, out, "%p [%p]\n", curr,
				      curr->addr);
			curr++;
			_svmf_printf (env, out, "%p [%p]\n", curr,
				      curr->addr);
			curr++;
		      }
		    /* all the PUT<x>, GET<x>, LDC_STRING,  CHECKCAST, INSTANCEOF */
		    else
		      if ((strstr
			   (env->vm->instructions[dest_instruction].name,
			    "PUT") != NULL)
			  ||
			  (strstr
			   (env->vm->instructions[dest_instruction].name,
			    "GET") != NULL)
			  ||
			  (strstr
			   (env->vm->instructions[dest_instruction].name,
			    "LDC_STRING") != NULL)
			  ||
			  (strstr
			   (env->vm->instructions[dest_instruction].name,
			    "CHECKCAST") != NULL)
			  ||
			  (strstr
			   (env->vm->instructions[dest_instruction].name,
			    "INSTANCEOF") != NULL))
		      {
			curr++;
			_svmf_printf (env, out, "%p [%p]\n", curr,
				      curr->addr);
			curr++;
		      }
		    /* MULTIANEWARRAY */
		    else
		      if (strstr
			  (env->vm->instructions[dest_instruction].name,
			   "MULTI") != NULL)
		      {
			curr++;
			_svmf_printf (env, out, "%p [%p]\n", curr,
				      curr->addr);
			curr++;
			_svmf_printf (env, out, "%p [%d]\n", curr,
				      curr->jint);
			curr++;
			_svmf_printf (env, out, "%p [%p]\n", curr,
				      curr->addr);
			curr++;
		      }
		    /* NEW & ANEWARRRAY */
		    else
		      if (strstr
			  (env->vm->instructions[dest_instruction].name,
			   "NEW") != NULL)
		      {
			curr++;
			_svmf_printf (env, out, "%p [%p]\n", curr,
				      curr->addr);
			curr++;
			_svmf_printf (env, out, "%p [%p]\n", curr,
				      curr->addr);
			curr++;
		      }
		  }
		else
		  {
		    curr++;
		  }

#else /*! _SABLEVM_INLINED_THREADED_INTERPRETER */
		{
		  _svmt_mi_sequence_node_info *sequence_tmp = NULL;
		  
		  if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
		    {
		      _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		      curr++;
		    }

/* 		  _svmf_printf (env, out, "%p analysing [%p]\n", curr, curr->addr); */
/* 		    curr++; */
		
/* /\* 		  _svmf_printf (env, stdout, "before while\n");  *\/ */
/* 		  while((_svmf_mi_get_sequence_by_implementation  */
/* 			 (env, curr->implementation) == NULL) && (curr < end)) */
/* 		  { */
/* 		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr); */
/* 		    curr++; */
/* 		  }  */
/* /\* 		_svmf_printf (env, stdout, "after while\n"); *\/ */

	      	
/*  		  _svmf_printf(env, out, "%p: is [%p] a prep seq ?\n", curr, curr->addr); */

		  if(code2 != NULL)
		    {		  
		      if (_svmm_mp_is_preparation_sequence (env,
							    curr->addr, code2 + length2,
							    sequence_tmp))
			{
/* 			  _svmf_printf(env, stderr, "YES prep seq - "); */
/* 			  _svmf_mi_print_super_instruction(env, stderr, sequence_tmp->implementation); */
/* 			  _svmf_printf(env, stderr, "\n"); */
			  sequence = sequence_tmp;
			  instructions = sequence->instructions;
			  instructions_length = sequence->instructions_length;
			  goto process_params;
			}
		      else
			{
/* 			  _svmf_printf(env, stderr, "NO prep seq\n"); */
			  _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
			  curr++;
			}
		    }
		  else
		    {
		      if (_svmm_mp_is_preparation_sequence (env,
							    curr->addr, code + length,
							    sequence_tmp))
			{
/* 			  _svmf_printf(env, stderr, "YES prep seq - "); */
/* 			  _svmf_mi_print_super_instruction(env, stderr, sequence_tmp->implementation); */
/* 			  _svmf_printf(env, stderr, "\n"); */
			  sequence = sequence_tmp;
			  instructions = sequence->instructions;
			  instructions_length = sequence->instructions_length;
			  goto process_params;
			}
		      else
			{
/* 			  _svmf_printf(env, stderr, "NO prep seq\n"); */
			  _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
			  curr++;
			}
		    }
		}
#endif
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	    case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	      {
		in_inlined_code = JNI_TRUE;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
	      {
		in_inlined_code = JNI_TRUE;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_RETURN:
	    case SVM_INSTRUCTION_INLINED_ARETURN:
	    case SVM_INSTRUCTION_INLINED_DRETURN:
	    case SVM_INSTRUCTION_INLINED_FRETURN:
	    case SVM_INSTRUCTION_INLINED_LRETURN:
	    case SVM_INSTRUCTION_INLINED_IRETURN:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		in_inlined_code = JNI_FALSE;
	      }
	      break;

	    case SVM_INSTRUCTION_SKIP:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_TABLESWITCH:
	      {
		jint j, low, high, size;

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		low = curr->jint;
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		high = curr->jint;
		curr++;

		size = high - low + 1;

		for (j = 0; j < size; j++)
		  {
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		  }
	      }
	      break;

	    case SVM_INSTRUCTION_PROFILING_TABLESWITCH:
	      {
		jint j, low, high, size;

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		low = curr->jint;
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		high = curr->jint;
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;

		size = high - low + 1;
		size *= 2;

		for (j = 0; j < size; j += 2)
		  {
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		    curr++;
		  }
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	      {
		jint j, npairs;

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		npairs = curr->jint;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;

		for (j = 0; j < npairs; j++)
		  {
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		    curr++;
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		  }
	      }
	      break;

	    case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH:
	      {
		jint j, npairs;

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		npairs = curr->jint;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;

		for (j = 0; j < npairs; j++)
		  {
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		    curr++;
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		    curr++;
		  }
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_LDC_FLOAT:
	      {
		_svmf_printf (env, out, "%p [%f]\n", curr, curr->jfloat);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_INLINED_IFEQ_CHECK:
	    case SVM_INSTRUCTION_INLINED_IFNE_CHECK:
	    case SVM_INSTRUCTION_INLINED_IFLT_CHECK:
	    case SVM_INSTRUCTION_INLINED_IFGE_CHECK:
	    case SVM_INSTRUCTION_INLINED_IFGT_CHECK:
	    case SVM_INSTRUCTION_INLINED_IFLE_CHECK:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPEQ_CHECK:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPNE_CHECK:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPLT_CHECK:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPGE_CHECK:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPGT_CHECK:
	    case SVM_INSTRUCTION_INLINED_IF_ICMPLE_CHECK:
	    case SVM_INSTRUCTION_INLINED_IF_ACMPEQ_CHECK:
	    case SVM_INSTRUCTION_INLINED_IF_ACMPNE_CHECK:
	    case SVM_INSTRUCTION_INLINED_IFNULL_CHECK:
	    case SVM_INSTRUCTION_INLINED_IFNONNULL_CHECK:
	    case SVM_INSTRUCTION_INLINED_JSR_CHECK:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		
		/* TO CHANGE */
#if 1
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
#else
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
#endif
		curr++;
	      }
	      break;
	      
	    case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		
		/* TO CHANGE */
#if 1
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr->addr);
#else
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
#endif
		curr++;

		_svmf_printf (env, out,
			      "%p [%p] stack_gc_map, end of inlined code\n",
			      curr, curr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_GETSTATIC_BOOLEAN:
	    case SVM_INSTRUCTION_GETSTATIC_BYTE:
	    case SVM_INSTRUCTION_GETSTATIC_SHORT:
	    case SVM_INSTRUCTION_GETSTATIC_CHAR:
	    case SVM_INSTRUCTION_GETSTATIC_INT:
	    case SVM_INSTRUCTION_GETSTATIC_LONG:
	    case SVM_INSTRUCTION_GETSTATIC_FLOAT:
	    case SVM_INSTRUCTION_GETSTATIC_DOUBLE:
	    case SVM_INSTRUCTION_GETSTATIC_REFERENCE:
	    case SVM_INSTRUCTION_PUTSTATIC_BOOLEAN:
	    case SVM_INSTRUCTION_PUTSTATIC_BYTE:
	    case SVM_INSTRUCTION_PUTSTATIC_SHORT:
	    case SVM_INSTRUCTION_PUTSTATIC_CHAR:
	    case SVM_INSTRUCTION_PUTSTATIC_INT:
	    case SVM_INSTRUCTION_PUTSTATIC_LONG:
	    case SVM_INSTRUCTION_PUTSTATIC_FLOAT:
	    case SVM_INSTRUCTION_PUTSTATIC_DOUBLE:
	    case SVM_INSTRUCTION_PUTSTATIC_REFERENCE:
	    case SVM_INSTRUCTION_GETFIELD_BOOLEAN:
	    case SVM_INSTRUCTION_GETFIELD_BYTE:
	    case SVM_INSTRUCTION_GETFIELD_SHORT:
	    case SVM_INSTRUCTION_GETFIELD_CHAR:
	    case SVM_INSTRUCTION_GETFIELD_INT:
	    case SVM_INSTRUCTION_GETFIELD_LONG:
	    case SVM_INSTRUCTION_GETFIELD_FLOAT:
	    case SVM_INSTRUCTION_GETFIELD_DOUBLE:
	    case SVM_INSTRUCTION_GETFIELD_REFERENCE:
	    case SVM_INSTRUCTION_PUTFIELD_BOOLEAN:
	    case SVM_INSTRUCTION_PUTFIELD_BYTE:
	    case SVM_INSTRUCTION_PUTFIELD_SHORT:
	    case SVM_INSTRUCTION_PUTFIELD_CHAR:
	    case SVM_INSTRUCTION_PUTFIELD_INT:
	    case SVM_INSTRUCTION_PUTFIELD_LONG:
	    case SVM_INSTRUCTION_PUTFIELD_FLOAT:
	    case SVM_INSTRUCTION_PUTFIELD_DOUBLE:
	    case SVM_INSTRUCTION_PUTFIELD_REFERENCE:
	    case SVM_INSTRUCTION_LDC_STRING:
	      {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
#else
		if (env->vm->instructions[curr_instruction].flag !=
		    SVM_INTRP_FLAG_INLINEABLE)
		  {
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->addr);
		    curr++;
		  }
		else
		  {
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->addr);
		    curr++;
		  }
#endif
	      }
	      break;

	    case SVM_INSTRUCTION_IFEQ_CHECK:
	    case SVM_INSTRUCTION_IFNE_CHECK:
	    case SVM_INSTRUCTION_IFLT_CHECK:
	    case SVM_INSTRUCTION_IFGE_CHECK:
	    case SVM_INSTRUCTION_IFGT_CHECK:
	    case SVM_INSTRUCTION_IFLE_CHECK:
	    case SVM_INSTRUCTION_IF_ICMPEQ_CHECK:
	    case SVM_INSTRUCTION_IF_ICMPNE_CHECK:
	    case SVM_INSTRUCTION_IF_ICMPLT_CHECK:
	    case SVM_INSTRUCTION_IF_ICMPGE_CHECK:
	    case SVM_INSTRUCTION_IF_ICMPGT_CHECK:
	    case SVM_INSTRUCTION_IF_ICMPLE_CHECK:
	    case SVM_INSTRUCTION_IF_ACMPEQ_CHECK:
	    case SVM_INSTRUCTION_IF_ACMPNE_CHECK:
	    case SVM_INSTRUCTION_JSR_CHECK:
	    case SVM_INSTRUCTION_IFNULL_CHECK:
	    case SVM_INSTRUCTION_IFNONNULL_CHECK:
	    case SVM_INSTRUCTION_CHECKCAST:
	    case SVM_INSTRUCTION_INSTANCEOF:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		break;
	      }

	    case SVM_INSTRUCTION_PROFILING_IFEQ_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IFNE_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IFLT_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IFGE_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IFGT_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IFLE_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPEQ_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPNE_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPLT_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPGE_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPGT_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IF_ICMPLE_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IF_ACMPEQ_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IF_ACMPNE_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IFNULL_CHECK:
	    case SVM_INSTRUCTION_PROFILING_IFNONNULL_CHECK:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	      {
		jint j, low, high, size;

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		low = curr->jint;
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		high = curr->jint;
		curr++;

		size = high - low + 1;

		for (j = 0; j < size; j++)
		  {
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		  }
	      }
	      break;

	    case SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK:
	      {
		jint j, low, high, size;

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		low = curr->jint;
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		high = curr->jint;
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;

		size = high - low + 1;
		size *= 2;

		for (j = 0; j < size; j += 2)
		  {
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		    curr++;
		  }
	      }
	      break;

	    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	      {
		jint j, npairs;

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		npairs = curr->jint;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;

		for (j = 0; j < npairs; j++)
		  {
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		    curr++;
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		  }

	      }
	      break;

	    case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK:
	      {
		jint j, npairs;

		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

		npairs = curr->jint;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;

		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;

		for (j = 0; j < npairs; j++)
		  {
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		    curr++;
		    _svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		    curr++;
		    _svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		    curr++;
		  }

	      }
	      break;

	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BOOLEAN:
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BYTE:
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_SHORT:
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_CHAR:
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_INT:
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_LONG:
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_FLOAT:
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_DOUBLE:
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_REFERENCE:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BOOLEAN:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BYTE:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_SHORT:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_CHAR:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_INT:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_LONG:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_FLOAT:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_DOUBLE:
	    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_REFERENCE:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_BOOLEAN:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_BYTE:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_SHORT:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_CHAR:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_INT:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_LONG:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_FLOAT:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_DOUBLE:
	    case SVM_INSTRUCTION_PREPARE_GETFIELD_REFERENCE:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_BOOLEAN:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_BYTE:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_SHORT:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_CHAR:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_INT:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_LONG:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_FLOAT:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_DOUBLE:
	    case SVM_INSTRUCTION_PREPARE_PUTFIELD_REFERENCE:
	    case SVM_INSTRUCTION_NEW:
	    case SVM_INSTRUCTION_ANEWARRAY:
	    case SVM_INSTRUCTION_PREPARE_NEW:
	    case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
	    case SVM_INSTRUCTION_PREPARE_CHECKCAST:
	    case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
	    case SVM_INSTRUCTION_PREPARE_LDC_STRING:
	    case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
	    case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
	    case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;


	    case SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_PROFILING_INVOKESTATIC:
	    case SVM_INSTRUCTION_PROFILING_INVOKESPECIAL:

	    case SVM_INSTRUCTION_INVOKESTATIC:
	    case SVM_INSTRUCTION_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	    case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;


	    case SVM_INSTRUCTION_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	      {
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;


	    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	      {
		_svmf_printf (env, out, "%p [%d, %p]\n", curr,
			      curr->invoke_info->count,
			      curr->invoke_info->last_method);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_MULTIANEWARRAY:
	    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
		_svmf_printf (env, out, "%p [%d]\n", curr, curr->jint);
		curr++;
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;
	      }
	      break;

	    case SVM_INSTRUCTION_REPLACE:
	      {
		_svmf_printf (env, out, "%p [%p]\n", curr, curr->addr);
		curr++;

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
		curr_instruction = curr->jint;

		assert ((curr_instruction >= 0)
			&& (curr_instruction < SVM_INSTRUCTION_COUNT));

		_svmf_printf (env, out, "%p [%s]\n", curr,
			      env->vm->instructions[curr_instruction].name);
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
		curr_instruction =
		  _svmf_mi_get_instruction_int_code (env,
						     curr->implementation);

		assert ((curr_instruction >= 0)
			&& (curr_instruction < SVM_INSTRUCTION_COUNT));

		_svmf_printf (env, out, "%p [%s]\n", curr,
			      env->vm->instructions[curr_instruction].name);
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		{
		  /* print super instruction bytecodes */
		  _svmf_printf (env, out, "%p ", curr);
		  _svmf_mi_print_super_instruction (env, out,
						    curr->implementation);
		  _svmf_printf (env, out, "\n");
		}
#endif
		curr++;
	      }
	      break;

	    default:
	      {
		/* bytecode has no parameters */
	      }
	      break;

	    }			/* end of switch */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

	}			/* end of for */
#endif

    }				/* end of while */
  _svmf_printf (env, out, "\n");
}


/*
----------------------------------------------------------------------
_svmf_mi_debug_on_dispatch
----------------------------------------------------------------------
*/
svm_static void SVM_UNUSED
_svmf_mi_debug_on_dispatch (_svmt_JNIEnv *env, jint stack_size,
			    _svmt_code *pc, const char *codename)
{

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  pc--;
#endif

  /* debugging using instruction counter */
  env->vm->mi_info.inst_count++;

  assert (codename != NULL);
  
/*   _svmf_mi_print_bytecode_count (env, pc, codename, stack_size); */
  
/*   if (env->vm->mi_info.inst_count_times >= 3) */
/*     { */
/*       _svmf_mi_print_bytecode_count (env, pc, codename, stack_size); */
/*     } */
  
  if (env->vm->mi_info.inst_count > 50000000)
    {
      env->vm->mi_info.inst_count = 0;
      env->vm->mi_info.inst_count_times++;
      _svmf_mi_print_bytecode_count (env, pc, codename, stack_size);
    }

#if 1
  if ((env->vm->mi_info.inst_count_times >= 13) &&
      (env->vm->mi_info.inst_count >= 41128700))
    {                               
      /*      env->vm->verbose_gc = JNI_TRUE; */
      env->vm->verbose_methods = JNI_TRUE;
      env->vm->verbose_instructions = JNI_TRUE;
/* 	env->vm->mi_info.show_instructions = JNI_TRUE; */

      _svmf_mi_print_bytecode_count(env, pc, codename, stack_size);

/* 	_svmf_print_method_name(env, stderr, */
/* 				env->stack.current_frame->method_frame_info->method, ""); */

/*   	_svmf_dump_stack_trace (env); */
/* 	_svmf_printf (env, stderr, "\n"); */

      /*      _svmf_mi_segfault(); */
    }

  if ((env->vm->mi_info.inst_count_times >= 59) &&
      (env->vm->mi_info.inst_count >= 81289085))
    {
/*       _svmt_code *code = */
/* 	env->stack.current_frame->method_frame_info->normal_code; */
/*       jint length = env->stack.current_frame->method_frame_info->code_length; */


/*       _svmf_print_method_name (env, stderr, */
/* 			       env->stack.current_frame->method_frame_info-> */
/* 			       method, "normal code"); */

/*       _svmf_mi_output_code_array (env, stderr, code, length, "", NULL); */
      /*      _svmf_mi_segfault(); */
    }

#endif

  if (env->vm->mi_info.show_instructions == JNI_TRUE)
    {

      /*     _svmt_method_info *method = env->stack.current_frame->method_frame_info->method; */

      /*     _svmf_printf(env, stderr, "[%s.%s] stack_size[%d] max_size[%d] pc[%p] [%s]\n", */
      /*           env->stack.current_frame->method_frame_info->method->class_info->name, */
      /*           DREF (env->stack.current_frame->method_frame_info->method->name, value), */
      /*           stack_size, */
      /*           env->stack.current_frame->method_frame_info->method->data.code_attribute->max_stack, */
      /*           pc, env->vm->instructions[pc->jint].name); */

      /*     _svmf_printf(env, stderr, "[%s.%s] pc[%p] [%s]\n", */
      /*           env->stack.current_frame->method_frame_info->method->class_info->name, */
      /*           DREF (env->stack.current_frame->method_frame_info->method->name, value), */
      /*           pc, env->vm->instructions[pc->jint].name); */

      _svmf_mi_print_bytecode_count (env, pc, codename, stack_size);

/*     _svmf_printf(env, stderr, "stack_size[%d] pc[%p][%p] [%s]\n", */
/* 		 stack_size, pc, pc->implementation, codename); */

      /*     _svmf_print_method_name(env, stderr, method, ""); */

      /*     _svmf_mi_output_code_array (env, */
      /*                          stdout, */
      /*                          method->frame_info->normal_code, */
      /*                          method->frame_info->code_length, */
      /*                          "CODE"); */

/*     _svmf_dump_stack_trace (env); */
/*     _svmf_printf(env, stderr, "\n"); */
    }

  assert (*(env->throwable) == NULL);

#if 1
  if (stack_size < 0)
    {
      _svmf_printf (env, stderr, "[%s.%s] stack_size[%d] pc[%p] [%s]\n",
		    env->stack.current_frame->method_frame_info->method->
		    class_info->name,
		    DREF (env->stack.current_frame->method_frame_info->
			  method->name, value), stack_size, pc, codename);
      _svmf_printf (env, stderr, "ASSERT failed in Method [%s.%s]\n",
		    env->stack.current_frame->method_frame_info->method->
		    class_info->name,
		    DREF (env->stack.current_frame->method_frame_info->
			  method->name, value));

      _svmf_mi_print_bytecode_count (env, pc, codename, stack_size);

      _svmf_mi_output_code_array (env,
				  stdout,
				  env->stack.current_frame->method_frame_info->normal_code,
				  env->stack.current_frame->method_frame_info->code_length,
				  "NORMAL FAILING: ", NULL, 0);
      _svmf_dump_stack_trace (env);
    }
#endif

  assert (stack_size >= 0);

  assert (stack_size == 0 ||
	  env->stack.current_frame->method_frame_info->method ==
	  &env->vm->internal_call_method
	  || env->stack.current_frame->method_frame_info->method ==
	  &env->vm->vm_initiated_call_method
	  || stack_size <=
	  env->stack.current_frame->method_frame_info->method->data.
	  code_attribute->max_stack);


#if 1
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  if (env->stack.current_frame->method_frame_info->code_length > 0)
#else
  if ((env->stack.current_frame->method_frame_info->code_length > 0) &&
      (strcmp (codename, "NEXT") != 0))
#endif
    {
      _svmt_method_frame_info *finfo =
	env->stack.current_frame->method_frame_info;

      if (finfo->has_been_inlined == JNI_FALSE)
	{
	  if ((finfo->profiling_status == SVM_METHOD_PROFILING_NOT_STARTED) ||
	      (finfo->profiling_status == SVM_METHOD_PROFILING_FINISHED))
	    {
	      if ((pc < finfo->code)
		  || (pc >= (finfo->code + finfo->code_length)))
		{
		  _svmf_mi_print_bytecode_count (env, pc, codename, stack_size);

		  _svmf_print_method_name (env, stderr, finfo->method, "");

		  _svmf_printf (env, stderr, "code[%p] code_end[%p]\n",
				finfo->code,
				finfo->code + finfo->code_length);

		  _svmf_printf (env, stderr,
				"ASSERT: [%s.%s] control flow is outside normal code, stack_size[%d] pc[%p] [%s]\n",
				finfo->method->class_info->name,
				DREF (finfo->method->name, value), stack_size,
				pc, codename);
		  
		  if ((pc >= finfo->profiling_code)
		      && (pc < (finfo->profiling_code + finfo->profiling_code_length)))
		    {
		      _svmf_printf (env, stderr, "pc[%p] is inside profiling code\n", pc);
		      _svmf_mi_output_code_array (env,
						  stdout,
						  finfo->normal_code,
						  finfo->code_length,
						  "NORMAL CODE: ", NULL, 0);
		      _svmf_mi_output_code_array (env,
						  stdout,
						  finfo->profiling_code,
						  finfo->profiling_code_length,
						  "PROFILING CODE: ", NULL, 0);

		    }

		  _svmf_dump_stack_trace (env);
		  _svmf_printf (env, stderr, "\n");
		  exit(1);

		  
		}
	    }
	  else if (finfo->profiling_status == SVM_METHOD_PROFILING_STARTED)
	    {
	      if ((pc < finfo->code)
		  || (pc >= (finfo->code + finfo->profiling_code_length)))
		{
		  _svmf_mi_print_bytecode_count (env, pc, codename, stack_size);
		  _svmf_printf (env, stderr,
				"ASSERT: [%s.%s] control flow outside profiling code, stack_size[%d] pc[%p] [%s]\n",
				finfo->method->class_info->name,
				DREF (finfo->method->name, value), stack_size,
				pc, codename);

		  if ((pc >= finfo->normal_code)
		      && (pc < (finfo->normal_code + finfo->code_length)))
		    {
		      _svmf_printf (env, stderr, "pc[%p] is inside normal code\n", pc);
		      _svmf_mi_output_code_array (env,
						  stdout,
						  finfo->normal_code,
						  finfo->code_length,
						  "NORMAL CODE: ", NULL, 0);
		      _svmf_mi_output_code_array (env,
						  stdout,
						  finfo->profiling_code,
						  finfo->profiling_code_length,
						  "PROFILING CODE: ", NULL, 0);
		    }
		  exit(1);
		}
	    }
	}
    }
#endif


#if 0
  if (env->stack.current_frame->method_frame_info->method->class_info != NULL)
    {
      if ((strcmp
	   (env->stack.current_frame->method_frame_info->method->class_info->
	    name, "HelloWorld")) == 0
	  &&
	  (strcmp
	   (DREF
	    (env->stack.current_frame->method_frame_info->method->name,
	     value), "m1") == 0))
	{
	  _svmf_printf (env, stderr,
			"<-> [%s.%s]  stack_size[%d] pc[%p] [%s]\n",
			env->stack.current_frame->method_frame_info->method->
			class_info->name,
			DREF (env->stack.current_frame->method_frame_info->
			      method->name, value), stack_size, pc,
			env->vm->instructions[pc->jint].name);

/* 	  if(env->stack.current_frame->method_frame_info->profiling_code != NULL) */
/* 	    { */
/* 	      env->vm->mi_info.debug_method = env->stack.current_frame->method_frame_info->method; */
/* 	      _svmf_mi_output_code_array (env, */
/* 					  stdout, */
/* 					  env->stack.current_frame->method_frame_info->profiling_code, */
/* 					  env->stack.current_frame->method_frame_info->profiling_code_length, */
/* 					  "\njava/util/AbstractMap.equals (profiling)\n"); */
/* 	    } */

/*  	  _svmf_dump_stack_trace (env);_svmf_printf (env, stderr, "\n"); */
	}
    }
#endif

}


#endif /* NDEBUG */
