/* This file has been automatically generated from "global_alloc.list" */

#ifndef SVM_GLOBAL_ALLOC_H
#define SVM_GLOBAL_ALLOC_H

/*
----------------------------------------------------------------------
_svmm_gzalloc_env_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_env_no_exception(ptr) \
_svmh_gzalloc_env_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzalloc_env_no_exception(ptr) \
_svmh_gzalloc_env_no_exception (&ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_env_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_env_no_exception(ptr) \
_svmh_gzfree_env_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_env_no_exception(ptr) \
_svmh_gzfree_env_no_exception (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_fat_lock_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_fat_lock_no_exception(ptr) \
_svmh_gzalloc_fat_lock_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzalloc_fat_lock_no_exception(ptr) \
_svmh_gzalloc_fat_lock_no_exception (&ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_fat_lock_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_fat_lock_no_exception(ptr) \
_svmh_gzfree_fat_lock_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_fat_lock_no_exception(ptr) \
_svmh_gzfree_fat_lock_no_exception (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_initialization_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_initialization_no_exception(ptr) \
_svmh_gzalloc_initialization_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzalloc_initialization_no_exception(ptr) \
_svmh_gzalloc_initialization_no_exception (&ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_initialization_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_initialization_no_exception(ptr) \
_svmh_gzfree_initialization_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_initialization_no_exception(ptr) \
_svmh_gzfree_initialization_no_exception (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_native_ref_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_native_ref_no_exception(ptr) \
_svmh_gzalloc_native_ref_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzalloc_native_ref_no_exception(ptr) \
_svmh_gzalloc_native_ref_no_exception (&ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_native_ref_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_native_ref_no_exception(ptr) \
_svmh_gzfree_native_ref_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_native_ref_no_exception(ptr) \
_svmh_gzfree_native_ref_no_exception (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_vm_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_vm_no_exception(ptr) \
_svmh_gzalloc_vm_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzalloc_vm_no_exception(ptr) \
_svmh_gzalloc_vm_no_exception (&ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_vm_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_vm_no_exception(ptr) \
_svmh_gzfree_vm_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_vm_no_exception(ptr) \
_svmh_gzfree_vm_no_exception (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_cchars_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_cchars_no_exception(n, ptr) \
_svmh_gzmalloc_cchars_no_exception (__FILE__, __FUNCTION__, __LINE__, n,&ptr)

#else

#define _svmm_gzmalloc_cchars_no_exception(n, ptr) \
_svmh_gzmalloc_cchars_no_exception (n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_cchars_no_exception
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_cchars_no_exception(ptr) \
_svmh_gzmfree_cchars_no_exception (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_cchars_no_exception(ptr) \
_svmh_gzmfree_cchars_no_exception (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_class_loader_info
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_class_loader_info(env, ptr) \
_svmh_gzalloc_class_loader_info (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_class_loader_info(env, ptr) \
_svmh_gzalloc_class_loader_info (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_class_loader_info
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_class_loader_info(ptr) \
_svmh_gzfree_class_loader_info (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_class_loader_info(ptr) \
_svmh_gzfree_class_loader_info (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_gc_map_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_gc_map_node(env, ptr) \
_svmh_gzalloc_gc_map_node (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_gc_map_node(env, ptr) \
_svmh_gzalloc_gc_map_node (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_gc_map_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_gc_map_node(ptr) \
_svmh_gzfree_gc_map_node (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_gc_map_node(ptr) \
_svmh_gzfree_gc_map_node (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_imethod_signature_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_imethod_signature_node(env, ptr) \
_svmh_gzalloc_imethod_signature_node (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_imethod_signature_node(env, ptr) \
_svmh_gzalloc_imethod_signature_node (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_imethod_signature_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_imethod_signature_node(ptr) \
_svmh_gzfree_imethod_signature_node (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_imethod_signature_node(ptr) \
_svmh_gzfree_imethod_signature_node (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_memory_block
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_memory_block(env, ptr) \
_svmh_gzalloc_memory_block (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_memory_block(env, ptr) \
_svmh_gzalloc_memory_block (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_memory_block
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_memory_block(ptr) \
_svmh_gzfree_memory_block (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_memory_block(ptr) \
_svmh_gzfree_memory_block (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_type_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_type_node(env, ptr) \
_svmh_gzalloc_type_node (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_type_node(env, ptr) \
_svmh_gzalloc_type_node (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_type_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_type_node(ptr) \
_svmh_gzfree_type_node (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_type_node(ptr) \
_svmh_gzfree_type_node (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_internal_method_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_internal_method_node(env, ptr) \
_svmh_gzalloc_internal_method_node (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_internal_method_node(env, ptr) \
_svmh_gzalloc_internal_method_node (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_internal_method_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_internal_method_node(ptr) \
_svmh_gzfree_internal_method_node (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_internal_method_node(ptr) \
_svmh_gzfree_internal_method_node (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzalloc_zip_file
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_zip_file(env, ptr) \
_svmh_gzalloc_zip_file (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_zip_file(env, ptr) \
_svmh_gzalloc_zip_file (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_zip_file
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_zip_file(ptr) \
_svmh_gzfree_zip_file (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_zip_file(ptr) \
_svmh_gzfree_zip_file (&ptr)

#endif


#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER) 

/*
----------------------------------------------------------------------
_svmm_gzalloc_sequence_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_sequence_node(env, ptr) \
_svmh_gzalloc_sequence_node (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_sequence_node(env, ptr) \
_svmh_gzalloc_sequence_node (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_sequence_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_sequence_node(ptr) \
_svmh_gzfree_sequence_node (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_sequence_node(ptr) \
_svmh_gzfree_sequence_node (&ptr)

#endif


#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER) && defined(_SABLEVM_METHOD_INLINING)

/*
----------------------------------------------------------------------
_svmm_gzalloc_mi_sequence_node_info
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_mi_sequence_node_info(env, ptr) \
_svmh_gzalloc_mi_sequence_node_info (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_mi_sequence_node_info(env, ptr) \
_svmh_gzalloc_mi_sequence_node_info (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_mi_sequence_node_info
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_mi_sequence_node_info(ptr) \
_svmh_gzfree_mi_sequence_node_info (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_mi_sequence_node_info(ptr) \
_svmh_gzfree_mi_sequence_node_info (&ptr)

#endif


#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER && _SABLEVM_METHOD_INLINING */

