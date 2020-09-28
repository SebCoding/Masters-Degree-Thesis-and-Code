/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "method_inlining.h"


/* method profiling default values */
#define SVM_METHOD_PROFILING_START_THRESHOLD 15
#define SVM_METHOD_PROFILING_STOP_THRESHOLD  20

/*
----------------------------------------------------------------------
_svmf_mp_method_profiling_init_defaults
----------------------------------------------------------------------
*/
svm_static void
_svmf_mp_method_profiling_init_defaults (_svmt_JavaVM *vm)
{
  vm->mi_info.method_profiling_start_threshold =
    SVM_METHOD_PROFILING_START_THRESHOLD;
  vm->mi_info.method_profiling_stop_threshold =
    SVM_METHOD_PROFILING_STOP_THRESHOLD;
}

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

/*
----------------------------------------------------------------------
_svmh_mp_is_preparation_sequence
----------------------------------------------------------------------
*/

#define _svmm_mp_is_preparation_sequence(a, b, c, d) \
_svmh_mp_is_preparation_sequence(a, b, c, &d)

svm_static jboolean
_svmh_mp_is_preparation_sequence (_svmt_JNIEnv *env,
				  _svmt_code *begin_addr,
				  _svmt_code *code_end_addr,
				  _svmt_mi_sequence_node_info ** sequence)
{
  _svmt_code *code = begin_addr; /* beginning of the potential preparation sequence */
  _svmt_mi_sequence_node_info *curr_seq;
/*   _svmt_method_frame_info *frame_info = method->frame_info; */

  jint *instructions;
  jint instructions_length;

  jboolean seen_prepare_bytecode = JNI_FALSE;
  jboolean seen_replace_bytecode = JNI_FALSE;
  
/*   _svmf_printf(env, stderr, "\n_svmh_mp_is_preparation_sequence:\n"); */
/*   _svmf_printf(env, stderr, "prep_seq begin addr [%p] end of array[%p]\n", */
/* 	       begin_addr, code_end_addr); */

  assert(code < code_end_addr);

  /* 
     To be a preparation sequence: 
     - The sequences contained in the part of the code array that we will 
     inspected must all be of size 1
     - We must encounter a bytecode PREPARATION<X> before the next branching
     of goto bytecode or the end of the code array
     - The sequence associated with the preparation sequenece will be given
     by one of the parameters of the REPLACE bytecode following the last
     PREPARE<X> byutecode of the preparation sequence 
   */

  while (code < code_end_addr)
    {
      curr_seq = _svmf_mi_get_sequence_by_implementation (env, code->
							  implementation);
/*       assert (curr_seq != NULL); */
      if(curr_seq == NULL)
	{
	  return JNI_FALSE;
	}

      instructions = curr_seq->instructions;
      instructions_length = curr_seq->instructions_length;

      if (instructions_length != 1)
	{
/* 	  _svmf_printf(env, stderr, "[%p] not a prep seq 1\n", begin_addr); */
	  return JNI_FALSE;
	}

      assert ((instructions[0] >= 0) &&
	      (instructions[0] < SVM_INSTRUCTION_COUNT));

      code++;

/*       _svmf_printf(env, stderr, "instruction[%s]\n", */
/* 		   env->vm->instructions[instructions[0]].name); */
      
      switch (instructions[0])
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
	case SVM_INSTRUCTION_LDC_FLOAT:
	case SVM_INSTRUCTION_LDC_LONG:
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
	case SVM_INSTRUCTION_JSR:
	  {
	    code++;
	    break;
	  }

	case SVM_INSTRUCTION_IINC:
	case SVM_INSTRUCTION_JSR_CHECK:
	  {
	    code += 2;
	    break;
	  }

	  /* prepare bytecode */
	case SVM_INSTRUCTION_PREPARE_LDC_STRING:
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
	case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
	case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
	case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
	case SVM_INSTRUCTION_PREPARE_NEW:
	case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
	case SVM_INSTRUCTION_PREPARE_CHECKCAST:
	case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
	  {
	    seen_prepare_bytecode = JNI_TRUE;
	    code += 3;
	    break;
	  }

	case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	  {
	    seen_prepare_bytecode = JNI_TRUE;
	    code += 4;
	    break;
	  }

	case SVM_INSTRUCTION_REPLACE:
	  {
	    assert (seen_prepare_bytecode == JNI_TRUE);
	    seen_replace_bytecode = JNI_TRUE;
	    code++;

	    *sequence = _svmf_mi_get_sequence_by_implementation (env, code->
								 implementation);
	    assert (*sequence != NULL);
	    code++;
	    break;
	  }

	  /* branch or jump */
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
	case SVM_INSTRUCTION_PROFILING_TABLESWITCH:
	case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH:

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
	case SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK:
	case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK:

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
	case SVM_INSTRUCTION_IFNULL:
	case SVM_INSTRUCTION_IFNONNULL:
	case SVM_INSTRUCTION_TABLESWITCH:
	case SVM_INSTRUCTION_LOOKUPSWITCH:
	case SVM_INSTRUCTION_GOTO:
	case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:

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
	case SVM_INSTRUCTION_IFNULL_CHECK:
	case SVM_INSTRUCTION_IFNONNULL_CHECK:
	case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	case SVM_INSTRUCTION_GOTO_CHECK:
	case SVM_INSTRUCTION_ATHROW:
	case SVM_INSTRUCTION_RET:
	  {
	    if (seen_prepare_bytecode && seen_replace_bytecode)
	      {
/* 		_svmf_printf(env, stderr, "result: YES\n"); */
		return JNI_TRUE;
	      }
	    else
	      {
/*  		_svmf_printf(env, stderr, "result: NO\n"); */
		return JNI_FALSE;
	      }
	    break;
	  }

	  /* never contained in a preparation sequence */
	case SVM_INSTRUCTION_PROFILING_INVOKESPECIAL:
	case SVM_INSTRUCTION_PROFILING_INVOKESTATIC:
	case SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE:
	case SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	case SVM_INSTRUCTION_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INVOKESPECIAL:
	case SVM_INSTRUCTION_INVOKESTATIC:
	case SVM_INSTRUCTION_INVOKEINTERFACE:

	case SVM_INSTRUCTION_IRETURN:
	case SVM_INSTRUCTION_LRETURN:
	case SVM_INSTRUCTION_FRETURN:
	case SVM_INSTRUCTION_DRETURN:
	case SVM_INSTRUCTION_ARETURN:
	case SVM_INSTRUCTION_RETURN:

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
	case SVM_INSTRUCTION_INLINED_RET:
	case SVM_INSTRUCTION_INLINED_JSR:
	case SVM_INSTRUCTION_INLINED_GOTO:
	case SVM_INSTRUCTION_INLINED_IRETURN:
	case SVM_INSTRUCTION_INLINED_LRETURN:
	case SVM_INSTRUCTION_INLINED_FRETURN:
	case SVM_INSTRUCTION_INLINED_DRETURN:
	case SVM_INSTRUCTION_INLINED_ARETURN:
	case SVM_INSTRUCTION_INLINED_RETURN:
	case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
	case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
	case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
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
	case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:

	case SVM_INSTRUCTION_LDC_STRING:
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
	case SVM_INSTRUCTION_NEW:
	case SVM_INSTRUCTION_ANEWARRAY:
	case SVM_INSTRUCTION_MULTIANEWARRAY:
	case SVM_INSTRUCTION_CHECKCAST:
	case SVM_INSTRUCTION_INSTANCEOF:
	  {
/* 	    _svmf_printf(env, stderr, "[%p] not a prep seq 3\n", begin_addr); */
/* 	    _svmf_printf(env, stderr, "result: NO\n"); */
	    return JNI_FALSE;
	  }

	default:
	  {
	    /* bytecode with no params */
	  }

	}			/* end of switch */
    }				/* end of while */

/*   _svmf_printf(env, stderr, "[%p] not a prep seq 4\n", begin_addr); */
/*   _svmf_printf(env, stderr, "result: NO\n"); */
  return JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmh_mp_get_sequence_profiling_version
----------------------------------------------------------------------
*/

