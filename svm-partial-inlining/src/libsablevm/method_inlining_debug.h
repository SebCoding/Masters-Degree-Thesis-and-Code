/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_METHOD_INLINING_DEBUG_H
#define SVM_METHOD_INLINING_DEBUG_H


svm_static void SVM_UNUSED _svmf_mi_segfault (void);

svm_static void SVM_UNUSED
_svmf_print_method_name (_svmt_JNIEnv *, FILE *, _svmt_method_info *,
			 const char *);

svm_static void SVM_UNUSED
_svmf_print_method_name_and_caller (_svmt_JNIEnv *, FILE *,
				    _svmt_method_info *, _svmt_method_info *,
				    const char *);

svm_static jboolean SVM_UNUSED
_svmf_mi_method_is (_svmt_method_info *, const char *, const char *);

svm_static void SVM_UNUSED
_svmf_mi_output_exception_table (_svmt_JNIEnv *, FILE *, jint,
				 _svmt_exception_table *, const char *);

svm_static void SVM_UNUSED
_svmf_mi_output_code_array (_svmt_JNIEnv *, FILE *, _svmt_code *,
			    size_t, const char *, _svmt_code *);


#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER
svm_static jint SVM_UNUSED
_svmf_mi_print_super_instruction (_svmt_JNIEnv *, FILE *, const void *);
#endif


#endif /* NOT SVM_METHOD_INLINING_DEBUG_H */
