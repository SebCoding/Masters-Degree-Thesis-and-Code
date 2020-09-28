/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "includes.h"

#ifdef _SABLEVM_CHECK_CASTS

/*
----------------------------------------------------------------------
_svmf_is_same_object
----------------------------------------------------------------------
*/

int
_svmf_is_same_object (jobject o1, jobject o2)
{
  return (((o1) != NULL && (o2) != NULL && (*(o1)) == (*(o2)))
	  || ((o1) == NULL && (o2) == NULL));
}

/*
----------------------------------------------------------------------
_svmf_toPtrJavaVM
----------------------------------------------------------------------
*/

JavaVM *
_svmf_cast_PtrJavaVM (_svmt_JavaVM *vm)
{
  return (JavaVM *) vm;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrSvmtClassInfo
----------------------------------------------------------------------
*/

_svmt_class_info *
_svmf_cast_PtrSvmtClassInfo (_svmt_type_info *type)
{
  assert ((type == NULL) ? 1 : (type->is_array == JNI_FALSE));
  return (_svmt_class_info *) type;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrSvmtArrayInfo
----------------------------------------------------------------------
*/

_svmt_array_info *
_svmf_cast_PtrSvmtArrayInfo (_svmt_type_info *type)
{
  assert ((type == NULL) ? 1 : (type->is_array == JNI_TRUE));
  return (_svmt_array_info *) type;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrSvmtType_c
----------------------------------------------------------------------
*/

_svmt_type_info *
_svmf_cast_PtrSvmtTypeInfo_c (_svmt_class_info *class)
{
  return (_svmt_type_info *) class;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrSvmtType_a
----------------------------------------------------------------------
*/

_svmt_type_info *
_svmf_cast_PtrSvmtTypeInfo_a (_svmt_array_info *array)
{
  return (_svmt_type_info *) array;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTClassInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_Class_info **
_svmf_cast_PtrPtrCONSTANTClassInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_Class_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTUtf8Info
----------------------------------------------------------------------
*/

_svmt_CONSTANT_Utf8_info **
_svmf_cast_PtrPtrCONSTANTUtf8Info (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_Utf8_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTFieldrefInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_Fieldref_info **
_svmf_cast_PtrPtrCONSTANTFieldrefInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_Fieldref_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTMethodrefInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_Methodref_info **
_svmf_cast_PtrPtrCONSTANTMethodrefInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_Methodref_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTInterfaceMethodrefInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_InterfaceMethodref_info **
_svmf_cast_PtrPtrCONSTANTInterfaceMethodrefInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_InterfaceMethodref_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTNameAndTypeInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_NameAndType_info **
_svmf_cast_PtrPtrCONSTANTNameAndTypeInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_NameAndType_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTStringInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_String_info **
_svmf_cast_PtrPtrCONSTANTStringInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_String_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTIntegerInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_Integer_info **
_svmf_cast_PtrPtrCONSTANTIntegerInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_Integer_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTFloatInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_Float_info **
_svmf_cast_PtrPtrCONSTANTFloatInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_Float_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTLongInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_Long_info **
_svmf_cast_PtrPtrCONSTANTLongInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_Long_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrPtrCONSTANTDoubleInfo
----------------------------------------------------------------------
*/

_svmt_CONSTANT_Double_info **
_svmf_cast_PtrPtrCONSTANTDoubleInfo (_svmt_cp_info **info)
{
  return (_svmt_CONSTANT_Double_info **) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_cv
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_cv (_svmt_ConstantValue_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_c
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_c (_svmt_Code_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_e
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_e (_svmt_Exceptions_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_ic
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_ic (_svmt_InnerClasses_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_s
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_s (_svmt_Synthetic_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_sf
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_sf (_svmt_SourceFile_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_lnt
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_lnt (_svmt_LineNumberTable_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_lvt
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_lvt (_svmt_LocalVariableTable_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrAttributeInfo_d
----------------------------------------------------------------------
*/

_svmt_attribute_info *
_svmf_cast_PtrAttributeInfo_d (_svmt_Deprecated_attribute *info)
{
  return (_svmt_attribute_info *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_Jobject_nr
----------------------------------------------------------------------
*/

jobject
_svmf_cast_Jobject_nr (_svmt_native_ref *nr)
{
  return (jobject) nr;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrNativeGlobal
----------------------------------------------------------------------
*/

_svmt_native_ref *
_svmf_cast_PtrNativeRef (jobject obj)
{
  return (_svmt_native_ref *) obj;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrCodeAttribute
----------------------------------------------------------------------
*/

_svmt_Code_attribute *
_svmf_cast_PtrCodeAttribute (_svmt_attribute_info *info)
{
  return (_svmt_Code_attribute *) info;
}

/*
----------------------------------------------------------------------
_svmf_cast_Jarray
----------------------------------------------------------------------
*/

jarray
_svmf_cast_Jarray (jobject obj)
{
  return (jarray) obj;
}

/*
----------------------------------------------------------------------
_svmf_cast_Jobject
----------------------------------------------------------------------
*/

jobject
_svmf_cast_Jobject (jarray array)
{
  return (jobject) array;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrObjectInstance
----------------------------------------------------------------------
*/

_svmt_object_instance *
_svmf_cast_PtrObjectInstance (_svmt_array_instance *array)
{
  return (_svmt_object_instance *) array;
}

/*
----------------------------------------------------------------------
_svmf_cast_PtrArrayInstance
----------------------------------------------------------------------
*/
_svmt_array_instance *
_svmf_cast_PtrArrayInstance (_svmt_object_instance *obj)
{
  return (_svmt_array_instance *) obj;
}

#endif /* _SABLEVM_CHECK_CASTS */
