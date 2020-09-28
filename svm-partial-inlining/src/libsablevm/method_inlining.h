/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef SVM_METHOD_INLINING_H
#define SVM_METHOD_INLINING_H

#ifdef _SABLEVM_DIRECT_THREADED_INTERPRETER

inline svm_static jint
_svmf_mi_get_instruction_int_code (_svmt_JNIEnv *, const void *);

#endif /* _SABLEVM_DIRECT_THREADED_INTERPRETER */

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

/* svm_static jint _svmf_mi_get_non_prepare_instruction (jint); */

#define _svmm_mi_get_sequence(a, b, c, d, e, f) \
_svmh_mi_get_sequence(a, &b, c, d, &e, f)

svm_static jint
_svmh_mi_get_sequence (_svmt_JNIEnv *, jint **, jint, size_t,
		       _svmt_mi_sequence_node_info **, jboolean);

inline svm_static _svmt_mi_sequence_node_info
  * _svmf_mi_get_sequence_by_implementation (_svmt_JNIEnv *, const void *);

#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */


#endif /* SVM_METHOD_INLINING_H */