#if defined (_SABLEVM_METHOD_INLINING) && defined (_SABLEVM_DIRECT_THREADED_INTERPRETER)

/*
----------------------------------------------------------------------
_svmm_gzalloc_mi_instruction_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzalloc_mi_instruction_node(env, ptr) \
_svmh_gzalloc_mi_instruction_node (__FILE__, __FUNCTION__, __LINE__, env, &ptr)

#else

#define _svmm_gzalloc_mi_instruction_node(env, ptr) \
_svmh_gzalloc_mi_instruction_node (env, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzfree_mi_instruction_node
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzfree_mi_instruction_node(ptr) \
_svmh_gzfree_mi_instruction_node (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzfree_mi_instruction_node(ptr) \
_svmh_gzfree_mi_instruction_node (&ptr)

#endif


#endif /* _SABLEVM_METHOD_INLINING && _SABLEVM_INLINED_THREADED_INTERPRETER */

/*
----------------------------------------------------------------------
_svmm_gmalloc_cchars
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmalloc_cchars(env, n, ptr) \
_svmh_gmalloc_cchars (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gmalloc_cchars(env, n, ptr) \
_svmh_gmalloc_cchars (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gmfree_cchars
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmfree_cchars(ptr) \
_svmh_gmfree_cchars (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gmfree_cchars(ptr) \
_svmh_gmfree_cchars (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gmalloc_ints
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmalloc_ints(env, n, ptr) \
_svmh_gmalloc_ints (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gmalloc_ints(env, n, ptr) \
_svmh_gmalloc_ints (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gmfree_ints
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmfree_ints(ptr) \
_svmh_gmfree_ints (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gmfree_ints(ptr) \
_svmh_gmfree_ints (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gmalloc_ubytes
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmalloc_ubytes(env, n, ptr) \
_svmh_gmalloc_ubytes (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gmalloc_ubytes(env, n, ptr) \
_svmh_gmalloc_ubytes (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gmfree_ubytes
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmfree_ubytes(ptr) \
_svmh_gmfree_ubytes (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gmfree_ubytes(ptr) \
_svmh_gmfree_ubytes (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gmalloc_chars
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmalloc_chars(env, n, ptr) \
_svmh_gmalloc_chars (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gmalloc_chars(env, n, ptr) \
_svmh_gmalloc_chars (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gmfree_chars
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gmfree_chars(ptr) \
_svmh_gmfree_chars (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gmfree_chars(ptr) \
_svmh_gmfree_chars (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_env_array
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_env_array(env,n,ptr) \
_svmh_gzmalloc_env_array (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_env_array(env,n,ptr) \
_svmh_gzmalloc_env_array (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_env_array
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_env_array(ptr) \
_svmh_gzmfree_env_array (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_env_array(ptr) \
_svmh_gzmfree_env_array (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_fat_lock_array
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_fat_lock_array(env,n,ptr) \
_svmh_gzmalloc_fat_lock_array (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_fat_lock_array(env,n,ptr) \
_svmh_gzmalloc_fat_lock_array (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_fat_lock_array
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_fat_lock_array(ptr) \
_svmh_gzmfree_fat_lock_array (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_fat_lock_array(ptr) \
_svmh_gzmfree_fat_lock_array (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_instruction_info
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_instruction_info(env,n,ptr) \
_svmh_gzmalloc_instruction_info (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_instruction_info(env,n,ptr) \
_svmh_gzmalloc_instruction_info (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_instruction_info
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_instruction_info(ptr) \
_svmh_gzmfree_instruction_info (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_instruction_info(ptr) \
_svmh_gzmfree_instruction_info (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_instruction_preparation
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_instruction_preparation(env,n,ptr) \
_svmh_gzmalloc_instruction_preparation (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_instruction_preparation(env,n,ptr) \
_svmh_gzmalloc_instruction_preparation (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_instruction_preparation
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_instruction_preparation(ptr) \
_svmh_gzmfree_instruction_preparation (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_instruction_preparation(ptr) \
_svmh_gzmfree_instruction_preparation (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_local_preparation
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_local_preparation(env,n,ptr) \
_svmh_gzmalloc_local_preparation (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_local_preparation(env,n,ptr) \
_svmh_gzmalloc_local_preparation (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_local_preparation
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_local_preparation(ptr) \
_svmh_gzmfree_local_preparation (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_local_preparation(ptr) \
_svmh_gzmfree_local_preparation (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_ubytes
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_ubytes(env,n,ptr) \
_svmh_gzmalloc_ubytes (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_ubytes(env,n,ptr) \
_svmh_gzmalloc_ubytes (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_ubytes
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_ubytes(ptr) \
_svmh_gzmfree_ubytes (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_ubytes(ptr) \
_svmh_gzmfree_ubytes (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_boot_class_path_entry
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_boot_class_path_entry(env,n,ptr) \
_svmh_gzmalloc_boot_class_path_entry (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_boot_class_path_entry(env,n,ptr) \
_svmh_gzmalloc_boot_class_path_entry (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_boot_class_path_entry
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_boot_class_path_entry(ptr) \
_svmh_gzmfree_boot_class_path_entry (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_boot_class_path_entry(ptr) \
_svmh_gzmfree_boot_class_path_entry (&ptr)

#endif


/*
----------------------------------------------------------------------
_svmm_gzmalloc_zip_file_entry
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmalloc_zip_file_entry(env,n,ptr) \
_svmh_gzmalloc_zip_file_entry (__FILE__, __FUNCTION__, __LINE__, env, n, &ptr)

#else

#define _svmm_gzmalloc_zip_file_entry(env,n,ptr) \
_svmh_gzmalloc_zip_file_entry (env, n, &ptr)

#endif

/*
----------------------------------------------------------------------
_svmm_gzmfree_zip_file_entry
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_MEMORY_DEBUGGING

#define _svmm_gzmfree_zip_file_entry(ptr) \
_svmh_gzmfree_zip_file_entry (__FILE__, __FUNCTION__, __LINE__, &ptr)

#else

#define _svmm_gzmfree_zip_file_entry(ptr) \
_svmh_gzmfree_zip_file_entry (&ptr)

#endif


#endif /* NOT SVM_GLOBAL_ALLOC_H */
