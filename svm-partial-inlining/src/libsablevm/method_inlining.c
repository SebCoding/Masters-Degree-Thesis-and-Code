/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* enable or disable profiling & inlining of specific invoke types */
#define SVM_PROFILE_AND_INLINE_INVOKESTATIC    0
#define SVM_PROFILE_AND_INLINE_INVOKESPECIAL   1
#define SVM_PROFILE_AND_INLINE_INVOKEVIRTUAL   0
#define SVM_PROFILE_AND_INLINE_INVOKEINTERFACE 0

/* default value */
#define SVM_INVOKE_INLINING_THRESHOLD 20
#define SVM_MAX_CALLEE_METHOD_LENGTH 10000
#define SVM_MAX_CALLING_METHOD_LENGTH 10000

/* Inlined virtual calls need to store the @ of the method_info
   that has been inlined to compare it to the actual method_info 
   to execute */
#define INLINED_INVOKEVIRTUAL_EXTRA_PARAMS 1

/* svm_static jint */
/* _svmf_mi_check(_svmt_JNIEnv *env) */
/* { */
/*   jint *new_seq_instructions; */
/*   _svmt_mi_sequence_node_info *new_sequence; */
/*   size_t size =  */
/*     env->vm->instructions[SVM_INSTRUCTION_COUNTING_INVOKESPECIAL].inlined_size + */
/*     env->vm->instructions[SVM_INSTRUCTION_NEXT].inlined_size; */
  
/*   _svmf_printf(env, stderr, "TREE_CHECK: trying\n");   */
  
/*   new_seq_instructions = malloc(sizeof(jint)); */

/*   new_seq_instructions[0] = SVM_INSTRUCTION_COUNTING_INVOKESPECIAL; */
  
/*   /\* create the new sequence *\/ */
/*   if (_svmm_mi_get_sequence (env, new_seq_instructions,  */
/* 			     1, */
/* 			     size, */
/* 			     new_sequence, JNI_FALSE)  */
/*       != JNI_OK) */
/*     { */
/*       _svmf_printf(env, stderr, "TREE_CHECK: FAILED [%d]\n", size); */
/*       return JNI_ERR; */
/*     } */
/*   _svmf_printf(env, stderr, "TREE_CHECK: OK size[%d]\n", size); */

/*   free(new_seq_instructions); */
/*   _svmf_printf(env, stderr, "TREE_CHECK: finished\n\n");   */

/*   return JNI_OK; */
/* } */

svm_static jboolean
_svmf_mi_inlined_lookupswitch_default__key_is_default(SVM_UNUSED _svmt_JNIEnv *env,
						      _svmt_code *table, 
						      jint key, _svmt_code **pc)
{
  jint npairs = table[-1].jint;
  jint low = 0;
  jint high = npairs - 1;
  jint middle;
  jint match;
  
 /*  _svmf_printf(env, stderr, "_svmf_mi_inlined_lookupswitch_default_job: IN\n"); */

  /* If the key does not correspond to the inlined default case */
  /* return the correct target in the original code */
  while (high >= low)
    {
      middle = (low + high) / 2;
      match = table[middle * 2].jint;
      
      if (key == match)
	{
/* 	  _svmf_printf(env, stderr, "inlined_lookupswitch_default__key_is_default: false\n"); */
	  *pc = table[middle * 2 + 1].addr;
	  return JNI_FALSE;
	}
      else if (key > match)
	{
	  low = middle + 1;
	}
      else
	{
	  high = middle - 1;
	}
    }

/*   _svmf_printf(env, stderr, "inlined_lookupswitch_default__key_is_default: true\n"); */
  return JNI_TRUE;
}

/*
----------------------------------------------------------------------
_svmf_mi_init_defaults
----------------------------------------------------------------------
*/
inline svm_static void
_svmf_mi_init_defaults (_svmt_JavaVM *vm)
{
  _svmf_mp_method_profiling_init_defaults (vm);
  vm->mi_info.invoke_inlining_threshold = SVM_INVOKE_INLINING_THRESHOLD;
  vm->mi_info.max_callee_method_length = SVM_MAX_CALLEE_METHOD_LENGTH;
  vm->mi_info.max_calling_method_length = SVM_MAX_CALLING_METHOD_LENGTH;

#ifndef NDEBUG
  /* erase previous content */
  vm->mi_info.code_arrays = fopen ("code_arrays.txt", "w");
  fclose (vm->mi_info.code_arrays);
#endif

}

/*
----------------------------------------------------------------------
_svmf_mi_cleanup
----------------------------------------------------------------------
*/
inline svm_static void
_svmf_mi_cleanup (_svmt_JNIEnv *env)
{
  _svmt_mi_info *mi_info = &(env->vm->mi_info);

  _svmm_free (mi_info->selected_path_working_array);
  _svmm_free (mi_info->selected_path_to_original_code_map);
  _svmm_free (mi_info->selected_path_to_new_code_map);
  _svmm_free (mi_info->working_exception_table);


#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  _svmm_free (mi_info->sequence_heads);
#endif

  /* TO COMPLETE ... */

  /* direct: instruction tree  */
  /* inlined: sequence trees   */
  /* etc ... */
}

#ifdef _SABLEVM_METHOD_INLINING_STATS
/*
----------------------------------------------------------------------
_svmf_mi_print_statistics
----------------------------------------------------------------------
*/
inline svm_static void
_svmf_mi_print_statistics (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  _svmf_printf (env, stderr, "\nMETHOD_INLINING_STATISTICS\n");
  _svmf_printf (env, stderr, "--------------------------\n");

  _svmf_printf (env, stderr, "MI_STATS: Number of inlined invokestatic: %u\n",
		vm->mi_info.total_inlined_invokestatic);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of inlined invokespecial: %u\n",
		vm->mi_info.total_inlined_invokespecial);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of inlined invokevirtual: %u\n",
		vm->mi_info.total_inlined_invokevirtual);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of inlined invokeinterface: %u\n\n",
		vm->mi_info.total_inlined_invokeinterface);

  if(vm->mi_info.total_inlined_invokestatic == 0)
    {
      _svmf_printf (env, stderr,
		    "MI_STATS: %% of complete sequence (invokestatic): 0\n");
    }
  else
    {
      _svmf_printf (env, stderr,
		    "MI_STATS: %% of complete sequence (invokestatic): %.2f%%\n",
		    ((double) vm->mi_info.
		     total_inlined_invokestatic_complete_sequence /
		     vm->mi_info.total_inlined_invokestatic) * 100);
    }

  if(vm->mi_info.total_inlined_invokespecial == 0)
    {
      _svmf_printf (env, stderr,
		    "MI_STATS: %% of complete sequence (invokespecial): 0\n");
    }
  else
    {
      _svmf_printf (env, stderr,
		    "MI_STATS: %% of complete sequence (invokespecial): %.2f%%\n",
		    ((double) vm->mi_info.
		     total_inlined_invokespecial_complete_sequence /
		     vm->mi_info.total_inlined_invokespecial) * 100);
    }

  if(vm->mi_info.total_inlined_invokevirtual == 0)
    {
      _svmf_printf (env, stderr,
		    "MI_STATS: %% of complete sequence (invokevirtual): 0\n");
    }
  else
    {
      _svmf_printf (env, stderr,
		    "MI_STATS: %% of complete sequence (invokevirtual): %.2f%%\n",
		    ((double) vm->mi_info.
		     total_inlined_invokevirtual_complete_sequence /
		     vm->mi_info.total_inlined_invokevirtual) * 100);
    }

  if(vm->mi_info.total_inlined_invokeinterface == 0)
    {
      _svmf_printf (env, stderr,
		    "MI_STATS: %% of complete sequence (invokeinterface): 0\n");
    }
  else
    {
      _svmf_printf (env, stderr,
		    "MI_STATS: %% of complete sequence (invokeinterface): %.2f%%\n\n",
		    ((double) vm->mi_info.
		     total_inlined_invokeinterface_complete_sequence /
		     vm->mi_info.total_inlined_invokeinterface) * 100);
    }

  _svmf_printf (env, stderr,
		"MI_STATS: Number of failed inlined invokestatic: %u\n",
		vm->mi_info.total_inlined_invokestatic_failed);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of failed inlined invokespecial: %u\n",
		vm->mi_info.total_inlined_invokespecial_failed);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of failed inlined invokevirtual: %u\n",
		vm->mi_info.total_inlined_invokevirtual_failed);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of failed inlined invokeinterface: %u\n\n",
		vm->mi_info.total_inlined_invokeinterface_failed);

  _svmf_printf (env, stderr,
		"MI_STATS: Number of used inlined invokestatic: %u\n",
		vm->mi_info.total_inlined_invokestatic_used);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of used inlined invokespecial: %u\n",
		vm->mi_info.total_inlined_invokespecial_used);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of used inlined invokevirtual: %u\n",
		vm->mi_info.total_inlined_invokevirtual_used);
  _svmf_printf (env, stderr,
		"MI_STATS: Number of used inlined invokeinterface: %u\n\n",
		vm->mi_info.total_inlined_invokeinterface_used);
}
#endif

/*
----------------------------------------------------------------------
_svmf_mi_update_conversion_table
----------------------------------------------------------------------
*/ 

