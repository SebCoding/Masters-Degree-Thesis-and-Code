/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_MACROS_H
#define SVM_MACROS_H

/*
----------------------------------------------------------------------
various macros
----------------------------------------------------------------------
*/



#define GET_BIT(Bytes,Index) \
(((((unsigned char *) (Bytes))[(Index) / 8]) >> (Index % 8)) & 1)

#define SET1_BIT(Bytes,Index) \
(((unsigned char *) (Bytes))[(Index) / 8] |= ((unsigned char) 1) << (Index % 8))

#define SET0_BIT(Bytes,Index) \
(((unsigned char *) (Bytes))[(Index) / 8] &= ~(((unsigned char) 1) << (Index % 8)))

/*
----------------------------------------------------------------------
array access
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_GEN_COPY_GC
#define WRITE_CARD(Instance,Vm)	\
  ((Vm)->heap).card_table_base1[CARD_TABLE_INDEX ((Instance), ((Vm)->heap))] = 1
#else
#define WRITE_CARD(Instance,Vm)
#endif



/*
----------------------------------------------------------------------
field access
----------------------------------------------------------------------
*/

#define GET_OBJECT_REFERENCE_FIELD(Instance,Offset) \
  (*((_svmt_object_instance **) (((char *) Instance) + Offset)))

#define SET_OBJECT_REFERENCE_FIELD(Vm,Instance,Offset,Value)		    \
  (*((_svmt_object_instance **) (((char *) Instance) + Offset))) = (Value);  \
  WRITE_CARD (((_svmt_object_instance **) (((char *) Instance) + Offset)), Vm)

#define GET_ARRAY_REFERENCE_FIELD(Instance,Offset) \
  (*((_svmt_array_instance **) (((char *) Instance) + Offset)))

#define SET_ARRAY_REFERENCE_FIELD(Vm,Instance,Offset,Value)		   \
  (*((_svmt_array_instance **) (((char *) Instance) + Offset))) = (Value);  \
  WRITE_CARD (((_svmt_array_instance **) (((char *) Instance) + Offset)), Vm)

#define BYTE_FIELD(Instance,Offset) \
  (*((jbyte *) (((char *) Instance) + Offset)))

#define SHORT_FIELD(Instance,Offset) \
  (*((jshort *) (((char *) Instance) + Offset)))

#define CHAR_FIELD(Instance,Offset) \
  (*((jchar *) (((char *) Instance) + Offset)))

#define INT_FIELD(Instance,Offset) \
  (*((jint *) (((char *) Instance) + Offset)))

#define LONG_FIELD(Instance,Offset) \
  (*((jlong *) (((char *) Instance) + Offset)))

#define FLOAT_FIELD(Instance,Offset) \
  (*((jfloat *) (((char *) Instance) + Offset)))

#define DOUBLE_FIELD(Instance,Offset) \
  (*((jdouble *) (((char *) Instance) + Offset)))


/*
----------------------------------------------------------------------
identity test
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_CHECK_CASTS

#define _svmm_is_same_object(o1,o2)		\
  _svmf_is_same_object ((o1), (o2))

int _svmf_is_same_object (jobject o1, jobject o2);

#else /* _SABLEVM_CHECK_CASTS */

#define _svmm_is_same_object(o1,o2)		\
  (((o1) != NULL && (o2) != NULL && (*(o1)) == (*(o2))) || ((o1) == NULL && (o2) == NULL ))

#endif /* _SABLEVM_CHECK_CASTS */



/*
----------------------------------------------------------------------
flags
----------------------------------------------------------------------
*/




/*
----------------------------------------------------------------------
rec_mutex
----------------------------------------------------------------------
*/

#define _svmm_rec_mutex_init(rec_mutex)			\
  pthread_rec_mutex_svm_init(&rec_mutex, NULL)

#define _svmm_rec_mutex_destroy(rec_mutex)		\
  pthread_rec_mutex_svm_destroy(&rec_mutex)

#define _svmm_rec_mutex_lock(rec_mutex)			\
{						\
  pthread_rec_mutex_svm_t *XXXprecmutexXXX = &rec_mutex;	\
  pthread_rec_mutex_svm_lock (XXXprecmutexXXX)

#define _svmm_rec_mutex_unlock()			\
  pthread_rec_mutex_svm_unlock (XXXprecmutexXXX);		\
}

/*
----------------------------------------------------------------------
allocation
----------------------------------------------------------------------
*/

#define _svmm_alloc_header(name,type)		\
jint _svmdf_alloc_ ## name (type **);		\
void _svmdf_free_ ## name (type **);

