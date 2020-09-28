/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_NATIVE_H
#define SVM_NATIVE_H

jint _svmf_bind_native_method (_svmt_JNIEnv *env, _svmt_method_info *method);
jint _svmf_native_method_short_name (_svmt_JNIEnv *env,
				     _svmt_method_info *method);
jint _svmf_native_method_long_name (_svmt_JNIEnv *env,
				    _svmt_method_info *method);
jint _svmf_compute_native_ffi_args (_svmt_JNIEnv *env,
				    _svmt_method_info *method);
jint _svmf_invoke_native_nonstatic (_svmt_JNIEnv *env);
jint _svmf_invoke_native_static (_svmt_JNIEnv *env);

#endif /* NOT SVM_NATIVE_H */