svm_static jint
_svmf_mi_update_conversion_table (SVM_UNUSED _svmt_JNIEnv *env,
				  _svmt_method_info *method)
{
  size_t j = 0;
  jint curr_instruction;
  jboolean in_inlined_code = JNI_FALSE;
  jboolean ignore_entries = JNI_FALSE;

  /* related to new code array */
  _svmt_code *curr = method->frame_info->normal_code;
  _svmt_code *code_end = curr + method->frame_info->code_length;
  _svmt_code *table = method->frame_info->original_code_conversion_table;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  jint inst;
  jint *instructions;
  jint instructions_length;
  _svmt_mi_sequence_node_info *sequence;
#endif

/*   _svmf_printf(env, stderr, "_svmf_mi_update_conversion_table:\n"); */

/*   _svmf_print_method_name(env, stderr, method, "table for: "); */
/*   _svmf_printf(env, stderr, " size[%d]\n", method->frame_info->code_length); */

  while (curr < code_end)
    {
#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
      curr_instruction = curr->jint;
      
      if(in_inlined_code)
	{
	  curr++;
	}
      else
	{
/* 	  _svmf_printf(env, stderr, "updating: table[%d]=%p\n\n", j, curr); */
	  table[j++].addr = curr++;
	}
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
      curr_instruction =
	_svmf_mi_get_instruction_int_code (env, curr->implementation);

      if(in_inlined_code)
	{
	  curr++;
	}
      else
	{
	  table[j++].addr = curr++;
	}
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

      if ((sequence =
	   _svmf_mi_get_sequence_by_implementation (env, curr->
						    implementation)) == NULL)
	{
	  assert (1 == 0);
	  return JNI_ERR;
	}
      
      instructions = sequence->instructions;
      instructions_length = sequence->instructions_length;

/*       _svmf_printf(env, stderr, "updating: table[%d]=%p\n\n", j, curr); */
      
      if(in_inlined_code)
	{
	  curr++;
	}
      else
	{
	  table[j++].addr = curr++;
	}

    process_params:
      
      assert(curr < code_end);
      assert(j < method->frame_info->original_code_conversion_table_length);
      
      if (sequence->starts_with_skip)
	{
	  if(in_inlined_code)
	    {
	      curr++;
	    }
	  else
	    {
	      table[j++].addr = curr++;
	    }
	}
      
      for (inst = 0; inst < instructions_length; inst++)
	{
	  curr_instruction = instructions[inst];
	  
/* 	  _svmf_printf(env, stderr, "%p [%d] table[%d] %s\n", curr, */
/* 		       curr - method->frame_info->normal_code, */
/* 		       j, */
/* 		       env->vm->instructions[curr_instruction].name); */
#endif

/* 	  _svmf_printf(env, stderr, "curr[%p] curr_instruction[%s]\n", */
/* 		       curr-1, env->vm->instructions[curr_instruction].name); */
	  
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

	    case SVM_INSTRUCTION_SKIP:
	      {
		if((in_inlined_code) || (ignore_entries))
		  {
		    curr++;
		  }
		else
		  {
		    table[j++].addr = curr++;
		  }
		break;
	      }

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
	      {
		assert(ignore_entries);
		curr++;
		break;
	      }
#endif
	      
	    case SVM_INSTRUCTION_IINC:
	      {
		if((in_inlined_code) || (ignore_entries))
		  {
		    curr += 2;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
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
		assert(in_inlined_code == JNI_FALSE);
		
		if(ignore_entries)
		  {
		    curr++;
		  }
		else
		  {
		    table[j++].addr = curr++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_GOTO:
	    case SVM_INSTRUCTION_GOTO_CHECK:
	      {
		assert(in_inlined_code == JNI_FALSE);
		
		if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
		  {
		    if(ignore_entries)
		      {
			curr++;
		      }
		    else
		      {
			table[j++].addr = curr++;
		      }
		  } 
		
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER		

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
		curr_instruction = curr->addr->jint;
#endif
		
#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
		curr_instruction =
		  _svmf_mi_get_instruction_int_code (env, curr->addr->
						     implementation);
#endif

/* 		_svmf_printf(env, stderr, "*curr_instruction[%d]\n", curr_instruction); */
		
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

		  case SVM_INSTRUCTION_PREPARE_CHECKCAST:
		  case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
		    {
		      table[j++].addr = curr++;
		      table[j++].addr = curr++;
		      break;
		    }

		  case SVM_INSTRUCTION_PREPARE_NEW:
		  case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
		    {
		      table[j++].addr = curr++;
		      table[j++].addr = curr++;	       
		      table[j++].addr = curr++;	       
		      break;
		    }

		  case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
		  case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
		  case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
		  case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
		  case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
		    {
		      table[j++].addr = curr++;
		      table[j++].addr = curr++;	       
		      table[j++].addr = curr++;
		      table[j++].addr = curr++;	       
		      break;
		    }

		  default:
		    {
		      /* not a preparation sequence */
		      table[j++].addr = curr++;	
		    }
		  }		/* end of inner switch */

#else /* !_SABLEVM_INLINED_THREADED_INTERPRETER */
		
		/* this GOTO must be at the of the sequence */
		assert (inst == (instructions_length - 1));
		
		if (((j-1) < method->frame_info->preparation_sequences_offset) &&
		    (_svmm_mp_is_preparation_sequence (env, curr->addr,
						       code_end, sequence)))
		  {
/* 		    _svmf_printf(env, stderr, "GOTO: preparation sequence\n"); */
		    instructions = sequence->instructions;
		    instructions_length = sequence->instructions_length;
		    goto process_params;
		  }
		else
		  {
		    if(ignore_entries)
		      {
			curr++;
		      }
		    else
		      {
			table[j++].addr = curr++;	   
		      }
/* 		    _svmf_printf(env, stderr, "GOTO: NOT! preparation sequence\n"); */
		  }
#endif
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
	    case SVM_INSTRUCTION_JSR_CHECK:
	    case SVM_INSTRUCTION_IFNULL_CHECK:
	    case SVM_INSTRUCTION_IFNONNULL_CHECK:
	      {
		assert(in_inlined_code == JNI_FALSE);

		if(ignore_entries)
		  {
		    curr += 2;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_TABLESWITCH:
	    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	      {
		jint z, low, high, length;

		assert(in_inlined_code == JNI_FALSE);

		if (curr_instruction == SVM_INSTRUCTION_TABLESWITCH_CHECK)
		  {
		    if(ignore_entries)
		      {
			curr++;
		      }
		    else
		      {
			table[j++].addr = curr++; /* skip stack_gc_map */
		      }
		  }
		
		/* Default dest. */
		if(ignore_entries)
		  {
		    curr++;
		  }
		else
		  {
		    table[j++].addr = curr++;
		  }


		if(!ignore_entries)
		  {
		    table[j++].addr = curr;
		  }
		low = (curr++)->jint;

		if(!ignore_entries)
		  {
		    table[j++].addr = curr;
		  }
		high = (curr++)->jint;

		length = high - low + 1;

		if(ignore_entries)
		  {
		    for (z = 0; z < length; z++)
		      {
			curr++;
		      }
		  }
		else
		  {
		    for (z = 0; z < length; z++)
		      {
			table[j++].addr = curr++;
		      }
		  }
		break;
	      }

	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	      {
		jint z, npairs;

		assert(in_inlined_code == JNI_FALSE);

		if (curr_instruction == SVM_INSTRUCTION_LOOKUPSWITCH_CHECK)
		  {
		    if(ignore_entries)
		      {
			curr++;
		      }
		    else
		      {
			table[j++].addr = curr++;
		      }
		  }

		/* default dest */
		if(ignore_entries)
		  {
		    curr++;
		  }
		else
		  {
		    table[j++].addr = curr++;
		  }

		if(!ignore_entries)
		  {
		    table[j++].addr = curr;
		  }
		npairs = (curr++)->jint;
		
		if(ignore_entries)
		  {
		    for (z = 0; z < npairs; z++)
		      {
			curr += 2;
		      }
		  }
		else
		  {
		    for (z = 0; z < npairs; z++)
		      {
			table[j++].addr = curr++;
			table[j++].addr = curr++;
		      }
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
		    if((in_inlined_code) || (ignore_entries))
		      {
			curr += 2;
		      }
		    else
		      {
			table[j++].addr = curr++;
			table[j++].addr = curr++;
		      }
		  }
		else
		  {
		    if((in_inlined_code) || (ignore_entries))
		      {
			curr++;
		      }
		    else
		      {
			table[j++].addr = curr++;
		      }
		  }
#else
		if((in_inlined_code) || (ignore_entries))
		  {
		    curr += 2;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
#endif
		break;
	      }

	    case SVM_INSTRUCTION_CHECKCAST:
	    case SVM_INSTRUCTION_INSTANCEOF:
	      {
		if((in_inlined_code) || (ignore_entries))
		  {
		    curr += 2;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_REPLACE:
	      {
		assert(in_inlined_code == JNI_FALSE);		

		if(ignore_entries)
		  {
		    curr += 2;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
		break;
	      }

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
	    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BOOLEAN:

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
		assert(in_inlined_code == JNI_FALSE);		

		if(ignore_entries)
		  {
		    curr += 3;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_NEW:
	    case SVM_INSTRUCTION_ANEWARRAY:
	      {
		if((in_inlined_code) || (ignore_entries))
		  {
		    curr += 3;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INVOKESTATIC:
	    case SVM_INSTRUCTION_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_MULTIANEWARRAY:
	      {
		if((in_inlined_code) || (ignore_entries))
		  {
		    curr += 4;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	    case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	      {
		assert(in_inlined_code == JNI_FALSE);

		if(ignore_entries)
		  {
		    curr += 4;
		  }
		else
		  {
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	    case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	      {
		if(ignore_entries)
		  {
		    curr += 4;
		  }
		else
		  {
		    /* don't support imbricated inlining yet */
		    assert(in_inlined_code == JNI_FALSE);
		    in_inlined_code = JNI_TRUE;
		    
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		    /* the invoke sequence of the original code does not map
		       to a sequence in the new code array anymore */
		    if(inst != 0)
		      {
			table[j++].addr = NULL;
		      }
#endif
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		  }
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
	      {
		if(ignore_entries)
		  {
		    curr += (4 + INLINED_INVOKEVIRTUAL_EXTRA_PARAMS);
		  }
		else
		  {
		    /* don't support imbricated inlining yet */
		    assert(in_inlined_code == JNI_FALSE); 
		    in_inlined_code = JNI_TRUE;
		    
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		    /* the invoke sequence of the original code does not map
		       to a sequence in the new code array anymore */
		    if(inst != 0)
		      {
			table[j++].addr = NULL;
		      }
#endif
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    table[j++].addr = curr++;
		    curr += INLINED_INVOKEVIRTUAL_EXTRA_PARAMS;
		  }
		break;
	      }

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
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
	      {
		assert(in_inlined_code);
		curr++;
		break;
	      }

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

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
	      {
		assert(in_inlined_code);
		curr += 2;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
	      {
		assert(in_inlined_code);
		curr += 3;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	      {
		assert(in_inlined_code);
		curr += 4;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_IRETURN:
	    case SVM_INSTRUCTION_INLINED_LRETURN:
	    case SVM_INSTRUCTION_INLINED_FRETURN:
	    case SVM_INSTRUCTION_INLINED_DRETURN:
	    case SVM_INSTRUCTION_INLINED_ARETURN:
	    case SVM_INSTRUCTION_INLINED_RETURN:
	      {
		assert(in_inlined_code);
		in_inlined_code = JNI_FALSE;
		curr++;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		/* we ignore the following bytecode they are duplicated */
		if(inst != (instructions_length - 1))
		  {
		    ignore_entries = JNI_TRUE;
		  }
#endif
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_RET:
	    case SVM_INSTRUCTION_INLINED_GOTO:
	      {
		assert(in_inlined_code);
		in_inlined_code = JNI_FALSE;
		/* end of inlined code, skip stack_gc_map */
		curr += 2;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		/* we ignore the following bytecode they are duplicated */
		if(inst != (instructions_length - 1))
		  {
		    ignore_entries = JNI_TRUE;
		  }
#endif
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	      {
		assert(in_inlined_code);
		in_inlined_code = JNI_FALSE;
		/* end of inlined code, skip stack_gc_map */
		curr += 3;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		/* we ignore the following bytecode they are duplicated */
		if(inst != (instructions_length - 1))
		  {
		    ignore_entries = JNI_TRUE;
		  }
#endif
		break;
	      }
	      
	    default:
	      {
		/* curr_instruction has no parameter */
		break;
	      }
	    } /* end of switch */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	}			/* end of for */
      ignore_entries = JNI_FALSE;
#endif   
      
    }				/* end of while */

/*   _svmf_printf(env, stderr, "j[%d] orginal_table[%d]\n", j, */
/* 	       method->frame_info->original_code_conversion_table_length); */
  
  /* Output original_code_conversion_table */
#if !defined(NDEBUG) && 0
  {
    size_t idx;
    size_t end = method->frame_info->original_code_conversion_table_length;
    FILE *file = stderr;
    _svmt_code *tab;   

    tab = method->frame_info->original_code_conversion_table;
    
    if(tab != NULL)
      {
	_svmf_print_method_name (env, file, method,
				 "Conversion Table array after inlining\n");
	
	for (idx = 0; idx < end; idx++)
	  {
	    _svmf_printf (env, file, "%p, table[%d]=%p\n", tab + idx, idx,
			  tab[idx].addr);
	  }
	_svmf_printf (env, file, "\n");
      }
  }
#endif
	 
  assert(j == method->frame_info->original_code_conversion_table_length);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mi_convert_old_addr_to_new: Convert an address from the old
 calling code array to the corresponding address in the new one. 
----------------------------------------------------------------------
*/

inline svm_static _svmt_code *
_svmf_mi_convert_old_addr_to_new (_svmt_JNIEnv *env,
				  _svmt_code *new_code,
				  _svmt_code *old_code,
				  _svmt_code *old_invoke, 
				  _svmt_code *addr)
{
  jint code_length_diff = env->vm->mi_info.code_length_diff;

  _svmt_code *after_old_invoke = old_invoke + 4;

  if(addr > after_old_invoke)
    {
      addr += code_length_diff;
    }
  
  return new_code + (addr - old_code);
}

/*
----------------------------------------------------------------------
_svmf_mi_get_instruction_int_code
----------------------------------------------------------------------
*/
#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
inline svm_static jint
_svmf_mi_get_instruction_int_code (_svmt_JNIEnv *env,
				   const void *implementation)
{
  _svmt_mi_instruction_node *node;
  _svmt_mi_instruction_node node2find;
  node2find.implementation = (void *) implementation;

  node =
    _svmm_tree_find_instructions (env->vm->class_loading.instruction_tree,
				  &node2find);
  if (node != NULL)
    return node->instruction;;

  return -1;
}
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

/*
----------------------------------------------------------------------
_svmf_mi_add_bytecode_in_sequence_trees
----------------------------------------------------------------------
*/
svm_static inline jint
_svmf_mi_init_sequence_by_implementation_tree (_svmt_JNIEnv *env,
					       jint bytecode,
					       size_t implementation_length)
{
  _svmt_mi_sequence_node_info *seq;

/*   _svmf_printf(env, stderr, "inserting[%s] ", env->vm->instructions[bytecode].name); */
  
  if (_svmm_gzalloc_mi_sequence_node_info (env, seq) != JNI_OK)
    {
      return JNI_ERR;
    }
  
  if (_svmm_gmalloc_ints (env, 1, seq->instructions) != JNI_OK)
    {
      return JNI_ERR;
    }
  
  seq->instructions_length = 1;  
  seq->instructions[0] = bytecode;
  seq->implementation_length = implementation_length;  
  seq->implementation =
    (void *) env->vm->instructions[bytecode].code.implementation;

  _svmm_tree_insert_sequence_by_implementation (env->vm->
						class_loading.
						sequence_tree_by_implementation,
						seq);
  
/*   _svmf_printf(env, stderr, "inserted[%p] ", seq->implementation); */
/*   _svmf_mi_print_super_instruction(env, stderr, seq->implementation); */
/*   _svmf_printf(env, stderr, " size[%d]\n", implementation_length); */
  
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mi_is_branch_or_jump
----------------------------------------------------------------------
*/

inline svm_static jboolean 
_svmf_mi_is_branch_or_jump (jint code)
{
  switch(code)
    {
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

    case SVM_INSTRUCTION_RET:
    case SVM_INSTRUCTION_GOTO:
    case SVM_INSTRUCTION_GOTO_CHECK:

    case SVM_INSTRUCTION_TABLESWITCH:
    case SVM_INSTRUCTION_TABLESWITCH_CHECK:

    case SVM_INSTRUCTION_LOOKUPSWITCH:
    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
      {
	return JNI_TRUE;
      }
    }
  
  return JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_mi_get_sequence_by_implementation
----------------------------------------------------------------------
*/

inline svm_static _svmt_mi_sequence_node_info *
_svmf_mi_get_sequence_by_implementation (_svmt_JNIEnv *env,
					 const void *implementation)
{
  _svmt_mi_sequence_node_info *node;
  _svmt_mi_sequence_node_info sequence2find;
  sequence2find.implementation = (void *) implementation;

  node =
    _svmm_tree_find_sequence_by_implementation (env->vm->class_loading.
						sequence_tree_by_implementation,
						&sequence2find);
  return node;
}

/*
----------------------------------------------------------------------
_svmf_mi_get_sequence_nb_params
----------------------------------------------------------------------
*/
svm_static jint SVM_UNUSED
_svmf_mi_get_sequence_nb_params (_svmt_JNIEnv *env,
				 _svmt_mi_sequence_node_info * sequence,
				 _svmt_code *code,
				 size_t code_length)
{
  jint inst;
  jint j = 1; /* +1: start index on the parameters of the sequence */
  
  jint curr_instruction;
  jint *instructions = sequence->instructions;
  jint instructions_length= sequence->instructions_length;

/*   _svmf_printf(env, stderr, "_svmf_mi_get_sequence_nb_params:\n"); */
/*   _svmf_printf(env, stderr, "_svmf_mi_get_sequence_nb_params: sequence addr=%p\n", code); */

  /* Used for GOTO that has multiple parameters,
     if it jumps to a preparation sequence */
 process_params:
  
  if (sequence->starts_with_skip)
    {
      j++;
    }
  
  for (inst = 0; inst < instructions_length; inst++)
    {
      curr_instruction = instructions[inst];

/*       _svmf_printf(env, stderr, "%p [%s]\n",  */
/* 		   code+j, env->vm->instructions[curr_instruction].name); */
      
      assert ((curr_instruction >= 0) &&
	      (curr_instruction < SVM_INSTRUCTION_COUNT));
      
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

	case SVM_INSTRUCTION_SKIP:
	  {
	    j++;
	    break;
	  }
	  
	case SVM_INSTRUCTION_IINC:
	  {
	    j += 2;
	    break;
	  }
	  
	case SVM_INSTRUCTION_GOTO:
	case SVM_INSTRUCTION_GOTO_CHECK:
	case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
	  {
	    /* this GOTO must be at the of the sequence */
	    assert (inst == (instructions_length - 1));
	    
	    if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
	      {
		j++;
	      }
	    
	    /* look in old code array were addresses are consistent,
	       to see if this GOTO is jumping to a preparation sequence */
	    if (_svmm_mp_is_preparation_sequence (env, 
						  code[j].addr,
						  code + code_length,
						  sequence))
	      {
		instructions = sequence->instructions;
		instructions_length = sequence->instructions_length;
		
		
/* 		_svmf_mi_print_super_instruction(env, stderr, sequence->implementation); */
/* 		_svmf_printf(env, stderr, "\n"); */
		
		goto process_params;
	      }
	    else
	      {
		j++;
	      }
	    
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
	case SVM_INSTRUCTION_JSR_CHECK:
	case SVM_INSTRUCTION_IFNULL_CHECK:
	case SVM_INSTRUCTION_IFNONNULL_CHECK:
	  {
	    j += 2;
	    break;
	  }
	  
	case SVM_INSTRUCTION_TABLESWITCH:
	case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	  {
	    jint z, low, high, length;
	    
	    if (curr_instruction == SVM_INSTRUCTION_TABLESWITCH_CHECK)
	      {
		j++;	/* skip stack_gc_map */
	      }
	    
	    /* Default dest. */
	    j++;
	    
	    low = code[j++].jint;
	    high = code[j++].jint;
	    length = high - low + 1;
	    
	    for (z = 0; z < length; z++)
	      {
		j++;
	      }
	    
	    break;
	  }

	case SVM_INSTRUCTION_LOOKUPSWITCH:
	case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	  {
	    jint z, npairs;
	    
	    if (curr_instruction == SVM_INSTRUCTION_LOOKUPSWITCH_CHECK)
	      {
		j++;
	      }
	    
	    /* default dest */
	    j++;
	    
	    npairs = code[j++].jint;
	    
	    for (z = 0; z < npairs; z++)
	      {
		j += 2;
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
	    if (env->vm->instructions[curr_instruction].flag !=
		SVM_INTRP_FLAG_INLINEABLE)
	      {
		j += 2;
	      }
	    else
	      {
		j++;
	      }
	    break;
	  }

	case SVM_INSTRUCTION_CHECKCAST:
	case SVM_INSTRUCTION_INSTANCEOF:
	  {
	    j += 2;
	    break;
	  }
	  
	case SVM_INSTRUCTION_REPLACE:
	  {
	    j += 2;
	    break;
	  }

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
	  
	case SVM_INSTRUCTION_NEW:
	case SVM_INSTRUCTION_ANEWARRAY:
	  {
	    j += 3;
	    break;
	  }

	case SVM_INSTRUCTION_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INVOKESPECIAL:
	case SVM_INSTRUCTION_INVOKESTATIC:
	case SVM_INSTRUCTION_INVOKEINTERFACE:
	case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:

	case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	  
	case SVM_INSTRUCTION_MULTIANEWARRAY:
	case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	  {
	    j += 4;
	    break;
	  }
	      
	case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
	  {
	    j += (4 + INLINED_INVOKEVIRTUAL_EXTRA_PARAMS);
	    break;
	  }

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
	case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:

	case SVM_INSTRUCTION_INLINED_IRETURN:
	case SVM_INSTRUCTION_INLINED_LRETURN:
	case SVM_INSTRUCTION_INLINED_FRETURN:
	case SVM_INSTRUCTION_INLINED_DRETURN:
	case SVM_INSTRUCTION_INLINED_ARETURN:
	case SVM_INSTRUCTION_INLINED_RETURN:
	  {
	    j++;
	    break;
	  }
	  
	case SVM_INSTRUCTION_INLINED_RET:
	case SVM_INSTRUCTION_INLINED_GOTO:
	  {
	    /* end of inlined code, skip stack_gc_map */
	    j += 2;
	    break;
	  }
	  
	case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	  {
	    /* end of inlined code, skip stack_gc_map */
	    j += 3;
	    break;
	  }
	  
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
	  
	case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
	  {
	    j += 2;
	    break;
	  }
	  
	case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
	  {
	    j += 3;
	    break;
	  }
	  
	case SVM_INSTRUCTION_RET:
	  {
	    j++;
	    break;
	  }
	  
	default:
	  {
	    /* curr_instruction has no parameter */
	    break;
	  }
	} /* end of switch */
    } /* end of for */


  return j - 1;
}

/*
----------------------------------------------------------------------------
_svmh_mi_get_sequence
----------------------------------------------------------------------------
*/

svm_static jint
_svmh_mi_get_sequence (_svmt_JNIEnv *env,
		       jint **pinstructions,
		       jint nb_instructions,
		       size_t implementation_length,
		       _svmt_mi_sequence_node_info ** psequence,
		       jboolean starts_with_skip)
{
  jint i;
  _svmt_JavaVM *vm = env->vm;
  _svmt_mi_sequence_node_info *sequence_result;
  jint *instructions = *pinstructions;
  
  {
/*     jint z; */
    
/*     _svmf_printf(env, stderr, "_svmh_mi_get_sequence: IN size[%d]\n", implementation_length); */
    
/*     for(z = 0 ; z < nb_instructions ; z++) */
/*       { */
/* 	_svmf_printf(env, stderr, "instructions[%d]= %s\n", z, */
/* 		     vm->instructions[instructions[z]].name); */
/*       } */
/*     _svmf_printf(env, stderr, "_svmh_mi_get_sequence: instructions_length=%d\n", */
/* 		 nb_instructions); */
/*     _svmf_printf(env, stderr, "_svmh_mi_get_sequence: implementation_length=%d\n", */
/* 		 implementation_length); */
  }
    
  /* try to reuse the sequence_node structure */
  if (vm->mi_info.sequence != NULL)
    {
      if (vm->mi_info.sequence->implementation != NULL)
	{
	  _svmm_free (vm->mi_info.sequence->implementation);
	  vm->mi_info.sequence->implementation = NULL;
	}

      if (vm->mi_info.sequence->instructions != NULL)
	{
	  _svmm_gmfree_ints (vm->mi_info.sequence->instructions);
	  vm->mi_info.sequence->instructions = NULL;
	  vm->mi_info.sequence->instructions_length = 0;
	}
    }
  else
    {
      if (_svmm_gzalloc_sequence_node (env, vm->mi_info.sequence) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  vm->mi_info.sequence->instructions_length = nb_instructions;
  vm->mi_info.sequence->instructions = instructions;

 {
/*     jint z; */
    
/*     _svmf_printf(env, stderr, "\n_svmh_mi_get_sequence: IN\n"); */
    
/*     for(z = 0 ; z < nb_instructions ; z++) */
/*       { */
/* 	_svmf_printf(env, stderr, "instructions[%d]= %s\n", z, */
/* 		     vm->instructions[vm->mi_info.sequence->instructions[z]].name); */
/*       } */
/*     _svmf_printf(env, stderr, "_svmh_mi_get_sequence: instructions_length=%d\n", */
/* 		 vm->mi_info.sequence->instructions_length); */
  }
  
  {
    _svmt_sequence_node *sequence =
      _svmm_tree_find_sequence_by_bytecodes (vm->class_loading.
					     sequence_tree_by_bytecodes,
					     vm->mi_info.sequence);
    if (sequence == NULL)
      {
	if((nb_instructions == 1) &&
	   (vm->instructions[instructions[0]].flag ==
	    SVM_INTRP_FLAG_CONTAINS_BRANCH_OR_CALL))
	  {
	    if ((sequence_result =
		 _svmf_mi_get_sequence_by_implementation 
		 (env, vm->instructions[instructions[0]].code.implementation))
		== NULL)
	      {
		assert (1 == 0);
		return JNI_ERR;
	      }

	    vm->mi_info.sequence->instructions = NULL;
	    vm->mi_info.sequence->instructions_length = 0;
	    _svmm_gmfree_ints (*pinstructions);
	  }
	else
	  {
	    void *implementation;
	    
	    /* 	_svmf_printf(env, stderr, "_svmh_mi_get_sequence: creating new sequence\n"); */
	    
	    vm->mi_info.sequence->implementation_length = implementation_length;
	    vm->mi_info.sequence->implementation =
	      _svmm_malloc (implementation_length);
	    
	    if (vm->mi_info.sequence->implementation == NULL)
	      {
		_svmf_error_OutOfMemoryError (env);
		return JNI_ERR;
	      }
	    
	    implementation = vm->mi_info.sequence->implementation;
	    
#if defined (__ia64__)
	    
	    /* Give execution permission to implementation memory */
	    {
	      /* mprotect manages permissions on a PAGE_SIZE basis */
	      
	      /* Note that POSIX says that mprotect can be used only on
		 regions of memory obtained from mmap.  As we have
		 obtained this memory from malloc, the following code is
		 not necessarily portable. */
	      
	      void *first_page =
		(void *) (((_svmt_word) implementation) &
			  ~((_svmt_word) (SVM_PAGE_SIZE - 1)));
	      size_t length =
		sequence_size +
		(((_svmt_word) implementation) &
		 ((_svmt_word) (SVM_PAGE_SIZE - 1)));
	      
	      if (mprotect
		  (first_page, length, PROT_WRITE | PROT_READ | PROT_EXEC) != 0)
		{
		  _svmm_fatal_error
		    ("cannot give execution permission to inlined code");
		}
	    }
	    
#endif
	    /* copy implementation of the SKIP instruction */
	    if (starts_with_skip)
	      {
		size_t j;
		size_t size = vm->instructions[SVM_INSTRUCTION_SKIP].inlined_size;
		
		for (j = 0; j < size; j++)
		  {
		    *((char *) implementation) =
		      ((char *) vm->instructions[SVM_INSTRUCTION_SKIP].
		       inlined_code.implementation)[j];
		    implementation = ((char *) implementation) + 1;
		  }
	      }
	    
	    /* copy implementations of instructions composing the sequence */
	    for (i = 0; i < nb_instructions; i++)
	      {
		jint code = instructions[i];
		size_t j;
		size_t size;
		
		/* 	    _svmf_printf(env, stderr, "MI : accessing vm->instructions[%d]\n", code); */
		
		size = vm->instructions[code].inlined_size;
		
		/* 	    _svmf_printf(env, stderr, "MI : copying[%s] size[%d]\n", */
		/* 			 env->vm->instructions[code].name, size); */
		
		for (j = 0; j < size; j++)
		  {
		    *((char *) implementation) =
		      ((char *) vm->instructions[code].inlined_code.
		       implementation)[j];
		    implementation = ((char *) implementation) + 1;
		  }
	      }
	    
	    /* copy implementation of the NEXT instruction */
	    {
	      size_t j;
	      size_t size = vm->instructions[SVM_INSTRUCTION_NEXT].inlined_size;
	      
	      for (j = 0; j < size; j++)
		{
		  *((char *) implementation) =
		    ((char *) vm->instructions[SVM_INSTRUCTION_NEXT].inlined_code.
		     implementation)[j];
		  implementation = ((char *) implementation) + 1;
		}
	    }
	    
	    assert (implementation ==
		    ((char *) vm->mi_info.sequence->implementation) +
		    implementation_length);

	    /* update instruction cache */
	    {
	      size_t updated = 0;
	      _svmt_word *pword =
		(_svmt_word *) vm->mi_info.sequence->implementation;

	      while (updated < implementation_length)
		{
		  _svmf_iflush (pword++);
		  updated += sizeof (_svmt_word);
		}
	    }
	    
/* 	    _svmf_printf(NULL, stderr, "INSERTING: %p\n", vm->mi_info.sequence); */

	    _svmm_tree_insert_sequence_by_bytecodes (vm->class_loading.
						     sequence_tree_by_bytecodes,
						     vm->mi_info.sequence);
	    
	 	
	    if (_svmf_mi_copy_sequence_node_to_sequence_node_info (env,
								   vm->mi_info.
								   sequence,
								   &sequence_result)
		!= JNI_OK)
	      {
		return JNI_ERR;
	      }
	    
	    sequence_result->starts_with_skip = starts_with_skip;
	    
	    _svmm_tree_insert_sequence_by_implementation (vm->class_loading.
							  sequence_tree_by_implementation,
							  sequence_result);

	    
	    /* sequence has been inserted into tree */
	    vm->mi_info.sequence = NULL;
	  }
      }
    else  /* if (sequence != NULL) */
      {
	/* 	_svmf_printf(env, stderr, "_svmh_mi_get_sequence: using already existing sequence\n"); */

	vm->mi_info.sequence->instructions = NULL;
	vm->mi_info.sequence->instructions_length = 0;
	
	if ((sequence_result =
	     _svmf_mi_get_sequence_by_implementation (env,
						      sequence->
						      implementation)) ==
	    NULL)
	  {
	    return JNI_ERR;
	  }

	_svmm_gmfree_ints (*pinstructions);
      }

    *psequence = sequence_result;
  }
  
  /* instructions array is not reusable */
  *pinstructions = NULL;

/*   _svmf_printf(env, stderr, "_svmh_mi_get_sequence: OUT\n"); */
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mi_fix_inlinedinvoke_param
----------------------------------------------------------------------
*/
svm_static jint
_svmf_mi_fix_inlinedinvoke_param(_svmt_JNIEnv *env,
				 _svmt_code *code,
				 _svmt_code *old_code,
				 size_t old_code_length,
				 jint extra_params,
				 jint inlined_callee_method_begin,
				 jint inlined_callee_method_end)
{
  jint i = inlined_callee_method_begin;
  jint inlined_code_length = -1;
  jint inlined_code_length_index = -1;

  jint inst;
  jint curr_instruction;
  jint *instructions;
  jint instructions_length;
  _svmt_mi_sequence_node_info *sequence;
  
/*   _svmf_printf(env, stderr, "_svmf_mi_fix_inlinedinvoke_param: start_at[%p] end[%p] extra[%p]\n", */
/* 	       code+i, code+inlined_callee_method_end, */
/* 	       extra_params); */
  
  while(i < inlined_callee_method_end)
    {
      if ((sequence =
	   _svmf_mi_get_sequence_by_implementation (env,
						    code[i++].
						    implementation)) ==
	  NULL)
	{
	  assert (1 == 0);
	  return JNI_ERR;
	}
      
      instructions = sequence->instructions;
      instructions_length = sequence->instructions_length;

      /* Used for GOTO that has multiple parameters,
	 if it jumps to a preparation sequence */
    process_params:
      
      if (sequence->starts_with_skip)
	{
	  i++;
	}
      
      for (inst = 0; inst < instructions_length; inst++)
	{
	  curr_instruction = instructions[inst];
	  
/* 	  _svmf_printf(env, stderr, "%p [%s]\n", */
/* 		       code+i, env->vm->instructions[curr_instruction].name); */
	  
	  assert ((curr_instruction >= 0) &&
		  (curr_instruction < SVM_INSTRUCTION_COUNT));
	  
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
	      
	    case SVM_INSTRUCTION_SKIP:
	      {
		i++;
		break;
	      }
	      
	    case SVM_INSTRUCTION_IINC:
	      {
		i += 2;
		break;
	      }
	      
	    case SVM_INSTRUCTION_GOTO:
	    case SVM_INSTRUCTION_GOTO_CHECK:
	    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
	      {
		if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
		  {
		    i++;
		  }
		
		if (_svmm_mp_is_preparation_sequence (env, 
						      code[i].addr,
						      old_code + old_code_length,
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
	    case SVM_INSTRUCTION_JSR_CHECK:
	    case SVM_INSTRUCTION_IFNULL_CHECK:
	    case SVM_INSTRUCTION_IFNONNULL_CHECK:
	      {
		i += 2;
		break;
	      }
	      
	    case SVM_INSTRUCTION_TABLESWITCH:
	    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	      {
		jint z, low, high, length;
		
		if (curr_instruction == SVM_INSTRUCTION_TABLESWITCH_CHECK)
		  {
		    i++;	/* skip stack_gc_map */
		  }
		
		/* Default dest. */
		i++;
		
		low = code[i++].jint;
		high = code[i++].jint;
		length = high - low + 1;
		
		for (z = 0; z < length; z++)
		  {
		    i++;
		  }
		
		break;
	      }
	      
	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	      {
		jint z, npairs;
		
		if (curr_instruction == SVM_INSTRUCTION_LOOKUPSWITCH_CHECK)
		  {
		    i++;
		  }
		
		/* default dest */
		i++;
		
		npairs = code[i++].jint;
		
		for (z = 0; z < npairs; z++)
		  {
		    i += 2;
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
		if (env->vm->instructions[curr_instruction].flag !=
		    SVM_INTRP_FLAG_INLINEABLE)
		  {
		    i += 2;
		  }
		else
		  {
		    i++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_CHECKCAST:
	    case SVM_INSTRUCTION_INSTANCEOF:
	      {
		i += 2;
		break;
	      }
	      
	    case SVM_INSTRUCTION_REPLACE:
	      {
		i += 2;
		break;
	      }
	      
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
	      
	    case SVM_INSTRUCTION_NEW:
	    case SVM_INSTRUCTION_ANEWARRAY:
	      {
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INVOKESTATIC:
	    case SVM_INSTRUCTION_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	    case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	      
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	      
	    case SVM_INSTRUCTION_MULTIANEWARRAY:
	    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	      {
		i += 4;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	    case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	      {
		inlined_code_length_index = i;
		i += 4;
		inlined_code_length = i;
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
	      {
		inlined_code_length_index = i;
		i += (4 + INLINED_INVOKEVIRTUAL_EXTRA_PARAMS);
		inlined_code_length = i;
		break;
	      }
	      
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
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:	      
	      {
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_IRETURN:
	    case SVM_INSTRUCTION_INLINED_LRETURN:
	    case SVM_INSTRUCTION_INLINED_FRETURN:
	    case SVM_INSTRUCTION_INLINED_DRETURN:
	    case SVM_INSTRUCTION_INLINED_ARETURN:
	    case SVM_INSTRUCTION_INLINED_RETURN:
	      {
/* 		_svmf_printf(env, stderr, "INLINED_<X>: i[%d]\n", i); */
		i++;

		if((inlined_code_length > 0) &&
		   (inlined_code_length_index > 0))
		  {
		    inlined_code_length = 
		      i - inlined_code_length + extra_params;
		    
		    /* 		_svmf_printf(env, stderr, "modifying inlined_code_length %p code[%d] = %d\n", */
		    /* 			     code+inlined_code_length_index,  */
		    /* 			     inlined_code_length_index, */
		    /* 			     inlined_code_length); */
		    
		    
		    code[inlined_code_length_index].jint = inlined_code_length;
		    inlined_code_length = inlined_code_length_index = -1;
		  }
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_RET:
	    case SVM_INSTRUCTION_INLINED_GOTO:
	      {
		/* end of inlined code, skip stack_gc_map */
		i += 2;

		if((inlined_code_length > 0) &&
		   (inlined_code_length_index > 0))
		  {
		    inlined_code_length = 
		      i - inlined_code_length + extra_params;
		    
/* 		    _svmf_printf(env, stderr, "RET/GOTO: modifying %p inlined_code_length code[%d] = %d\n", */
/* 				 code+inlined_code_length_index, */
/* 				 inlined_code_length_index, */
/* 				 inlined_code_length); */
		    
		    code[inlined_code_length_index].jint = inlined_code_length;
		    inlined_code_length = inlined_code_length_index = -1;
		  }
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	      {
		/* end of inlined code, skip stack_gc_map */
		i += 3;

		if((inlined_code_length > 0) &&
		   (inlined_code_length_index > 0))
		  {
		    inlined_code_length = 
		      i - inlined_code_length + extra_params;
		    
		    /* 		_svmf_printf(env, stderr, "modifying %p code[%d] = %d\n", */
		    /* 			     code+inlined_code_length_index,  */
		    /* 			     inlined_code_length_index, */
		    /* 			     inlined_code_length); */
		    
		    code[inlined_code_length_index].jint = inlined_code_length;
		    inlined_code_length = inlined_code_length_index = -1;
		  }
		break;
	      }
	      
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
	      
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
	      {
		i += 2;
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
	      {
		i += 3;
		break;
	      }
	      
	    case SVM_INSTRUCTION_RET:
	      {
		i++;
		break;
	      }
	      
	    default:
	      {
		/* curr_instruction has no parameter */
		break;
	      }
	    } /* end of switch */
	} /* end of for */
      
    }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmf_mi_identify_sequence_heads
----------------------------------------------------------------------
*/

svm_static jint
_svmf_mi_identify_sequence_heads(_svmt_JNIEnv *env,
				 _svmt_method_info *calling_method,
				 _svmt_method_info *callee_method,
				 _svmt_code *new_code,
				 size_t new_code_length)
{
  _svmt_JavaVM *vm = env->vm;

  jboolean *heads;  
  jint invoke_offset = vm->mi_info.invoke_offset;
  jint preparation_sequences_offset =
    calling_method->frame_info->preparation_sequences_offset;

  _svmt_code *old_code = calling_method->frame_info->code;
  _svmt_code *old_invoke = old_code + invoke_offset;

  /* sequence follwing the invoke that we inlining */
  _svmt_code *following_old_invoke = old_invoke + 5;

/*   _svmf_printf(env, stderr, "_svmf_mi_identify_sequence_heads: in\n"); */

  /* Check if heads working array is large enough */
  if(vm->mi_info.sequence_heads_length < new_code_length)
    {
      /* *2: minimize future reallocs */
      size_t length = new_code_length * 2;

      if((vm->mi_info.sequence_heads =
	  _svmm_realloc (vm->mi_info.sequence_heads,
			 length * sizeof (jboolean))) == NULL)
	{
#ifndef NDEBUG
	  _svmm_fatal_error("method inlining: realloc failed");
#endif
	  return JNI_ERR;
	}
      
      vm->mi_info.sequence_heads_length = length;
    }
  
  heads = vm->mi_info.sequence_heads;
  
  /* init heads array */
  {
    size_t i;

    for(i = 0; i < new_code_length; i++)
      {
	heads[i] = JNI_FALSE;
      }
  }

  /* Identify sequences that must be the heads of the newly merges sequences */

  /* The 1st bytecode starts a sequence */
  heads[0] = JNI_TRUE; 
  
/*   _svmf_printf(env, stderr, "exception calling method\n"); */

  /* exception boundaries and handlers for calling method */
  {
    jint i;
    jint exception_table_length =
      calling_method->data.code_attribute->exception_table_length;
  
    _svmt_exception_table *exception_table =
      calling_method->data.code_attribute->exception_table;
    
    for (i = 0; i < exception_table_length; i++)
      {
/* 	_svmf_printf(env, stderr, "entry caller: %d\n", i); */

	/* -1: pc always points to the next instruction */
	_svmt_code *start = exception_table[i].normal_start - 1;
	
	_svmt_code *handler = exception_table[i].handler;
	
	/* inclusive end */
	_svmt_code *end = exception_table[i].normal_end;
	
	start = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code, old_invoke, start);
	end = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code, old_invoke, end);
	handler = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code, old_invoke, handler);

	assert(start >= new_code);			

	assert(_svmf_mi_get_sequence_by_implementation 
	       (env, new_code[start - new_code].implementation) != NULL);
	

/* 	_svmf_printf(env, stderr, "\nstart: heads[%d]=1\n", start - new_code); */
	heads[start - new_code] = JNI_TRUE;
	
/* 	_svmf_printf(env, stderr, "preparation_sequences_offset[%d]\n", preparation_sequences_offset); */

	if(_svmf_mi_get_sequence_by_implementation 
	   (env, new_code[end - new_code].implementation) != NULL)
	  {
	    assert(end >= new_code);
/* 	    _svmf_printf(env, stderr, "end:: heads[%d]=1\n", end - new_code); */
	    heads[end - new_code] = JNI_TRUE;
	  }

/* 	if ((end - new_code) < preparation_sequences_offset) */
/* 	  { */
/* 	    assert(end >= new_code); */
/* 	    _svmf_printf(env, stderr, "end:: heads[%d]=1\n", end - new_code); */
/* 	    heads[end - new_code] = JNI_TRUE; */
/* 	  }	 */

	/* if handler is not in code current code array, it concerns inlined code
	   and jumps to original code. So we ignore it */
	if((handler >= new_code) && (handler < (new_code + new_code_length)))
	  {
	    assert(handler >= new_code);			
	    heads[handler - new_code] = JNI_TRUE;
	  }
      }
  }

/*   _svmf_printf(env, stderr, "exception callee method\n"); */

  /* exception boundaries and handlers for inlined callee method */
  {
    jint i;
    jint offset;

    jint exception_table_length =
      callee_method->frame_info->selected_path_exception_table_nb_entries;
    
    _svmt_exception_table *exception_table =
      callee_method->frame_info->selected_path_exception_table;

    _svmt_code *selected_path = callee_method->frame_info->selected_path;
    _svmt_code *selected_path_map = vm->mi_info.selected_path_to_new_code_map;

    for (i = 0; i < exception_table_length; i++)
      {
	/* in this tmp table, entries do not point to next instruction,
	   no need for -1 */
	_svmt_code *start = exception_table[i].normal_start;
	_svmt_code *end = exception_table[i].normal_end;

	/* handler points to original code, it's useless here */
	
	offset = start - selected_path;
	start = selected_path_map[offset].addr;
	assert(start >= new_code);

	offset = end - selected_path;
	end = selected_path_map[offset].addr;
	assert(end >= new_code);

	assert(_svmf_mi_get_sequence_by_implementation 
	       (env, new_code[start - new_code].implementation) != NULL);
	
/* 	_svmf_printf(env, stderr, "start: heads[%d]=1\n", start - new_code); */
	heads[start - new_code] = JNI_TRUE;
	
	if(_svmf_mi_get_sequence_by_implementation 
	   (env, new_code[end - new_code].implementation) != NULL)
	  {
/* 	    _svmf_printf(env, stderr, "end: heads[%d]=1\n", end - new_code); */
	    heads[end - new_code] = JNI_TRUE;
	  }
      }
  }

  /* branch targets, instructions following a branch, calls 
     & non inlineable bytecodes */
  {
    size_t i = 0;
    jint inst;
    jint curr_instruction;
    jint instructions_length;
    jint last_sequence_index;

    jint *instructions;

    _svmt_code *target;
    _svmt_mi_sequence_node_info *sequence;
    _svmt_mi_sequence_node_info *previous_sequence = NULL;

    size_t old_length = calling_method->frame_info->code_length;
    
    while(i < new_code_length)
      {
/* 	_svmf_printf(env, stderr, "%p top while i=%d\n", new_code+i, i); */
	
	if ((sequence =
	     _svmf_mi_get_sequence_by_implementation (env,
						      new_code[i].
						      implementation)) ==
	    NULL)
	  {
	    assert (1 == 0);
	    return JNI_ERR;
	  }
	
	instructions = sequence->instructions;
	instructions_length = sequence->instructions_length;
	last_sequence_index = i++;
	
	/* Used for GOTO that has multiple parameters,
	   if it jumps to a preparation sequence */
      process_params:

	assert(i < new_code_length);

	if (sequence->starts_with_skip)
	  {
	    i++;
	  }
	
	for (inst = 0; inst < instructions_length; inst++)
	  {
	    curr_instruction = instructions[inst];

/* 	    _svmf_printf(env, stderr, "new_code[%d] %p curr_instruction[%s]\n", i-1, */
/* 			 new_code+i-1,env->vm->instructions[curr_instruction].name); */
	    
	    assert ((curr_instruction >= 0) &&
		    (curr_instruction < SVM_INSTRUCTION_COUNT));
	    	    
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
		
	      case SVM_INSTRUCTION_SKIP:
		{
		  i++;
		break;
		}
	      
	    case SVM_INSTRUCTION_IINC:
	      {
		i += 2;
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
		target = new_code[i++].addr;
		target = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code,
							  old_invoke, target);
		heads[target - new_code] = JNI_TRUE;
		
		/* next instruction */
		assert((i < new_code_length));

		heads[i] = JNI_TRUE;
		break;
	      }

	    case SVM_INSTRUCTION_GOTO:
	    case SVM_INSTRUCTION_GOTO_CHECK:
	    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
	      {
		/* this GOTO must be at the of the sequence */
		assert (inst == (instructions_length - 1));

		if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
		  {
		    i++;
		  }
		
		target = new_code[i].addr;

/* 		_svmf_printf(env, stderr, "GOTO: target[%p]  i-1[%d]  preparation_sequences_offset[%d]\n", */
/* 			     target, i-1, preparation_sequences_offset); */

		/* look in old code array were addresses are consistent,
		   to see if this GOTO is jumping to a preparation sequence */
		if (((i-1) < calling_method->frame_info->preparation_sequences_offset) && 
		    (_svmm_mp_is_preparation_sequence (env, 
						       target,
						       old_code + old_length,
						       sequence)))
		  {
		    /* no need to mark as heads the preparation sequences, they
		       are never used in the construction of super instruction 
		       sequences */
		    
		    instructions = sequence->instructions;
		    instructions_length = sequence->instructions_length;
		    goto process_params;
		  }

		target = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code,
							  old_invoke, target);
		
/* 		_svmf_printf(env, stderr, "GOTO2: converted target[%p]\n", target); */

		/* if we are in the preparation sequence */
		if((i-1) >= (size_t) preparation_sequences_offset)
		  {
		    if((target == old_invoke) || (target == following_old_invoke))
		      {
			_svmt_mi_sequence_node_info *s;
			
			s = _svmf_mi_get_sequence_by_implementation (env, target->implementation);
			
			/* if preparation sequence has been executed, we won't have to 
			   jump there from this GOTO */
			if((s != NULL) && (s->instructions[0] != SVM_INSTRUCTION_GOTO))
			  {
			    /* only mark next instruction */
			    assert((i < new_code_length));
			    heads[++i] = JNI_TRUE;
/* 			    _svmf_printf(env, stderr, "GOTO1: heads[%d]=1\n", i); */
			    
			    /* goto next sequence */
			    break;
			  }
		      }
		  }
		
		heads[target - new_code] = JNI_TRUE;
/* 		_svmf_printf(env, stderr, "GOTO2: heads[%d]=1\n", target-new_code); */
		
		i++;
		
		/* next instruction (a goto is always at the end of a sequence */
		if(i < new_code_length)
		  {
		    heads[i] = JNI_TRUE;
/* 		    _svmf_printf(env, stderr, "GOTO3: next heads[%d]=1\n", i-1); */
		  }
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
	    case SVM_INSTRUCTION_JSR_CHECK:
	    case SVM_INSTRUCTION_IFNULL_CHECK:
	    case SVM_INSTRUCTION_IFNONNULL_CHECK:
	      {
		i++;
		target = new_code[i++].addr;
		target = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code,
							  old_invoke, target);
		heads[target - new_code] = JNI_TRUE;
		
		/* TO CHANGE ??? */
		/* next instruction */
		assert((i < new_code_length));
		heads[i] = JNI_TRUE;
		break;
	      }

	    case SVM_INSTRUCTION_TABLESWITCH:
	    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	      {
		jint z, low, high, length;

		if (curr_instruction == SVM_INSTRUCTION_TABLESWITCH_CHECK)
		  {
		    i++;	/* skip stack_gc_map */
		  }

		/* Default dest. */
		target = new_code[i++].addr;
		target = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code,
							  old_invoke, target);
		heads[target - new_code] = JNI_TRUE;
		
		low = new_code[i++].jint;
		high = new_code[i++].jint;
		length = high - low + 1;

		for (z = 0; z < length; z++)
		  {
		    target = new_code[i++].addr;
		    target = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code,
							      old_invoke, target);
		    heads[target - new_code] = JNI_TRUE;
		  }

		/* next instruction */
		assert((i < new_code_length));
		heads[i] = JNI_TRUE;

		break;
	      }

	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	      {
		jint z, npairs;

		if (curr_instruction == SVM_INSTRUCTION_LOOKUPSWITCH_CHECK)
		  {
		    i++;
		  }

		/* default dest */
		target = new_code[i++].addr;
		target = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code,
							  old_invoke, target);
		heads[target - new_code] = JNI_TRUE;


		npairs = new_code[i++].jint;

		for (z = 0; z < npairs; z++)
		  {
		    i++;
		    
		    target = new_code[i++].addr;
		    target = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code,
							  old_invoke, target);
		    heads[target - new_code] = JNI_TRUE;
		  }

		/* next instruction */
		assert((i < new_code_length));
		heads[i] = JNI_TRUE;

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
		if (env->vm->instructions[curr_instruction].flag !=
		    SVM_INTRP_FLAG_INLINEABLE)
		  {
		    i += 2;
		  }
		else
		  {
		    i++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_CHECKCAST:
	    case SVM_INSTRUCTION_INSTANCEOF:
	      {
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_REPLACE:
	      {
		target = new_code[i++].addr;

/* 		_svmf_printf(env, stderr, "REPLACE: target[%p] old_invoke[%p]\n", */
/* 			     target, old_invoke); */

		if(target != old_invoke)
		  {
		    if(target == following_old_invoke)
		      {
			_svmt_mi_sequence_node_info *s;
			
			s = _svmf_mi_get_sequence_by_implementation (env, target->implementation);
			
			/* if preparation sequence has been executed on seq following inlined code */
			if((s != NULL) && (s->instructions[0] != SVM_INSTRUCTION_GOTO))
			  {
			    /* do not mark it as a head */
			    i++;

			    /* goto next sequence */
			    break;
			  }
		      }

		    target = _svmf_mi_convert_old_addr_to_new(env, new_code, old_code,
							      old_invoke, target);

/* 		    _svmf_printf(env, stderr, "REPLACE: heads[%d]=1\n",  */
/* 				 target-new_code); */
		    heads[target - new_code] = JNI_TRUE;
		  }
		
		i++;;
		break;
	      }

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

	    case SVM_INSTRUCTION_NEW:
	    case SVM_INSTRUCTION_ANEWARRAY:
	      {
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INVOKESTATIC:
	    case SVM_INSTRUCTION_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	    case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	      {
		heads[last_sequence_index] = JNI_TRUE;
		i += 4;
		
		/* next instruction */
		assert((i < new_code_length));
		heads[i] = JNI_TRUE;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	    case SVM_INSTRUCTION_MULTIANEWARRAY:
	    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	      {
		i += 4;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	    case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	      {
/* 		_svmf_printf(env, stderr, "INLINED_INVOKE 1: %d %p\n", i, new_code+i);  */

		if(previous_sequence != NULL)
		  {
/* 		    _svmf_printf(env, stderr, "INLINED_INVOKE 2: last_sequence_index[%d]\n",  */
/* 			    last_sequence_index);  */

		    /* we cannot merge a INLINED_<X>RETURN directly followed
		       by a INLINED_INVOKE<X> without adding an extra sequence
		       after the inlined code of the callee method associated
		       with the INLINED_<X>RETURN */
		    switch(previous_sequence->
			   instructions[previous_sequence->instructions_length-1])
		      {
		      case SVM_INSTRUCTION_INLINED_IRETURN:
		      case SVM_INSTRUCTION_INLINED_LRETURN:
		      case SVM_INSTRUCTION_INLINED_FRETURN:
		      case SVM_INSTRUCTION_INLINED_DRETURN:
		      case SVM_INSTRUCTION_INLINED_ARETURN:
		      case SVM_INSTRUCTION_INLINED_RETURN:
		      case SVM_INSTRUCTION_INLINED_RET:
		      case SVM_INSTRUCTION_INLINED_GOTO:
		      case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
			{
			  heads[last_sequence_index] = JNI_TRUE;
			}
		      }
		  }

		i += 4;
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
	      {
/* 		_svmf_printf(env, stderr, "INLINED_INVOKE 2: %d %p\n", i, new_code+i);  */

		if(previous_sequence != NULL)
		  {
/* 		    _svmf_printf(env, stderr, "INLINED_INVOKE 2: last_sequence_index[%d]\n",  */
/* 				 last_sequence_index);  */

		    /* we cannot merge a INLINED_<X>RETURN directly followed
		       by a INLINED_INVOKE<X> without adding an extra sequence
		       after the inlined code of the callee method associated
		       with the INLINED_<X>RETURN */
		    switch(previous_sequence->
			   instructions[previous_sequence->instructions_length-1])
		      {
		      case SVM_INSTRUCTION_INLINED_IRETURN:
		      case SVM_INSTRUCTION_INLINED_LRETURN:
		      case SVM_INSTRUCTION_INLINED_FRETURN:
		      case SVM_INSTRUCTION_INLINED_DRETURN:
		      case SVM_INSTRUCTION_INLINED_ARETURN:
		      case SVM_INSTRUCTION_INLINED_RETURN:
		      case SVM_INSTRUCTION_INLINED_RET:
		      case SVM_INSTRUCTION_INLINED_GOTO:
		      case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
			{
			  heads[last_sequence_index] = JNI_TRUE;
			}
		      }
		  }
		    
		i += (4 + INLINED_INVOKEVIRTUAL_EXTRA_PARAMS);
		break;
	      }

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
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
	      {
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_IRETURN:
	    case SVM_INSTRUCTION_INLINED_LRETURN:
	    case SVM_INSTRUCTION_INLINED_FRETURN:
	    case SVM_INSTRUCTION_INLINED_DRETURN:
	    case SVM_INSTRUCTION_INLINED_ARETURN:
	    case SVM_INSTRUCTION_INLINED_RETURN:
	      {
		i++;

		/* TO CHANGE ... */
		/* for the moment the sequence following inlined callee method will
		   always be head */
/* 		heads[i] = JNI_TRUE; */
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_RET:
	    case SVM_INSTRUCTION_INLINED_GOTO:
	      {
		/* end of inlined code, skip stack_gc_map */
		i += 2;

		/* TO CHANGE ... */
		/* for the moment the sequence following inlined callee method will
		   always be head */
		heads[i] = JNI_TRUE;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	      {
		/* end of inlined code, skip stack_gc_map */
		i += 3;

		/* TO CHANGE ... */
		/* for the moment the sequence following inlined callee method will
		   always be head */
		heads[i] = JNI_TRUE;
		break;
	      }

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

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
	      {
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
	      {
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_RET:
	      {
		i++;
		/* next instruction */
		assert((i < new_code_length));
		heads[i] = JNI_TRUE;
		break;
	      }

	    default:
	      {
		/* curr_instruction has no parameter */
		break;
	      }
	    } /* end of switch */

	    if(instructions_length == 1)
	      {
		if (vm->instructions[curr_instruction].flag ==
		    SVM_INTRP_FLAG_CONTAINS_BRANCH_OR_CALL)
		  {
		    heads[last_sequence_index] = JNI_TRUE;

/* 		    _svmf_printf(env, stderr, "not inlineable [%d] next_one[%d]\n",  */
/* 				 last_sequence_index, i); */
		    
		    /* next instruction (since it is not inlineable it's 
		       the last of it's sequence) */
		    assert((i < new_code_length));
		    heads[i] = JNI_TRUE;
		  }
	      }
	    
	  } /* end of for */

	previous_sequence = sequence;

      } /* end of while */

    assert(i <= new_code_length);
  }


#if !defined(NDEBUG) && 0
  /* output heads array */
  {
    size_t i;
    FILE *file = vm->mi_info.code_arrays;
    
    if(file == NULL)
      {
	if((file = fopen ("code_arrays.txt", "a")) == NULL)
	  {
	    _svmm_fatal_error("impossible to open file");
	  }
	vm->mi_info.code_arrays = file;
      }

    _svmf_printf(env, file, "Heads array size[%d]\n", new_code_length);
    
    for(i = 0; i < new_code_length; i++)
      {
	_svmf_printf(env, file, "%d) heads[%d]\n", i, heads[i]);
      }
    _svmf_printf(env, file, "\n");
  }
#endif

/* check */
#ifndef NDEBUG
 {
   size_t a;

   for(a = 0; a < new_code_length ; a++)
     {
       if(heads[a] == 1)
	 {
	   if(_svmf_mi_get_sequence_by_implementation (env, new_code[a].
						       implementation) 
	      == NULL)
	     {
	       _svmf_printf(env, stderr, "heads[%d] not a bytecode\n", a);
	       assert(1 == 0);
	     }
	 }
     } 
 }
#endif

/*   _svmf_printf(env, stderr, "_svmf_mi_identify_sequence_heads: out\n"); */

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_mi_merge_sequences
----------------------------------------------------------------------
*/

#define _svmm_mi_merge_sequences(a, b, c, d, e) \
_svmh_mi_merge_sequences(a, b, c, &d, &e)

svm_static jint
_svmh_mi_merge_sequences(_svmt_JNIEnv *env,
			 _svmt_method_info *calling_method,
			 _svmt_method_info *callee_method,
			 _svmt_code **non_merged_code,
			 size_t *non_merged_code_length)
{
  _svmt_JavaVM *vm = env->vm;

  jboolean *heads;
  jint merged_index = 0;
  jint code_length_diff = vm->mi_info.code_length_diff;

  size_t source_code_length = *non_merged_code_length;
  size_t invoke_offset = vm->mi_info.invoke_offset;
  size_t preparation_sequences_offset =
    calling_method->frame_info->preparation_sequences_offset;
  size_t old_code_length = calling_method->frame_info->code_length;

  _svmt_code *merged_code;
  _svmt_code *seq_old_code_addr;
  _svmt_code *source_code = *non_merged_code;
  _svmt_code *old_code = calling_method->frame_info->code;
  _svmt_code *selected_path_map = vm->mi_info.selected_path_to_new_code_map;

  size_t end_of_inlined_code_offset = invoke_offset + source_code[invoke_offset+1].jint + 5;

  jint resuming_seq_index = -1;
  jint seq_following_extra_seq_offset = -1;
  jint following_inlined_callee_method_offset = 0;
  jint extra_sequence_nb_params = 0;
  jboolean add_extra_seq_following_inlined_method;
  jboolean add_INLINED_JMP_OVER_NEXT_SEQ = JNI_FALSE;

  /*   _svmf_printf(env, stderr, "_svmf_mi_merge_sequences: in\n"); */  

  if((vm->mi_info.invoke_instruction == SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE)
     || (vm->mi_info.invoke_instruction == SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL))
    {
      end_of_inlined_code_offset += INLINED_INVOKEVIRTUAL_EXTRA_PARAMS;
    }
  
/*   _svmf_printf(env, stderr, "_svmf_mi_merge_sequences: end of inlined code: %d\n", */
/* 	       end_of_inlined_code_offset); */

  /* output selected path map */
/*   { */
/*     size_t i; */
    
/*     _svmf_printf(env, stderr, "selected_path_map:\n");  */
/*     for(i = 0 ; i < callee_method->frame_info->selected_path_code_length; i++) */
/*       { */
/* 	_svmf_printf(env, stderr, "selected_path_map[%d]=%p\n", i,  */
/* 		     selected_path_map[i].addr); */
/*       } */
/*     _svmf_printf(env, stderr, "\n");  */
/*   } */

  /* Identify the new sequence heads */  
  if(_svmf_mi_identify_sequence_heads(env, calling_method, callee_method,
				      source_code, source_code_length) != JNI_OK)
    {
      assert(1 == 0);
      return JNI_ERR;
    }

  /* Check if merged_sequences_code working array is large enough */
  if(vm->mi_info.merged_sequences_working_code_length < source_code_length)
    {
      /* *2: minimize future reallocs */
      size_t length = source_code_length * 2;

      if((vm->mi_info.merged_sequences_working_code =
	  _svmm_realloc (vm->mi_info.merged_sequences_working_code,
			 length * sizeof (_svmt_code *))) == NULL)
	{
#ifndef NDEBUG	  
	  _svmm_fatal_error("method inlining: realloc failed");
#endif
	  return JNI_ERR;
	}   

      vm->mi_info.merged_sequences_working_code_length = length;
    }

  merged_code = vm->mi_info.merged_sequences_working_code;
  heads = vm->mi_info.sequence_heads;

  /* merge the sequences that can be merged */
  {
    size_t i = 0;

    jint new_seq_instruction_index;
    jint new_seq_instructions_length;

    jint *new_seq_instructions;
    _svmt_mi_sequence_node_info *new_sequence;
    size_t new_seq_implementation_length;
    jboolean new_seq_starts_with_skip = JNI_FALSE;
    jboolean building_resuming_seq = JNI_FALSE;
    jboolean building_final_callee_method_seq = JNI_FALSE;

    /* true if we are copying the parameters of the last sequence
       of the inlined callee method */
    jboolean copying_params_of_ending_seq = JNI_FALSE;


    jint last_visited_sequence_offset = -1;
    
/*     _svmf_printf(env, stderr, "invoke_offset[%d]\n", invoke_offset); */
/*     _svmf_printf(env, stderr, "end_of_inlined_code_offset[%d]\n", end_of_inlined_code_offset); */

    /* If we need to add an extra sequence at the end of the 
       inlined method */
    if(heads[end_of_inlined_code_offset] == 0)
      {
	add_extra_seq_following_inlined_method = JNI_TRUE;
      }
    else
      {
/* 	following_inlined_callee_method_offset = 0; */
	add_extra_seq_following_inlined_method = JNI_FALSE;
      }

    /* Process code before preparation sequences */
    while(i < preparation_sequences_offset)
      {
	size_t j;
	size_t next = i + 1;
	
	/* find next head */
	while((heads[next] == JNI_FALSE) && (next < preparation_sequences_offset))
	  {
	    next++;
	  }

/* 	_svmf_printf(env, stderr, "\n*** Merging from i[%d] to next[%d]\n", i, next); */

	j = i;
	new_seq_instructions_length = 0;

/* 	_svmf_printf(env, stderr, "while_1: compute new_seq length\n"); */

	/* STEP 1: Compute new_seq_instructions_length */
	while(j < next)
	  {
	    jint nb_params;
	    _svmt_mi_sequence_node_info *sequence;
    	    
	    last_visited_sequence_offset = j;

/* 	    _svmf_printf(env, stderr, "while_1: j[%d] next[%d]\n", j, next); */

/* 	    _svmf_printf(env, stderr, "while_1: trying sequence %p [%p]\n",  */
/* 			 source_code+j, source_code[j].implementation); */
	    
	    if ((sequence =
		 _svmf_mi_get_sequence_by_implementation (env,
							  source_code[j].
							  implementation)) ==
		NULL)
	      {
		assert (1 == 0);
		return JNI_ERR;
	      }
	    
/* 	    _svmf_printf(env, stderr, "while_1: sequence->instructions[0]=%s\n",  */
/* 			 vm->instructions[sequence->instructions[0]].name); */

	    /* check if we are building the final sequence of the inlined 
	       callee method */
	    if((j > invoke_offset) && (j <= end_of_inlined_code_offset))
	      {
		switch(sequence->instructions[sequence->instructions_length-1])
		  {
		  case SVM_INSTRUCTION_INLINED_IRETURN:
		  case SVM_INSTRUCTION_INLINED_LRETURN:
		  case SVM_INSTRUCTION_INLINED_FRETURN:
		  case SVM_INSTRUCTION_INLINED_DRETURN:
		  case SVM_INSTRUCTION_INLINED_ARETURN:
		  case SVM_INSTRUCTION_INLINED_RETURN:
		    {
		      building_final_callee_method_seq = JNI_TRUE;
		      break;
		    }

		  case SVM_INSTRUCTION_INLINED_RET:
		  case SVM_INSTRUCTION_INLINED_GOTO:
		    {
/* 		      _svmf_printf(env, stderr, "INLINED_RET/GOTO: j[%d]\n"); */
		      building_final_callee_method_seq = JNI_TRUE;
		      break;
		    }

		  case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
		    {
		      building_final_callee_method_seq = JNI_TRUE;
		      break;
		    }
		  }
	      }

	    new_seq_instructions_length += sequence->instructions_length;	

	    /* if we are not in the first sequence */
	    if(j != i)
	      {
		/* add one because we will explicitly put a SKIP instruction 
		   in the instructions array of the merged sequence, for SKIPs 
		   that will be in the middle of the sequence */
		if(sequence->starts_with_skip)
		  {
		    new_seq_instructions_length++;
		  }
	      }
	    
	    /* get this sequence's addr in the old code array */
	    if(j < invoke_offset)
	      {
		seq_old_code_addr = old_code + j;
	      }
	    else
	      {
		seq_old_code_addr = old_code + j - code_length_diff;
	      }
	    
	    if((nb_params = 
		_svmf_mi_get_sequence_nb_params (env, sequence, 
						 seq_old_code_addr, 
						 old_code_length)) < 0)
	      {
		assert(1 == 0);
		return JNI_ERR;
	      }

/* 	    _svmf_printf(env, stderr, "while_1: nb_params[%d]\n", nb_params); */

	    j += nb_params + 1;
	  }
	
	if(building_final_callee_method_seq && add_extra_seq_following_inlined_method)
	  {
	    _svmt_mi_sequence_node_info *sequence;
	    
/* 	    _svmf_printf(env, stderr, "last_visited_sequence_offset[%d]\n",  */
/* 			 last_visited_sequence_offset); */
	    
	    if ((sequence =
		 _svmf_mi_get_sequence_by_implementation 
		 (env, source_code[last_visited_sequence_offset].implementation)) 
		== NULL)
	      {
		assert (1 == 0);
		return JNI_ERR;
	      }
	    
	    /* check if following sequence end with a branch or jump */
	    if(!_svmf_mi_is_branch_or_jump
	       (sequence->instructions[sequence->instructions_length-1]))
	      {
		/* we will add an INLINED_JMP_OVER_NEXT_SEQ 
		   to jump over the extra sequence */
		add_INLINED_JMP_OVER_NEXT_SEQ = JNI_TRUE;
		new_seq_instructions_length++;
	      }	      
	  }
	
	if (_svmm_gmalloc_ints (env, new_seq_instructions_length,
				new_seq_instructions) != JNI_OK)
	  {
	    return JNI_ERR;
	  }

	j = i;
	new_seq_instruction_index = 0;
	new_seq_implementation_length = 0;

/* 	_svmf_printf(env, stderr, "\nwhile_2: collect instructions\n"); */

	/* STEP 2: Collect the instructions & implementation lengths
	           forming the new sequence */
	while(j < next)
	  {
	    jint k;
	    jint nb_params;
	    jint *instructions;
	    jint instructions_length;

	    _svmt_mi_sequence_node_info *sequence;
	    
/* 	    _svmf_printf(env, stderr, "while_2: i[%d] j[%d] next[%d]\n", i, j, next); */

	    /* check if we are building the resuming_seq (sequence that contains
	       the inlined_invoke in which we should resume after inlining) */
	    if(j == invoke_offset)
	      {
		building_resuming_seq = JNI_TRUE;
	      }

	    if ((sequence =
		 _svmf_mi_get_sequence_by_implementation (env,
							  source_code[j].
							  implementation)) ==
		NULL)
	      {
		assert (1 == 0);
		return JNI_ERR;
	      }

	    instructions = sequence->instructions;
	    instructions_length = sequence->instructions_length;
	    new_seq_implementation_length += sequence->implementation_length;
	    new_seq_implementation_length -= vm->instructions[SVM_INSTRUCTION_NEXT].inlined_size;
	    
/* 	    _svmf_printf(env, stderr,  */
/* 			 "implementation_length[%d]\n", */
/* 			 sequence->implementation_length); */
	    
	    /* if we are in the first sequence */
	    if(j == i)
	      {
		new_seq_starts_with_skip = sequence->starts_with_skip;
	      }
	    else
	      {
		if(sequence->starts_with_skip)
		  {
		    new_seq_instructions[new_seq_instruction_index++] = SVM_INSTRUCTION_SKIP;
/* 		    new_seq_implementation_length += vm->instructions[SVM_INSTRUCTION_SKIP].inlined_size; */
/* 		    _svmf_printf(env, stderr, "while_2: collecting[SKIP]\n"); */
		  }

		/* if we are in inlined code */
		if((j >= invoke_offset) && (j < end_of_inlined_code_offset))
		  {
		    /* update selected_path_map, this sequence does not exist
		       anymore in the new merged code */
		    selected_path_map[j - invoke_offset].addr = NULL;
		  }
	      }

	    for (k = 0; k < instructions_length; k++)
	      {
/* 		_svmf_printf(env, stderr, "while_2: collecting[%s]\n", */
/* 			     vm->instructions[instructions[k]].name); */

/* 		_svmf_printf(env, stderr, "new_seq_instructions [%d] <-- [%d]\n", */
/* 			     new_seq_instruction_index, k); */

		new_seq_instructions[new_seq_instruction_index++] = instructions[k];
	      }

/* 	    _svmf_printf(env, stderr, "while_2: after collecting 1st is [%s]\n",  */
/* 			 vm->instructions[new_seq_instructions[0]].name); */

	    /* get this sequence's addr in the old code array */
	    if(j < invoke_offset)
	      {
		seq_old_code_addr = old_code + j;
	      }
	    else
	      {
		seq_old_code_addr = old_code + j - code_length_diff;
	      }
	    
	    if((nb_params = 
		_svmf_mi_get_sequence_nb_params (env, sequence, 
						 seq_old_code_addr, 
						 old_code_length)) < 0)
	      {
		assert(1 == 0);
		return JNI_ERR;
	      }
	    
	    j += nb_params + 1;
	  }
/* 	_svmf_printf(env, stderr, "before creation of new sequence 1st is [%s]\n",  */
/* 		     vm->instructions[new_seq_instructions[0]].name); */

/* 	_svmf_printf(env, stderr, */
/* 		     "nb_instructions[%d] implementation_length[%d]\n", */
/* 		     new_seq_instructions_length, */
/* 		     new_seq_implementation_length); */

	if(building_final_callee_method_seq && 
	   add_extra_seq_following_inlined_method)
	  {
	    if(add_INLINED_JMP_OVER_NEXT_SEQ)
	      {
/* 		_svmf_printf(env, stderr, "adding[INLINED_JMP_OVER_NEXT_SEQ] in instructions[%d]\n",  */
/* 			     new_seq_instruction_index); */
		new_seq_instructions[new_seq_instruction_index++] = SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ;
		new_seq_implementation_length += 
		  vm->instructions[SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ].inlined_size;
	      }
	    seq_following_extra_seq_offset = j;
	  }

	assert(new_seq_instruction_index == new_seq_instructions_length);
	
	new_seq_implementation_length += vm->instructions[SVM_INSTRUCTION_NEXT].inlined_size;

	/* create the new sequence */
	if (_svmm_mi_get_sequence (env, new_seq_instructions, 
				   new_seq_instructions_length,
				   new_seq_implementation_length,
				   new_sequence, new_seq_starts_with_skip) 
	    != JNI_OK)
	  {
	    return JNI_ERR;
	  }

	/* if we are in inlined code */
	if((i >= invoke_offset) && (i < end_of_inlined_code_offset))
	  {
	    /* update selected_path_map */
	    selected_path_map[i - invoke_offset].addr = merged_code + merged_index;
	  }
	
	/* remember what sequence contains the beginning of the inlined code */
	if(building_resuming_seq)
	  {
	    building_resuming_seq = JNI_FALSE;
	    resuming_seq_index = merged_index;
	    vm->mi_info.resuming_seq = new_sequence;
/* 	    _svmf_printf(env, stderr, "resuming_seq_index[%d]\n", resuming_seq_index); */
	  }
	
	/* insert sequence in merged_code */
	merged_code[merged_index++].implementation = new_sequence->implementation;

#ifndef NDEBUG
	{
	  jint cpt = 0;
	  size_t w;

	  for(w = 0 ; w < new_sequence->instructions_length ; w++)
	    {
	      switch(new_sequence->instructions[w])
		{
		case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
		case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
		case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
		case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
		  cpt++;
		}
	    }

	  if(cpt > 1)
	    {
#ifndef NDEBUG
	      _svmf_print_method_name(env, stderr, callee_method, "XXXXXXX:");
	      _svmf_print_method_name(env, stderr, calling_method, " in  ");
#endif
	      _svmf_printf(env, stderr, " contains 2 INLINED_INVOKE<X>\n");
	      assert(1 == 0);
	    }
	}
#endif


/* 	_svmf_printf(env, stderr, "\nwhile_3: copy in new array\n"); */

	/* STEP 3: Copy parameters of the newly created sequence */
	while(i < next)
	  {
	    jint p; /* used to count nb_params */
	    jint inst; /* used to go through instructions array */
	    jint nb_params = 0;
	    jint curr_instruction;
	    jint *instructions;
	    jint instructions_length;
	    _svmt_mi_sequence_node_info *sequence;

	    /* check if we are copying params of the resuming_seq */
	    if(i == end_of_inlined_code_offset)
	      {
/* 		_svmf_printf(env, stderr, "I = %d merged_index = %d\n", i, merged_index); */
		copying_params_of_ending_seq = JNI_TRUE;
	      }

/* 	    _svmf_printf(env, stderr, "while_3: i[%d] next[%d] top of the loop \n", i, next); */

	    if ((sequence =
		 _svmf_mi_get_sequence_by_implementation (env,
							  source_code[i].
							  implementation)) ==
		NULL)
	      {
		assert (1 == 0);
		return JNI_ERR;
	      }

	    instructions = sequence->instructions;
	    instructions_length = sequence->instructions_length;
	    	    	    
	    /* skip current implementation addr */
	    i++;

	    p = i;

	    /* count params & remember the position that the pc should have when we
	       resume execution after inlining (we use old code array for parameter
	       copying because it's the only place where addresses are consistent) */
	    
	  process_params:
	    
	    if (sequence->starts_with_skip)
	      {
		p++;
	      }
	    
	    for (inst = 0; inst < instructions_length; inst++)
	      {
		curr_instruction = instructions[inst];
		
		assert ((curr_instruction >= 0) &&
			(curr_instruction < SVM_INSTRUCTION_COUNT));
		
/* 		_svmf_printf(env, stderr, "while3: inst[%d] inst_length[%d] [%s]\n", */
/* 			     inst, instructions_length, vm->instructions[curr_instruction].name); */
		

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
		    
		  case SVM_INSTRUCTION_SKIP:
		    {
		      p++;
		      break;
		    }
	  
		  case SVM_INSTRUCTION_IINC:
		    {
		      p += 2;
		      break;
		    }
	  
		  case SVM_INSTRUCTION_GOTO:
		  case SVM_INSTRUCTION_GOTO_CHECK:
		  case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
		    {
		      /* this GOTO must be at the of the sequence */
		      assert (inst == (instructions_length - 1));
		      
		      if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
			{
			  p++;
			}
		      
		      /* target addr in source_code is an addr in old_code 
			 (addresses have not yet been converted) */
  
		      /* look in old code array were addresses are consistent,
			 to see if this GOTO is jumping to a preparation sequence */
		      if (_svmm_mp_is_preparation_sequence (env, 
							    source_code[p].addr,
							    old_code + old_code_length,
							    sequence))
			{
			  instructions = sequence->instructions;
			  instructions_length = sequence->instructions_length;
			  
			  
			  /* 		_svmf_mi_print_super_instruction(env, stderr, sequence->implementation); */
			  /* 		_svmf_printf(env, stderr, "\n"); */
			  
			  goto process_params;
			}
		      else
			{
			  p++;
			}
		      
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
		  case SVM_INSTRUCTION_JSR_CHECK:
		  case SVM_INSTRUCTION_IFNULL_CHECK:
		  case SVM_INSTRUCTION_IFNONNULL_CHECK:
		    {
		      p += 2;
		      break;
		    }
	  
		  case SVM_INSTRUCTION_TABLESWITCH:
		  case SVM_INSTRUCTION_TABLESWITCH_CHECK:
		    {
		      jint z, low, high, length;
		      
		      if (curr_instruction == SVM_INSTRUCTION_TABLESWITCH_CHECK)
			{
			  p++;	/* skip stack_gc_map */
			}
		      
		      /* Default dest. */
		      p++;
		      
		      low = source_code[p++].jint;
		      high = source_code[p++].jint;
		      length = high - low + 1;
		      
		      for (z = 0; z < length; z++)
			{
			  p++;
			}
		      
		      break;
		    }
		    
		  case SVM_INSTRUCTION_LOOKUPSWITCH:
		  case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
		    {
		      jint z, npairs;
		      
		      if (curr_instruction == SVM_INSTRUCTION_LOOKUPSWITCH_CHECK)
			{
			  p++;
			}
		      
		      /* default dest */
		      p++;
		      
		      npairs = source_code[p++].jint;
		      
		      for (z = 0; z < npairs; z++)
			{
			  p += 2;
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
		      if (env->vm->instructions[curr_instruction].flag !=
			  SVM_INTRP_FLAG_INLINEABLE)
			{
			  p += 2;
			}
		      else
			{
			  p++;
			}
		      break;
		    }

		  case SVM_INSTRUCTION_CHECKCAST:
		  case SVM_INSTRUCTION_INSTANCEOF:
		    {
		      p += 2;
		      break;
		    }
		    
		  case SVM_INSTRUCTION_REPLACE:
		    {
		      p += 2;
		      break;
		    }

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
		    
		  case SVM_INSTRUCTION_NEW:
		  case SVM_INSTRUCTION_ANEWARRAY:
		    {
		      p += 3;
		      break;
		    }
		    
		  case SVM_INSTRUCTION_INVOKEVIRTUAL:
		  case SVM_INSTRUCTION_INVOKESPECIAL:
		  case SVM_INSTRUCTION_INVOKESTATIC:
		  case SVM_INSTRUCTION_INVOKEINTERFACE:
		  case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
		  case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
		  case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
		  case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
		  case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
		  case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
		  case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
		  case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
		    		    
		  case SVM_INSTRUCTION_MULTIANEWARRAY:
		  case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:

		  case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
		    {
		      p += 4;
		      break;
		    }

		  case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
		  case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
		    {
		      if((i - 1) == invoke_offset)
			{
			  /* remember where the pc should be after inlining */
			  vm->mi_info.resuming_pc = merged_code + (merged_index-0) + (p - i);
			}
		      p += 4;
		      break;
		    }
		    
		  case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
		  case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
		    {
		      if((i - 1) == invoke_offset)
			{
			  /* remember where the pc should be after inlining */
			  vm->mi_info.resuming_pc = merged_code + (merged_index-0) + (p - i);
			}
		      p += (4 + INLINED_INVOKEVIRTUAL_EXTRA_PARAMS);
		      break;
		    }

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
		  case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
		    
		  case SVM_INSTRUCTION_INLINED_IRETURN:
		  case SVM_INSTRUCTION_INLINED_LRETURN:
		  case SVM_INSTRUCTION_INLINED_FRETURN:
		  case SVM_INSTRUCTION_INLINED_DRETURN:
		  case SVM_INSTRUCTION_INLINED_ARETURN:
		  case SVM_INSTRUCTION_INLINED_RETURN:
		    {
		      p++;
		      break;
		    }
		    
		  case SVM_INSTRUCTION_INLINED_RET:
		  case SVM_INSTRUCTION_INLINED_GOTO:
		    {
		      /* end of inlined code, skip stack_gc_map */
		      p += 2;
		      break;
		    }
		    
		  case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
		    {
		      /* end of inlined code, skip stack_gc_map */
		      p += 3;
		      break;
		    }
	  
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
		    
		  case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
		  case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
		  case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
		    {
		      p += 2;
		      break;
		    }
	  
		  case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
		  case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
		  case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
		    {
		      p += 3;
		      break;
		    }
		    
		  case SVM_INSTRUCTION_RET:
		    {
		      p++;
		      break;
		    }
		    
		  default:
		    {
		      /* curr_instruction has no parameter */
		      break;
		    }
		  } /* end of switch */
	      } /* end of for */
	    
	    nb_params = p - i;


/* 	    _svmf_printf(env, stderr, "nb_params [%d]\n", nb_params); */

	    /* copy params & update selected_path_map */
	    {
	      jint k; 

	      for(k = 0 ; k < nb_params ; k++)
		{
		  /* if we are in inlined code */
		  if((i >= invoke_offset) && (i < end_of_inlined_code_offset))
		  {
		    /* update selected_path_map */
		    selected_path_map[i - invoke_offset].addr = merged_code + merged_index;
		  }

/* 		  _svmf_printf(env, stderr, "copying param [%d] [%p]\n", merged_index, */
/* 			       merged_code+merged_index); */

		  merged_code[merged_index++] = source_code[i];
		  i++;
		}

	      if(copying_params_of_ending_seq)
		{
		  copying_params_of_ending_seq = JNI_FALSE;

		  if(add_extra_seq_following_inlined_method)
		    {
		      extra_sequence_nb_params = nb_params;

		      if(add_INLINED_JMP_OVER_NEXT_SEQ)
			{		  
			  /* put address relative to old code array, it will be converted 
			     later on in _svmf_mi_fix_calling_method_addresses() */
			  merged_code[merged_index].addr = old_code + (i - code_length_diff);
			  
			  /* 		  _svmf_printf(env, stderr, "%p extra goto dest %p\n", */
			  /* 			       merged_code + merged_index, */
			  /* 			       merged_code[merged_index].addr); */
			  
			  merged_index++;
			}
		    }		      
		}
	    }
	    
/* 	    _svmf_printf(env, stderr, "while3: i[%d] at the end of the loop\n", i); */

	  } /* End of Step 3 */	

	/* if we just finished copying the last sequence of the inlined 
	   callee method, add extra sequence */
	if(building_final_callee_method_seq)
	  {
	    building_final_callee_method_seq = JNI_FALSE;
	    
	    /* remember the offset of the ending sequence */
	    following_inlined_callee_method_offset = merged_index;
	    
/* 	    _svmf_printf(env, stderr, "after inlined callee method merged_index[%d]\n",  */
/* 			 merged_index); */
	    
	    if(add_extra_seq_following_inlined_method)
	      {
		jint k;
		jint p;
		jint nb_params;
		_svmt_mi_sequence_node_info *extra_sequence;

		if ((extra_sequence =
		     _svmf_mi_get_sequence_by_implementation 
		     (env, source_code[end_of_inlined_code_offset].implementation)) == NULL)
		  {
		    assert (1 == 0);
		    return JNI_ERR;
		  }
		
		merged_code[merged_index++].implementation = extra_sequence->implementation;

		/* get this sequence's addr in the old code array */
		seq_old_code_addr = old_code + end_of_inlined_code_offset - code_length_diff;
	    
		if((nb_params = 
		    _svmf_mi_get_sequence_nb_params (env, extra_sequence, 
						     seq_old_code_addr, 
						     old_code_length)) < 0)
		  {
		    assert(1 == 0);
		    return JNI_ERR;
		  }
		
		p = end_of_inlined_code_offset + 1;

		/* copy params */
		for(k = 0 ; k < nb_params ; k++)
		  {
		    merged_code[merged_index++] = source_code[p++];
		  }		
	      }
	  }	
      }

/*     _svmf_printf(env, stderr, "i[%d] after merge\n", i); */
    assert(i == preparation_sequences_offset);
    
    /* Process code after preparation sequences */
    while(i < source_code_length)
      {
	/* no merge needed */
	merged_code[merged_index++] = source_code[i++];
      }
  }

  /* readjust code_length_diff */
  vm->mi_info.code_length_diff -= (source_code_length - merged_index);

  /* fix inlined_code_length that is an inlined_invoke<x> parameter */
  {
    jint extra_params = extra_sequence_nb_params;
    
    /* we add 1 to extra_sequence_nb_params to take into account
       the parameter of trailing goto that jumps over the extra
       sequence */
    if(add_INLINED_JMP_OVER_NEXT_SEQ)
      {
	extra_params++;
      }
    
/*     if ((env->vm->mi_info.inst_count_times >= 156) && */
/* 	(env->vm->mi_info.inst_count >= 26125020 )) */
/*       { */
/* 	_svmf_mi_output_code_array (env, stderr, merged_code, merged_index, */
/* 				    "merged code before fix\n", old_code, old_code_length); */
/*       } */


    if(_svmf_mi_fix_inlinedinvoke_param(env, merged_code, old_code,
					old_code_length,
					extra_params,
					resuming_seq_index,
					following_inlined_callee_method_offset)
       != JNI_OK)
      {
	assert(1 == 0);
	return JNI_ERR;
      }
  }

  /* replace non merged code by merged code */
  {
    size_t i;
    size_t max = callee_method->frame_info->selected_path_code_length;

    _svmt_code *code;
    _svmt_class_loader_info *cli = calling_method->class_info->class_loader_info;
    
    if (_svmm_cl_malloc_code (env, cli, merged_index, code) != JNI_OK)
      {
#ifndef NDEBUG
	_svmm_fatal_error("method inlining: memory malloc failed\n");
#endif
	return JNI_ERR;
      } 
    
    memcpy(code, merged_code, merged_index * sizeof(_svmt_code));
    _svmm_cl_mfree_code (env, cli, source_code_length, source_code);    
    
    vm->mi_info.code_length_diff = merged_index - old_code_length; 
    calling_method->frame_info->preparation_sequences_offset -=  
      (source_code_length - merged_index);

    *non_merged_code = code;
    *non_merged_code_length = merged_index;

    /* convert selected_path_map */
    for(i = 0; i < max; i++)
      {
	if(selected_path_map[i].addr != NULL)
	  {
	    selected_path_map[i].addr =
	      code + (selected_path_map[i].addr - merged_code);
	  }
      }

    /* readjust resuming_pc */
    vm->mi_info.resuming_pc = code + (vm->mi_info.resuming_pc - merged_code);

/*     _svmf_mi_output_code_array (env, stderr, code, merged_index, */
/* 				"merged code after fix\n", old_code, old_code_length); */

  }
  
#if !defined(NDEBUG) && 0
  /* output the merged  array */
  {
    FILE *file = vm->mi_info.code_arrays;
    
    if(file == NULL)
      {
	if((file = fopen ("code_arrays.txt", "a")) == NULL)
	  {
	    _svmm_fatal_error("impossible to open file");
	  }
	vm->mi_info.code_arrays = file;
      }
    
    file = stderr;

    _svmf_mi_output_code_array(env, file, merged_code, 
			       merged_index, "Merged code working array", 
			       old_code, old_code_length);
    
    _svmf_printf(env, stderr, "\n");
  }
#endif
  
  /* output selected path map */
  {
/*     size_t i; */
    
/*     _svmf_printf(env, stderr, "selected_path_map:\n");  */
/*     for(i = 0 ; i < callee_method->frame_info->selected_path_code_length; i++) */
/*       { */
/* 	_svmf_printf(env, stderr, "selected_path_map[%d]=%p\n", i,  */
/* 		     selected_path_map[i].addr); */
/*       } */
/*     _svmf_printf(env, stderr, "\n");  */
  }

/*   _svmf_printf(env, stderr, "_svmf_mi_merge_sequences: out\n"); */
  
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mi_get_instruction_int_code: returns the address of the 
beginning of the first occurence of 'bytecode' in the sequence.
----------------------------------------------------------------------
*/
svm_static const void*
_svmf_mi_get_bytecode_impl_in_sequence(SVM_UNUSED _svmt_JNIEnv *env, 
				       _svmt_mi_sequence_node_info *sequence,
				       jint bytecode)
{
  _svmt_JavaVM *vm = env->vm;

  jint inst;
  jint *instructions;
  jint curr_instruction;
  jint instructions_length;
  const void *implementation;
  
/*   _svmf_printf(env, stderr, "_svmf_mi_get_bytecode_impl_in_sequence:\n"); */

  assert((sequence != NULL) && (bytecode >= 0));

  instructions = sequence->instructions;
  instructions_length = sequence->instructions_length;
  implementation = sequence->implementation;
  
  if (sequence->starts_with_skip)
    {
      size_t j;
      size_t size = vm->instructions[SVM_INSTRUCTION_SKIP].inlined_size;
      
      for (j = 0; j < size; j++)
	{
	  implementation = ((char *) implementation) + 1;
	}      
    }

  for (inst = 0; inst < instructions_length; inst++)
    {
      curr_instruction = instructions[inst];
      
      if(curr_instruction == bytecode)
	{
/* 	  _svmf_printf(env, stderr, "returning @ of inst[%d] in ", inst); */
/* 	  _svmf_mi_print_super_instruction(env, stderr, sequence->implementation); */
/* 	  _svmf_printf(env, stderr, "\n"); */
	  return implementation;
	}
      else
	{
	  size_t j;
	  size_t size = vm->instructions[curr_instruction].inlined_size;
      
	  for (j = 0; j < size; j++)
	    {
	      implementation = ((char *) implementation) + 1;
	    }      	  
	}
    }
  
  return NULL;
}

#endif/* _SABLEVM_INLINED_THREADED_INTERPRETER */


/*
----------------------------------------------------------------------
_svmf_mi_get_instruction_int_code
----------------------------------------------------------------------
*/
svm_static jint
_svmf_mi_fix_addresses_in_checkpoints (SVM_UNUSED _svmt_JNIEnv *env,
				       _svmt_code *code,
				       size_t code_length,
				       _svmt_code *conversion_table)
{
  size_t i = 0;
  jint curr_instruction;
  
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  jint inst;
  jint *instructions;
  jint instructions_length;
  _svmt_mi_sequence_node_info *sequence;
#endif

  /*   _svmf_printf(env, stderr, "_svmf_mi_fix_addresses_in_checkpoints:\n"); */

  /* Walk through inlined path */
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
	   _svmf_mi_get_sequence_by_implementation
	   (env, code[i++].implementation)) == NULL)
	{
	  assert (1 == 0);
	  return JNI_ERR;
	}

      instructions = sequence->instructions;
      instructions_length = sequence->instructions_length;

      if (sequence->starts_with_skip)
	{
	  i++;
	}

      for (inst = 0; inst < instructions_length; inst++)
	{
	  curr_instruction = instructions[inst];
#endif

/* 	  _svmf_printf (env, stderr, "%p[%s]\n", code+i, */
/* 			env->vm->instructions[curr_instruction].name); */
	  
	  assert ((curr_instruction >= 0) &&
		  (curr_instruction < SVM_INSTRUCTION_COUNT));

	  switch (curr_instruction)
	    {
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
	    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	    case SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_PROFILING_INVOKESPECIAL:
	    case SVM_INSTRUCTION_PROFILING_INVOKESTATIC:
	    case SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE:
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
	    case SVM_INSTRUCTION_REPLACE:
	    case SVM_INSTRUCTION_TABLESWITCH:
	    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	    case SVM_INSTRUCTION_GOTO:
	    case SVM_INSTRUCTION_GOTO_CHECK:

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
#endif
	      {
		/* should never be found in inlined path */
		assert (1 == 0);
		return JNI_ERR;
	      }

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
	      {
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_IINC:
	    case SVM_INSTRUCTION_CHECKCAST:
	    case SVM_INSTRUCTION_INSTANCEOF:
	      {
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_NEW:
	    case SVM_INSTRUCTION_ANEWARRAY:
	      {
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_MULTIANEWARRAY:
	      {
		i += 4;
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
		    i += 2;
		  }
		else
		  {
		    i += 1;
		  }
#else
		i += 2;
#endif
		break;
	      }

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
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:
	      {
		code[i].addr = conversion_table + code[i].jint;
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_RET:
	      {
		/* end of inlined code, skip stack_gc_map */
		i += 2;		
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_GOTO:
	      {
		code[i].addr = conversion_table + code[i].jint;
		
		/* end of inlined code, skip stack_gc_map */
		i += 2;		
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	      {
		i++;
		code[i].addr = conversion_table + code[i].jint;
		
		/* end of inlined code, skip stack_gc_map */
		i += 2;
		break;		
	      }

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
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
	      {
		i++;
		code[i].addr = conversion_table + code[i].jint;
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	      {
		code[i].addr = conversion_table + code[i].jint;
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
	      {
		i++;
		code[i].addr = conversion_table + code[i].jint;
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	      {
		code[i].addr = conversion_table + code[i].jint;
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	      {
		i++;
		code[i].addr = conversion_table + code[i].jint;
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_IRETURN:
	    case SVM_INSTRUCTION_INLINED_LRETURN:
	    case SVM_INSTRUCTION_INLINED_FRETURN:
	    case SVM_INSTRUCTION_INLINED_DRETURN:
	    case SVM_INSTRUCTION_INLINED_ARETURN:
	    case SVM_INSTRUCTION_INLINED_RETURN:
	      {
		/* skip final stack_gc_map */
		i++;
		break;
	      }

	      /* curr_instruction has no parameters */
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
_svmf_mi_fix_calling_method_addresses
----------------------------------------------------------------------
*/
svm_static jint
_svmf_mi_fix_calling_method_addresses (SVM_UNUSED _svmt_JNIEnv *env,
				       _svmt_method_info *method,
				       _svmt_code *new_code,
				       size_t new_length,
				       jint invoke_offset)
{
  size_t i = 0;
  jint curr_instruction = -1;
  jint code_length_diff = env->vm->mi_info.code_length_diff;

  _svmt_code *target;
  _svmt_code *old_code = method->frame_info->code;
  _svmt_code *after_invoke_site_addr = old_code + invoke_offset + 4;


#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  jint inst;
  jint *instructions;
  jint instructions_length;
  _svmt_mi_sequence_node_info *sequence;
  size_t old_length = method->frame_info->code_length;
#endif

/*   _svmf_printf(env, stderr, "_svmf_mi_fix_calling_method_addresses:\n"); */

  while (i < new_length)
    {
      
#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
      curr_instruction = new_code[i++].jint;
#endif
      
#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
      curr_instruction =
	_svmf_mi_get_instruction_int_code (env,
					   new_code[i++].implementation);
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

/* 	  _svmf_printf(env, stderr, "get sequence for: %p new_code[%d]\n", */
/* 		       new_code+i, i); */

      if ((sequence =
	   _svmf_mi_get_sequence_by_implementation (env,
						    new_code[i++].
						    implementation)) ==
	  NULL)
	{
	  assert (1 == 0);
	  return JNI_ERR;
	}
      
      instructions = sequence->instructions;
      instructions_length = sequence->instructions_length;
      
      /* Used for GOTO that has multiple parameters,
	 if it jumps to a preparation sequence */
    process_params:
      
      if (sequence->starts_with_skip)
	{
	  i++;
	}
      
      for (inst = 0; inst < instructions_length; inst++)
	{
	  curr_instruction = instructions[inst];
#endif
	  
/* 	  _svmf_printf(env, stderr, "new_code[%d] %p curr_instruction[%s]\n", i-1, */
/* 		       new_code+i-1,env->vm->instructions[curr_instruction].name); */

/* 	  _svmf_printf(env, stderr, "new_code[186]=%p\n", new_code[186].addr); */
	  
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

	    case SVM_INSTRUCTION_SKIP:
	      {
		i++;
		break;
	      }
	      
	    case SVM_INSTRUCTION_IINC:
	      {
		i += 2;
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
		target = new_code[i].addr;
		
		if (target > after_invoke_site_addr)
		  {
		    target += code_length_diff;
		  }
		
		new_code[i].addr = new_code + (target - old_code);
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_GOTO:
	    case SVM_INSTRUCTION_GOTO_CHECK:

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
#endif
	      {
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		_svmt_code *addr_before_fix;
#endif
		if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
		  {
		    i++;
		  }

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		addr_before_fix = new_code[i].addr;
#endif
		target = new_code[i].addr;
		
		if (target > after_invoke_site_addr)
		  {
		    target += code_length_diff;
		  }
		    
#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
		curr_instruction = (new_code[i].addr)->jint;
#endif
		
#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
		curr_instruction =
		  _svmf_mi_get_instruction_int_code (env,
						     (new_code[i].addr)->
						     implementation);
#endif

		new_code[i].addr = new_code + (target - old_code);

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER		
/* 		_svmf_printf(env, stderr, "*curr_instruction[%d]\n", curr_instruction); */
		
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

		  default:
		    {
		      /* not a preparation sequence */
		      i++;
		    }
		  }		/* end of inner switch */

#else /* !_SABLEVM_INLINED_THREADED_INTERPRETER */
		
		/* this GOTO must be at the of the sequence */
		assert (inst == (instructions_length - 1));

/* 		_svmf_printf(env, stderr, "GOTO: addr_before_fix[%p] end_old_code[%p]\n",  */
/* 			     addr_before_fix, old_code + old_length - 1); */

		/* look in old code array were addresses are consistent,
		   To see if this GOTO is jumping to a preparation sequence */
		if (_svmm_mp_is_preparation_sequence (env, 
						      addr_before_fix,
						      old_code +
						      old_length,
						      sequence))
		  {
/* 		    _svmf_printf(env, stderr, "GOTO: preparation sequence\n"); */
		    instructions = sequence->instructions;
		    instructions_length = sequence->instructions_length;
		    goto process_params;
		  }
		else
		  {
		    i++;
/* 		    _svmf_printf(env, stderr, "GOTO: NOT! preparation sequence\n"); */
		  }
#endif
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
	    case SVM_INSTRUCTION_JSR_CHECK:
	    case SVM_INSTRUCTION_IFNULL_CHECK:
	    case SVM_INSTRUCTION_IFNONNULL_CHECK:
	      {
		i++;
		target = new_code[i].addr;

		if (target > after_invoke_site_addr)
		  {
		    target += code_length_diff;
		  }

		new_code[i].addr = new_code + (target - old_code);

		i++;
		break;
	      }

	    case SVM_INSTRUCTION_TABLESWITCH:
	    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	      {
		jint z, low, high, length;

		if (curr_instruction == SVM_INSTRUCTION_TABLESWITCH_CHECK)
		  {
		    i++;	/* skip stack_gc_map */
		  }

		/* Default dest. */
		target = new_code[i].addr;

		if (target > after_invoke_site_addr)
		  {
		    target += code_length_diff;
		  }

		new_code[i].addr = new_code + (target - old_code);
		i++;

		low = new_code[i++].jint;
		high = new_code[i++].jint;
		length = high - low + 1;

		for (z = 0; z < length; z++)
		  {
		    target = new_code[i].addr;

		    if (target > after_invoke_site_addr)
		      {
			target += code_length_diff;
		      }

		    new_code[i].addr = new_code + (target - old_code);
		    i++;
		  }
		break;
	      }

	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	      {
		jint z, npairs;

		if (curr_instruction == SVM_INSTRUCTION_LOOKUPSWITCH_CHECK)
		  {
		    i++;
		  }

		/* default dest */
		target = new_code[i].addr;

		if (target > after_invoke_site_addr)
		  {
		    target += code_length_diff;
		  }

		new_code[i].addr = new_code + (target - old_code);
		i++;

		npairs = new_code[i++].jint;

		for (z = 0; z < npairs; z++)
		  {
		    i++;
		    target = new_code[i].addr;
		    if (target > after_invoke_site_addr)
		      {
			target += code_length_diff;
		      }

		    new_code[i].addr = new_code + (target - old_code);
		    i++;
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
		    i += 2;
		  }
		else
		  {
		    i++;
		  }
#else
		i += 2;
#endif
		break;
	      }

	    case SVM_INSTRUCTION_CHECKCAST:
	    case SVM_INSTRUCTION_INSTANCEOF:
	      {
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_REPLACE:
	      {
		target = new_code[i].addr;
		
		/* this concerns the current invoke being inlined */
		if(target == (old_code + env->vm->mi_info.invoke_offset))
		  {
		    /* Assure that if the frame->pc is on a REPLACE it won't overwrite
		       inlined code */
		    new_code[i-1] = env->vm->instructions[SVM_INSTRUCTION_NOP].code;
		    new_code[i]   = env->vm->instructions[SVM_INSTRUCTION_NOP].code;
		    new_code[i+1] = env->vm->instructions[SVM_INSTRUCTION_NOP].code;
		  }
		else /* fix address */
		  {
		    if (target > after_invoke_site_addr)
		      {
			target += code_length_diff;
		      }
		    
		    new_code[i].addr = new_code + (target - old_code);
		  }
		
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_PREPARE_LDC_STRING:
	      {
		target = new_code[i].addr;

		if (target > after_invoke_site_addr)
		  {
		    target += code_length_diff;
		  }

		new_code[i].addr = new_code + (target - old_code);
		i += 3;
		break;
	      }

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
		target = new_code[i].addr;

		if (target > after_invoke_site_addr)
		  {
		    target += code_length_diff;
		  }

		new_code[i].addr = new_code + (target - old_code);
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_NEW:
	    case SVM_INSTRUCTION_ANEWARRAY:
	      {
		i += 3;
		break;
	      }

	    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	      {
		target = new_code[i].addr;

		if (target > after_invoke_site_addr)
		  {
		    target += code_length_diff;
		  }

		new_code[i].addr = new_code + (target - old_code);
		i += 4;
		break;
	      }

	    case SVM_INSTRUCTION_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INVOKESTATIC:
	    case SVM_INSTRUCTION_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	    case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	    case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK:
	    case SVM_INSTRUCTION_MULTIANEWARRAY:
	      {
		i += 4;
		break;
	      }
	      
	    case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
	      {
		i += (4 + INLINED_INVOKEVIRTUAL_EXTRA_PARAMS);
		break;
	      }

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
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT:

	    case SVM_INSTRUCTION_INLINED_IRETURN:
	    case SVM_INSTRUCTION_INLINED_LRETURN:
	    case SVM_INSTRUCTION_INLINED_FRETURN:
	    case SVM_INSTRUCTION_INLINED_DRETURN:
	    case SVM_INSTRUCTION_INLINED_ARETURN:
	    case SVM_INSTRUCTION_INLINED_RETURN:
	      {
		i++;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_RET:
	    case SVM_INSTRUCTION_INLINED_GOTO:
	      {
		/* end of inlined code, skip stack_gc_map */
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_GOTO_CHECK:
	      {
		/* end of inlined code, skip stack_gc_map */
		i += 3;
		break;
	      }

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

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK:
	      {
		i += 2;
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT:
	    case SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK:
	    case SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK:
	      {
		i += 3;
		break;
	      }

	    default:
	      {
		/* curr_instruction has no parameter */
		break;
	      }
	    }		/* end of switch */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	}			/* end of for */
#endif

    }			/* end of while */

  return JNI_OK;
}

/*
  ----------------------------------------------------------------------
  _svmf_mi_get_if_condition_inverted
  --
  Returns the inlined if-instruction containing negation of the 
  condition the the 'inst' instruction 
  ----------------------------------------------------------------------
*/
inline svm_static jint
_svmf_mi_get_if_condition_inverted (jint inst)
{
  jint result = -1;

  switch (inst)
    {
    case SVM_INSTRUCTION_PROFILING_IFEQ:
      {
	result = SVM_INSTRUCTION_INLINED_IFNE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNE:
      {
	result = SVM_INSTRUCTION_INLINED_IFEQ;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFLT:
      {
	result = SVM_INSTRUCTION_INLINED_IFGE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFGE:
      {
	result = SVM_INSTRUCTION_INLINED_IFLT;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFGT:
      {
	result = SVM_INSTRUCTION_INLINED_IFLE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFLE:
      {
	result = SVM_INSTRUCTION_INLINED_IFGT;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPEQ:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPNE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPNE:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPEQ;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPLT:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPGE:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLT;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPGT:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPLE:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGT;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ACMPEQ:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPNE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ACMPNE:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPEQ;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNULL:
      {
	result = SVM_INSTRUCTION_INLINED_IFNONNULL;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNONNULL:
      {
	result = SVM_INSTRUCTION_INLINED_IFNULL;
	break;
      }

    case SVM_INSTRUCTION_PROFILING_IFEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFLT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFGE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFGE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFLT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFGT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFLE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFLE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFGT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPLT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPGE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPGT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPLE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ACMPEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ACMPNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNULL_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNONNULL_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNONNULL_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNULL_CHECK;
	break;
      }
    default:
      {
	_svmm_fatal_error ("impossible control flow");
      }
    }

  return result;
}

/*
  ----------------------------------------------------------------------
  _svmf_get_inlined_if_instruction
  --
  Returns the special if-instruction corresponding to 'inst'
  ----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_mi_get_inlined_if_instruction (jint inst)
{
  jint result = -1;

  switch (inst)
    {
    case SVM_INSTRUCTION_PROFILING_IFEQ:
      {
	result = SVM_INSTRUCTION_INLINED_IFEQ;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNE:
      {
	result = SVM_INSTRUCTION_INLINED_IFNE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFLT:
      {
	result = SVM_INSTRUCTION_INLINED_IFLT;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFGE:
      {
	result = SVM_INSTRUCTION_INLINED_IFGE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFGT:
      {
	result = SVM_INSTRUCTION_INLINED_IFGT;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFLE:
      {
	result = SVM_INSTRUCTION_INLINED_IFLE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPEQ:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPEQ;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPNE:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPNE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPLT:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLT;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPGE:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPGT:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGT;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPLE:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ACMPEQ:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPEQ;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ACMPNE:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPNE;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNULL:
      {
	result = SVM_INSTRUCTION_INLINED_IFNULL;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNONNULL:
      {
	result = SVM_INSTRUCTION_INLINED_IFNONNULL;
	break;
      }

    case SVM_INSTRUCTION_PROFILING_IFEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFLT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFLT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFGE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFGE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFGT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFGT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFLE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFLE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPLT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPGE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPGT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ICMPLE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ACMPEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IF_ACMPNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNULL_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNULL_CHECK;
	break;
      }
    case SVM_INSTRUCTION_PROFILING_IFNONNULL_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNONNULL_CHECK;
	break;
      }

    case SVM_INSTRUCTION_IFEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IFNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IFLT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFLT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IFGE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFGE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IFGT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFGT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IFLE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFLE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IF_ICMPEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IF_ICMPNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IF_ICMPLT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IF_ICMPGE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IF_ICMPGT_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPGT_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IF_ICMPLE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ICMPLE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IF_ACMPEQ_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPEQ_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IF_ACMPNE_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IF_ACMPNE_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IFNULL_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNULL_CHECK;
	break;
      }
    case SVM_INSTRUCTION_IFNONNULL_CHECK:
      {
	result = SVM_INSTRUCTION_INLINED_IFNONNULL_CHECK;
	break;
      }
    default:
      {
	_svmm_fatal_error ("impossible control flow");
      }
    }

  return result;
}

/*
----------------------------------------------------------------------------
_svmf_mi_select_path_to_inline 
----------------------------------------------------------------------------
*/

svm_static jint
_svmf_mi_select_path_to_inline (_svmt_JNIEnv *env,
				_svmt_method_info *calling_method,
				_svmt_method_info *callee_method)
{
  _svmt_JavaVM *vm = env->vm;
  jint invoke_instruction = vm->mi_info.invoke_instruction;

  size_t c;			/* index of current instruction in calling code array */
  size_t s = 0;			/* index of current instruction in source code array  */
  size_t p = 0;			/* index of current instruction in selected path code array  */

  _svmt_code *path;		/* selected path to be inlined */
  _svmt_code *map;	/* used to build new exception table */
  _svmt_code *addresses;	/* used to build new exception table */
  jint curr_instruction;
  jint path_begin_index;
  jint invoke_offset = vm->mi_info.invoke_offset;

  _svmt_code *profiling_code = callee_method->frame_info->profiling_code;
  _svmt_code *calling_code = calling_method->frame_info->code;
  size_t profiling_code_length =
    callee_method->frame_info->profiling_code_length;
  size_t max_size;

  _svmt_class_loader_info *cli = callee_method->class_info->class_loader_info;

/*   _svmf_printf(env, stderr, "_svmf_mi_select_path_to_inline:\n"); */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

  size_t i;			/* index of the current instruction in the current sequence */
  size_t instructions_length;
  jint last_sequence_index;
  jint *instructions;
  _svmt_mi_sequence_node_info *sequence;

#endif 
    
  /* +1 for stack_gc_map at the end */
  /* +5 for INLINED_INVOKE<X> params */
  max_size = profiling_code_length + 6;
  
  if ((invoke_instruction == SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL) ||
      (invoke_instruction == SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE))
    {
      max_size += INLINED_INVOKEVIRTUAL_EXTRA_PARAMS;
    }
  
  /* check if working arrays are big enough */
  if (vm->mi_info.selected_path_working_arrays_length < max_size)
    {
      /* *2: minimize future reallocs */
      size_t length = max_size * 2;

      if ((vm->mi_info.selected_path_working_array =
	   _svmm_realloc (vm->mi_info.selected_path_working_array,
			  length * sizeof (_svmt_code))) == NULL)
	{
#ifndef NDEBUG
	  _svmm_fatal_error ("method inlining: memory realloc failed\n");
#endif
	  return JNI_ERR;
	}  

      if ((vm->mi_info.selected_path_to_original_code_map =
	   _svmm_realloc (vm->mi_info.selected_path_to_original_code_map,
			  length * sizeof (_svmt_code))) == NULL)
	{
#ifndef NDEBUG
	  _svmm_fatal_error("method inlining: memory realloc failed\n");
#endif
	  return JNI_ERR;
	}

      if ((vm->mi_info.selected_path_to_new_code_map =
	   _svmm_realloc (vm->mi_info.selected_path_to_new_code_map,
			  length * sizeof (_svmt_code))) == NULL)
	{
#ifndef NDEBUG
	  _svmm_fatal_error ("method inlining: memory realloc failed\n");
#endif
	  return JNI_ERR;
	}
            
      vm->mi_info.selected_path_working_arrays_length = length;
    }

  path = vm->mi_info.selected_path_working_array;
  addresses = vm->mi_info.selected_path_to_original_code_map;
  map = vm->mi_info.selected_path_to_new_code_map;

  /* init the addresses working arrays array */
  {
    size_t z;
    
    for(z = 0 ; z < vm->mi_info.selected_path_working_arrays_length; z++)
      {
	addresses[z].addr = NULL;
	map[z].addr = NULL;
      } 
  }

  /* start building the path */

  switch (invoke_instruction)
    {
    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
      {
	path[p++] =
	  vm->instructions[SVM_INSTRUCTION_INLINED_INVOKESTATIC].code;
	break;
      }
    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
      {
	path[p++] =
	  vm->instructions[SVM_INSTRUCTION_INLINED_INVOKESPECIAL].code;
	break;
      }
    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
      {
	path[p++] =
	  vm->instructions[SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL].code;
	break;
      }
    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
      {
	path[p++] =
	  vm->instructions[SVM_INSTRUCTION_INLINED_INVOKEINTERFACE].code;
	break;
      }
    default:
      _svmm_fatal_error ("Invalid invoke instruction");
    }
  
  /* Check if the job was already done from another invoke site */
  if(callee_method->frame_info->selected_path != NULL)
    {
      _svmt_method_frame_info *frame = callee_method->frame_info;
      
#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
      if(path[0].jint == frame->selected_path[0].jint)
#else
      if(path[0].implementation == frame->selected_path[0].implementation)
#endif
	{
	  /* The invoke types match, The job is already done */
	  return JNI_OK;
	}
      else
	{
	  /* Selected path already present for this method was build from
	     a different invoke type. We destroy the old one et redo the 
	     job. We must also destroy the exception table associated with
	     the path */
	  _svmm_cl_mfree_code (env, cli, frame->selected_path_code_length,
			       frame->selected_path);
	  
	  frame->selected_path = NULL;
	  frame->selected_path_code_length = 0;
	  
	  if(frame->selected_path_exception_table != NULL)
	    {
	      _svmm_cl_zmfree_exception_table
		(env, cli, frame->selected_path_exception_table_nb_entries, 
		 frame->selected_path_exception_table);
	      
	      frame->selected_path_exception_table = NULL;
	      frame->selected_path_exception_table_nb_entries = 0;
	    }
	}
    }

  p++;				/* skip inlined_code_length index */

  /* copy inlined @method_info */
  if ((invoke_instruction == SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL) ||
      (invoke_instruction == SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE))
    {
      path[p++].method_info = callee_method;
    }

  c = invoke_offset + 2;

  path[p++] = calling_code[c++];	/* copy args_count */
  path[p++] = calling_code[c++];	/* copy @method_info or method_offset */
  path[p++] = calling_code[c++];	/* copy @stack_gc_map */
  
  path_begin_index = p;

  while (s < profiling_code_length)
    {
#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
      curr_instruction = profiling_code[s].jint;

      path[p] = profiling_code[s];
      addresses[p++].addr = profiling_code + (s++);
#endif

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER
      curr_instruction =
	_svmf_mi_get_instruction_int_code (env,
					   profiling_code[s].implementation);

      path[p] = profiling_code[s];
      addresses[p++].addr = profiling_code + (s++);
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

/*       _svmf_printf(env, stderr, "top while loop: r=%d  s=%d\n", r, s); */

/*       _svmf_printf(env, stderr, "looking for: profiling_code[%d].implementation=%p\n", */
/* 		   s, profiling_code[s].implementation); */

      if ((sequence =
	   _svmf_mi_get_sequence_by_implementation (env,
						    profiling_code[s].
						    implementation)) == NULL)
	{
	  assert (1 == 0);
	  return JNI_ERR;
	}

      last_sequence_index = p;
      instructions = sequence->instructions;
      instructions_length = sequence->instructions_length;

      path[p] = profiling_code[s];
      addresses[p++].addr = profiling_code + (s++);

      if (sequence->starts_with_skip)
	{
	  path[p++] = profiling_code[s++];
	}

      for (i = 0; i < instructions_length; i++)
	{
	  curr_instruction = instructions[i];

/* 	  _svmf_printf(env, stderr, "top for loop: i=%d  curr_instruction=%s\n", */
/* 		       i, vm->instructions[curr_instruction].name); */

/* 	  _svmf_printf(env, stderr, "path[%d]\n", r); */
/* 	  _svmf_printf(env, stderr, "path[48]=%p\n", path[48].implementation); */

#endif

	  assert ((curr_instruction >= 0) &&
		  (curr_instruction < SVM_INSTRUCTION_COUNT));

	  switch (curr_instruction)
	    {
	      /* we are not profiling backward jumps, these bytecodes should 
	         never be found in the profiling code array */
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

	      /* these instructions should never be found in profiling code array */
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

	      /* should not be found on path to inline */
	    case SVM_INSTRUCTION_REPLACE:
	      {
		return JNI_ERR;
	      }

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
	    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	      {
#if 0
		/* if we did not profile the callee method long enough,
		   it's possible that we encounter one of these bytecodes
		   in the path, then the callee method is marked not
		   inlinable to prevent other invoke site to try the
		   inlining of this method */

		callee_method->frame_info->inlinable = JNI_FALSE;
		return JNI_ERR;
#endif
		/* if we did not profile the callee method long enough,
		   it's possible that we encounter one of these bytecodes
		   in the path, it then marks the end of the path we inline */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

		/* we assume this bytecode in not inlinable and 
		   is alone in it's sequence */
		assert ((vm->instructions[curr_instruction].flag !=
			 SVM_INTRP_FLAG_INLINEABLE)
			&& (instructions_length == 1));

		path[p - 1] =
		  vm->instructions[SVM_INSTRUCTION_INLINED_GOTO].code;

#else
		path[p - 1] =
		  vm->instructions[SVM_INSTRUCTION_INLINED_GOTO].code;
#endif

		/* end of sequence, jumping back to original non profiling code */
		/* keep offset (from the beginning of original code) for the moment */
		path[p++].jint = _svmf_mp_get_old_offset (callee_method,
							    profiling_code +
							    s - 1);

		/* for ending stack_gc_map */
		p++;
		goto finished;
	      }

	    case SVM_INSTRUCTION_ILOAD:
	    case SVM_INSTRUCTION_FLOAD:
	    case SVM_INSTRUCTION_ISTORE:
	    case SVM_INSTRUCTION_FSTORE:
	    case SVM_INSTRUCTION_LLOAD:
	    case SVM_INSTRUCTION_DLOAD:
	    case SVM_INSTRUCTION_LSTORE:
	    case SVM_INSTRUCTION_DSTORE:
	    case SVM_INSTRUCTION_ALOAD:
	    case SVM_INSTRUCTION_ASTORE:
	    case SVM_INSTRUCTION_ASTORE_RET:

	    case SVM_INSTRUCTION_LDC_INTEGER:
	    case SVM_INSTRUCTION_LDC_FLOAT:
	    case SVM_INSTRUCTION_LDC_LONG:
	    case SVM_INSTRUCTION_LDC_DOUBLE:
	    case SVM_INSTRUCTION_NEWARRAY_BOOLEAN:
	    case SVM_INSTRUCTION_NEWARRAY_CHAR:
	    case SVM_INSTRUCTION_NEWARRAY_FLOAT:
	    case SVM_INSTRUCTION_NEWARRAY_DOUBLE:
	    case SVM_INSTRUCTION_NEWARRAY_BYTE:
	    case SVM_INSTRUCTION_NEWARRAY_SHORT:
	    case SVM_INSTRUCTION_NEWARRAY_INT:
	    case SVM_INSTRUCTION_NEWARRAY_LONG:

	    case SVM_INSTRUCTION_MONITORENTER:
	    case SVM_INSTRUCTION_SKIP:
	      {
		path[p++] = profiling_code[s++];
		break;
	      }

	    case SVM_INSTRUCTION_IINC:
	      {
		path[p++].jint = profiling_code[s++].jint;
		path[p++].jint = profiling_code[s++].jint;
		break;
	      }

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
		_svmt_code *target = profiling_code[s++].addr;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

		size_t idx = 0;
		jint *instructions_tmp = NULL;
		_svmt_mi_sequence_node_info *sequence_tmp;
		size_t implementation_length = sequence->implementation_length;
		
		/* we must be at the end of the sequence since 
		   curr_instruction is a branching bytecode */
		assert (i == (instructions_length - 1));

		if(instructions_length > 1)
		  {
		    implementation_length -=
		      vm->instructions[curr_instruction].inlined_size;
		    
		    if (_svmm_gmalloc_ints
			(env, instructions_length,
			 instructions_tmp) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    
		    /* copy the n-1 elems of the sequence's instructions array */
		    for (idx = 0; idx < instructions_length - 1; idx++)
		      {
			instructions_tmp[idx] = instructions[idx];
		      }
		  }
#endif
		/* If the branch is backwards, we inline the non branching path */
		if (target < (profiling_code + s))
		  {
		    /* overwrite counter value */
		    profiling_code[s].jint = -1;
		  }

		/* if we choose the branching path */
		if (profiling_code[s++].jint >0)
		  {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER

		    /* Check Point: if we should not branch, return to normal code */
		    jint inst =
		      _svmf_mi_get_if_condition_inverted (curr_instruction);
		    assert (inst >= 0);
		    path[p - 1] = vm->instructions[inst].code;
#else
		    if (instructions_length == 1)
		      {
			/* Check Point: if we should not branch, return to normal code */
			jint inst =
			  _svmf_mi_get_if_condition_inverted
			  (curr_instruction);
			path[last_sequence_index] =
			  vm->instructions[inst].code;
		      }
		    else
		      {
			/* Check Point: if we should not branch, return to normal code */
			instructions_tmp[idx] =
			  _svmf_mi_get_if_condition_inverted
			  (curr_instruction);
			implementation_length +=
			  vm->instructions[instructions_tmp[idx]].
			  inlined_size;
			
			if (_svmm_mi_get_sequence
			    (env, instructions_tmp, instructions_length,
			     implementation_length,
			     sequence_tmp,
			     sequence->starts_with_skip) != JNI_OK)
			  {
			    return JNI_ERR;
			  }
			
			path[last_sequence_index].implementation =
			  sequence_tmp->implementation;
		      }
#endif
		    /* keep offset (from the beginning of original code) for the moment */
		    path[p++].jint = _svmf_mp_get_old_offset (callee_method,
								profiling_code+s);

		    s = target - profiling_code;	/* jump forward */
		  }
		else		/* if we choose the non-branching path */
		  {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER

		    /* Check Point: if we should branch, return to original code */
		    jint inst =
		      _svmf_mi_get_inlined_if_instruction (curr_instruction);
		    assert (inst >= 0);
		    path[p - 1] = vm->instructions[inst].code;
#else
		    if (instructions_length == 1)
		      {
			/* Check Point: if we should branch, return to original code */
			jint inst =
			  _svmf_mi_get_inlined_if_instruction
			  (curr_instruction);
			path[last_sequence_index] =
			  vm->instructions[inst].code;
		      }
		    else
		      {
			/* Check Point: if we should branch, return to original code */
			instructions_tmp[idx] =
			  _svmf_mi_get_inlined_if_instruction
			  (curr_instruction);
			implementation_length +=
			  vm->instructions[instructions_tmp[idx]].
			  inlined_size;

			if (_svmm_mi_get_sequence
			    (env, instructions_tmp, instructions_length,
			     implementation_length,
			     sequence_tmp,
			     sequence->starts_with_skip) != JNI_OK)
			  {
			    return JNI_ERR;
			  }

			path[last_sequence_index].implementation =
			  sequence_tmp->implementation;
		      }
#endif
		    /* keep offset (from the beginning of original code) for the moment */
		    path[p++].jint =
		      _svmf_mp_get_old_offset (callee_method, target);
		  }

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		if (instructions_tmp != NULL)
		  {
		    _svmm_gmfree_ints (instructions_tmp);
		  }
#endif
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
		jint inst;
		_svmt_code *target;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

		size_t idx;
		jint *instructions_tmp = NULL;
		_svmt_mi_sequence_node_info *sequence_tmp;

		/* we must be at the end of the sequence since
		   curr_instruction is a branching bytecode */
		assert (i == (instructions_length - 1));
#endif

		/* copy stack_gc_map */
		path[p++] = profiling_code[s++];

		target = profiling_code[s++].addr;

		/* Here we suppose that a IF<X>_CHECK is always a backward branch */
		assert (target < profiling_code + s);

		/* we choose the non-branching path */

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER

		/* Check Point: if we should branch, return to original code */
		inst = _svmf_mi_get_inlined_if_instruction (curr_instruction);
		path[p - 2] = vm->instructions[inst].code;
#else
		if (instructions_length == 1)
		  {
		    /* Check Point: if we should branch, return to original code */
		    inst =
		      _svmf_mi_get_inlined_if_instruction (curr_instruction);
		    path[last_sequence_index] = vm->instructions[inst].code;
		  }
		else
		  {
		    size_t implementation_length =
		      sequence->implementation_length;

		    if (_svmm_gmalloc_ints
			(env, instructions_length,
			 instructions_tmp) != JNI_OK)
		      {
			return JNI_ERR;
		      }

		    /* copy the n-1 elems of the sequence's instructions array */
		    for (idx = 0; idx < instructions_length - 1; idx++)
		      {
			instructions_tmp[idx] = instructions[idx];
		      }

		    /* Check Point: if we should branch, return to original code */
		    instructions_tmp[idx] =
		      _svmf_mi_get_inlined_if_instruction (curr_instruction);
		    implementation_length -=
		      vm->instructions[curr_instruction].inlined_size;
		    implementation_length +=
		      vm->instructions[instructions_tmp[idx]].inlined_size;

		    if (_svmm_mi_get_sequence
			(env, instructions_tmp, instructions_length,
			 implementation_length, sequence_tmp, 
			 sequence->starts_with_skip) != JNI_OK)
		      {
			return JNI_ERR;
		      }

		    path[last_sequence_index].implementation =
		      sequence_tmp->implementation;
		  }
#endif
		/* keep offset (from the beginning of original code) for the moment */
		path[p++].jint =
		  _svmf_mp_get_old_offset (callee_method, target);

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		if (instructions_tmp != NULL)
		  {
		    _svmm_gmfree_ints (instructions_tmp);
		  }
#endif
		break;
	      }

	    case SVM_INSTRUCTION_GOTO:
	    case SVM_INSTRUCTION_GOTO_CHECK:

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	    case SVM_INSTRUCTION_INLINED_JMP_OVER_NEXT_SEQ:
#endif
	      {
		_svmt_code *target;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

		size_t idx = 0;
		jint *instructions_tmp = NULL;
		_svmt_mi_sequence_node_info *sequence_tmp;
		size_t implementation_length = sequence->implementation_length;

		/* we must be at the end of the sequence since 
		   curr_instruction is a jump */
		assert (i == (instructions_length - 1));

		if(instructions_length > 1)
		  {
		    implementation_length -=
		      vm->instructions[curr_instruction].inlined_size;
		    
		    if (_svmm_gmalloc_ints
			(env, instructions_length,
			 instructions_tmp) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    
		    /* copy the n-1 elems of the sequence's instructions array */
		    for (idx = 0; idx < instructions_length - 1; idx++)
		      {
			instructions_tmp[idx] = instructions[idx];
		      }
		  }
#endif

		if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
		  {
		    s++;	/* skip stack_gc_map */
		  }

		target = profiling_code[s].addr;

		p--;

		/* if jump is forward, we take the jump */
		if (target > profiling_code + s)
		  {
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

		    /* we remove the GOTO from the sequence */
		    if (instructions_length != 1)
		      {
			if (_svmm_mi_get_sequence
			(env, instructions_tmp, instructions_length - 1,
			 implementation_length, sequence_tmp, 
			 sequence->starts_with_skip) != JNI_OK)
			  {
			    return JNI_ERR;
			  }
			
			assert(sequence_tmp->implementation != NULL);
			
			path[last_sequence_index].implementation =
			  sequence_tmp->implementation;

			p++;			
		      }
#endif
		    s = target - profiling_code;
		  }
		else		/* target is preceding current position */
		  {
		    /* end of sequence, jumping back to original non profiling code */
		    /* keep offset (from the beginning of original code) for the moment */
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER

		    if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
		      {
			path[p++] =
			  vm->
			  instructions[SVM_INSTRUCTION_INLINED_GOTO_CHECK].
			  code;

			/* stack_gc_map */
			path[p++] = profiling_code[s-1];
		      }
		    else
		      {
			path[p++] =
			  vm->instructions[SVM_INSTRUCTION_INLINED_GOTO].code;
		      }
#else
		    if (instructions_length == 1)
		      {
			if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
			  {
			    path[p++] =
			      vm->
			      instructions
			      [SVM_INSTRUCTION_INLINED_GOTO_CHECK].code;

			    /* stack_gc_map */
			    path[p++] = profiling_code[s-1];
			  }
			else
			  {
			    path[p++] =
			      vm->instructions[SVM_INSTRUCTION_INLINED_GOTO].
			      code;
			  }
		      }
		    else	/* we replace GOTO by INLINED_GOTO in the sequence */
		      {
			if (curr_instruction == SVM_INSTRUCTION_GOTO_CHECK)
			  {
			    instructions_tmp[idx] =
			      SVM_INSTRUCTION_INLINED_GOTO_CHECK;
			    implementation_length +=
			      vm->
			      instructions
			      [SVM_INSTRUCTION_INLINED_GOTO_CHECK].
			      inlined_size;
			  }
			else
			  {
			    instructions_tmp[idx] =
			      SVM_INSTRUCTION_INLINED_GOTO;
			    implementation_length +=
			      vm->instructions[SVM_INSTRUCTION_INLINED_GOTO].
			      inlined_size;
			  }

			if (_svmm_mi_get_sequence
			    (env, instructions_tmp, instructions_length,
			     implementation_length, sequence_tmp, 
			     sequence->starts_with_skip) != JNI_OK)
			  {
			    return JNI_ERR;
			  }

			path[last_sequence_index].implementation =
			  sequence_tmp->implementation;
			p++;
		      }
#endif
		    path[p++].jint =
		      _svmf_mp_get_old_offset (callee_method, target);

		    /* for ending stack_gc_map */
		    p++;
		    goto finished;
		  }

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		    if (instructions_tmp != NULL)
		      {
			_svmm_gmfree_ints (instructions_tmp);
		      }
#endif
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
		if (vm->instructions[curr_instruction].flag !=
		    SVM_INTRP_FLAG_INLINEABLE)
		  {
		    path[p++] = profiling_code[s++];
		    path[p++] = profiling_code[s++];
		  }
		else
		  {
		    path[p++] = profiling_code[s++];
		  }
#else
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
#endif
		break;
	      }

	    case SVM_INSTRUCTION_CHECKCAST:
	    case SVM_INSTRUCTION_INSTANCEOF:
	      {
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		break;
	      }

	    case SVM_INSTRUCTION_NEW:
	    case SVM_INSTRUCTION_ANEWARRAY:
	      {
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		break;
	      }

	    case SVM_INSTRUCTION_MULTIANEWARRAY:
	      {
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		break;
	      }

	      /* profiling code should not contain this instruction */
	    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	      {
		assert (1 == 0);
		return JNI_ERR;
	      }

	    case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
	    case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INVOKESTATIC:
	    case SVM_INSTRUCTION_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL:
	    case SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_PROFILING_INVOKESTATIC:
	    case SVM_INSTRUCTION_PROFILING_INVOKESPECIAL:
	      {
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		/* assuming */
		assert (vm->instructions[curr_instruction].flag !=
			SVM_INTRP_FLAG_INLINEABLE);
#endif

		switch (curr_instruction)
		  {
		  case SVM_INSTRUCTION_INITIAL_INVOKEVIRTUAL:
		  case SVM_INSTRUCTION_PROFILING_INVOKEVIRTUAL:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INVOKEVIRTUAL].code;
		      break;
		    }
		  case SVM_INSTRUCTION_INITIAL_INVOKESPECIAL:
		  case SVM_INSTRUCTION_PROFILING_INVOKESPECIAL:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INVOKESPECIAL].code;
		      break;
		    }
		  case SVM_INSTRUCTION_INITIAL_INVOKESTATIC:
		  case SVM_INSTRUCTION_PROFILING_INVOKESTATIC:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INVOKESTATIC].code;
		      break;
		    }
		  case SVM_INSTRUCTION_INITIAL_INVOKEINTERFACE:
		  case SVM_INSTRUCTION_PROFILING_INVOKEINTERFACE:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INVOKEINTERFACE].
			code;
		      break;
		    }
		  default:
		    {
		      break;
		    }
		  }

		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		path[p++] = profiling_code[s++];
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_INVOKESTATIC:
	    case SVM_INSTRUCTION_INLINED_INVOKESPECIAL:
	    case SVM_INSTRUCTION_INLINED_INVOKEINTERFACE:
	    case SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL:
	      {
		/* do not suport imbricated inlining */
		return JNI_ERR;
	      }

	    case SVM_INSTRUCTION_IRETURN:
	    case SVM_INSTRUCTION_LRETURN:
	    case SVM_INSTRUCTION_FRETURN:
	    case SVM_INSTRUCTION_DRETURN:
	    case SVM_INSTRUCTION_ARETURN:
	    case SVM_INSTRUCTION_RETURN:
	      {
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		/* assuming */
		assert (vm->instructions[curr_instruction].flag !=
			SVM_INTRP_FLAG_INLINEABLE);
#endif

		switch (curr_instruction)
		  {
		  case SVM_INSTRUCTION_IRETURN:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INLINED_IRETURN].
			code;
		      break;
		    }
		  case SVM_INSTRUCTION_LRETURN:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INLINED_LRETURN].
			code;
		      break;
		    }
		  case SVM_INSTRUCTION_FRETURN:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INLINED_FRETURN].
			code;
		      break;
		    }
		  case SVM_INSTRUCTION_DRETURN:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INLINED_DRETURN].
			code;
		      break;
		    }
		  case SVM_INSTRUCTION_ARETURN:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INLINED_ARETURN].
			code;
		      break;
		    }
		  case SVM_INSTRUCTION_RETURN:
		    {
		      path[p - 1] =
			vm->instructions[SVM_INSTRUCTION_INLINED_RETURN].code;
		      break;
		    }
		  default:
		    {
		      _svmm_fatal_error ("impossible control flow");
		    }
		  }

		addresses[p - 1].addr = NULL;

		/* for ending stack_gc_map */
		p++;

#ifdef _SABLEVM_METHOD_INLINING_STATS
		switch (invoke_instruction)
		  {
		  case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
		    {
		      vm->mi_info.
			total_inlined_invokevirtual_complete_sequence++;
		      break;
		    }
		  case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
		    {
		      vm->mi_info.
			total_inlined_invokeinterface_complete_sequence++;
		      break;
		    }
		  case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
		    {
		      vm->mi_info.
			total_inlined_invokespecial_complete_sequence++;
		      break;
		    }
		  case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
		    {
		      vm->mi_info.
			total_inlined_invokestatic_complete_sequence++;
		      break;
		    }
		  }
#endif
		goto finished;
	      }

	    case SVM_INSTRUCTION_JSR:
	    case SVM_INSTRUCTION_JSR_CHECK:
	      {
		jint offset;

		if (curr_instruction == SVM_INSTRUCTION_JSR_CHECK)
		  {
		    s++;	/* skip stack_gc_map */
		  }

		offset = profiling_code[s].addr - &profiling_code[s];

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		size_t idx;
		jint *instructions_tmp = NULL;
		_svmt_mi_sequence_node_info *sequence_tmp;

		/* we must be at the end of the sequence since 
		   curr_instruction is a jump */
		assert (i == (instructions_length - 1));
#endif

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER

		if (curr_instruction == SVM_INSTRUCTION_JSR)
		  {
		    path[p - 1] =
		      vm->instructions[SVM_INSTRUCTION_INLINED_JSR].code;
		  }
		else
		  {
		    path[p - 1] =
		      vm->instructions[SVM_INSTRUCTION_INLINED_JSR_CHECK].
		      code;
		  }
#else
		if (instructions_length == 1)
		  {
		    if (curr_instruction == SVM_INSTRUCTION_JSR_CHECK)
		      {
			path[last_sequence_index] =
			  vm->instructions[SVM_INSTRUCTION_INLINED_JSR_CHECK].code;
		      }
		    else
		      {
			path[last_sequence_index] =
			  vm->instructions[SVM_INSTRUCTION_INLINED_JSR].
			  code;
		      }
		  }
		else
		  {
		    size_t implementation_length =
		      sequence->implementation_length;
		    implementation_length -=
		      vm->instructions[curr_instruction].inlined_size;

		    if (_svmm_gmalloc_ints
			(env, instructions_length,
			 instructions_tmp) != JNI_OK)
		      {
			return JNI_ERR;
		      }

		    /* copy the sequence's instructions array */
		    for (idx = 0; idx < instructions_length-1; idx++)
		      {
			instructions_tmp[idx] = instructions[idx];
		      }

		    if (curr_instruction == SVM_INSTRUCTION_JSR_CHECK)
		      {
			instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_JSR_CHECK;
			implementation_length +=
			  vm->instructions[SVM_INSTRUCTION_INLINED_JSR_CHECK].
			  inlined_size;
		      }
		    else
		      {
			instructions_tmp[i] =
			  SVM_INSTRUCTION_INLINED_JSR;
			implementation_length +=
			  vm->instructions[SVM_INSTRUCTION_INLINED_JSR].
			  inlined_size;
		      }

		    if (_svmm_mi_get_sequence
			(env, instructions_tmp, instructions_length,
			 implementation_length, sequence_tmp, 
			 sequence->starts_with_skip) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    
		    path[last_sequence_index].implementation =
		      sequence_tmp->implementation;
		    
		    /* replace the current sequence with the new one */
		    sequence = sequence_tmp;
		  }

		if (instructions_tmp != NULL)
		  {
		    _svmm_gmfree_ints (instructions_tmp);
		  }
#endif

		if (curr_instruction == SVM_INSTRUCTION_JSR_CHECK)
		  {
		    path[p++] = profiling_code[s - 1];
		  }

		/* keep offset (from the beginning of original code) for the moment */
		path[p++].jint = _svmf_mp_get_old_offset (callee_method,
							    profiling_code +
							    s + 1);

		s += offset;	/* jump to subroutine */
		break;
	      }

	    case SVM_INSTRUCTION_RET:
	      {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
		path[p - 1] =
		  vm->instructions[SVM_INSTRUCTION_INLINED_RET].code;		
#else
		size_t idx;
		jint *instructions_tmp = NULL;
		_svmt_mi_sequence_node_info *sequence_tmp;
		
		/* we must be at the end of the sequence since
		   curr_instruction is a branching bytecode */
		assert (i == (instructions_length - 1));

		if (instructions_length == 1)
		  {
		    path[last_sequence_index] =
		      vm->instructions[SVM_INSTRUCTION_INLINED_RET].
		      code;
		  }
		else
		  {
		    size_t implementation_length =
		      sequence->implementation_length;
		    implementation_length -=
		      vm->instructions[curr_instruction].inlined_size;

		    if (_svmm_gmalloc_ints
			(env, instructions_length,
			 instructions_tmp) != JNI_OK)
		      {
			return JNI_ERR;
		      }

		    /* copy the sequence's instructions array */
		    for (idx = 0; idx < instructions_length-1; idx++)
		      {
			instructions_tmp[idx] = instructions[idx];
		      }
		    
		    instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_RET;
		    implementation_length +=
		      vm->instructions[SVM_INSTRUCTION_INLINED_RET].
		      inlined_size;
		    
		    if (_svmm_mi_get_sequence
			(env, instructions_tmp, instructions_length,
			 implementation_length, sequence_tmp, 
			 sequence->starts_with_skip) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    
		    path[last_sequence_index].implementation =
		      sequence_tmp->implementation;
		    
		    /* replace the current sequence with the new one */
		    sequence = sequence_tmp;
		  }
		
		if (instructions_tmp != NULL)
		  {
		    _svmm_gmfree_ints (instructions_tmp);
		  }
#endif

		path[p].jint = profiling_code[s++].jint;
		addresses[p++].addr = NULL;

		/* for ending stack_gc_map */
		p++;
		goto finished;
	      }

	    case SVM_INSTRUCTION_PROFILING_TABLESWITCH:
	    case SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK:
	      {
		size_t k, end;
		_svmt_code *default_dest;
		jint low, high, default_count;
		jint max_case_value = 0;
		jint max_case_count = -1;
		_svmt_code *max_case_addr = NULL;
		_svmt_code gc_map;
		
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		size_t idx = 0;
		jint *instructions_tmp = NULL;
		_svmt_mi_sequence_node_info *sequence_tmp;
		size_t implementation_length = sequence->implementation_length;

		/* we must be at the end of the sequence since 
		   curr_instruction is a branch */
		assert (i == (instructions_length - 1));
		
		if(instructions_length > 1)
		  {
		    implementation_length -=
		      vm->instructions[curr_instruction].inlined_size;
		    
		    if (_svmm_gmalloc_ints (env, instructions_length, instructions_tmp) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    
		    /* copy the n-1 elems of the sequence's instructions array */
		    for (idx = 0; idx < instructions_length - 1; idx++)
		      {
			instructions_tmp[idx] = instructions[idx];
		      }
		  }
#endif
		
		if (curr_instruction ==
		    SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
		  {
		    gc_map = profiling_code[s++];
		  }
		
		default_dest = profiling_code[s++].addr;
		low = profiling_code[s++].jint;
		high = profiling_code[s++].jint;
		default_count = profiling_code[s++].jint;
		
		end = s + ((high - low + 1) * 2);
		
		/* find the highest count for the cases */
		for (k = s; k < end; k += 2)
		  {
/* 		    _svmf_printf(env, stderr, "k=%d %p[%p]\n", k,  */
/* 				 profiling_code+k, profiling_code[k].addr); */
		    
		    /* branch must be forward && count larger */
		    if ((profiling_code[k].addr > (profiling_code + s)) &&
			(profiling_code[k + 1].jint >max_case_count))
		      {
			max_case_value = low + ((k - s) / 2);
			max_case_addr = profiling_code[k].addr;
			max_case_count = profiling_code[k + 1].jint;
		      }
		  }

		/* all jumps in cases are backwards */
		if (max_case_count < 0)
		  {
		    /* default case jump and all cases jump are backwards */
		    if (default_dest < (profiling_code + s))
		      {
			/* end of sequence jump to original tableswitch */
			/* TO DO ... */
			assert (1 == 0);
		      }
		    else	/* default case jump if forward */
		      {
			/* we inline the default case */

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
			if (curr_instruction ==
			    SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK].code;
			    path[p++] = gc_map;
			  }
			else
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT].code;
			  }
#else
			if(instructions_length == 1)
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			      {
				path[last_sequence_index] =
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK].code;
				path[p++] = gc_map;
			      }
			    else
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT].code;
			      }
			  }
			else
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK].inlined_size;
			      }
			    else
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT].inlined_size;
			      }

			    if (_svmm_mi_get_sequence
				(env, instructions_tmp, instructions_length,
				 implementation_length, sequence_tmp, 
				 sequence->starts_with_skip) != JNI_OK)
			      {
				return JNI_ERR;
			      }
			    
			    path[last_sequence_index].implementation = sequence_tmp->implementation;
			  }
#endif
			/* write original table address */
			/* keep offset (from the beginning of original code) for the moment */
			path[p++].jint =
			  _svmf_mp_get_old_offset (callee_method,
						   profiling_code + s);

			path[p++].jint = low;
			path[p++].jint = high;
			s = default_dest - profiling_code;
		      }
		  }
		else		/* cases contains at least one forward jump */
		  {
		    /* default jump is backwards or 
		       default jump if forward but a case has a higher count */
		    if ((default_dest < (profiling_code + s))
			|| (max_case_count > default_count))
		      {
			/* for cases with count that are equal select the nearest jump */
			for (k = s; k < end; k += 2)
			  {
			    /* for branches that are equal and forward,
			       select the nearest */
			    if ((profiling_code[k + 1].jint ==
				 max_case_count) &&(profiling_code[k].addr >
						    (profiling_code + s))
				&& (profiling_code[k].addr < max_case_addr))
			      {
				max_case_value = low + ((k - s) / 2);
				max_case_addr = profiling_code[k].addr;
				max_case_count = profiling_code[k].jint;
			      }
			  }

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
			if (curr_instruction ==
			    SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK].code;
			    path[p++] = gc_map;
			  }
			else
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE].code;
			  }
#else
			if(instructions_length == 1)
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK].code;
				path[p++] = gc_map;
			      }
			    else
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE].code;
			      }
			  }
			else
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE_CHECK].inlined_size;
			      }
			    else
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_CASE].inlined_size;
			      }
			    
			    if (_svmm_mi_get_sequence
				(env, instructions_tmp, instructions_length,
				 implementation_length, sequence_tmp, 
				 sequence->starts_with_skip) != JNI_OK)
			      {
				return JNI_ERR;
			      }			    

			    path[last_sequence_index].implementation = sequence_tmp->implementation;
			  }
#endif
			/* write original table address */
			/* keep offset (from the beginning of original code) for the moment */
			path[p++].jint =
			  _svmf_mp_get_old_offset (callee_method,
						   profiling_code + s);

			path[p++].jint = max_case_value;
			s = max_case_addr - profiling_code;
		      }
		    else	/* default case jump is forward and has a higher count */
		      {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
			if (curr_instruction ==
			    SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->
			      instructions
			      [SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK].
			      code;
			    path[p++] = gc_map;
			  }
			else
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->
			      instructions
			      [SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT].
			      code;
			  }
#else
			if(instructions_length == 1)
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->
				  instructions
				  [SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK].
				  code;
				path[p++] = gc_map;
			      }
			    else
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->
				  instructions
				  [SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT].
				  code;
			      }			    
			  }
			else
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_TABLESWITCH_CHECK)
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT_CHECK].inlined_size;
			      }
			    else
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_TABLESWITCH_DEFAULT].inlined_size;
			      }
			    
			    if (_svmm_mi_get_sequence
				(env, instructions_tmp, instructions_length,
				 implementation_length, sequence_tmp, 
				 sequence->starts_with_skip) != JNI_OK)
			      {
				return JNI_ERR;
			      }

			    path[last_sequence_index].implementation = sequence_tmp->implementation;
			  }
#endif
			/* write original table address */
			/* keep offset (from the beginning of original code) for the moment */
			path[p++].jint =
			  _svmf_mp_get_old_offset (callee_method,
						   profiling_code + s);
			
			path[p++].jint = low;
			path[p++].jint = high;
			s = default_dest - profiling_code;
		      }
		  }

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		if (instructions_tmp != NULL)
		  {
		    _svmm_gmfree_ints (instructions_tmp);
		  }
#endif
		break;
	      }

	    case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH:
	    case SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK:
	      {
		size_t k, end;
		jint ncases;
		jint default_count;
		jint max_case_value = 0;
		jint max_case_count = -1;

		_svmt_code gc_map;
		_svmt_code *max_case_addr = NULL;
		_svmt_code *default_dest;

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

		size_t idx = 0;
		jint *instructions_tmp = NULL;
		_svmt_mi_sequence_node_info *sequence_tmp;
		size_t implementation_length = sequence->implementation_length;

		/* we must be at the end of the sequence since 
		   curr_instruction is a branch */
		assert (i == (instructions_length - 1));
		
		if(instructions_length > 1)
		  {
		    implementation_length -=
		      vm->instructions[curr_instruction].inlined_size;
		    
		    if (_svmm_gmalloc_ints (env, instructions_length, instructions_tmp) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    
		    /* copy the n-1 elems of the sequence's instructions array */
		    for (idx = 0; idx < instructions_length - 1; idx++)
		      {
			instructions_tmp[idx] = instructions[idx];
		      }
		  }
#endif

		if (curr_instruction ==
		    SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
		  {
		    gc_map = profiling_code[s++];
		  }

		default_dest = profiling_code[s++].addr;
		ncases = profiling_code[s++].jint;
		default_count = profiling_code[s++].jint;

		end = s + (ncases * 3);

		/* find the highest count for the cases */
		for (k = s + 1; k < end; k += 3)
		  {
/* 		    _svmf_printf(env, stderr, */
/* 				 "k=%d %p[%p]\n", k, profiling_code+k,  */
/* 				 profiling_code[k].addr); */
		    
		    /* branch must be forward && count larger */
		    if ((profiling_code[k].addr > (profiling_code + s)) &&
			(profiling_code[k + 1].jint >max_case_count))
		      {
			max_case_value = profiling_code[k - 1].jint;
			max_case_addr = profiling_code[k].addr;
			max_case_count = profiling_code[k + 1].jint;
		      }
		  }

/* 	    _svmf_printf(env, stderr, "max_case1[%d] jump_addr[%p]\n", max_case_value, max_case_addr); */

		/* all jumps in cases are backwards */
		if (max_case_count < 0)
		  {
		    /* default case jump is backwards */
		    if (default_dest < (profiling_code + s))
		      {
			/* end of sequence jump to original tableswitch */
			/* TO DO ... */
			assert (1 == 0);
		      }
		    else	/* default case jump if forward */
		      {
			/* we inline the default case */

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER			
			if (curr_instruction ==
			    SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK].code;
			    path[p++] = gc_map;
			  }
			else
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT].code;
			  }
#else
			if(instructions_length == 1)
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			      {
				/* overwrite tableswitch */
				path[last_sequence_index] =
				  vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK].code;
				path[p++] = gc_map;
			      }
			    else
			      {
				/* overwrite tableswitch */
				path[last_sequence_index] =
				  vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT].code;
			      }			    
			  }
			else
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK].inlined_size;
			      }
			    else
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT].inlined_size;
			      }
			    
			    if (_svmm_mi_get_sequence
				(env, instructions_tmp, instructions_length,
				 implementation_length, sequence_tmp, 
				 sequence->starts_with_skip) != JNI_OK)
			      {
				return JNI_ERR;
			      }
			    
			    path[last_sequence_index].implementation = sequence_tmp->implementation;
			  }
#endif			
			/* write original table address */
			/* keep offset (from the beginning of original code) for the moment */
			path[p++].jint =
			  _svmf_mp_get_old_offset (callee_method, profiling_code + s);

			s = default_dest - profiling_code;
		      }
		  }
		else		/* cases contains at least one forward jump */
		  {
		    /* default jump is backwards or 
		       default jump if forward but a case has a higher count */
		    if ((default_dest < (profiling_code + s))
			|| (max_case_count > default_count))
		      {
			/* for cases with count that are equal select the nearest jump */
			for (k = s + 1; k < end; k += 3)
			  {
			    /* count must be equal,
			       branch must be forward,
			       branch must be nearer */
			    if ((profiling_code[k + 1].jint ==
				 max_case_count) &&(profiling_code[k].addr >
						    (profiling_code + s))
				&& (profiling_code[k].addr < max_case_addr))
			      {
				max_case_value = profiling_code[k - 1].jint;
				max_case_addr = profiling_code[k].addr;
				max_case_count = profiling_code[k].jint;
			      }
			  }

/* 		    _svmf_printf(env, stderr, "max_case2[%d] jump_addr[%p]\n", max_case_value, max_case_addr); */

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
			if (curr_instruction ==
			    SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->
			      instructions
			      [SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK].
			      code;
			    path[p++] = gc_map;
			  }
			else
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->
			      instructions
			      [SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE].
			      code;
			  }
#else
			if(instructions_length == 1)
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->
				  instructions
				  [SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK].
				  code;
				path[p++] = gc_map;
			      }
			    else
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->
				  instructions
				  [SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE].
				  code;
			      }			    
			  }
			else
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE_CHECK].inlined_size;
			      }
			    else
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_CASE].inlined_size;
			      }
			    
			    if (_svmm_mi_get_sequence
				(env, instructions_tmp, instructions_length,
				 implementation_length, sequence_tmp, 
				 sequence->starts_with_skip) != JNI_OK)
			      {
				return JNI_ERR;
			      }
			    
			    path[last_sequence_index].implementation = sequence_tmp->implementation;
			  }
#endif

			/* write original table address */
			/* keep offset (from the beginning of original code) for the moment */
			path[p++].jint =
			  _svmf_mp_get_old_offset (callee_method,
						   profiling_code + s);

			path[p++].jint = max_case_value;
			s = max_case_addr - profiling_code;
		      }
		    else	/* default case jump is forward and default case has a higher count */
		      {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
			if (curr_instruction ==
			    SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->
			      instructions
			      [SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK].
			      code;
			    path[p++] = gc_map;
			  }
			else
			  {
			    /* overwrite tableswitch */
			    path[p - 1] =
			      vm->
			      instructions
			      [SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT].
			      code;
			  }
#else
			if(instructions_length == 1)
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->
				  instructions
				  [SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK].
				  code;
				path[p++] = gc_map;
			      }
			    else
			      {
				/* overwrite tableswitch */
				path[p - 1] =
				  vm->
				  instructions
				  [SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT].
				  code;
			      }			    
			  }
			else
			  {
			    if (curr_instruction ==
				SVM_INSTRUCTION_PROFILING_LOOKUPSWITCH_CHECK)
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT_CHECK].inlined_size;
			      }
			    else
			      {
				instructions_tmp[idx] = SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT;
				implementation_length +=
				  vm->instructions[SVM_INSTRUCTION_INLINED_LOOKUPSWITCH_DEFAULT].inlined_size;
			      }
			    
			    if (_svmm_mi_get_sequence
				(env, instructions_tmp, instructions_length,
				 implementation_length, sequence_tmp, 
				 sequence->starts_with_skip) != JNI_OK)
			      {
				return JNI_ERR;
			      }

			    path[last_sequence_index].implementation = sequence_tmp->implementation;
			  }			
#endif
			/* write original table address */
			path[p++].jint =
			  _svmf_mp_get_old_offset (callee_method,
						   profiling_code + s);

			s = default_dest - profiling_code;
		      }
		  }

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
		if (instructions_tmp != NULL)
		  {
		    _svmm_gmfree_ints (instructions_tmp);
		  }
#endif
		break;
	      }

	    case SVM_INSTRUCTION_INLINED_IRETURN:
	    case SVM_INSTRUCTION_INLINED_LRETURN:
	    case SVM_INSTRUCTION_INLINED_FRETURN:
	    case SVM_INSTRUCTION_INLINED_DRETURN:
	    case SVM_INSTRUCTION_INLINED_ARETURN:
	    case SVM_INSTRUCTION_INLINED_RETURN:
	      {
		path[p++].stack_gc_map = profiling_code[s++].stack_gc_map;
		break;
	      }

	    default:
	      {
		/* instruction has no parameters */
		break;
	      }
	    }			/* end of switch */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
	}			/* end of for */
#endif
    }				/* end of while */