#define _svmm_alloc_implementation(name,type)			\
jint								\
_svmdf_alloc_ ## name (type **name)				\
{								\
  return internal_alloc (sizeof (type), (void **) name);	\
}								\
void								\
_svmdf_free_ ## name (type **name)				\
{								\
  internal_free ((void **) name);				\
}

#define _svmm_zalloc_header(name,type)		\
jint _svmdf_zalloc_ ## name (type **);		\
void _svmdf_free_ ## name (type **);

#define _svmm_zalloc_implementation(name,type)			\
jint								\
_svmdf_zalloc_ ## name (type **name)				\
{								\
  return internal_zalloc (sizeof (type), (void **) name);	\
}								\
void								\
_svmdf_free_ ## name (type **name)				\
{								\
  internal_free ((void **) name);				\
}

#define _svmm_malloc_header(name,type) 		\
jint _svmdf_malloc_ ## name (size_t, type **); 	\
void _svmdf_free_ ## name (type **);

#define _svmm_malloc_implementation(name,type) 				\
jint 									\
_svmdf_malloc_ ## name (size_t nmemb, type **name) 			\
{ 									\
  if (((sizeof (type) * nmemb) / nmemb) != sizeof (type))		\
    {									\
      return JNI_ERR;							\
    } 									\
  return internal_alloc (sizeof (type) * nmemb, (void **) name); 	\
} 									\
void 									\
_svmdf_free_ ## name (type **name) 					\
{ 									\
  internal_free ((void **) name); 					\
}

/*
----------------------------------------------------------------------
class loader allocation
----------------------------------------------------------------------
*/

#define _svmm_clalloc_header(name,type)					\
jint _svmdf_clalloc_ ## name (_svmt_JNIEnv *, _svmt_class_loader_info *, type **);	\
void _svmdf_clfree_ ## name (_svmt_JNIEnv *, _svmt_class_loader_info *, type **);

#define _svmm_clalloc_implementation(name,type)					\
jint 										\
_svmdf_clalloc_ ## name (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info, type **name)	\
{										\
  return internal_alloc (env, class_loader_info, sizeof (type), (void **) name);	\
}										\
void										\
_svmdf_clfree_ ## name (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info, type **name)	\
{										\
  internal_free (env, class_loader_info, sizeof (type), (void **) name);	        \
}

#define _svmm_clzalloc_header(name,type)					\
jint _svmdf_clzalloc_ ## name (_svmt_JNIEnv *, _svmt_class_loader_info *, type **);		\
void _svmdf_clfree_ ## name (_svmt_JNIEnv *, _svmt_class_loader_info *, type **);

#define _svmm_clzalloc_implementation(name,type)				\
jint 										\
_svmdf_clzalloc_ ## name (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info, type **name)	\
{										\
  return internal_zalloc (env, class_loader_info, sizeof (type), (void **) name);	\
}										\
void										\
_svmdf_clfree_ ## name (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info, type **name)	\
{										\
  internal_free (env, class_loader_info, sizeof (type), (void **) name);	        \
}

#define _svmm_clmalloc_header(name,type)					\
jint _svmdf_clmalloc_ ## name (_svmt_JNIEnv *, _svmt_class_loader_info *, size_t, type **);	\
void _svmdf_clfree_ ## name (_svmt_JNIEnv *, _svmt_class_loader_info *, size_t, type **);

#define _svmm_clmalloc_implementation(name,type)						\
jint												\
_svmdf_clmalloc_ ## name (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info, size_t nmemb, type **name)	\
{											        \
  if (((sizeof (type) * nmemb) / nmemb) != sizeof (type))				        \
    {											        \
      return JNI_ERR;									        \
    } 											        \
  return internal_alloc (env, class_loader_info, sizeof (type) * nmemb, (void **) name);             \
}												\
void												\
_svmdf_clfree_ ## name (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info, size_t nmemb, type **name)	\
{												\
  internal_free (env, class_loader_info, sizeof (type) * nmemb, (void **) name);		        \
}

#define _svmm_clzmalloc_header(name,type)					\
jint _svmdf_clzmalloc_ ## name (_svmt_JNIEnv *, _svmt_class_loader_info *, size_t, type **);	\
void _svmdf_clfree_ ## name (_svmt_JNIEnv *, _svmt_class_loader_info *, size_t, type **);

