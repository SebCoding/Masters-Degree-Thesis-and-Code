/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_RESOLVE_H
#define SVM_RESOLVE_H

jint _svmf_resolve_CONSTANT_Class
  (_svmt_JNIEnv *env, _svmt_class_info *class,
   _svmt_CONSTANT_Class_info **cp_class);

jint _svmf_resolve_CONSTANT_Fieldref
  (_svmt_JNIEnv *env, _svmt_class_info *class,
   _svmt_CONSTANT_Fieldref_info **cp_field);

jint _svmf_resolve_CONSTANT_Methodref
  (_svmt_JNIEnv *env, _svmt_class_info *class,
   _svmt_CONSTANT_Methodref_info **cp_method);

jint _svmf_resolve_CONSTANT_InterfaceMethodref
  (_svmt_JNIEnv *env, _svmt_class_info *class,
   _svmt_CONSTANT_InterfaceMethodref_info **cp_imethod);

_svmt_method_info *_svmf_resolve_class_method
  (_svmt_JNIEnv *env, _svmt_class_info *class,
   const char *name, const char *descriptor);

#endif /* NOT SVM_RESOLVE_H */