finished:

  /* Set 1st parameter of the INLINED_INVOKE (inlined code length) */
  path[1].jint = p - path_begin_index;
  
  /* Replace relative offset in checkpoints by address of the corresponding entry
     in the conversion table */
  if ((_svmf_mi_fix_addresses_in_checkpoints (env, path, p,
					      callee_method->frame_info->
					      original_code_conversion_table)) 
      != JNI_OK)
    {
      assert (1 == 0);
      return JNI_ERR;
    }

  /* remember selected path for this method */
  {
    _svmt_code *path_tmp;
    
    if (_svmm_cl_malloc_code (env, callee_method->class_info->
			      class_loader_info, p,
			      path_tmp) != JNI_OK)
      {
#ifndef NDEBUG
	_svmm_fatal_error("method inlining: memory malloc failed\n");
#endif
	return JNI_ERR;
      } 
    
    memcpy(path_tmp, path, p * sizeof(_svmt_code));
    callee_method->frame_info->selected_path = path_tmp;

/*     _svmf_mi_output_code_array(env, stderr, path_tmp, p, "\n\nselected path:", NULL, 0); */
  }
  
  callee_method->frame_info->selected_path_code_length = p;
  
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mi_build_selected_path_exception_table
--
Build exception table for selected path to be inlined
----------------------------------------------------------------------
*/