#define _svmm_clzmalloc_implementation(name,type)						\
jint												\
_svmdf_clzmalloc_ ## name (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info, size_t nmemb, type **name)	\
{											        \
  if (((sizeof (type) * nmemb) / nmemb) != sizeof (type))				        \
    {											        \
      return JNI_ERR;									        \
    } 											        \
  return internal_zalloc (env, class_loader_info, sizeof (type) * nmemb, (void **) name);            \
}												\
void												\
_svmdf_clfree_ ## name (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info, size_t nmemb, type **name)	\
{												\
  internal_free (env, class_loader_info, sizeof (type) * nmemb, (void **) name);		        \
}

/*
----------------------------------------------------------------------
safe casts
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_CHECK_CASTS

#define _svmm_cast_PtrJavaVM(vm)			\
  _svmf_cast_PtrJavaVM ((vm))

#define _svmm_cast_PtrSvmtClassInfo(type) \
  _svmf_cast_PtrSvmtClassInfo ((type))

#define _svmm_cast_PtrSvmtArrayInfo(type) \
  _svmf_cast_PtrSvmtArrayInfo ((type))

#define _svmm_cast_PtrSvmtTypeInfo_c(class) \
  _svmf_cast_PtrSvmtTypeInfo_c ((class))

#define _svmm_cast_PtrSvmtTypeInfo_a(array) \
  _svmf_cast_PtrSvmtTypeInfo_a ((array))

#define _svmm_cast_PtrPtrCONSTANTClassInfo(info) \
  _svmf_cast_PtrPtrCONSTANTClassInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTUtf8Info(info) \
  _svmf_cast_PtrPtrCONSTANTUtf8Info ((info))

#define _svmm_cast_PtrPtrCONSTANTFieldrefInfo(info) \
  _svmf_cast_PtrPtrCONSTANTFieldrefInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTMethodrefInfo(info) \
  _svmf_cast_PtrPtrCONSTANTMethodrefInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTInterfaceMethodrefInfo(info) \
  _svmf_cast_PtrPtrCONSTANTInterfaceMethodrefInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTNameAndTypeInfo(info) \
  _svmf_cast_PtrPtrCONSTANTNameAndTypeInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTStringInfo(info) \
  _svmf_cast_PtrPtrCONSTANTStringInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTIntegerInfo(info) \
  _svmf_cast_PtrPtrCONSTANTIntegerInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTFloatInfo(info) \
  _svmf_cast_PtrPtrCONSTANTFloatInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTLongInfo(info) \
  _svmf_cast_PtrPtrCONSTANTLongInfo ((info))

#define _svmm_cast_PtrPtrCONSTANTDoubleInfo(info) \
  _svmf_cast_PtrPtrCONSTANTDoubleInfo ((info))

#define _svmm_cast_PtrAttributeInfo_cv(info) \
  _svmf_cast_PtrAttributeInfo_cv ((info))

#define _svmm_cast_PtrAttributeInfo_c(info) \
  _svmf_cast_PtrAttributeInfo_c ((info))

#define _svmm_cast_PtrAttributeInfo_e(info) \
  _svmf_cast_PtrAttributeInfo_e ((info))

#define _svmm_cast_PtrAttributeInfo_ic(info) \
  _svmf_cast_PtrAttributeInfo_ic ((info))

#define _svmm_cast_PtrAttributeInfo_s(info) \
  _svmf_cast_PtrAttributeInfo_s ((info))

#define _svmm_cast_PtrAttributeInfo_sf(info) \
  _svmf_cast_PtrAttributeInfo_sf ((info))

#define _svmm_cast_PtrAttributeInfo_lnt(info) \
  _svmf_cast_PtrAttributeInfo_lnt ((info))

#define _svmm_cast_PtrAttributeInfo_lvt(info) \
  _svmf_cast_PtrAttributeInfo_lvt ((info))

#define _svmm_cast_PtrAttributeInfo_d(info) \
  _svmf_cast_PtrAttributeInfo_d ((info))

#define _svmm_cast_Jobject_nr(nr) \
  _svmf_cast_Jobject_nr ((nr))

#define _svmm_cast_PtrNativeRef(obj) \
  _svmf_cast_PtrNativeRef ((obj))

#define _svmm_cast_PtrCodeAttribute(info) \
  _svmf_cast_PtrCodeAttribute ((info))

#define _svmm_cast_Jarray(obj) \
  _svmf_cast_Jarray ((obj))

#define _svmm_cast_Jobject(array) \
  _svmf_cast_Jobject ((array))

#define _svmm_cast_PtrArrayInstance(obj) \
  _svmf_cast_PtrArrayInstance ((obj))

#define _svmm_cast_PtrObjectInstance(array) \
  _svmf_cast_PtrObjectInstance ((array))

JavaVM *_svmf_cast_PtrJavaVM (_svmt_JavaVM *vm);
_svmt_class_info *_svmf_cast_PtrSvmtClassInfo (_svmt_type_info *type);
_svmt_array_info *_svmf_cast_PtrSvmtArrayInfo (_svmt_type_info *type);
_svmt_type_info *_svmf_cast_PtrSvmtTypeInfo_c (_svmt_class_info *class);
_svmt_type_info *_svmf_cast_PtrSvmtTypeInfo_a (_svmt_array_info *array);
_svmt_CONSTANT_Class_info **_svmf_cast_PtrPtrCONSTANTClassInfo
  (_svmt_cp_info **info);
_svmt_CONSTANT_Utf8_info **_svmf_cast_PtrPtrCONSTANTUtf8Info
  (_svmt_cp_info **info);
_svmt_CONSTANT_Fieldref_info **_svmf_cast_PtrPtrCONSTANTFieldrefInfo
  (_svmt_cp_info **info);
_svmt_CONSTANT_Methodref_info **_svmf_cast_PtrPtrCONSTANTMethodrefInfo
  (_svmt_cp_info **info);
_svmt_CONSTANT_InterfaceMethodref_info
  **_svmf_cast_PtrPtrCONSTANTInterfaceMethodrefInfo (_svmt_cp_info **info);
_svmt_CONSTANT_NameAndType_info
  **_svmf_cast_PtrPtrCONSTANTNameAndTypeInfo (_svmt_cp_info **info);
_svmt_CONSTANT_String_info
  **_svmf_cast_PtrPtrCONSTANTStringInfo (_svmt_cp_info **info);
_svmt_CONSTANT_Integer_info
  **_svmf_cast_PtrPtrCONSTANTIntegerInfo (_svmt_cp_info **info);
_svmt_CONSTANT_Float_info **_svmf_cast_PtrPtrCONSTANTFloatInfo
  (_svmt_cp_info **info);
_svmt_CONSTANT_Long_info **_svmf_cast_PtrPtrCONSTANTLongInfo
  (_svmt_cp_info **info);
_svmt_CONSTANT_Double_info
  **_svmf_cast_PtrPtrCONSTANTDoubleInfo (_svmt_cp_info **info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_cv
  (_svmt_ConstantValue_attribute *info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_c
  (_svmt_Code_attribute *info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_e
  (_svmt_Exceptions_attribute *info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_ic
  (_svmt_InnerClasses_attribute *info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_s
  (_svmt_Synthetic_attribute *info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_sf
  (_svmt_SourceFile_attribute *info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_lnt
  (_svmt_LineNumberTable_attribute *info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_lvt
  (_svmt_LocalVariableTable_attribute *info);
_svmt_attribute_info *_svmf_cast_PtrAttributeInfo_d
  (_svmt_Deprecated_attribute *info);
jobject _svmf_cast_Jobject_nr (_svmt_native_ref *nr);
_svmt_native_ref *_svmf_cast_PtrNativeRef (jobject obj);
_svmt_Code_attribute *_svmf_cast_PtrCodeAttribute (_svmt_attribute_info
						   *info);
jarray _svmf_cast_Jarray (jobject obj);
jobject _svmf_cast_Jobject (jarray array);
_svmt_array_instance *_svmf_cast_PtrArrayInstance (_svmt_object_instance
						   *obj);
_svmt_object_instance *_svmf_cast_PtrObjectInstance (_svmt_array_instance
						     *array);

#else /* _SABLEVM_CHECK_CASTS */