#define _svmm_mp_get_sequence_profiling_version(env, sequence, result) \
_svmh_mp_get_sequence_profiling_version(env, sequence, &result)

svm_static jint
_svmh_mp_get_sequence_profiling_version (_svmt_JNIEnv *env,
					 _svmt_mi_sequence_node_info *
					 sequence,
					 _svmt_mi_sequence_node_info **
					 p_result)
{
  _svmt_JavaVM *vm = env->vm;

  jint i;
  jint *instructions;
  jint *prof_instructions;
  jint instructions_length;

  size_t implementation_length;
  _svmt_mi_sequence_node_info *prof_sequence;
  jboolean seq_needs_modifications = JNI_FALSE;

  assert (sequence != NULL);

  if (sequence->profiling_version != NULL)
    {
      *p_result = sequence->profiling_version;
      return JNI_OK;
    }

  instructions = sequence->instructions;
  instructions_length = sequence->instructions_length;
  implementation_length = sequence->implementation_length;

  /* check if the sequence needs to be modified */
  for (i = 0; i < instructions_length; i++)
    {
      switch (instructions[i])
	{

	case SVM_INSTRUCTION_PROFILING_TABLESWITCH:
	case SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK:
	case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH:
	case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK:
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
	case SVM_INSTRUCTION_PROFILING_INVOKESPECIAL:
	case SVM_INSTRUCTION_PROFILING_INVOKESTATIC:
	case SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE:
	case SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL:
	  {
	    /* TO DO ... What should we do ? */
	    assert (1 == 0);
	    break;
	  }

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
	case SVM_INSTRUCTION_IFNULL:
	case SVM_INSTRUCTION_IFNONNULL:
	case SVM_INSTRUCTION_TABLESWITCH:
	case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	case SVM_INSTRUCTION_LOOKUPSWITCH:
	case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	  {
	    seq_needs_modifications = JNI_TRUE;

	    /* end the loop */
	    i = instructions_length;

	    break;
	  }
	}
    }

  /* Here we assume that if one of these bytecodes if inlineable then its
     profiling counter part will also be inlineable since they only differ
     in their implementation by a counter implementation.

	IFEQ	--> PROFILING_IFEQ
	IFNE	--> PROFILING_IFNE
	IFLT	--> PROFILING_IFLT
	IFGE	--> PROFILING_IFGE
	IFGT	--> PROFILING_IFGT
	IFLE	--> PROFILING_IFLE
	IF_ICMPEQ	--> PROFILING_IF_ICMPEQ
	IF_ICMPNE	--> PROFILING_IF_ICMPNE
	IF_ICMPLT	--> PROFILING_IF_ICMPLT
	IF_ICMPGE	--> PROFILING_IF_ICMPGE
	IF_ICMPGT	--> PROFILING_IF_ICMPGT
	IF_ICMPLE	--> PROFILING_IF_ICMPLE
	IF_ACMPEQ	--> PROFILING_IF_ACMPEQ
	IF_ACMPNE	--> PROFILING_IF_ACMPNE
	IFNULL	        --> PROFILING_IFNULL
	IFNONNULL	--> PROFILING_IFNONNULL
	TABLESWITCH	--> PROFILING_TABLESWITCH
	TABLESWITCH_CHECK	--> PROFILING_TABLESWITCH_CHECK
	LOOKUPSWITCH	        --> PROFILING_LOOKUPSWITCH
	LOOKUPSWITCH_CHECK	--> PROFILING_LOOKUPSWITCH_CHECK
	COUNTING_INVOKEVIRTUAL	--> PROFILING_INVOKEVIRTUAL
	COUNTING_INVOKESPECIAL	--> PROFILING_INVOKESPECIAL
	COUNTING_INVOKESTATIC	--> PROFILING_INVOKESTATIC
	COUNTING_INVOKEINTERFACE --> PROFILING_INVOKEINTERFACE

	This assumption is enforced by asserts in the code.
  */

  if (seq_needs_modifications)
    {
      if (_svmm_gmalloc_ints
	  (env, instructions_length, prof_instructions) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < instructions_length; i++)
	{	  
	  switch (instructions[i])
	    {
	    case SVM_INSTRUCTION_IFEQ:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IFEQ].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IFEQ;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IFEQ].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IFEQ].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IFNE:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IFNE].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IFNE;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IFNE].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IFNE].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IFLT:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IFLT].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IFLT;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IFLT].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IFLT].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IFGE:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IFGE].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IFGE;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IFGE].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IFGE].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IFGT:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IFGT].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IFGT;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IFGT].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IFGT].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IFLE:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IFLE].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IFLE;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IFLE].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IFLE].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IF_ICMPEQ:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPEQ].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IF_ICMPEQ;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IF_ICMPEQ].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPEQ].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IF_ICMPNE:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPNE].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IF_ICMPNE;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IF_ICMPNE].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPNE].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IF_ICMPLT:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPLT].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IF_ICMPLT;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IF_ICMPLT].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPLT].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IF_ICMPGE:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPGE].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IF_ICMPGE;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IF_ICMPGE].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPGE].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IF_ICMPGT:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPGT].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IF_ICMPGT;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IF_ICMPGT].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPGT].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IF_ICMPLE:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPLE].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IF_ICMPLE;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IF_ICMPLE].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPLE].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IF_ACMPEQ:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ACMPEQ].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IF_ACMPEQ;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IF_ACMPEQ].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ACMPEQ].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IF_ACMPNE:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ACMPNE].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IF_ACMPNE;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IF_ACMPNE].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IF_ACMPNE].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IFNULL:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IFNULL].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IFNULL;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IFNULL].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IFNULL].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_IFNONNULL:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_IFNONNULL].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_IFNONNULL;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_IFNONNULL].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_IFNONNULL].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_TABLESWITCH:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_TABLESWITCH].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_TABLESWITCH;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_TABLESWITCH].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_TABLESWITCH].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] =
		  SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_TABLESWITCH_CHECK].
		  inlined_size;
		implementation_length +=
		  vm->
		  instructions[SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_LOOKUPSWITCH].inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] =
		  SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_LOOKUPSWITCH_CHECK].
		  inlined_size;
		implementation_length +=
		  vm->
		  instructions[SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] =
		  SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL].
		  inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_INVOKESPECIAL].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] =
		  SVM_INSTRUCTION_PROFILING_INVOKESPECIAL;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_COUNTING_INVOKESPECIAL].
		  inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_INVOKESPECIAL].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_INVOKESTATIC].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] = SVM_INSTRUCTION_PROFILING_INVOKESTATIC;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_COUNTING_INVOKESTATIC].
		  inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_INVOKESTATIC].
		  inlined_size;
		break;
	      }
	    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	      {
#ifndef NDEBUG
		if(instructions_length > 1)
		  {
		    assert(vm->instructions[SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE].flag 
			   == SVM_INTRP_FLAG_INLINEABLE);
		  }
#endif
		prof_instructions[i] =
		  SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE;
		implementation_length -=
		  vm->instructions[SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE].
		  inlined_size;
		implementation_length +=
		  vm->instructions[SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE].
		  inlined_size;
		break;
	      }

	    default:
	      {
		prof_instructions[i] = instructions[i];
	      }
	    }			/* end of switch */
	}			/* end of for loop */


      if (instructions_length == 1)
	{
	  if ((prof_sequence =
	       _svmf_mi_get_sequence_by_implementation (env,
							env->vm->
							instructions
							[prof_instructions
							 [0]].code.
							implementation)) ==
	      NULL)
	    {
	      return JNI_ERR;
	    }
	}
      else
	{
	  if (_svmm_mi_get_sequence
	      (env, prof_instructions, instructions_length,
	       implementation_length, prof_sequence, 
	       sequence->starts_with_skip) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }				/* end of if(seq_needs_modifications) */
  else
    {
      prof_sequence = sequence;
    }

  sequence->profiling_version = prof_sequence;
  *p_result = prof_sequence;

  return JNI_OK;
}
#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */

/*
  ----------------------------------------------------------------------
  _svmf_mp_build_profiling_code_array
  ----------------------------------------------------------------------
*/