svm_static jint
_svmf_mi_build_selected_path_exception_table (_svmt_JNIEnv *env,
					      _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  
  jint p;		/* index used to go through the selected path */
  jint t;		/* index used to go through the original exception table */
  jint entry_count = 0;
  jint path_start_index;

  _svmt_code *curr = NULL;
  _svmt_code *start = NULL;
  _svmt_code *end = NULL;
  _svmt_code *normal_end = NULL;
  _svmt_code *selected_path = method->frame_info->selected_path;  
  jint path_length = method->frame_info->selected_path_code_length;

  _svmt_exception_table *tmp_table = vm->mi_info.working_exception_table;

  jint table_length = method->data.code_attribute->exception_table_length;
  _svmt_exception_table *table =
    method->data.code_attribute->profiling_exception_table;

/*   _svmt_exception_table *new_table; */
  
  _svmt_code *addrs = vm->mi_info.selected_path_to_original_code_map;

  
  if(method->frame_info->selected_path_exception_table != NULL)
    {
      /* The job is already done */
      return JNI_OK;
    }
  
  /* Assure that the working exception table is big enough */
  /* Resize to maximum number of entries */
  if(vm->mi_info.working_exception_table_length < table_length)
    {
      if((tmp_table = _svmm_realloc(tmp_table, table_length *
				    sizeof(_svmt_exception_table))) == NULL)
	{
#ifndef NDEBUG      
	  _svmm_fatal_error("method inlining: memory realloc failed\n");
#endif
	  return JNI_ERR;
	}

      vm->mi_info.working_exception_table = tmp_table;
      vm->mi_info.working_exception_table_length = table_length;
    }

  /* skip parameters of the INLINED_INVOKE<X> */  
  path_start_index = 5;

  if ((vm->mi_info.invoke_instruction ==
       SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL)
      || (vm->mi_info.invoke_instruction ==
	  SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL))
    {
      path_start_index += INLINED_INVOKEVIRTUAL_EXTRA_PARAMS;
    }

  /* output addrs table */
/*   { */
/*     jint i; */
    
/*     for(i = 0 ; i < path_length ; i++) */
/*       { */
/* 	_svmf_printf(env, stderr, "addrs[%d]=%p\n", i, addrs[i].addr); */
/*       } */
/*   } */


/* This algorithm assumes that since we are not supporting 
   profiling of backward jumps (backward jump --> end of selected path), 
   the instructions in the selected path are in the same order 
   as in the profiling code */

  for (t = 0; t < table_length; t++)
    {
      /* (-1) because entries in table consider pc to always point 
	 on the next instruction to execute */
      start = table[t].normal_start - 1;
      end = table[t].normal_end - 1;
      
/*       _svmf_printf(env, stderr, "table_entry[%d] \n", t); */
      
      for (p = path_start_index; p < path_length; p++)
	{
	  /* not an instruction */
	  if (addrs[p].addr == NULL)
	    {
/* 	      _svmf_printf(env, stderr, "path[%d] not an instruction, skipping\n", p); */
	      continue;
	    }
	  
/* 	  _svmf_printf(env, stderr, "path[%d] is an instruction\n", p); */
	  
	  curr = addrs[p].addr;
	 
	  /* check if curr is handled by this entry in table */
	  if ((curr >= start) && (curr <= end))
	    {
	      assert(entry_count < table_length);

	      tmp_table[entry_count].normal_start = selected_path + p;

	      tmp_table[entry_count].handler = method->frame_info->code +
		_svmf_mp_get_old_offset (method, table[t].handler);

	      tmp_table[entry_count].catch_type = table[t].catch_type;

	      /* unused in inlined code, 
	         has to be initialized for 'instruction switch' in instructions.m4.c */
	      tmp_table[entry_count].prepare_start = 0;
	      tmp_table[entry_count].prepare_end = 0;

	      /* walk through the sequence to find to end */
	      do
		{
/* 		  _svmf_printf(env, stderr, "path[%d] in do-while\n", p); */
		  
		  /* current instruction */
		  if (addrs[p].addr != NULL)
		    {
		      curr = addrs[p].addr;
		    }

		  normal_end = selected_path + p;
		  p++;
		}
	      while ((curr >= start) && (curr <= end) && (p < path_length));

	      tmp_table[entry_count++].normal_end = normal_end;

	      break; /* goto next entry in the table */
	    }
	}
    }
  
  /* Remember the selected path exception table for this method */
  if(entry_count > 0)
    {
      jint i;
      _svmt_exception_table *selected_path_table;
      
      if((_svmm_cl_zmalloc_exception_table(env, method->class_info->
					   class_loader_info, entry_count, 
					   selected_path_table)) != JNI_OK)
	{
	  return JNI_ERR;
	}
      
      for(i = 0; i < entry_count; i++)
	{
	  selected_path_table[i] = tmp_table[i];
	}

      method->frame_info->selected_path_exception_table = selected_path_table;;
      method->frame_info->selected_path_exception_table_nb_entries = entry_count;
    }
  
/*     _svmf_mi_output_exception_table (env, stderr, */
/*   				   entry_count, */
/*   				   tmp_table, */
/*   				   "build exception table: selected path exception table"); */
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mi_fix_exception_table
--
Fix the exception table asscoiated with the calling method. Fix 
addresses for already existing entries et add new entries for
inlined code.
----------------------------------------------------------------------
*/
svm_static jint
_svmf_mi_fix_exception_table (_svmt_JNIEnv *env,
			      _svmt_method_info *calling_method,
			      _svmt_method_info *callee_method,
			      _svmt_code *new_code,
			      size_t new_code_length,
			      jint invoke_offset)
{
  jint i, j;
  jint offset;
  _svmt_JavaVM *vm = env->vm;
 
  _svmt_code *old_code = calling_method->frame_info->code;  
  _svmt_code *selected_path = callee_method->frame_info->selected_path;
  _svmt_code *selected_path_map = vm->mi_info.selected_path_to_new_code_map;
  _svmt_code *after_invoke_site_addr = old_code + invoke_offset + 4;

  size_t old_code_length = calling_method->frame_info->code_length;
  size_t inlined_code_length = vm->mi_info.code_length_diff;

  jint new_table_length;
  jint path_table_length = 
    callee_method->frame_info->selected_path_exception_table_nb_entries;
  jint old_table_length = 
    calling_method->data.code_attribute->exception_table_length;
  
  _svmt_exception_table *path_table = 
    callee_method->frame_info->selected_path_exception_table;
  _svmt_exception_table *old_table =
    calling_method->data.code_attribute->exception_table;
  _svmt_exception_table *new_table;
  
  _svmt_class_loader_info *class_loader_info =
    env->stack.current_frame->method_frame_info->method->class_info->
    class_loader_info;

  /* TO REMOVE !!! */
  new_code_length = new_code_length;

  new_table_length = old_table_length + path_table_length;

/*   _svmf_print_method_name (env, stderr, calling_method, */
/* 			   "Fixing exception table for: "); */

/*   _svmf_mi_output_exception_table (env, stderr, */
/* 				   old_table_length, */
/* 				   old_table, */
/* 				   "fix_exception_table: old table"); */

/*   if (path_table_length > 0) */
/*     { */
/*       _svmf_mi_output_exception_table (env, stdout, */
/* 				       path_table_length, */
/* 				       path_table, */
/* 				       "fix_exception_table: tmp table"); */
/*     } */

  if (path_table_length > 0)
    {
      if (_svmm_cl_zmalloc_exception_table
	  (env, class_loader_info, new_table_length, new_table) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }
  else
    {
      new_table = old_table;
    }

/*   _svmf_printf(env, stderr, "invoke_addr[%p] after_invoke[%p]\n", invoke_addr, after_invoke); */
/*   _svmf_printf(env, stderr, "after_inlined_code[%p]\n", after_inlined_code); */

  /* Copy new entries. Give priority to inlined code handlers by putting 
     them in the beginning of the table  */
  for (i = 0; i < path_table_length; i++)
    {
      new_table[i] = path_table[i];

      /* fix addresses in path_table to fit adresses in the calling method */
      /* we add 1 because, in the interpreter, "pc" is pointing to 
         the next thing to do. */

      offset = path_table[i].normal_start - selected_path;
      assert(selected_path_map[offset].addr != NULL);
      new_table[i].normal_start = selected_path_map[offset].addr + 1;

      /* inclusive end */
      offset = path_table[i].normal_end - selected_path;
      assert(selected_path_map[offset].addr != NULL);
      new_table[i].normal_end = selected_path_map[offset].addr;

      /* handlers are not inlined so they stay in the original code */
    }

  /* copy original entries of the caller method */
  for (j = 0; j < old_table_length; i++, j++)
    {
      new_table[i] = old_table[j];

      if (old_table[j].normal_start > after_invoke_site_addr)
	{
	  old_table[j].normal_start += inlined_code_length;
	}

      /* fix addesses to fit the new_code array */
      offset = old_table[j].normal_start - old_code;
      new_table[i].normal_start = new_code + offset;

      if (old_table[j].normal_end > after_invoke_site_addr)
	{
	  old_table[j].normal_end += inlined_code_length;
	}
      
      /* fix addesses to fit the new_code array */
      offset = old_table[j].normal_end - old_code;
      new_table[i].normal_end = new_code + offset;

      /* prepare_start (preparaton seq.) is always after invoke site */
      if(old_table[j].prepare_start != NULL)
	{
	  new_table[i].prepare_start += inlined_code_length;
	  offset = old_table[j].prepare_start - old_code;
	  new_table[i].prepare_start = new_code + offset;
	}

      /* prepare_end (preparaton seq.) is always after inlined code */
      if(old_table[j].prepare_end != NULL)
	{
	  new_table[i].prepare_end += inlined_code_length;
	  offset = old_table[j].prepare_end - old_code;
	  new_table[i].prepare_end = new_code + offset;
	}

      /* handler is in this method */
      if ((old_table[j].handler >= old_code) &&
	  (old_table[j].handler < (old_code + old_code_length)))
	{
	  if (old_table[j].handler > after_invoke_site_addr)
	    {
	      old_table[j].handler += inlined_code_length;
	    }
	  
	  /* fix addesses to fit the new_code array */
	  offset = old_table[j].handler - old_code;
	  new_table[i].handler = new_code + offset;
	}
      else
	{
	  /* This entry corresponds to inlined code. The handler 
	     points to original code of inlined method */
	  new_table[i].handler = old_table[j].handler;
	}
    }

  /* update exception table */
  calling_method->data.code_attribute->exception_table = new_table;
  calling_method->data.code_attribute->exception_table_length = new_table_length;

  if ((old_table_length > 0) && (path_table_length > 0))
    {
      _svmm_cl_zmfree_exception_table (env, class_loader_info,
				       old_table_length, old_table);
    }

/*   _svmf_mi_output_exception_table (env, stderr, */
/* 				   new_table_length, */
/* 				   new_table, */
/* 				   "fix_exception_table: new table"); */


  return JNI_OK;
}

/*
-------------------------------------------------------------------------------
_svmf_mi_build_new_calling_method
-------------------------------------------------------------------------------
*/

svm_static jint
_svmf_mi_build_new_calling_method(_svmt_JNIEnv *env,
				  _svmt_method_info *calling_method,
				  _svmt_method_info *callee_method)
{
  _svmt_JavaVM *vm = env->vm;

  size_t i;			/* index in the old code array */
  size_t j;			/* index in the to_inline code array */
  size_t k;			/* index in the new_code array */
 
  size_t old_code_length;
  size_t new_code_length;
  size_t selected_path_length;

  size_t invoke_offset = vm->mi_info.invoke_offset;
  _svmt_gc_map_node *stack_gc_map;

  _svmt_code *map;

 /* Code arrays */
  _svmt_code *old_code;		/* calling method old code array */
  _svmt_code *new_code;		/* calling method new code array */
  _svmt_code *selected_path;	/* selected path in the callee method */

  old_code = calling_method->frame_info->code;
  old_code_length = calling_method->frame_info->code_length;
  stack_gc_map = old_code[invoke_offset+4].stack_gc_map;

  selected_path = callee_method->frame_info->selected_path;
  selected_path_length = callee_method->frame_info->selected_path_code_length;

  new_code_length = old_code_length + selected_path_length - 5;

  map = vm->mi_info.selected_path_to_new_code_map;

  /* Temporary used to output code arrays in a file for debugging */
#if !defined(NDEBUG)
  {
    FILE *file;
    
    file = vm->mi_info.code_arrays = fopen ("code_arrays.txt", "a");
    

    _svmf_print_method_name_and_caller (env, file, calling_method,
					callee_method, "Inlining method");
    
    _svmf_printf (env, file, " invoke_address[%p]\n", old_code + invoke_offset);
    
    _svmf_mi_output_code_array (env, file, old_code,
				old_code_length, "Old_Code", NULL, 0);

    _svmf_mi_output_exception_table (env, file,
				     calling_method->data.code_attribute->
				     exception_table_length,
				     calling_method->data.code_attribute->
				     exception_table,
				     "calling_method exception table");

/*     if( calling_method->data.code_attribute-> */
/* 	profiling_exception_table != NULL) */
/*       { */
/* 	_svmf_mi_output_exception_table (env, file, */
/* 					 calling_method->data.code_attribute-> */
/* 					 exception_table_length, */
/* 					 calling_method->data.code_attribute-> */
/* 					 profiling_exception_table, "calling_method profiling exception table original"); */
/*       } */


    _svmf_mi_output_code_array (env, file,
				callee_method->frame_info->normal_code,
				callee_method->frame_info->code_length,
				"callee method (normal)", NULL, 0);

    _svmf_mi_output_exception_table (env, file,
				     callee_method->data.code_attribute->
				     exception_table_length,
				     callee_method->data.code_attribute->
				     exception_table,
				     "callee_method normal exception table");

    _svmf_mi_output_code_array (env, file,
				callee_method->frame_info->profiling_code,
				callee_method->frame_info->
				profiling_code_length,
				"callee method (profiling)", NULL, 0);

    _svmf_mi_output_exception_table (env, file,
				     callee_method->data.code_attribute->
				     exception_table_length,
				     callee_method->data.code_attribute->
				     profiling_exception_table,
				     "callee_method profiling exception table");
  }
#endif

  /* build new code array */
  
  /* allocate new code array */
  if (_svmm_cl_malloc_code (env, calling_method->class_info->
			    class_loader_info, new_code_length, new_code)
      != JNI_OK)
    {
#ifndef NDEBUG
      _svmm_fatal_error("method inlining: memory alloc failed\n");
#endif
      return JNI_ERR;
    }
  
  /* Copy 1st part: before code to inline */
  for (i = 0; i < invoke_offset; i++)
    {
      new_code[i] = old_code[i];
    }
  
  /* 'k' is the current position in the new code array */
  k = i;
  
  /* Copy 2nd part: code to inline */
  for (j = 0; j < selected_path_length; j++)
    {
      new_code[k] = selected_path[j];
      map[j].addr = new_code + k++;
    }

  /* write inlined code trailing stack_gc_map */
  new_code[k-1].stack_gc_map = stack_gc_map;
  
  /* continue after invoke */
  i = invoke_offset + 5;
  
  /* Copy 3rd part: after the inlined code */
  for (; i < old_code_length; i++)
    {
      new_code[k++] = old_code[i];
    }

  vm->mi_info.code_length_diff = new_code_length - old_code_length;  

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
  calling_method->frame_info->preparation_sequences_offset +=  vm->mi_info.code_length_diff;
#endif

#if 0 
  _svmf_mi_output_code_array (env, stderr, new_code, new_code_length,
			      "Calling method before merge\n", old_code, old_code_length);
#endif

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

  if(_svmm_mi_merge_sequences(env, calling_method, callee_method,
			      new_code, new_code_length) != JNI_OK)
    {
      assert(1 == 0);
      return JNI_ERR;
    }

#if 0
  _svmf_mi_output_code_array (env, stderr, new_code, new_code_length,
			      "Merged Code\n", old_code, old_code_length);
#endif

#endif

/*   _svmf_printf(env, stderr, "\nupdating code_diff: [%d]\n", */
/* 	       vm->mi_info.code_length_diff); */
  
/*   _svmf_printf(env, stderr, "updating prep_seq_offset: [%d]\n", */
/* 	       calling_method->frame_info->preparation_sequences_offset); */

  
  /* Fix calling method addresses */
  if(_svmf_mi_fix_calling_method_addresses (env, calling_method, new_code,
					    new_code_length, invoke_offset) 
     != JNI_OK)
    {
      assert(1 == 0);
      return JNI_ERR;
    }

#if 0
  _svmf_mi_output_code_array (env, stdout, new_code, new_code_length,
			      "Calling method after address fix:", NULL, 0);
#endif

  /* fix exception table of the caller method */
  if ((callee_method->frame_info->selected_path_exception_table_nb_entries > 0) ||
      (calling_method->data.code_attribute->exception_table_length > 0))
    {
      if (_svmf_mi_fix_exception_table (env, calling_method, callee_method,
					new_code, new_code_length,
					invoke_offset) != JNI_OK)
	{
	  assert (1 == 0);
	  return JNI_ERR;
	}
    }

  /* Update calling method */
  calling_method->frame_info->code = new_code;
  calling_method->frame_info->normal_code = new_code;
  calling_method->frame_info->profiling_code_length = new_code_length +
    (calling_method->frame_info->profiling_code_length -
     calling_method->frame_info->code_length);
  calling_method->frame_info->code_length = new_code_length;

#if 0
  _svmf_mi_output_code_array (env, stderr, new_code, new_code_length,
			      "Calling method before conversion table update:", NULL, 0);
#endif

  /* Adjust the conversion table for the calling method */
  if (calling_method->frame_info->inlinable)
    {
      if ((_svmf_mi_update_conversion_table (env, calling_method)) != JNI_OK)
	{
	  assert (1 == 0);
	  return JNI_ERR;
	}
    }
  
  /* Output original_code_conversion_table */
#if !defined(NDEBUG) && 0
  {
    size_t idx;
    FILE *file = vm->mi_info.code_arrays; 
    _svmt_code *table;   

    if(file == NULL)
      {
	if((file = fopen ("code_arrays.txt", "a")) == NULL)
	  {
	    _svmm_fatal_error("impossible to open file");
	  }
	vm->mi_info.code_arrays = file;
      }

    table = calling_method->frame_info->original_code_conversion_table;
    
    if(table != NULL)
      {
	_svmf_print_method_name (env, file, calling_method,
				 "Conversion Table array after inlining\n");
	
	for (idx = 0; idx < old_code_length; idx++)
	  {
	    _svmf_printf (env, file, "%p, table[%d]=%p\n", table + idx, idx,
			  table[idx].addr);
	  }
	_svmf_printf (env, file, "\n");
      }
  }
#endif

  /* Temporary used to output code array in a file for debugging */
#if !defined(NDEBUG) && 1
  {
    FILE *file = vm->mi_info.code_arrays;
    
    _svmf_mi_output_code_array (env, file, new_code,
				new_code_length, "New_Code", NULL, 0);
    
    _svmf_mi_output_exception_table (env, file,
				     calling_method->data.code_attribute->
				     exception_table_length,
				     calling_method->data.code_attribute->
				     exception_table,
				     "\nFinal calling_method exception table");
    fclose (file);
  }
#endif

  /* free old calling method code array */
  _svmm_cl_mfree_code (env, calling_method->class_info->class_loader_info,
		       old_code_length, old_code);
    
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_mi_prevent_overwriting_inlined_code
----------------------------------------------------------------------
*/

/* inline svm_static jint */
/* _svmf_mi_prevent_overwriting_inlined_code (_svmt_JNIEnv *env, */
/* 					   _svmt_method_info *method, */
/* 					   _svmt_code *addr) */
/* { */
/*   jint inst; */
/*   _svmt_JavaVM *vm = env->vm;  */
/*   _svmt_code *new_code = method->frame_info->code; */
/*   _svmt_code *new_code_end = new_code + method->frame_info->code_length; */

/* #ifdef _SABLEVM_INLINED_THREADED_INTERPRETER */
/*   _svmt_mi_sequence_node_info *sequence; */
/* #endif */

/*   if ((addr >= new_code) && (addr < new_code_end)) */
/*     { */
/* #ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER */
/*       inst = addr->jint; */
/* #endif */

/* #ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER */
/*       inst = _svmf_mi_get_instruction_int_code (env, addr->implementation); */
/* #endif */

/* #ifdef _SABLEVM_INLINED_THREADED_INTERPRETER */
     
/*       if ((sequence = */
/* 	   _svmf_mi_get_sequence_by_implementation (env, */
/* 						    addr-> */
/* 						    implementation)) == NULL) */
/* 	{ */
/* 	  _svmf_printf(env, stderr, "_svmf_mi_prevent_overwriting_inlined_code: %p\n", */
/* 		       addr); */

/* 	  assert (1 == 0); */
/* 	  return JNI_ERR; */
/* 	} */
      
/*       inst = sequence->instructions[0];       */
/* #endif */
      
/*       if (inst == SVM_INSTRUCTION_REPLACE) */
/* 	{ */
/* 	  jint to_replace; */
/* 	  _svmt_code *where_to_replace; */

/* #ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER */
/* 	  where_to_replace = addr[1].addr; */
/* 	  to_replace = where_to_replace->jint; */
/* #endif */

/* #ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER */
/* 	  where_to_replace = addr[1].addr; */
/* 	  to_replace = _svmf_mi_get_instruction_int_code */
/* 	    (env, where_to_replace->implementation); */
/* #endif */

/* #ifdef _SABLEVM_INLINED_THREADED_INTERPRETER */

/* 	  /\* we assume REPLACE is not inlineable, thus not part of a sequence *\/ */
/* 	  assert(vm->instructions[SVM_INSTRUCTION_REPLACE].flag != */
/* 		 SVM_INTRP_FLAG_INLINEABLE); */

/* 	  assert(sequence->instructions_length == 1); */

/* 	  where_to_replace = addr[1].addr; */
	  
/* 	  sequence = */
/* 	    _svmf_mi_get_sequence_by_implementation  */
/* 	    (env, where_to_replace->implementation); */
	  
/* 	  /\* not a sequence head, code has changed do not apply the REPLACE *\/ */
/* 	  if(sequence == NULL) */
/* 	    { */
/* 	      /\* not a bytecode *\/ */
/* 	      to_replace = -1;       */
/* 	    } */
/* 	  else */
/* 	    { */
/* 	      to_replace = sequence->instructions[0];       */
/* 	    } */
/* #endif */

/* 	  if (to_replace != SVM_INSTRUCTION_GOTO) */
/* 	    { */
/* 	      /\* erase REPLACE and it's parameters to prevent overwriting  */
/* 	         inlined code *\/ */
/* 	      addr[0] = vm->instructions[SVM_INSTRUCTION_NOP].code; */
/* 	      addr[1] = vm->instructions[SVM_INSTRUCTION_NOP].code; */
/* 	      addr[2] = vm->instructions[SVM_INSTRUCTION_NOP].code; */
/* 	    } */
/* 	} */
/*     } */

/*   return JNI_OK; */
/* } */

/*
  ----------------------------------------------------------------------
  _svmf_mi_update_all_active_invoke_sites
  --
  Assumes the world has been previously stopped.
  Check if this is the only invokation of the calling method. If not,
  update pc of all invokes activated in order for them to resume in 
  the new code array. 
  ----------------------------------------------------------------------
*/

svm_static jint
_svmf_mi_update_all_active_invoke_sites (_svmt_JNIEnv *env,
					 _svmt_method_info *calling_method,
					 _svmt_code *old_code,
					 size_t old_code_length,
					 _svmt_code *old_invoke)
{
  jint i;
  _svmt_JavaVM *vm = env->vm;
  _svmt_JNIEnv *thread;
  _svmt_stack_frame *tmp_frame;
  _svmt_method_info *tmp_method;
  _svmt_code *tmp_frame_pc;
  _svmt_code *old_code_end = old_code + old_code_length;
  _svmt_code *new_code = calling_method->frame_info->code;

/*   _svmt_stack_frame *curr_stack_frame = env->stack.current_frame; */

  thread = vm->threads.user;

  /* i = 0 : check all user threads   */
  /* i = 1 : check all system threads */
  for (i = 0; i <= 1; i++)
    {
      while (thread != NULL)
	{
	  tmp_frame = thread->stack.current_frame;
	  tmp_method = tmp_frame->method_frame_info->method;

	  while (tmp_method != &vm->stack_bottom_method)
	    {
	      tmp_frame_pc = tmp_frame->pc;

	      /* This method is calling method or inlined method executing in calling method */
	      if ((tmp_frame_pc >= old_code) && (tmp_frame_pc < old_code_end))

/* 		if (tmp_method == calling_method) */
		{
		  /* fix the invoke's pc */
		  tmp_frame->pc = _svmf_mi_convert_old_addr_to_new
		    (env, new_code, old_code, old_invoke,
		     tmp_frame_pc);
		  
		  /* adjust ASTORE_RET local variables */
		  {
		    jint curr = tmp_method->frame_info->non_addr_locals_count;
		    jint max =
		      curr +
		      tmp_method->frame_info->non_parameter_addr_locals_count;
		    _svmt_stack_value *locals =
		      (_svmt_stack_value *) (void *) (((char *) tmp_frame) -
						      tmp_frame->
						      method_frame_info->
						      start_offset);

		    while (curr < max)
		      {
			locals[curr].addr = _svmf_mi_convert_old_addr_to_new
			  (env, new_code, old_code, old_invoke,
			   locals[curr].addr);

			curr++;

		      }
		  }

		}

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
_svmf_mi_inline_method
----------------------------------------------------------------------
*/
svm_static jint
_svmf_mi_inline_method (_svmt_JNIEnv *env,
			_svmt_method_info *callee_method,
			_svmt_code *invoke_addr,
			jint invoke_instruction)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_method_info *calling_method =
    env->stack.current_frame->method_frame_info->method;
  _svmt_code *old_code = calling_method->frame_info->code;
  size_t old_code_length = calling_method->frame_info->code_length;

  /* stop the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_stop_the_world (env);
  _svmm_mutex_unlock ();

  /* check if another thread has changed the code array 
     while we were waiting for the mutex */
  {
    _svmt_code *pc = env->stack.current_frame->pc;
    
    /* code array has changed,  */
    if((pc < old_code) || (pc >= (old_code + old_code_length)))
      {
	goto error; 
      }
  }
  
#ifndef NDEBUG

  if (vm->verbose_method_inlining)
    {
      _svmf_printf(env, stderr, "\n[T%d] ", env->thread.id);
      switch (invoke_instruction)
	{
	case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	  {
	    _svmf_print_method_name_and_caller (env, stderr, calling_method,
						callee_method,
						"INLINING STARTED (VIRTUAL): ");
	    break;
	  }
	case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	  {
	    _svmf_print_method_name_and_caller (env, stderr, calling_method,
						callee_method,
						"INLINING STARTED (INTERFACE): ");
	    break;
	  }
	case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	  {
	    _svmf_print_method_name_and_caller (env, stderr, calling_method,
						callee_method,
						"INLINING STARTED (SPECIAL): ");
	    break;
	  }
	case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	  {
	    _svmf_print_method_name_and_caller (env, stderr, calling_method,
						callee_method,
						"INLINING STARTED (STATIC): ");
	    break;
	  }
	}
    }
#endif

  /* Don't inline callee method in profiling array */
  if (old_code == calling_method->frame_info->profiling_code)
    {
      goto error;
    }

  if ((calling_method == callee_method) ||
      callee_method->frame_info->contains_inlined_code ||
      calling_method->frame_info->execution_is_in_caller_inlined_code)
    {
      /* DO NOT SUPPORT IMBRICATED INLINING */
      goto error;
    }

  vm->mi_info.invoke_instruction = invoke_instruction;
  vm->mi_info.invoke_offset = invoke_addr - 
    calling_method->frame_info->code;

  /* Use collected profiling info to select the path to inline 
     in the callee method */
  if (_svmf_mi_select_path_to_inline (env,
				      calling_method,
				      callee_method) != JNI_OK)
    {
      return JNI_ERR;
    }

/*   _svmf_mi_output_code_array (env, */
/* 			      stdout, */
/* 			      selected_path, */
/* 			      selected_path_length, */
/* 			      "\nSelected Path to inline", NULL); */

  /* Build temporary exception table for path to inline */
  if (callee_method->data.code_attribute->exception_table_length > 0)
    {
      /* build temporary exception table for selected path in the callee method */
      if (_svmf_mi_build_selected_path_exception_table
	  (env, callee_method) != JNI_OK)
	{
	  assert(1 == 0);
	  return JNI_ERR;
	}
    }
  
  /* build calling method new code array + exception table */
  if(_svmf_mi_build_new_calling_method(env, calling_method, callee_method)
     != JNI_OK)
    {
      assert(1 == 0);
      return JNI_ERR;
    }
  
  /* assure there's enough space for stack_frame needed by inlined method */
  {
    size_t extra_space =
      callee_method->frame_info->java_invoke_frame_size -
      calling_method->frame_info->extra_frame_size;
    
    if (extra_space > 0)
      {
	calling_method->frame_info->extra_frame_size += extra_space;
	
	if (_svmf_ensure_stack_capacity (env,
					 calling_method->frame_info->
					 extra_frame_size) != JNI_OK)
	  {
	    assert (1 == 0);
	    return JNI_ERR;
	  }
      }
  }
  
  /* Adjust pc to continue execution at the beginning of the inlined code 
     in the new code array */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

  /* find address where to resume execution 
     (might be in the middle of a sequence) */
  {
    jint bytecode = -1;

    switch(invoke_instruction)
      {
      case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
	{
	  bytecode = SVM_INSTRUCTION_INLINED_INVOKESTATIC;
	  break;
	}
      case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
	{
	  bytecode = SVM_INSTRUCTION_INLINED_INVOKESPECIAL;
	  break;
	}
      case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
	{
	  bytecode = SVM_INSTRUCTION_INLINED_INVOKEVIRTUAL;
	  break;
	}
      case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
	{
	  bytecode = SVM_INSTRUCTION_INLINED_INVOKEINTERFACE;
	  break;
	}
      default:
	{
	  _svmm_fatal_error("impossible control flow");
	}
      }
    
    if((env->stack.current_frame->resuming_implementation = 
	_svmf_mi_get_bytecode_impl_in_sequence(env, 
					       vm->mi_info.resuming_seq,
					       bytecode)) == NULL)
      {
	assert(1 == 0);
	return JNI_ERR;
      }
  }

  /* resuming_pc has already been set in _svmf_mi_merge_sequences */
/*   _svmf_printf(env, stderr, "resuming_pc[%p]\n", vm->mi_info.resuming_pc); */

#else
  vm->mi_info.resuming_pc = calling_method->frame_info->code + vm->mi_info.invoke_offset;							
#endif

/*   _svmf_printf (env, stderr, "setting pc to: pc=%p\n", */
/* 		new_code + invoke_offset); */

  /* TO REMOVE ???: useless */
#ifndef NDEBUG
  callee_method->frame_info->has_been_inlined = JNI_TRUE;
#endif

  calling_method->frame_info->contains_inlined_code = JNI_TRUE;

#if 0
  if((_svmf_mi_method_is(callee_method,
			"java/lang/Throwable", "fillInStackTrace") == JNI_TRUE) && 
     (_svmf_mi_method_is(calling_method, "java/lang/Throwable", "<init>") == JNI_TRUE))
  {
      vm->verbose_methods = JNI_TRUE;
      vm->verbose_instructions = JNI_TRUE;
      _svmf_dump_stack_trace(env);
      /*   vm->verbose_gc = JNI_TRUE; */
  }
#endif
  

  /* update method code for all invokes currently activated */
  if (_svmf_mi_update_all_active_invoke_sites
      (env, calling_method, old_code, old_code_length, invoke_addr) != JNI_OK)
    {
      assert (1 == 0);
      goto error;
    }

  /* wait at the last minute to adjust pc for resuming in the newly 
     created calling method code array */
  env->stack.current_frame->pc = vm->mi_info.resuming_pc;
  
/*   _svmf_printf(env, stderr, "[T%d] setting frame->pc to %p in frame[%p]\n",  */
/* 	       env->thread.id, */
/* 	       env->stack.current_frame->pc, */
/*   	       env->stack.current_frame); */

#ifndef NDEBUG
  if (vm->verbose_method_inlining)
    {
      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
      _svmf_print_method_name_and_caller (env, stderr, calling_method,
					  callee_method, "INLINING DONE: ");
    }

/* [soot/SootClass.getMethods] in [soot/SootResolver.bringToSignatures] */

  if((_svmf_mi_method_is(callee_method, "soot/SootClass", "getMethods") == JNI_TRUE) &&
     (_svmf_mi_method_is(calling_method, "soot/SootResolver", "bringToSignatures") == JNI_TRUE))
    
    {
      _svmf_mi_print_bytecode_count(env, NULL, "AFTER INLINING", -1);
    }

#if 0
 {
   jint cpt;
   if((_svmf_mi_method_is(calling_method, "java/lang/ref/Reference", "<init>") == JNI_TRUE) &&
      (_svmf_mi_method_is(callee_method, "java/lang/Object", "<init>") == JNI_TRUE))
     
     { 
       if(cpt == 0)
	 {
	   vm->mi_info.debug_method = calling_method;
	 }

       cpt++;
       _svmf_dump_stack_trace(env);
       _svmf_printf(env, stderr, "\n");
     }
#endif

#endif

#ifdef _SABLEVM_METHOD_INLINING_STATS
  switch (invoke_instruction)
    {
    case SVM_INSTRUCTION_COUNTING_INVOKEVIRTUAL:
      {
	vm->mi_info.total_inlined_invokevirtual++;
	break;
      }
    case SVM_INSTRUCTION_COUNTING_INVOKEINTERFACE:
      {
	vm->mi_info.total_inlined_invokeinterface++;
	break;
      }
    case SVM_INSTRUCTION_COUNTING_INVOKESPECIAL:
      {
	vm->mi_info.total_inlined_invokespecial++;
	break;
      }
    case SVM_INSTRUCTION_COUNTING_INVOKESTATIC:
      {
	vm->mi_info.total_inlined_invokestatic++;
	break;
      }
    }
#endif

  /* resume the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_resume_the_world (env);
  _svmm_mutex_unlock ();

  return JNI_OK;

error:

#ifndef NDEBUG
  if (vm->verbose_method_inlining)
    {
      _svmf_printf(env, stderr, "[T%d] ", env->thread.id);
      _svmf_print_method_name_and_caller (env, stderr, calling_method,
					  callee_method,
					  "INLINING FAILED for ");
      _svmf_printf (env, stderr, "\n");
    }
#endif

  /* resume the world */
  _svmm_mutex_lock (vm->global_mutex);
  _svmf_resume_the_world (env);
  _svmm_mutex_unlock ();

  return JNI_ERR;
}



/* 	m4svm_instruction_head (INLINED_LOOKUPSWITCH_DEFAULT, -1); */

/* 	_svmf_printf_ptr(env, stderr, "\n---------------------------------\n"); */
/* 	_svmf_printf_ptr(env, stderr, */
/* 			 "INLINED_LOOKUPSWITCH_DEFAULT: IN\n"); */
/* /\* 	_svmf_mi_print_bytecode_count_ptr (env, pc); *\/ */
	
/* 	{ */
/* 	  _svmt_code *table; */
/* 	  jint npairs; */
/* 	  jint key; */

/* 	  jint low; */
/* 	  jint high; */

/* 	  table = (pc++)->addr->addr;	/\* original table *\/ */

/* 	  _svmf_printf_ptr(env, stderr, */
/* 			   "INLINED_LOOKUPSWITCH_DEFAULT: %p table[%p]\n", pc-1, table); */

/* 	  npairs = table[-1].jint; */

/* 	  _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: npairs[%d]\n", npairs); */

/* 	  key = stack[--stack_size].jint; */

/* 	  _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: key[%d]\n", key); */

/* 	  low = 0; */
/* 	  high = npairs - 1; */

/* 	  /\* If the key does not correspond to the inlined default case *\/ */
/* 	  /\* branch at the correct target in the original code *\/ */
/* 	  while (high >= low) */
/* 	    { */
/* 	      jint middle; */
/* 	      jint match; */

/* 	      _svmf_printf_ptr(env, stderr, "\nINLINED_LOOKUPSWITCH_DEFAULT: low[%d] high[%d]\n", */
/* 			       low, high); */

/* 	      middle = (low + high) / 2; */
/* 	      _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: middel*2[%d]\n", middle*2); */

/* 	      match = table[middle * 2].jint; */
/* 	      _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: key[%d] match[%d]\n", key, match); */

/* 	      _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: before if\n"); */
/* 	      _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: (key == match)[%d]\n", (key == match)); */
	      
/* 	      if (key == match) */
/* 		{ */
/* 		  _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: inside if\n"); */

/* 		  _svmf_printf_ptr(env, stderr, */
/* 				   "INLINED_LOOKUPSWITCH_DEFAULT: setting pc to addr contained at "); */
/* 		  _svmf_printf_ptr(env, stderr,"%p\n", table+(middle*2+1)); */

/* 		  pc = table[middle * 2 + 1].addr; */
/* 		  break; */
/* 		} */
/* 	      else if (key > match) */
/* 		{ */
/* 		  _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: in if(key > match)\n"); */
/* 		  low = middle + 1; */
/* 		} */
/* 	      else */
/* 		{ */
/* 		  _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: in if(key < match)\n"); */
/* 		  high = middle - 1; */
/* 		} */
/* 	      _svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: after if\n"); */

/* 	    } */

/* 	  _svmf_printf_ptr(env, stderr, */
/* 			   "INLINED_LOOKUPSWITCH_DEFAULT: continuing inlined code\n"); */
/* 	} */

/* 	_svmf_printf_ptr(env, stderr, "INLINED_LOOKUPSWITCH_DEFAULT: OUT\n"); */
/* 	_svmf_printf_ptr(env, stderr, "---------------------------------\n"); */

/* 	m4svm_instruction_tail (); */

/* ---------------------------------------------------------------------- */

/* 	m4svm_instruction_head (INLINED_LOOKUPSWITCH_DEFAULT, -1); */
/* 	{ */
/* 	  _svmt_code *table = (pc++)->addr->addr; /\* original table *\/ */
/* 	  jint key = stack[--stack_size].jint; */
/* 	  pc = _svmf_mi_inlined_lookupswitch_default_job_ptr(env, table, key, pc);  */
/* 	}     */
/* 	m4svm_instruction_tail (); */