#define _svmm_cast_PtrJavaVM(vm)			\
  ((JavaVM *) (vm))

#define _svmm_cast_PtrSvmtClassInfo(type) \
  ((_svmt_class_info *) (type))

#define _svmm_cast_PtrSvmtArrayInfo(type) \
  ((_svmt_array_info *) (type))

#define _svmm_cast_PtrSvmtTypeInfo_c(class) \
  ((_svmt_type_info *) (class))

#define _svmm_cast_PtrSvmtTypeInfo_a(array) \
  ((_svmt_type_info *) (array))

#define _svmm_cast_PtrPtrCONSTANTClassInfo(info) \
  ((_svmt_CONSTANT_Class_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTUtf8Info(info) \
  ((_svmt_CONSTANT_Utf8_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTFieldrefInfo(info) \
  ((_svmt_CONSTANT_Fieldref_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTMethodrefInfo(info) \
  ((_svmt_CONSTANT_Methodref_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTInterfaceMethodrefInfo(info) \
  ((_svmt_CONSTANT_InterfaceMethodref_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTNameAndTypeInfo(info) \
  ((_svmt_CONSTANT_NameAndType_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTStringInfo(info) \
  ((_svmt_CONSTANT_String_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTIntegerInfo(info) \
  ((_svmt_CONSTANT_Integer_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTFloatInfo(info) \
  ((_svmt_CONSTANT_Float_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTLongInfo(info) \
  ((_svmt_CONSTANT_Long_info **) (info))

#define _svmm_cast_PtrPtrCONSTANTDoubleInfo(info) \
  ((_svmt_CONSTANT_Double_info **) (info))

#define _svmm_cast_PtrAttributeInfo_cv(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_PtrAttributeInfo_c(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_PtrAttributeInfo_e(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_PtrAttributeInfo_ic(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_PtrAttributeInfo_s(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_PtrAttributeInfo_sf(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_PtrAttributeInfo_lnt(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_PtrAttributeInfo_lvt(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_PtrAttributeInfo_d(info) \
  ((_svmt_attribute_info *) (info))

#define _svmm_cast_Jobject_nr(nr) \
  ((jobject) (nr))

#define _svmm_cast_PtrNativeRef(obj) \
  ((_svmt_native_ref *) (obj))

#define _svmm_cast_PtrCodeAttribute(info) \
  ((_svmt_Code_attribute *) (info))

#define _svmm_cast_Jarray(obj) \
  ((jarray) (obj))

#define _svmm_cast_Jobject(array) \
  ((jobject) (array))

#define _svmm_cast_PtrArrayInstance(obj) \
  ((_svmt_array_instance *) (obj))

#define _svmm_cast_PtrObjectInstance(array) \
  ((_svmt_object_instance *) (array))

#endif /* _SABLEVM_CHECK_CASTS */

/*
----------------------------------------------------------------------
errors
----------------------------------------------------------------------
*/

#define _svmm_error_header(name)				\
void _svmdf_error_ ## name (_svmt_JNIEnv *env, const char *message);


#define _svmm_error_nomsg_header(name)		\
void _svmdf_error_ ## name (_svmt_JNIEnv *env);

/*
----------------------------------------------------------------------
method invocation
----------------------------------------------------------------------
*/

#define void_RET
#define jint_RET , jint *
#define jlong_RET , jlong *
#define jfloat_RET , jfloat *
#define jdouble_RET , jdouble *
#define jobject_RET , jobject

#define NONE_PARAM
#define jint_PARAM , jint
#define jlong_PARAM , jlong
#define jfloat_PARAM , jfloat
#define jdouble_PARAM , jdouble
#define jobject_PARAM , jobject

#define _svmm_method_header(name, rt, t1, t2, t3, t4, t5, t6) \
jint _svmdf_invoke_ ## name (_svmt_JNIEnv *, _svmt_method_info * \
                             rt ## _RET \
                             t1 ## _PARAM \
                             t2 ## _PARAM \
                             t3 ## _PARAM \
                             t4 ## _PARAM \
                             t5 ## _PARAM \
                             t6 ## _PARAM \
			     );

#define _svmm_method_header0(name, rt) \
_svmm_method_header(name, rt, NONE, NONE, NONE, NONE, NONE, NONE)

#define _svmm_method_header1(name, rt, t1) \
_svmm_method_header(name, rt, t1, NONE, NONE, NONE, NONE, NONE)

#define _svmm_method_header2(name, rt, t1, t2) \
_svmm_method_header(name, rt, t1, t2, NONE, NONE, NONE, NONE)

#define _svmm_method_header3(name, rt, t1, t2, t3) \
_svmm_method_header(name, rt, t1, t2, t3, NONE, NONE, NONE)

#define _svmm_method_header4(name, rt, t1, t2, t3, t4) \
_svmm_method_header(name, rt, t1, t2, t3, t4, NONE, NONE)

#define _svmm_method_header5(name, rt, t1, t2, t3, t4, t5) \
_svmm_method_header(name, rt, t1, t2, t3, t4, t5, NONE)

#define _svmm_method_header6(name, rt, t1, t2, t3, t4, t5, t6) \
_svmm_method_header(name, rt, t1, t2, t3, t4, t5, t6)

#ifdef _SABLEVM_GEN_COPY_GC

#define CARD_ID(ref, heap_struct) (((size_t) (ref)) >> ((heap_struct).free_bits))
#define CARD_TABLE_INDEX(ref, heap_struct) (CARD_ID(ref, heap_struct) - (heap_struct).heap_base_id)

#endif /*_SABLEVM_GEN_COPY_GC */

#endif /* NOT SVM_MACROS_H */