svm_static jint
_svmf_mp_build_profiling_code_array (_svmt_JNIEnv *env,
				     _svmt_method_info *method)
{
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  _svmt_JavaVM *vm = env->vm;
#endif

  size_t i = 0;			/* index in the non profiling code */
  _svmt_code *code;		/* non profiling code array */
  _svmt_code *profiling_code;	/* profiling code array */

  size_t code_length;		/* non profiling code length */
  size_t profiling_code_length;	/* profiling code length */

  jint *offsets;
  _svmt_method_frame_info *frame_info = method->frame_info;

/*   _svmf_printf(env, stderr, "_svmf_mp_build_profiling_code_array:\n"); */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  jint inst;
  jint last_sequence_index;
  jint instructions_length;
  jint *instructions;
  jboolean skipping_goto_prep_seq_params = JNI_FALSE;
  _svmt_mi_sequence_node_info *goto_seq = NULL;
  _svmt_mi_sequence_node_info *last_sequence;
  size_t prep_seq_offset = frame_info->preparation_sequences_offset;
#endif

/*   _svmf_printf (env, stderr, "_svmf_mp_build_profiling_code_array:\n"); */

  code = frame_info->code;
  code_length = frame_info->code_length;
  profiling_code_length = frame_info->profiling_code_length;

  /* allocate profiling code array */
  if (_svmm_cl_malloc_code (env, method->class_info->class_loader_info,
			    profiling_code_length, profiling_code) != JNI_OK)
    {
      _svmf_printf (env, stderr, "method profiling: memory alloc failed\n");
      return JNI_ERR;
    }
  frame_info->profiling_code = profiling_code;

  /* allocate offsets code array */
  if ((offsets = _svmm_malloc (code_length * sizeof (jint))) == NULL)
    {
      _svmf_printf (env, stderr, "method profiling: memory alloc failed\n");
      return JNI_ERR;
    }
  frame_info->mp_offsets = offsets;

  /* Copy code array into profiling code array and replace branching bytecodes
     by profiling branching bytecodes */
  {

    size_t j = 0;		/* index in the profiling code */
    jint curr_instruction;

    while (i < code_length)
      {
#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
	curr_instruction = code[i].jint;

	profiling_code[j] = code[i];
	offsets[i++] = j++;
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
	curr_instruction =
	  _svmf_mi_get_instruction_int_code (env, code[i].implementation);

	profiling_code[j] = code[i];
	offsets[i++] = j++;
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

	last_sequence_index = i;

/* 	_svmf_printf (env, stderr, "analysing sequence at[%p] i[%d] j[%d]\n", */
/* 		      code + i, i, j); */

	if ((last_sequence =
	     _svmf_mi_get_sequence_by_implementation (env,
						      code[i].
						      implementation)) ==
	    NULL)
	  {
	    assert (1 == 0);
	    return JNI_ERR;
	  }

	instructions = last_sequence->instructions;
	instructions_length = last_sequence->instructions_length;

/* 	_svmf_printf(env, stderr, "copying: %p profiling_code=", profiling_code+j); */
/* 	_svmf_mi_print_super_instruction(env, stderr, last_sequence->implementation); */
/* 	_svmf_printf(env, stderr, "\n"); */

	profiling_code[j] = code[i];
	offsets[i++] = j++;

	/* Used for GOTO that has multiple parameters,
	   if it jumps to a preparation sequence */
      copy_params:

	if (last_sequence->starts_with_skip)
	  {
	    profiling_code[j] = code[i];
	    offsets[i++] = j++;
	  }

	for (inst = 0; inst < instructions_length; inst++)
	  {
	    curr_instruction = instructions[inst];
#endif

/* 	    _svmf_printf(env, stderr, "%p curr_instruction[%s] i[%d] j[%d]\n",  */
/* 			 code+last_sequence_index, env->vm->instructions[curr_instruction].name, i, j); */

	    assert ((curr_instruction >= 0) &&
		    (curr_instruction < SVM_INSTRUCTION_COUNT));

	    /* NOTE: We need to keep the offset for every parameter too to be able 
	       to fix the profiling exception table properly */

	    switch (curr_instruction)
	      {
	      case SVM_INSTRUCTION_ILOAD:
	      case SVM_INSTRUCTION_FLOAD:
	      case SVM_INSTRUCTION_ISTORE:
	      case SVM_INSTRUCTION_FSTORE:
	      case SVM_INSTRUCTION_RET:
	      case SVM_INSTRUCTION_ASTORE_RET:
	      case SVM_INSTRUCTION_LLOAD:
	      case SVM_INSTRUCTION_DLOAD:
	      case SVM_INSTRUCTION_LSTORE:
	      case SVM_INSTRUCTION_DSTORE:
	      case SVM_INSTRUCTION_ALOAD:
	      case SVM_INSTRUCTION_ASTORE:
	      case SVM_INSTRUCTION_JSR:

	      case SVM_INSTRUCTION_LDC_INTEGER:
	      case SVM_INSTRUCTION_LDC_FLOAT:
	      case SVM_INSTRUCTION_LDC_LONG:
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
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      case SVM_INSTRUCTION_IINC:
	      case SVM_INSTRUCTION_CHECKCAST:
	      case SVM_INSTRUCTION_INSTANCEOF:

	      case SVM_INSTRUCTION_JSR_CHECK:

		/* we don't profile backward branching */
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
	      case SVM_INSTRUCTION_IFNULL_CHECK:
	      case SVM_INSTRUCTION_IFNONNULL_CHECK:

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
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      case SVM_INSTRUCTION_INLINED_IRETURN:
	      case SVM_INSTRUCTION_INLINED_LRETURN:
	      case SVM_INSTRUCTION_INLINED_FRETURN:
	      case SVM_INSTRUCTION_INLINED_DRETURN:
	      case SVM_INSTRUCTION_INLINED_ARETURN:
	      case SVM_INSTRUCTION_INLINED_RETURN:
		{
		  /* end of inlined code, skip final stack_gc_map */
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      case SVM_INSTRUCTION_INLINED_RET: 
	      case SVM_INSTRUCTION_INLINED_GOTO:
		{
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;

		  /* end of inlined code, skip final stack_gc_map */
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
		{
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  
		  /* end of inlined code, skip final stack_gc_map */
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      case SVM_INSTRUCTION_REPLACE:
		{
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

		  /* convert sequence to profiling sequence,
		     the sequence might end with a branching 
		     bytecode */

		  _svmt_mi_sequence_node_info *prof_seq;
		  _svmt_mi_sequence_node_info *normal_seq;

		  if ((normal_seq =
		       _svmf_mi_get_sequence_by_implementation (env,
								code[i].
								implementation))
		      == NULL)
		    {
		      assert (1 == 0);
		      return JNI_ERR;
		    }


		  if (_svmm_mp_get_sequence_profiling_version
		      (env, normal_seq, prof_seq) != JNI_OK)
		    {
		      assert (1 == 0);
		      return JNI_ERR;
		    }

		  profiling_code[j].implementation = prof_seq->implementation;
		  offsets[i++] = j++;
#else
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
#endif
		  break;
		}

		/* target is never a prep. seq. (backward jump) */
	      case SVM_INSTRUCTION_GOTO_CHECK:
		{
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;

		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}


	      case SVM_INSTRUCTION_GOTO:

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	      case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
#endif
		{
		  profiling_code[j] = code[i];
		  offsets[i] = j;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
		  curr_instruction = (code[i].addr)->jint;
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
		  curr_instruction =
		    _svmf_mi_get_instruction_int_code (env,
						       (code[i].addr)->
						       implementation);
#endif

		  /*                    printf("*curr_instruction[%d]\n", curr_instruction); */

		  assert ((curr_instruction < SVM_INSTRUCTION_COUNT)
			  && (curr_instruction > 0));

		  /* goto preparation sequence */
		  switch (curr_instruction)
		    {
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
		    case SVM_INSTRUCTION_PREPARE_LDC_STRING:
		      {
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			break;
		      }

		    case SVM_INSTRUCTION_PREPARE_CHECKCAST:
		    case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
		      {
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			break;
		      }

		    case SVM_INSTRUCTION_PREPARE_NEW:
		    case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
		      {
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			break;
		      }

		    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
		    case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
		    case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
		    case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
		    case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
		      {
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			profiling_code[j] = code[i];
			offsets[i++] = j++;
			break;
		      }

		    default:	/* not a preparation sequence */
		      {
			i++;
			j++;
		      }
		    }		/* end of inner switch */
#else
		  /* _SABLEVM_INLINED_THREADED_INTERPRETER */
		  {
		    _svmt_mi_sequence_node_info *seq_ptr_copy = last_sequence;
		    
		    if (_svmm_mp_is_preparation_sequence
			(env, code[i].addr, code + code_length,
			 last_sequence))
		      {
			goto_seq = seq_ptr_copy;
			skipping_goto_prep_seq_params = JNI_TRUE;
			instructions = last_sequence->instructions;
			instructions_length =
			  last_sequence->instructions_length;
			goto copy_params;
		      }
		    else
		      {
			i++;
			j++;
		      }
		  }
#endif /* !_SABLEVM_INLINED_THREADED_INTERPRETER */

		  break;
		}

		/* We will be profiling these, so we add counters */
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
	      case SVM_INSTRUCTION_IFNULL:
	      case SVM_INSTRUCTION_IFNONNULL:
		{
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER

		      switch (curr_instruction)
			{
			case SVM_INSTRUCTION_IFEQ:
			  {
			    profiling_code[j - 1] =
			      vm->instructions[SVM_INSTRUCTION_PROFILING_IFEQ].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IFNE:
			  {
			    profiling_code[j - 1] =
			      vm->instructions[SVM_INSTRUCTION_PROFILING_IFNE].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IFLT:
			  {
			    profiling_code[j - 1] =
			      vm->instructions[SVM_INSTRUCTION_PROFILING_IFLT].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IFGE:
			  {
			    profiling_code[j - 1] =
			      vm->instructions[SVM_INSTRUCTION_PROFILING_IFGE].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IFGT:
			  {
			    profiling_code[j - 1] =
			      vm->instructions[SVM_INSTRUCTION_PROFILING_IFGT].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IFLE:
			  {
			    profiling_code[j - 1] =
			      vm->instructions[SVM_INSTRUCTION_PROFILING_IFLE].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IF_ICMPEQ:
			  {
			    profiling_code[j - 1] =
			      vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPEQ].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IF_ICMPNE:
			  {
			    profiling_code[j - 1] =
			      vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPNE].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IF_ICMPLT:
			  {
			    profiling_code[j - 1] =
			      vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPLT].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IF_ICMPGE:
			  {
			    profiling_code[j - 1] =
			      vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPGE].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IF_ICMPGT:
			  {
			    profiling_code[j - 1] =
			      vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPGT].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IF_ICMPLE:
			  {
			    profiling_code[j - 1] =
			      vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IF_ICMPLE].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IF_ACMPEQ:
			  {
			    profiling_code[j - 1] =
			      vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IF_ACMPEQ].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IF_ACMPNE:
			  {
			    profiling_code[j - 1] =
			      vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IF_ACMPNE].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IFNULL:
			  {
			    profiling_code[j - 1] =
			      vm->instructions[SVM_INSTRUCTION_PROFILING_IFNULL].
			      code;
			    break;
			  }
			case SVM_INSTRUCTION_IFNONNULL:
			  {
			    profiling_code[j - 1] =
			  vm->
			      instructions[SVM_INSTRUCTION_PROFILING_IFNONNULL].
			      code;
			    break;
			  }
			}		/* end of inner switch */

		      profiling_code[j] = code[i];
		      offsets[i++] = j++;
		      profiling_code[j++].jint = 0;
		      
#else /* !_SABLEVM_INLINED_THREADED_INTERPRETER */
		      
		  if(i < prep_seq_offset)
		    {		      
		      profiling_code[j] = code[i];
		      offsets[i++] = j++;
		      profiling_code[j++].jint = 0;
		    }
		  else 	/* no profiling in preparation sequences */
		    {
		      profiling_code[j] = code[i];
		      offsets[i++] = j++;
		    }
#endif
		  break;
		}

	      case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	      case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	      case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	      case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:

	      case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	      case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	      case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
	      case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
		{

		  /* TO DO ... */
		  /* we don't support imbricated inlining, 
		     no need to profile thi smethod */
		  assert (1 == 0);
		  return JNI_ERR;
		}

	      case SVM_INSTRUCTION_TABLESWITCH:
	      case SVM_INSTRUCTION_TABLESWITCH_CHECK:
		{
		  jint z, low, high, length;

		  if (curr_instruction == SVM_INSTRUCTION_TABLESWITCH_CHECK)
		    {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		      profiling_code[j - 1] =
			vm->
			instructions
			[SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK].code;
#endif
		      /* stack_gc_map */
		      profiling_code[j++] = code[i++];
		    }
		  else
		    {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		      profiling_code[j - 1] =
			vm->
			instructions[SVM_INSTRUCTION_PROFILING_TABLESWITCH].
			code;
#endif
		    }

		  /* default target */
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;

		  /* low */
		  low = code[i].jint;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;

		  /* high */
		  high = code[i].jint;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;

		  /* default case counter */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		  profiling_code[j++].jint = 0;
#else
		  if(i < prep_seq_offset)
		    {
		      profiling_code[j++].jint = 0;
		    }
#endif

		  length = high - low + 1;

		  for (z = 0; z < length; z++)
		    {
		      /* target */
		      profiling_code[j] = code[i];
		      offsets[i++] = j++;

		      /* case counter */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		      profiling_code[j++].jint = 0;
#else
		      if(i < prep_seq_offset)
			{
			  profiling_code[j++].jint = 0;
			}
#endif
		    }
		  break;
		}

	      case SVM_INSTRUCTION_LOOKUPSWITCH:
	      case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
		{
		  jint z, npairs;

		  if (curr_instruction == SVM_INSTRUCTION_LOOKUPSWITCH_CHECK)
		    {
#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
			  profiling_code[j - 1] =
			    vm->
			    instructions
			    [SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK].code;
#endif
		      /* stack_gc_map */
		      profiling_code[j++] = code[i++];
		    }
		  else
		    {
#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
			  profiling_code[j - 1] =
			    vm->
			    instructions[SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH].
			    code;
#endif
		    }

		  /* default dest */
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;

		  /* npairs */
		  npairs = code[i].jint;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;

		  /* default case counter */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		  profiling_code[j++].jint = 0;
#else
		  if(i < prep_seq_offset)
		    {
		      profiling_code[j++].jint = 0;
		    }
#endif

		  for (z = 0; z < npairs; z++)
		    {
		      profiling_code[j] = code[i];
		      offsets[i++] = j++;
		      profiling_code[j] = code[i];
		      offsets[i++] = j++;

		      /* case counter */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		      profiling_code[j++].jint = 0;
#else
		      if(i < prep_seq_offset)
			{
			  profiling_code[j++].jint = 0;
			}
#endif
		    }
		  break;
		}

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
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		  if (env->vm->instructions[curr_instruction].flag !=
		      SVM_INTRP_FLAG_INLINEABLE)
		    {
		      profiling_code[j] = code[i];
		      offsets[i++] = j++;
		      profiling_code[j] = code[i];
		      offsets[i++] = j++;
		    }
		  else
		    {
		      profiling_code[j] = code[i];
		      offsets[i++] = j++;
		    }
#else
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
#endif
		  break;
		}

	      case SVM_INSTRUCTION_NEW:
	      case SVM_INSTRUCTION_ANEWARRAY:

	      case SVM_INSTRUCTION_PREPARE_LDC_STRING:
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
	      case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
	      case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
	      case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
	      case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
	      case SVM_INSTRUCTION_PREPARE_NEW:
	      case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
	      case SVM_INSTRUCTION_PREPARE_CHECKCAST:
	      case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
		{
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	      case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	      case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	      case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:

	      case SVM_INSTRUCTION_INVOKEVIRTUAL:
	      case SVM_INSTRUCTION_INVOKESPECIAL:
	      case SVM_INSTRUCTION_INVOKESTATIC:
	      case SVM_INSTRUCTION_INVOKEINTERFACE:

	      case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	      case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:

	      case SVM_INSTRUCTION_MULTIANEWARRAY:
	      case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
		{
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	      case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	      case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	      case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
		{
		  /* we don't want inlining to occur in profiling code array, 
		     so we replace special invokes by normal invokes */

		  switch (curr_instruction)
		    {
		    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
		      {
#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
			profiling_code[j - 1] =
			  vm->
			  instructions
			  [SVM_INSTRUCTION_PROFILING_INVOKESPECIAL].code;
#endif
			profiling_code[j].addr = code + i;
			break;
		      }
		    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
		      {
#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
			profiling_code[j - 1] =
			  vm->
			  instructions
			  [SVM_INSTRUCTION_PROFILING_INVOKESTATIC].code;
#endif
			profiling_code[j].addr = code + i;
			break;
		      }
		    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
		      {
#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
			profiling_code[j - 1] =
			  vm->
			  instructions
			  [SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL].code;
#endif
			profiling_code[j].invoke_info = code[i].invoke_info;
			break;
		      }
		    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
		      {
#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
			profiling_code[j - 1] =
			  vm->
			  instructions
			  [SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE].code;
#endif
			profiling_code[j].invoke_info = code[i].invoke_info;
			break;
		      }

		    default:
		      assert (1 == 0);
		    }

		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	      case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
		{
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  profiling_code[j] = code[i];
		  offsets[i++] = j++;
		  break;
		}

	      default:
		{
		  /* bytecode with no params */
		}
	      }			/* end of switch */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	  }			/* end of for loop */

	{
	  _svmt_mi_sequence_node_info *prof_seq;

	  if (skipping_goto_prep_seq_params)
	    {
	      assert (goto_seq != NULL);
	      prof_seq = goto_seq;
	      skipping_goto_prep_seq_params = JNI_FALSE;
/* 	      profiling_code[offsets[last_sequence_index]].implementation = */
/* 		prof_seq->implementation; */
	    }
	  else
	    {
	      /* we profile if we are not in the preparation sequences */
	      if(i < prep_seq_offset)
		{
		  if (_svmm_mp_get_sequence_profiling_version
		      (env, last_sequence, prof_seq) != JNI_OK)
		    {
		      assert (1 == 0);
		      return JNI_ERR;
		    }

		  profiling_code[offsets[last_sequence_index]].implementation =
		    prof_seq->implementation;

/* 		  _svmf_printf(env, stderr, "replacing seq for prof version: %p profiling_code=",  */
/* 			       profiling_code+offsets[last_sequence_index]); */
/* 		  _svmf_mi_print_super_instruction(env, stderr, prof_seq->implementation); */
/* 		  _svmf_printf(env, stderr, "\n"); */

		}
	    }

/* 	  _svmf_printf (env, stderr, "adding at @%p: ", &profiling_code[offsets[last_sequence_index]]); */
/* 	  _svmf_mi_print_super_instruction(env, stderr,  prof_seq->implementation); */
/* 	  _svmf_printf (env, stderr, "\n"); */
	}

#endif

      }				/* end of while */

    assert (j == profiling_code_length);
  }

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
/*   frame_info->profiling_preparation_sequences_offset = */
/*     offsets[frame_info->normal_preparation_sequences_offset]; */
#endif

  /* output offsets array */
#if 0
  {
    size_t i2;

    for (i2 = 0; i2 < code_length; i2++)
      {
	_svmf_printf (env, stderr, "offsets[%d]=[%d]\n", i2, offsets[i2]);
      }
  }
#endif

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mp_fix_profiling_code_adrresses
----------------------------------------------------------------------
*/

svm_static jint
_svmf_mp_fix_profiling_code_adrresses (SVM_UNUSED _svmt_JNIEnv *env,
				       _svmt_method_info *method)
{
  size_t i = 0;
  jint curr_instruction;

  _svmt_code *code;		/* non profiling code array */
  _svmt_code *profiling_code;	/* profiling code array */

  size_t code_length;		/* non profiling code length */
  size_t profiling_code_length;	/* profiling code length */
  _svmt_method_frame_info *frame_info = method->frame_info;
  jint *offsets = frame_info->mp_offsets;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  jint inst;
  jint *instructions;
  jint instructions_length;
  _svmt_mi_sequence_node_info *sequence;
  size_t prep_seq_offset = frame_info->preparation_sequences_offset;
#endif

/*   _svmf_printf(env, stderr, "_svmf_mp_fix_profiling_code_adrresses:\n"); */

  code = frame_info->normal_code;
  code_length = frame_info->code_length;

  profiling_code = frame_info->profiling_code;
  profiling_code_length = frame_info->profiling_code_length;

  while (i < code_length)
    {
#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
      curr_instruction = code[i++].jint;
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
      curr_instruction =
	_svmf_mi_get_instruction_int_code (env, code[i++].implementation);
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

      if ((sequence =
	   _svmf_mi_get_sequence_by_implementation (env,
						    code[i++].
						    implementation)) == NULL)
	{
	  assert (sequence != NULL);
	  return JNI_ERR;
	}

      instructions = sequence->instructions;
      instructions_length = sequence->instructions_length;

      /* used for GOTO that has multiple parameters,
         if it is a jump to a preparation sequence */
    process_params:

/*       _svmf_printf(env, stderr, "%p ", code+i-1); */
/*       _svmf_mi_print_super_instruction(env, stderr, */
/* 				       sequence->implementation); */
/*       _svmf_printf(env, stderr, "\n"); */

      if (sequence->starts_with_skip)
	{
	  jint to_modif_offset = offsets[i - 1] + 1;
	  jint target_offset = offsets[code[i].addr - code];
	  profiling_code[to_modif_offset].addr =
	    profiling_code + target_offset;
	  i++;
	}

      for (inst = 0; inst < instructions_length; inst++)
	{
	  curr_instruction = instructions[inst];
#endif

/* 	  if (sequence->starts_with_skip) */
/* 	    { */
/* 	      _svmf_printf(env, stderr, "curr_instruction[%d] @%p\n",  */
/* 			   curr_instruction, profiling_code+offsets[i]-2); */
/* 	    } */
/* 	  else */
/* 	    { */
/* 	      _svmf_printf(env, stderr, "curr_instruction[%d] @%p\n",  */
/* 			   curr_instruction, profiling_code+offsets[i]-1); */
/* 	    } */

	  assert ((curr_instruction >= 0) &&
		  (curr_instruction < SVM_INSTRUCTION_COUNT));

	  switch (curr_instruction)
	    {
	    case SVM_INSTRUCTION_ILOAD:
	    case SVM_INSTRUCTION_FLOAD:
	    case SVM_INSTRUCTION_ISTORE:
	    case SVM_INSTRUCTION_FSTORE:
	    case SVM_INSTRUCTION_RET:
	    case SVM_INSTRUCTION_ASTORE_RET:
	    case SVM_INSTRUCTION_LLOAD:
	    case SVM_INSTRUCTION_DLOAD:
	    case SVM_INSTRUCTION_LSTORE:
	    case SVM_INSTRUCTION_DSTORE:
	    case SVM_INSTRUCTION_ALOAD:
	    case SVM_INSTRUCTION_ASTORE:

	    case SVM_INSTRUCTION_LDC_INTEGER:
	    case SVM_INSTRUCTION_LDC_FLOAT:
	    case SVM_INSTRUCTION_LDC_LONG:
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

	      /* do not convert target address */
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
	      {
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_IINC:

	      /* no need to convert @preparation sequence */
	    case SVM_INSTRUCTION_CHECKCAST:
	    case SVM_INSTRUCTION_INSTANCEOF:

	      /* do not convert target address */
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
	      {
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_IRETURN:
	    case SVM_INSTRUCTION_INLINED_LRETURN:
	    case SVM_INSTRUCTION_INLINED_FRETURN:
	    case SVM_INSTRUCTION_INLINED_DRETURN:
	    case SVM_INSTRUCTION_INLINED_ARETURN:
	    case SVM_INSTRUCTION_INLINED_RETURN:
	      {
		/* end of inlined code, skip final stack_gc_map */
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_RET: 
	    case SVM_INSTRUCTION_INLINED_GOTO:
	      {
		/* do not convert target addr */
		/* end of inlined code, skip final stack_gc_map */
		i += 2;
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	      {
		/* do not convert target addr */
		/* end of inlined code, skip final stack_gc_map */
		i += 3;
		break;
	      }
	      
	      /* no need to convert @preparation sequence */
	    case SVM_INSTRUCTION_NEW:
	    case SVM_INSTRUCTION_ANEWARRAY:
	      {
		i += 3;
		break;
	      }

	      /* no need to convert @preparation_sequenece */
	    case SVM_INSTRUCTION_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INVOKESTATIC:
	    case SVM_INSTRUCTION_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	    case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_MULTIANEWARRAY:

	    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	    case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	      {
		i += 4;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
	      {
		i += 5;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
	      {
		/* TO DO .... */
		/* not supporting imbricated inlining yet */
		assert (1 == 0);
		break;
	      }

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
	      {
		jint to_modif_offset = offsets[i - 1] + 1;
		jint target_offset = offsets[code[i].addr - code];
		profiling_code[to_modif_offset].addr =
		  profiling_code + target_offset;
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_JSR_CHECK:
	      {
		jint to_modif_offset = offsets[i - 1] + 2;
		jint target_offset = offsets[code[++i].addr - code];
		profiling_code[to_modif_offset].addr =
		  profiling_code + target_offset;
		i++;
		break;
	      }

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
	    case SVM_INSTRUCTION_IFNULL_CHECK:
	    case SVM_INSTRUCTION_IFNONNULL_CHECK:
	      {
		jint to_modif_offset = offsets[i - 1] + 2;
		jint target_offset = offsets[code[++i].addr - code];
		profiling_code[to_modif_offset].addr =
		  profiling_code + target_offset;
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_TABLESWITCH:
	    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	      {
		jint z, low, high, length;
		jint to_modif_offset = offsets[i - 1] + 1;
		jint target_offset;

		if (curr_instruction == SVM_INSTRUCTION_TABLESWITCH_CHECK)
		  {
		    i++;
		    to_modif_offset++;
		  }

		/* Default dest. */
		target_offset = offsets[code[i++].addr - code];
		profiling_code[to_modif_offset++].addr =
		  profiling_code + target_offset;


		low = code[i++].jint;
		to_modif_offset++;
		high = code[i++].jint;
		to_modif_offset++;

		/* skip default case counter */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		to_modif_offset++;
#else
		if(i < prep_seq_offset)
		  {
		    to_modif_offset++;
		  }
#endif

		length = high - low + 1;

		for (z = 0; z < length; z++)
		  {
		    target_offset = offsets[code[i++].addr - code];
		    profiling_code[to_modif_offset++].addr =
		      profiling_code + target_offset;

		    /* skip target counter */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		    to_modif_offset++;
#else
		    if(i < prep_seq_offset)
		      {
			to_modif_offset++;
		      }
#endif
		  }
		break;
	      }

	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	      {
		jint z, npairs;
		jint to_modif_offset = offsets[i - 1] + 1;
		jint target_offset;


		if (curr_instruction == SVM_INSTRUCTION_LOOKUPSWITCH_CHECK)
		  {
		    i++;
		    to_modif_offset++;
		  }

		/* Default dest. */
		target_offset = offsets[code[i++].addr - code];
		profiling_code[to_modif_offset++].addr =
		  profiling_code + target_offset;

		npairs = code[i++].jint;
		to_modif_offset++;

		/* skip default case counter */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		to_modif_offset++;
#else
		if(i < prep_seq_offset)
		  {
		    to_modif_offset++;
		  }
#endif

		for (z = 0; z < npairs; z++)
		  {
		    i++;
		    to_modif_offset++;

		    target_offset = offsets[code[i++].addr - code];
		    profiling_code[to_modif_offset++].addr =
		      profiling_code + target_offset;

		    /* skip target counter */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		    to_modif_offset++;
#else
		    if(i < prep_seq_offset)
		      {
			to_modif_offset++;
		      }
#endif
		  }
		break;
	      }

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
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

		if (env->vm->instructions[curr_instruction].flag !=
		    SVM_INTRP_FLAG_INLINEABLE)
		  {
		    i += 2;	/* no need to convert @preparation_sequence */
		  }
		else
		  {
		    i++;
		  }
#else
		i += 2;		/* no need to convert @preparation_sequence */
#endif
		break;
	      }

	    case SVM_INSTRUCTION_REPLACE:
	      {
		jint to_modif_offset = offsets[i - 1] + 1;
		jint target_offset = offsets[code[i].addr - code];
		profiling_code[to_modif_offset].addr =
		  profiling_code + target_offset;
		i += 2;
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

	    case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
	    case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
	    case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:

	    case SVM_INSTRUCTION_PREPARE_NEW:
	    case SVM_INSTRUCTION_PREPARE_ANEWARRAY:

	    case SVM_INSTRUCTION_PREPARE_CHECKCAST:
	    case SVM_INSTRUCTION_PREPARE_INSTANCEOF:

	    case SVM_INSTRUCTION_PREPARE_LDC_STRING:
	      {
		jint to_modif_offset = offsets[i - 1] + 1;
		jint target_offset = offsets[code[i].addr - code];
		profiling_code[to_modif_offset].addr =
		  profiling_code + target_offset;
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	      {
		jint to_modif_offset = offsets[i - 1] + 1;
		jint target_offset = offsets[code[i].addr - code];
		profiling_code[to_modif_offset].addr =
		  profiling_code + target_offset;
		i += 4;
		break;
	      }

	      /* never jumps to a preparation sequence (backward jump)  */
	    case SVM_INSTRUCTION_GOTO_CHECK:
	      {
		jint target_offset;
		jint to_modif_offset = offsets[i - 1] + 1;

		/* skip stack_gc_map */
		i++;
		to_modif_offset++;

		target_offset = offsets[code[i++].addr - code];
		profiling_code[to_modif_offset].addr =
		  profiling_code + target_offset;
		break;
	      }

	    case SVM_INSTRUCTION_GOTO:

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
#endif
	      {
		jint to_modif_offset = offsets[i - 1] + 1;
		jint target_offset = offsets[code[i].addr - code];
		profiling_code[to_modif_offset].addr =
		  profiling_code + target_offset;

		/* skip other possible parameters (if jumps to preparation seq.) */

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
		curr_instruction = (code[i].addr)->jint;
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
		curr_instruction =
		  _svmf_mi_get_instruction_int_code (env,
						     (code[i].addr)->
						     implementation);
#endif
		/*                      printf("*curr_instruction[%d]\n", curr_instruction); */

		assert ((curr_instruction < SVM_INSTRUCTION_COUNT)
			&& (curr_instruction > 0));

		/* goto preparation sequence */
		switch (curr_instruction)
		  {
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
		  case SVM_INSTRUCTION_PREPARE_LDC_STRING:
		    {
		      i += 2;
		      break;
		    }

		  case SVM_INSTRUCTION_PREPARE_CHECKCAST:
		  case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
		    {
		      i += 2;
		      break;
		    }

		  case SVM_INSTRUCTION_PREPARE_NEW:
		  case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
		    {
		      i += 3;
		      break;
		    }

		  case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
		  case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
		  case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
		  case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
		  case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
		    {
		      i += 4;
		      break;
		    }

		  default:	/* not a preparation sequence */
		    {
		      i++;
		    }
		  }		/* end of inner switch */

#else /* _SABLEVM_INLINED_THREADED_INTERPRETER */
		{
		  if (_svmm_mp_is_preparation_sequence (env, code[i].addr,
							code +
							code_length,
							sequence))
		    {
		      instructions = sequence->instructions;
		      instructions_length = sequence->instructions_length;
		      goto process_params;
		    }
		  else
		    {
		      i++;
		    }
		}
#endif /* !_SABLEVM_INLINED_THREADED_INTERPRETER */
		break;
	      }

	    default:
	      {
		break;
	      }

	    }			/* end of switch */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	}			/* end of for */
#endif

    }				/* end of while */

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mp_build_profiling_code_exception_table
----------------------------------------------------------------------
*/

svm_static jint
_svmf_mp_build_profiling_code_exception_table (_svmt_JNIEnv *env,
					       _svmt_method_info *method)
{
  jint i;
  jint *offsets = method->frame_info->mp_offsets;
  _svmt_code *code = method->frame_info->normal_code;
  _svmt_code *profiling_code = method->frame_info->profiling_code;

  _svmt_exception_table *new_table;
  jint table_length = method->data.code_attribute->exception_table_length;
  _svmt_exception_table *table =
    method->data.code_attribute->normal_exception_table;


  _svmt_class_loader_info *cl = method->class_info->class_loader_info;

  _svmt_code *normal_start;
  _svmt_code *normal_end;
  _svmt_code *handler;

  /* allocate profiling exception table */
  if (_svmm_cl_zmalloc_exception_table (env, cl, table_length, new_table) !=
      JNI_OK)
    {
      return JNI_ERR;
    }
  method->data.code_attribute->profiling_exception_table = new_table;

  for (i = 0; i < table_length; i++)
    {
      size_t index;

      normal_start = table[i].normal_start;
      normal_end = table[i].normal_end;
      handler = table[i].handler;

      new_table[i].normal_start =
	profiling_code + offsets[normal_start - code];
      new_table[i].normal_end = profiling_code + offsets[normal_end - code];
      new_table[i].handler = profiling_code + offsets[handler - code];
      new_table[i].catch_type = table[i].catch_type;

      if (table[i].prepare_start != NULL)
	{
	  index = table[i].prepare_start - code;

	  assert (index <= method->frame_info->code_length);

	  /* we need to check this because exception table values reprensent pc values
	     and this value might point outside the code array. We don't want to index 
	     offsets[] outside it's limits */
	  if (index < method->frame_info->code_length)
	    {
	      new_table[i].prepare_start = profiling_code + offsets[index];
	    }
	  else
	    {
	      new_table[i].prepare_start =
		profiling_code + method->frame_info->profiling_code_length;
	    }
	}

      if (table[i].prepare_end != NULL)
	{
	  index = table[i].prepare_end - code;

	  assert (index <= method->frame_info->code_length);

	  /* we need to check this because exception table values reprensent pc values
	     and this value might point outside the code array. We don't want to index 
	     offsets[] outside it's limits */
	  if (index < method->frame_info->code_length)
	    {
	      new_table[i].prepare_end = profiling_code + offsets[index];
	    }
	  else
	    {
	      new_table[i].prepare_end =
		profiling_code + method->frame_info->profiling_code_length;
	    }
	}
    }

  return JNI_OK;
}

/*
  ----------------------------------------------------------------------
  _svmf_mp_get_old_offset
  ----------------------------------------------------------------------
*/

svm_static jint
_svmf_mp_get_old_offset (_svmt_method_info *method, _svmt_code *pc)
{
  jint left, mid, right;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jint *offsets = frame_info->mp_offsets;
  jint to_find = pc - frame_info->profiling_code;

  assert ((pc >= frame_info->profiling_code) &&
	  (pc <
	   (frame_info->profiling_code + frame_info->profiling_code_length)));

  left = 0;
  right = frame_info->code_length - 1;

  /* binary search */
  while (left <= right)
    {
      mid = (right + left) / 2;

      if (to_find > offsets[mid])
	{
	  left = mid + 1;
	}
      else if (to_find < offsets[mid])
	{
	  right = mid - 1;
	}
      else
	{
	  return mid;
	}
    }

  return -1;
}

#define _svmm_mp_disable_profiling_for_all_invokations(env,method) \
_svmh_mp_update_all_method_invokations (env,method,0)

#define _svmm_mp_enable_profiling_for_all_invokations(env,method) \
_svmh_mp_update_all_method_invokations (env,method,1)

/*
  ----------------------------------------------------------------------
  _svmh_mp_update_all_method_invokations

  if (mode == 0) profiling for all invokations of this method is disabled
  anf if (mode == 1) profiling is enabled.
  ----------------------------------------------------------------------
*/

svm_static jint
_svmh_mp_update_all_method_invokations (_svmt_JNIEnv *env,
					_svmt_method_info *method, jint mode)
{
  jint i;
  _svmt_JNIEnv *thread;
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *tmp_frame;
  _svmt_method_info *tmp_method;

  jint *offsets = method->frame_info->mp_offsets;
  _svmt_code *normal_code = method->frame_info->normal_code;
  _svmt_code *profiling_code = method->frame_info->profiling_code;

  jint normal_code_length = method->frame_info->code_length;
  jint profiling_code_length = method->frame_info->profiling_code_length;

  assert ((mode == 0) || (mode == 1));

  thread = vm->threads.user;

/*   if(mode == 0) */
/*     _svmf_printf(env, stderr, "[T%d] _svmh_mp_update_all_method_invokations_stop: ", env->thread.id); */
/*   else */
/*     _svmf_printf(env, stderr, "[T%d] _svmh_mp_update_all_method_invokations_start: ", env->thread.id); */

/*   _svmf_print_method_name(env, stderr, method, ""); */
/*   _svmf_printf(env, stderr, "\n"); */
/*   _svmf_mi_print_bytecode_count (env,  NULL, "" , -1); */
  
  /* i = 0 : check all user threads   */
  /* i = 1 : check all system threads */
  for (i = 0; i <= 1; i++)
    {
      while (thread != NULL)
	{
/* 	  _svmf_printf(env, stderr, "\n_svmh_mp_update_all_method_invokations mode[%d]: thread[%d]\n", */
/* 		       mode, thread->thread.id); */
/* 	  _svmf_dump_stack_trace(thread); */
/* 	  _svmf_printf(env, stderr, "\n"); */

	  tmp_frame = thread->stack.current_frame;
	  tmp_method = tmp_frame->method_frame_info->method;

	  while (tmp_method != &vm->stack_bottom_method)
	    {
	      if (tmp_method == method)
		{
		  /* disable profiling */
		  if (mode == 0)
		    {
		      jint offset;
		      
		      _svmt_code *tmp_pc;

		      assert ((tmp_frame->pc >= profiling_code) &&
			      (tmp_frame->pc <
			       (profiling_code + profiling_code_length)));

		      if ((offset =
			   _svmf_mp_get_old_offset (method,
						    tmp_frame->pc)) < 0)
			{
			  return JNI_ERR;
			}

		      tmp_pc = tmp_frame->pc;

		      /* fix the invoke's pc */
		      tmp_frame->pc = normal_code + offset;
		      
/* 		      _svmf_printf(env, stderr, "[T%d] replacing old[%p] by new[%p] in [T%d]\n",  */
/* 				   env->thread.id, */
/* 				   tmp_pc, tmp_frame->pc, thread->thread.id); */

		      /* adjust ASTORE_RET local variables */
		      {
			jint curr =
			  tmp_method->frame_info->non_addr_locals_count;
			jint max =
			  curr +
			  tmp_method->frame_info->
			  non_parameter_addr_locals_count;
			_svmt_stack_value *locals =
			  (_svmt_stack_value *) (void *) (((char *) tmp_frame)
							  -
							  tmp_frame->
							  method_frame_info->
							  start_offset);

			while (curr < max)
			  {
			    if ((locals[curr].addr >= profiling_code) &&
				(locals[curr].addr <
				 (profiling_code + profiling_code_length)))
			      {
				if ((offset =
				     _svmf_mp_get_old_offset (method,
							      locals[curr].
							      addr)) < 0)
				  {
				    return JNI_ERR;
				  }

/* 				_svmf_printf (env, stderr, */
/* 					      "_svmh_mp_update_all_method_invokations: updating ASTORE_RET local variable\n"); */

				locals[curr].addr = normal_code + offset;
			      }

			    curr++;
			  }
		      }
		    }
		  /* enable profiling */
		  else if (mode == 1)
		    {
		      assert ((tmp_frame->pc >= normal_code) &&
			      (tmp_frame->pc <
			       (normal_code + normal_code_length)));

		      /* fix the invoke's pc */
		      tmp_frame->pc =
			profiling_code + offsets[tmp_frame->pc - normal_code];

		      /* adjust ASTORE_RET local variables */
		      {
			jint curr =
			  tmp_method->frame_info->non_addr_locals_count;
			jint max =
			  curr +
			  tmp_method->frame_info->
			  non_parameter_addr_locals_count;
			_svmt_stack_value *locals =
			  (_svmt_stack_value *) (void *) (((char *) tmp_frame)
							  -
							  tmp_frame->
							  method_frame_info->
							  start_offset);

			while (curr < max)
			  {
			    jint index = locals[curr].addr - normal_code;

			    if ((index >= 0) && (index < normal_code_length))
			      {
/* 				_svmf_printf (env, stderr, */
/* 					      "_svmh_mp_update_all_method_invokations: updating ASTORE_RET local variable\n"); */

				locals[curr].addr =
				  profiling_code + offsets[locals[curr].addr -
							   normal_code];
			      }

			    curr++;
			  }
		      }
		    }
		}

	      /* goto next frame */
	      tmp_frame = (_svmt_stack_frame *) (void *)
		(((char *) tmp_frame) - tmp_frame->previous_offset);
	      tmp_method = tmp_frame->method_frame_info->method;
	    }

	  thread = thread->next;
	}

      thread = vm->threads.system;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mp_start_profiling
----------------------------------------------------------------------
*/

svm_static jint
_svmf_mp_start_profiling (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;

  /* Do not support imbricated inlining, no need to profile this method */
  if (method->frame_info->contains_inlined_code)
    {
      return JNI_ERR;
    }

  assert (vm->mi_info.method_profiling_start_threshold <
	  vm->mi_info.method_profiling_stop_threshold);

  /* stop the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_stop_the_world (env);
  _svmm_mutex_unlock ();
  
  /* check if another thraed has done the job while we 
     were waiting for the mutex */
  if(method->frame_info->profiling_code != NULL)
    {
      goto ok;
    }

#ifndef NDEBUG
  if (env->vm->verbose_method_profiling)
    {
      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
      _svmf_print_method_name (env, stderr, method, "PROFILING STARTED: ");
    }
#endif

#if 0
/*   if(_svmf_mi_method_is(method, "InvokeSpecial",  */
/* 			"m1")) */
  {
    _svmf_printf (env, stderr,
		  "=============================================\n");
    _svmf_mi_output_code_array (env, stderr, method->frame_info->code,
				method->frame_info->code_length,
				"\nNORMAL CODE: ");
/*       env->vm->mi_info.show_instructions = JNI_TRUE; */
/*       vm->verbose_methods = JNI_TRUE; */
/*       _svmf_dump_stack_trace (env); */

    _svmf_mi_output_exception_table (env, stdout,
				     method->data.code_attribute->
				     exception_table_length,
				     method->data.code_attribute->
				     normal_exception_table,
				     "a)normal exception table");

    _svmf_printf (env, stderr, "\n");
  }
#endif

/*   _svmf_mi_output_code_array (env, */
/* 			      stdout, */
/* 			      method->frame_info->code, */
/* 			      method->frame_info->code_length, */
/* 			      "NORMAL CODE: "); */

  if (_svmf_mp_build_profiling_code_array (env, method) != JNI_OK)
    {
      goto error;
    }

#if 0
/*   if (_svmf_mi_method_is (method, "InvokeSpecial", "m1")) */
    {
      _svmf_mi_output_code_array (env,
				  stderr,
				  method->frame_info->profiling_code,
				  method->frame_info->profiling_code_length,
				  "\n1- PROFILING CODE: before addr fix");
    }
#endif

  if (_svmf_mp_fix_profiling_code_adrresses (env, method) != JNI_OK)
    {
      goto error;
    }

/*   _svmf_mi_output_code_array (env, */
/* 			      stdout, */
/* 			      method->frame_info->profiling_code, */
/* 			      method->frame_info->profiling_code_length, */
/* 			      "2- PROFILING CODE: "); */

  if (_svmf_mp_build_profiling_code_exception_table (env, method) != JNI_OK)
    {
      goto error;
    }

  method->frame_info->code = method->frame_info->profiling_code;
  method->data.code_attribute->exception_table =
    method->data.code_attribute->profiling_exception_table;


  if (_svmm_mp_enable_profiling_for_all_invokations (env, method) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "Method Profiling: unable to adjust pc for all invoke sites\n");
      _svmm_fatal_error ("VM might be in an inconsistent state\n");
      goto error;
    }

  method->frame_info->profiling_status = SVM_METHOD_PROFILING_STARTED;

#if 0
  if (_svmf_mi_method_is (method, "java/lang/Exception", "<init>"))
    {

      env->vm->mi_info.show_instructions = JNI_TRUE;

/*       _svmf_mi_output_code_array (env, */
/* 				  stderr, */
/* 				  method->frame_info->profiling_code, */
/* 				  method->frame_info->profiling_code_length, */
/* 				  "\nPROFILING CODE"); */
    }
#endif

#if 0
  _svmf_print_method_name (env, stdout, method,
			   "\nPROFILING_CODE: freshly built");
  _svmf_mi_output_code_array (env, stdout, method->frame_info->profiling_code,
			      method->frame_info->profiling_code_length, "");

  _svmf_printf (env, stderr, "\n");
  _svmf_mi_output_exception_table (env, stdout,
				   method->data.code_attribute->
				   exception_table_length,
				   method->data.code_attribute->
				   profiling_exception_table,
				   "b)profiling exception table");
  _svmf_printf (env, stderr,
		"=============================================\n");
#endif

 ok:
  /* resume the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_resume_the_world (env);
  _svmm_mutex_unlock ();

  return JNI_OK;

error:
  /* resume the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_resume_the_world (env);
  _svmm_mutex_unlock ();

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_mp_stop_profiling
----------------------------------------------------------------------
*/

svm_static jint SVM_UNUSED
_svmf_mp_stop_profiling (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_method_frame_info *frame_info = method->frame_info;

  /* stop the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_stop_the_world (env);
  _svmm_mutex_unlock ();

  /* check if another thraed has done the job while we 
     were waiting for the mutex */
  if(method->frame_info->code == method->frame_info->normal_code)
    {
      goto error;
    }

#ifndef NDEBUG
/*   if (env->vm->verbose_method_profiling) */
/*     { */
/*       _svmf_print_method_name (env, stderr, method, "_svmf_mp_stop_profiling: "); */
/*     } */
#endif


  if (_svmm_mp_disable_profiling_for_all_invokations (env, method) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "Method Profiling: unable to adjust pc for all method invokations\n");

      /* exception table might not correspond to code array */
      _svmm_fatal_error ("VM might be in an inconsistent state\n");
      goto error;
    }

  frame_info->code = frame_info->normal_code;
  method->data.code_attribute->exception_table =
    method->data.code_attribute->normal_exception_table;
  frame_info->profiling_status = SVM_METHOD_PROFILING_FINISHED;

  /* do not free, used to inline methods */
#if 0
  _svmm_free (frame_info->offsets);
  frame_info->offsets = NULL;
#endif

#ifndef NDEBUG
  if (env->vm->verbose_method_profiling)
    {
      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
      _svmf_print_method_name (env, stderr, method, "PROFILING STOPPED: ");
    }
#endif

#if 0
  if (_svmf_mi_method_is (method, "java/util/TreeMap", "insertFixup"))
    {
      env->vm->verbose_instructions = JNI_TRUE;
      env->vm->mi_info.show_instructions = JNI_TRUE;
      env->vm->verbose_methods = JNI_TRUE;
    }
#endif


  /* resume the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_resume_the_world (env);
  _svmm_mutex_unlock ();

  return JNI_OK;

error:

  /* resume the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_resume_the_world (env);
  _svmm_mutex_unlock ();

  return JNI_ERR;
}
