/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* m4svm_file_name */

/*
----------------------------------------------------------------------
m4svm_parse_number
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_parse_number:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_parse_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_parse_$1(env, current, size, result) \
_svmh_parse_$1 (env, &current, &size, &result)

svm_static jint
_svmh_parse_$1 (_svmt_JNIEnv *env, _svmt_u8 **pcurrent, size_t *psize,
		$3 * presult)
{
  size_t i;
  $2 result = 0;

  if (*psize < sizeof ($2))
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  for (i = 0; i < sizeof ($2); i++)
    {
      result = (result << 8) | (*pcurrent)[i];
    }

  *psize -= sizeof ($2);
  *pcurrent += sizeof ($2);

  *presult = result;
  return JNI_OK;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_parse_constant_pool_entry
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  switch (dummy)
    {
    case dummy:
      m4svm_define_begin = ":], [:m4svm_parse_constant_pool_entry:])";

    case SVM_$1:
      {
	_svmt_$1_info **pinfo = (_svmt_$1_info **) pentry;

	if (_svmm_cl_zalloc_$1_info (env, class_loader_info, *pinfo) !=
	    JNI_OK)
	  {
	    return JNI_ERR;
	  }

	DREF (pinfo, tag) = tag;

	if (_svmf_parse_$1_info (env, class_loader_info, pcurrent,
				 psize, class, *pinfo) != JNI_OK)
	  {
	    return JNI_ERR;
	  }
      }
      break;
      m4svm_define_end = ":])";
    }
}

/*
----------------------------------------------------------------------
m4svm_parse_cp_index
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_parse_cp_index:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_parse_cp_index_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_parse_cp_index_$1(env, current, size, class, result) \
_svmh_parse_cp_index_$1 (env, &current, &size, class, &result)

svm_static jint
_svmh_parse_cp_index_$1 (_svmt_JNIEnv *env, _svmt_u8 **pcurrent,
			 size_t *psize, _svmt_class_info *class,
			 _svmt_$1_info *** presult)
{
  jint index;

  if (_svmm_parse_u16 (env, *pcurrent, *psize, index) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (index >= class->constant_pool_count)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  *presult = (_svmt_$1_info **) & class->constant_pool[index];

  return JNI_OK;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_parse_attribute_if
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  m4svm_define_begin v = ":], [:m4svm_parse_attribute_if:])";

  if (strcmp (name, "$1") == 0)
    {
      /* m4svm_comment_define([:m4svm_parse_attribute_1:],
       * [:[:m4svm_parse_attribute($:][:1):][::]m4_dnl:]) */
      m4svm_parse_attribute_1 = dummy;

    }
  m4svm_define_end = ":])";
}

/*
----------------------------------------------------------------------
m4svm_parse_attribute_elseif
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  if (dummy)
    m4svm_define_begin = ":], [:m4svm_parse_attribute_elseif:])";
  else if (strcmp (name, "$1") == 0)
    {
      /* m4svm_comment_define([:m4svm_parse_attribute_1:],
       * [:[:m4svm_parse_attribute($:][:1):][::]m4_dnl:]) */
      m4svm_parse_attribute_1 = dummy;

    }
  m4svm_define_end = ":])";
}

/*
----------------------------------------------------------------------
m4svm_parse_attribute_elseifexternal
----------------------------------------------------------------------
*/

/* usage: specify the attribute name as the first parameter and the
   package name as the second parameter.
*/

void
m4_dnl ()
{
  if (dummy)
    m4svm_define_begin = ":], [:m4svm_parse_attribute_elseifexternal:])";
  else if (strcmp (name, "$2.$1") == 0)
    {
      /* m4svm_comment_define([:m4svm_parse_attribute_1:],
       * [:[:m4svm_parse_attribute($:][:1):][::]m4_dnl:]) */
      m4svm_parse_attribute_1 = dummy;

    }
  m4svm_define_end = ":])";
}

/*
----------------------------------------------------------------------
m4svm_parse_attribute_else
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  if (dummy)
    m4svm_define_begin = ":], [:m4svm_parse_attribute_else:])";
  else
    {
      /* m4svm_comment_define([:m4svm_parse_attribute_1:],
       * [:[:m4svm_parse_attribute($:][:1):][::]m4_dnl:]) */
      m4svm_parse_attribute_1 = dummy;

    }
  m4svm_define_end = ":])";
}

/*
----------------------------------------------------------------------
m4svm_parse_attribute
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  if (dummy)
    {
      m4svm_define_begin v = ":], [:m4svm_parse_attribute:])";

      _svmt_$1_attribute **p$1attribute = (_svmt_$1_attribute **) pattribute;

      if (_svmm_cl_zalloc_$1_attribute
	  (env, class_loader_info, *p$1attribute) != JNI_OK)
	{
	  return JNI_ERR;
	}

      DREF (p$1attribute, name) = attribute_name;

      if (_svmf_parse_$1_attribute (env, class_loader_info, pcurrent,
				    psize, length, class,
				    *p$1attribute) != JNI_OK)
	{
	  return JNI_ERR;
	}
      m4svm_define_end = ":])";
    }
}

/*
----------------------------------------------------------------------
_svmm_parse_(number)
----------------------------------------------------------------------
*/

/* m4svm_parse_number(s64, _svmt_s64, jlong) */
/* m4svm_parse_number(u32, _svmt_u32, jlong) */
/* m4svm_parse_number(s32, _svmt_s32, jint) */
/* m4svm_parse_number(u16, _svmt_u16, jint) */

/*
----------------------------------------------------------------------
_svmm_parse_cp_index_(*)
----------------------------------------------------------------------
*/

/* m4svm_parse_cp_index(cp) */
/* m4svm_parse_cp_index(CONSTANT_Utf8) */
/* m4svm_parse_cp_index(CONSTANT_Class) */
/* m4svm_parse_cp_index(CONSTANT_NameAndType) */

/* m4svm_on(0)m4_dnl */

/*
----------------------------------------------------------------------
_svmh_parse_d64
----------------------------------------------------------------------
*/

#define _svmm_parse_d64(env, current, size, result) \
_svmh_parse_d64 (env, &current, &size, &result)

svm_static jint
_svmh_parse_d64 (_svmt_JNIEnv *env, _svmt_u8 **pcurrent, size_t *psize,
		 jdouble *presult)
{
  size_t i;
  _svmt_u64 result = 0;

  if (*psize < sizeof (_svmt_u64))
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  for (i = 0; i < sizeof (_svmt_u64); i++)
    {
      result = (result << 8) | (*pcurrent)[i];
    }

#if defined(__arm__)

  /* On ARM 'double' values have their two 32bit parts reversed. */

  {
    _svmt_u64 result1, result2;

    result1 = result & 0xffffffff;
    result2 = result >> 32;
    result = (result1 << 32) | result2;
  }

#endif

  *psize -= sizeof (_svmt_u64);
  *pcurrent += sizeof (_svmt_u64);

  *presult = *((jdouble *) &result);
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_parse_f32
----------------------------------------------------------------------
*/

#define _svmm_parse_f32(env, current, size, result) \
_svmh_parse_f32 (env, &current, &size, &result)

svm_static jint
_svmh_parse_f32 (_svmt_JNIEnv *env, _svmt_u8 **pcurrent, size_t *psize,
		 jfloat *presult)
{
  size_t i;
  _svmt_u32 result = 0;

  if (*psize < sizeof (_svmt_u32))
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  for (i = 0; i < sizeof (_svmt_u32); i++)
    {
      result = (result << 8) | (*pcurrent)[i];
    }

  *psize -= sizeof (_svmt_u32);
  *pcurrent += sizeof (_svmt_u32);

  *presult = *((jfloat *) &result);
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_Class_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_Class_info (_svmt_JNIEnv *env,
				 _svmt_class_loader_info
				 *class_loader_info SVM_UNUSED,
				 _svmt_u8 **pcurrent, size_t *psize,
				 _svmt_class_info *class,
				 _svmt_CONSTANT_Class_info *info)
{
  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, info->name) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_Fieldref_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_Fieldref_info (_svmt_JNIEnv *env,
				    _svmt_class_loader_info
				    *class_loader_info SVM_UNUSED,
				    _svmt_u8 **pcurrent, size_t *psize,
				    _svmt_class_info *class,
				    _svmt_CONSTANT_Fieldref_info *info)
{
  if (_svmm_parse_cp_index_CONSTANT_Class
      (env, *pcurrent, *psize, class, info->class) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_cp_index_CONSTANT_NameAndType
      (env, *pcurrent, *psize, class, info->name_and_type) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_Methodref_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_Methodref_info (_svmt_JNIEnv *env,
				     _svmt_class_loader_info
				     *class_loader_info SVM_UNUSED,
				     _svmt_u8 **pcurrent, size_t *psize,
				     _svmt_class_info *class,
				     _svmt_CONSTANT_Methodref_info *info)
{
  if (_svmm_parse_cp_index_CONSTANT_Class
      (env, *pcurrent, *psize, class, info->class) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_cp_index_CONSTANT_NameAndType
      (env, *pcurrent, *psize, class, info->name_and_type) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_InterfaceMethodref_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_InterfaceMethodref_info (_svmt_JNIEnv *env,
					      _svmt_class_loader_info
					      *class_loader_info SVM_UNUSED,
					      _svmt_u8 **pcurrent,
					      size_t *psize,
					      _svmt_class_info *class,
					      _svmt_CONSTANT_InterfaceMethodref_info
					      *info)
{
  if (_svmm_parse_cp_index_CONSTANT_Class
      (env, *pcurrent, *psize, class, info->class) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_cp_index_CONSTANT_NameAndType
      (env, *pcurrent, *psize, class, info->name_and_type) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_String_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_String_info (_svmt_JNIEnv *env,
				  _svmt_class_loader_info
				  *class_loader_info SVM_UNUSED,
				  _svmt_u8 **pcurrent, size_t *psize,
				  _svmt_class_info *class,
				  _svmt_CONSTANT_String_info *info)
{
  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, info->string) != JNI_OK)
    {
      return JNI_ERR;
    }

  info->class_info = class;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_Integer_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_Integer_info (_svmt_JNIEnv *env,
				   _svmt_class_loader_info
				   *class_loader_info SVM_UNUSED,
				   _svmt_u8 **pcurrent, size_t *psize,
				   _svmt_class_info *class SVM_UNUSED,
				   _svmt_CONSTANT_Integer_info *info)
{
  if (_svmm_parse_s32 (env, *pcurrent, *psize, info->value) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_Float_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_Float_info (_svmt_JNIEnv *env,
				 _svmt_class_loader_info
				 *class_loader_info SVM_UNUSED,
				 _svmt_u8 **pcurrent, size_t *psize,
				 _svmt_class_info *class SVM_UNUSED,
				 _svmt_CONSTANT_Float_info *info)
{
  if (_svmm_parse_f32 (env, *pcurrent, *psize, info->value) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_Long_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_Long_info (_svmt_JNIEnv *env,
				_svmt_class_loader_info
				*class_loader_info SVM_UNUSED,
				_svmt_u8 **pcurrent, size_t *psize,
				_svmt_class_info *class SVM_UNUSED,
				_svmt_CONSTANT_Long_info *info)
{
  if (_svmm_parse_s64 (env, *pcurrent, *psize, info->value) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_Double_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_Double_info (_svmt_JNIEnv *env,
				  _svmt_class_loader_info
				  *class_loader_info SVM_UNUSED,
				  _svmt_u8 **pcurrent, size_t *psize,
				  _svmt_class_info *class SVM_UNUSED,
				  _svmt_CONSTANT_Double_info *info)
{
  if (_svmm_parse_d64 (env, *pcurrent, *psize, info->value) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_NameAndType_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_NameAndType_info (_svmt_JNIEnv *env,
				       _svmt_class_loader_info
				       *class_loader_info SVM_UNUSED,
				       _svmt_u8 **pcurrent, size_t *psize,
				       _svmt_class_info *class,
				       _svmt_CONSTANT_NameAndType_info *info)
{
  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, info->name) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, info->descriptor) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_CONSTANT_Utf8_info
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_CONSTANT_Utf8_info (_svmt_JNIEnv *env,
				_svmt_class_loader_info *class_loader_info,
				_svmt_u8 **pcurrent, size_t *psize,
				_svmt_class_info *class SVM_UNUSED,
				_svmt_CONSTANT_Utf8_info *info)
{
  if (_svmm_parse_u16 (env, *pcurrent, *psize, info->length) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (*psize < (size_t) info->length)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  if (_svmm_cl_malloc_chars
      (env, class_loader_info, info->length + 1, info->value) != JNI_OK)
    {
      return JNI_ERR;
    }

  {
    jint length = info->length;
    jint i;

    *psize -= length;

    for (i = 0; i < length; i++)
      {
	jbyte b = *((*pcurrent)++);

	if ((b == 0) || ((b >= (jbyte) 0xf0) && (b <= (jbyte) 0xff)))
	  {
	    _svmf_error_ClassFormatError (env);
	    return JNI_ERR;
	  }

	info->value[i] = b;
      }

    info->value[length] = 0;
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_parse_constant_pool_entry
----------------------------------------------------------------------
*/

#define _svmm_parse_constant_pool_entry(env,cli,current,size,class,entry) \
_svmh_parse_constant_pool_entry (env, cli, &current, &size, class, &entry)

svm_static jint
_svmh_parse_constant_pool_entry (_svmt_JNIEnv *env,
				 _svmt_class_loader_info *class_loader_info
				 SVM_UNUSED, _svmt_u8 **pcurrent,
				 size_t *psize, _svmt_class_info *class,
				 _svmt_cp_info **pentry)
{
  jint tag;

  if ((*psize)-- < 1)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  tag = *((*pcurrent)++);

  switch (tag)
    {
      /* constant pool entries *[::]/
         m4svm_off()

         m4svm_parse_constant_pool_entry(CONSTANT_Class)
         m4svm_parse_constant_pool_entry(CONSTANT_Fieldref)
         m4svm_parse_constant_pool_entry(CONSTANT_Methodref)
         m4svm_parse_constant_pool_entry(CONSTANT_InterfaceMethodref)
         m4svm_parse_constant_pool_entry(CONSTANT_String)
         m4svm_parse_constant_pool_entry(CONSTANT_Integer)
         m4svm_parse_constant_pool_entry(CONSTANT_Float)
         m4svm_parse_constant_pool_entry(CONSTANT_Long)
         m4svm_parse_constant_pool_entry(CONSTANT_Double)
         m4svm_parse_constant_pool_entry(CONSTANT_NameAndType)
         m4svm_parse_constant_pool_entry(CONSTANT_Utf8)

         m4svm_on(0)m4_dnl */

    default:
      {
	_svmf_error_ClassFormatError (env);
	return JNI_ERR;
      }
      break;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_ConstantValue_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_ConstantValue_attribute (_svmt_JNIEnv *env,
				     _svmt_class_loader_info
				     *class_loader_info SVM_UNUSED,
				     _svmt_u8 **pcurrent,
				     size_t *psize SVM_UNUSED,
				     jlong length SVM_UNUSED,
				     _svmt_class_info *class,
				     _svmt_ConstantValue_attribute *attribute)
{
  if (_svmm_parse_cp_index_cp
      (env, *pcurrent, *psize, class, attribute->constantvalue) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_Synthetic_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_Synthetic_attribute (_svmt_JNIEnv *env SVM_UNUSED,
				 _svmt_class_loader_info
				 *class_loader_info SVM_UNUSED,
				 _svmt_u8 **pcurrent SVM_UNUSED,
				 size_t *psize SVM_UNUSED,
				 jlong length SVM_UNUSED,
				 _svmt_class_info *class SVM_UNUSED,
				 _svmt_Synthetic_attribute *attribute
				 SVM_UNUSED)
{
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_Deprecated_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_Deprecated_attribute (_svmt_JNIEnv *env SVM_UNUSED,
				  _svmt_class_loader_info
				  *class_loader_info SVM_UNUSED,
				  _svmt_u8 **pcurrent SVM_UNUSED,
				  size_t *psize SVM_UNUSED,
				  jlong length SVM_UNUSED,
				  _svmt_class_info *class SVM_UNUSED,
				  _svmt_Deprecated_attribute *attribute
				  SVM_UNUSED)
{
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_unknown_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_unknown_attribute (_svmt_JNIEnv *env,
			       _svmt_class_loader_info *class_loader_info,
			       _svmt_u8 **pcurrent,
			       size_t *psize,
			       jlong length,
			       _svmt_class_info *class SVM_UNUSED,
			       _svmt_unknown_attribute *attribute)
{
  if (*psize < (size_t) length)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  if (length > 0)
    {
      if (_svmm_cl_malloc_u8
	  (env, class_loader_info, length, attribute->info) != JNI_OK)
	{
	  return JNI_ERR;
	}

      memcpy (attribute->info, pcurrent, length);
      *psize -= length;
      *pcurrent += length;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_LineNumberTable_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_LineNumberTable_attribute (_svmt_JNIEnv *env,
				       _svmt_class_loader_info
				       *class_loader_info,
				       _svmt_u8 **pcurrent, size_t *psize,
				       jlong length SVM_UNUSED,
				       _svmt_class_info
				       *class SVM_UNUSED,
				       _svmt_LineNumberTable_attribute
				       *attribute)
{
  if (_svmm_parse_u16
      (env, *pcurrent, *psize, attribute->line_number_table_length) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (attribute->line_number_table_length > 0)
    {
      jint line_number_table_length = attribute->line_number_table_length;
      jint i;

      if (_svmm_cl_zmalloc_line_number_table
	  (env, class_loader_info, line_number_table_length,
	   attribute->line_number_table) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < line_number_table_length; i++)
	{
	  _svmt_line_number_table *line_number_entry =
	    &attribute->line_number_table[i];

	  if (_svmm_parse_u16
	      (env, *pcurrent, *psize, line_number_entry->start_pc) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_u16
	      (env, *pcurrent, *psize,
	       line_number_entry->line_number) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_LocalVariableTable_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_LocalVariableTable_attribute (_svmt_JNIEnv *env,
					  _svmt_class_loader_info
					  *class_loader_info,
					  _svmt_u8 **pcurrent,
					  size_t *psize,
					  jlong length SVM_UNUSED,
					  _svmt_class_info *class,
					  _svmt_LocalVariableTable_attribute
					  *attribute)
{
  if (_svmm_parse_u16
      (env, *pcurrent, *psize,
       attribute->local_variable_table_length) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (attribute->local_variable_table_length > 0)
    {
      jint local_variable_table_length =
	attribute->local_variable_table_length;
      jint i;

      if (_svmm_cl_zmalloc_local_variable_table
	  (env, class_loader_info, local_variable_table_length,
	   attribute->local_variable_table) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < local_variable_table_length; i++)
	{
	  _svmt_local_variable_table *local_variable_entry =
	    &attribute->local_variable_table[i];

	  if (_svmm_parse_u16
	      (env, *pcurrent, *psize,
	       local_variable_entry->start_pc) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_u16
	      (env, *pcurrent, *psize,
	       local_variable_entry->length) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Utf8
	      (env, *pcurrent, *psize, class,
	       local_variable_entry->name) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Utf8
	      (env, *pcurrent, *psize, class,
	       local_variable_entry->descriptor) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_u16
	      (env, *pcurrent, *psize, local_variable_entry->index) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_Exceptions_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_Exceptions_attribute (_svmt_JNIEnv *env,
				  _svmt_class_loader_info
				  *class_loader_info,
				  _svmt_u8 **pcurrent, size_t *psize,
				  jlong length SVM_UNUSED,
				  _svmt_class_info *class,
				  _svmt_Exceptions_attribute *attribute)
{
  if (_svmm_parse_u16
      (env, *pcurrent, *psize, attribute->number_of_exceptions) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (attribute->number_of_exceptions > 0)
    {
      jint number_of_exceptions = attribute->number_of_exceptions;
      jint i;

      if (_svmm_cl_malloc_classes
	  (env, class_loader_info, number_of_exceptions,
	   attribute->exception_table) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < number_of_exceptions; i++)
	{
	  if (_svmm_parse_cp_index_CONSTANT_Class
	      (env, *pcurrent, *psize, class,
	       attribute->exception_table[i]) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmf_parse_InnerClasses_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_InnerClasses_attribute (_svmt_JNIEnv *env,
				    _svmt_class_loader_info
				    *class_loader_info,
				    _svmt_u8 **pcurrent, size_t *psize,
				    jlong length SVM_UNUSED,
				    _svmt_class_info *class,
				    _svmt_InnerClasses_attribute *attribute)
{
  if (_svmm_parse_u16
      (env, *pcurrent, *psize, attribute->number_of_classes) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (attribute->number_of_classes > 0)
    {
      jint number_of_classes = attribute->number_of_classes;
      jint i;

      if (_svmm_cl_malloc_inner_classes
	  (env, class_loader_info, number_of_classes,
	   attribute->classes) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < number_of_classes; i++)
	{
	  if (_svmm_parse_cp_index_CONSTANT_Class
	      (env, *pcurrent, *psize, class,
	       attribute->classes[i].inner_class_info) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Class
	      (env, *pcurrent, *psize, class,
	       attribute->classes[i].outer_class_info) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Utf8
	      (env, *pcurrent, *psize, class,
	       attribute->classes[i].inner_name) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_u16
	      (env, *pcurrent, *psize,
	       attribute->classes[i].inner_class_access_flags) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	}
    }

  return JNI_OK;
}





/*
----------------------------------------------------------------------
_svmf_parse_SourceFile_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_SourceFile_attribute (_svmt_JNIEnv *env,
				  _svmt_class_loader_info
				  *class_loader_info SVM_UNUSED,
				  _svmt_u8 **pcurrent, size_t *psize,
				  jlong length SVM_UNUSED,
				  _svmt_class_info *class,
				  _svmt_SourceFile_attribute *attribute)
{
  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, attribute->sourcefile) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_parse_code_attribute
----------------------------------------------------------------------
*/

#define _svmm_parse_code_attribute(env,cli,current,size,class,attribute) \
_svmh_parse_code_attribute (env, cli, &current, &size, class, &attribute)

svm_static jint
_svmh_parse_code_attribute (_svmt_JNIEnv *env,
			    _svmt_class_loader_info *class_loader_info,
			    _svmt_u8 **pcurrent, size_t *psize,
			    _svmt_class_info *class,
			    _svmt_attribute_info **pattribute)
{
  _svmt_CONSTANT_Utf8_info **attribute_name;
  jlong length;
  size_t old_size;
  char *name;

  /* attribute name */

  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, attribute_name) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (CANNOT_DREF (attribute_name) ||
      DREF (attribute_name, tag) != SVM_CONSTANT_Utf8)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  name = DREF (attribute_name, value);

  if (_svmm_parse_u32 (env, *pcurrent, *psize, length) != JNI_OK)
    {
      return JNI_ERR;
    }

  old_size = *psize;

  /* parse attributes *[::]/
     m4svm_off()

     m4svm_parse_attribute_if(LineNumberTable)
     m4svm_parse_attribute_elseif(LocalVariableTable)
     m4svm_parse_attribute_else(unknown)

     m4svm_on(0)m4_dnl */

  if (old_size - length != *psize)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_parse_Code_attribute
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_Code_attribute (_svmt_JNIEnv *env,
			    _svmt_class_loader_info *class_loader_info,
			    _svmt_u8 **pcurrent,
			    size_t *psize,
			    jlong length SVM_UNUSED,
			    _svmt_class_info *class,
			    _svmt_Code_attribute *attribute)
{
  if (_svmm_parse_u16 (env, *pcurrent, *psize, attribute->max_stack) !=
      JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_u16 (env, *pcurrent, *psize, attribute->max_locals) !=
      JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_u32 (env, *pcurrent, *psize, attribute->code_length) !=
      JNI_OK)
    {
      return JNI_ERR;
    }

  if (attribute->code_length > 0)
    {
      if (*psize < (size_t) attribute->code_length)
	{
	  _svmf_error_ClassFormatError (env);
	  return JNI_ERR;
	}

      if (_svmm_cl_malloc_u8
	  (env, class_loader_info, attribute->code_length,
	   attribute->code) != JNI_OK)
	{
	  return JNI_ERR;
	}

      memcpy (attribute->code, *pcurrent, attribute->code_length);
      *psize -= attribute->code_length;
      *pcurrent += attribute->code_length;
    }

  if (_svmm_parse_u16
      (env, *pcurrent, *psize, attribute->exception_table_length) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (attribute->exception_table_length > 0)
    {
      jint exception_table_length = attribute->exception_table_length;
      jint i;

      if (_svmm_cl_zmalloc_exception_table
	  (env, class_loader_info, exception_table_length,
	   attribute->exception_table) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < exception_table_length; i++)
	{
	  _svmt_exception_table *exception = &attribute->exception_table[i];

	  if (_svmm_parse_u16 (env, *pcurrent, *psize, exception->start_pc) !=
	      JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_u16 (env, *pcurrent, *psize, exception->end_pc) !=
	      JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_u16 (env, *pcurrent, *psize, exception->handler_pc)
	      != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Class
	      (env, *pcurrent, *psize, class,
	       exception->catch_type) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  /* attributes_count */

  if (_svmm_parse_u16 (env, *pcurrent, *psize, attribute->attributes_count) !=
      JNI_OK)
    {
      return JNI_ERR;
    }

  /* attributes */
  if (attribute->attributes_count > 0)
    {
      jint attributes_count = attribute->attributes_count;
      jint nested_attribute;
      _svmt_attribute_info **attributes;

      if (_svmm_cl_malloc_attributes
	  (env, class_loader_info, attributes_count,
	   attribute->attributes) != JNI_OK)
	{
	  return JNI_ERR;
	}

      attributes = attribute->attributes;

      for (nested_attribute = 0; nested_attribute < attributes_count;
	   nested_attribute++)
	{
	  if (_svmm_parse_code_attribute
	      (env, class_loader_info, *pcurrent, *psize, class,
	       attributes[nested_attribute]) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_parse_field_attribute
----------------------------------------------------------------------
*/

#define _svmm_parse_field_attribute(env,cli,current,size,class,attribute) \
_svmh_parse_field_attribute (env, cli, &current, &size, class, &attribute)

svm_static jint
_svmh_parse_field_attribute (_svmt_JNIEnv *env,
			     _svmt_class_loader_info *class_loader_info,
			     _svmt_u8 **pcurrent, size_t *psize,
			     _svmt_class_info *class,
			     _svmt_attribute_info **pattribute)
{
  _svmt_CONSTANT_Utf8_info **attribute_name;
  jlong length;
  size_t old_size;
  char *name;

  /* attribute name */

  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, attribute_name) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (CANNOT_DREF (attribute_name) ||
      DREF (attribute_name, tag) != SVM_CONSTANT_Utf8)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  name = DREF (attribute_name, value);

  if (_svmm_parse_u32 (env, *pcurrent, *psize, length) != JNI_OK)
    {
      return JNI_ERR;
    }

  old_size = *psize;

  /* parse attributes *[::]/
     m4svm_off()

     m4svm_parse_attribute_if(ConstantValue)
     m4svm_parse_attribute_elseif(Synthetic)
     m4svm_parse_attribute_elseif(Deprecated)
     m4svm_parse_attribute_else(unknown)

     m4svm_on(0)m4_dnl */

  if (old_size - length != *psize)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_parse_method_attribute
----------------------------------------------------------------------
*/

#define _svmm_parse_method_attribute(env,cli,current,size,class,attribute) \
_svmh_parse_method_attribute (env, cli, &current, &size, class, &attribute)

svm_static jint
_svmh_parse_method_attribute (_svmt_JNIEnv *env,
			      _svmt_class_loader_info *class_loader_info,
			      _svmt_u8 **pcurrent, size_t *psize,
			      _svmt_class_info *class,
			      _svmt_attribute_info **pattribute)
{
  _svmt_CONSTANT_Utf8_info **attribute_name;
  jlong length;
  size_t old_size;
  char *name;

  /* attribute name */

  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, attribute_name) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (CANNOT_DREF (attribute_name) ||
      DREF (attribute_name, tag) != SVM_CONSTANT_Utf8)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  name = DREF (attribute_name, value);

  if (_svmm_parse_u32 (env, *pcurrent, *psize, length) != JNI_OK)
    {
      return JNI_ERR;
    }

  old_size = *psize;

  /* parse attributes *[::]/
     m4svm_off()

     m4svm_parse_attribute_if(Code)
     m4svm_parse_attribute_elseif(Exceptions)
     m4svm_parse_attribute_elseif(Synthetic)
     m4svm_parse_attribute_elseif(Deprecated)
     m4svm_parse_attribute_else(unknown)

     m4svm_on(0)m4_dnl */

  if (old_size - length != *psize)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_parse_class_attribute
----------------------------------------------------------------------
*/

#define _svmm_parse_class_attribute(env,cli,current,size,class,attribute) \
_svmh_parse_class_attribute (env, cli, &current, &size, class, &attribute)

svm_static jint
_svmh_parse_class_attribute (_svmt_JNIEnv *env,
			     _svmt_class_loader_info *class_loader_info,
			     _svmt_u8 **pcurrent, size_t *psize,
			     _svmt_class_info *class,
			     _svmt_attribute_info **pattribute)
{
  _svmt_CONSTANT_Utf8_info **attribute_name;
  jlong length;
  size_t old_size;
  char *name;

  /* attribute name */

  if (_svmm_parse_cp_index_CONSTANT_Utf8
      (env, *pcurrent, *psize, class, attribute_name) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (CANNOT_DREF (attribute_name) ||
      DREF (attribute_name, tag) != SVM_CONSTANT_Utf8)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  name = DREF (attribute_name, value);

  if (_svmm_parse_u32 (env, *pcurrent, *psize, length) != JNI_OK)
    {
      return JNI_ERR;
    }

  old_size = *psize;

  /* parse attributes *[::]/
     m4svm_off()

     m4svm_parse_attribute_if(SourceFile)
     m4svm_parse_attribute_elseif(Deprecated)
     m4svm_parse_attribute_elseif(InnerClasses)
     m4svm_parse_attribute_else(unknown)

     m4svm_on(0)m4_dnl */

  if (old_size - length != *psize)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_parse_class_file
----------------------------------------------------------------------
*/

svm_static jint
_svmh_parse_class_file (_svmt_JNIEnv *env,
			_svmt_class_loader_info *class_loader_info,
			size_t class_file_length,
			_svmt_u8 *class_file_bytes, _svmt_class_info **pclass)
{
  _svmt_class_info *class;

  size_t size = class_file_length;
  _svmt_u8 *current = class_file_bytes;

  if (_svmm_cl_zalloc_class_info (env, class_loader_info, class) != JNI_OK)
    {
      return JNI_ERR;
    }

  class->class_loader_info = class_loader_info;
  class->is_array = JNI_FALSE;

  /* magic, version, constant pool count */
  {
    jlong magic;

    if (_svmm_parse_u32 (env, current, size, magic) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (magic != 0xCAFEBABE)
      {
	_svmf_error_ClassFormatError (env);
	return JNI_ERR;
      }
  }

  if (_svmm_parse_u16 (env, current, size, class->minor_version) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_u16 (env, current, size, class->major_version) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_u16 (env, current, size, class->constant_pool_count) !=
      JNI_OK)
    {
      return JNI_ERR;
    }

  if (class->constant_pool_count < 1)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  /* constant_pool */

  if (_svmm_cl_malloc_constant_pool
      (env, class_loader_info, class->constant_pool_count,
       class->constant_pool) != JNI_OK)
    {
      return JNI_ERR;
    }

  {
    jint entry;
    _svmt_cp_info **constant_pool = class->constant_pool;

    constant_pool[0] = NULL;

    for (entry = 1; entry < class->constant_pool_count; entry++)
      {
	if (_svmm_parse_constant_pool_entry
	    (env, class_loader_info, current, size, class,
	     constant_pool[entry]) != JNI_OK)
	  {
	    return JNI_ERR;
	  }

	if (constant_pool[entry]->tag == SVM_CONSTANT_Long ||
	    constant_pool[entry]->tag == SVM_CONSTANT_Double)
	  {
	    if (++entry >= class->constant_pool_count)
	      {
		_svmf_error_ClassFormatError (env);
		return JNI_ERR;
	      }
	  }
      }
  }

  /* access flags, this_class, super_class, interfaces_count */

  if (_svmm_parse_u16 (env, current, size, class->access_flags) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_cp_index_CONSTANT_Class
      (env, current, size, class, class->this_class) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_cp_index_CONSTANT_Class
      (env, current, size, class, class->super_class) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_parse_u16 (env, current, size, class->interfaces_count) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* interfaces */
  if (class->interfaces_count > 0)
    {
      jint i;
      jint interfaces_count = class->interfaces_count;
      _svmt_CONSTANT_Class_info ***interfaces;

      if (_svmm_cl_malloc_classes
	  (env, class_loader_info, interfaces_count,
	   class->interfaces) != JNI_OK)
	{
	  return JNI_ERR;
	}

      interfaces = class->interfaces;

      for (i = 0; i < interfaces_count; i++)
	{
	  if (_svmm_parse_cp_index_CONSTANT_Class
	      (env, current, size, class, interfaces[i]) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  /* fields_count */

  if (_svmm_parse_u16 (env, current, size, class->fields_count) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* fields */
  if (class->fields_count > 0)
    {
      jint fields_count = class->fields_count;
      jint i;

      if (_svmm_cl_zmalloc_fields
	  (env, class_loader_info, fields_count, class->fields) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < fields_count; i++)
	{
	  _svmt_field_info *field = &class->fields[i];

	  /* access_flags, name_index, descriptor_index, attributes_count */

	  if (_svmm_parse_u16 (env, current, size, field->access_flags) !=
	      JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Utf8
	      (env, current, size, class, field->name) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Utf8
	      (env, current, size, class, field->descriptor) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_u16 (env, current, size, field->attributes_count) !=
	      JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  /* attributes */
	  if (field->attributes_count > 0)
	    {
	      jint attributes_count = field->attributes_count;
	      jint attribute;
	      _svmt_attribute_info **attributes;

	      if (_svmm_cl_malloc_attributes
		  (env, class_loader_info, attributes_count,
		   field->attributes) != JNI_OK)
		{
		  return JNI_ERR;
		}

	      attributes = field->attributes;

	      for (attribute = 0; attribute < attributes_count; attribute++)
		{
		  if (_svmm_parse_field_attribute
		      (env, class_loader_info, current, size, class,
		       attributes[attribute]) != JNI_OK)
		    {
		      return JNI_ERR;
		    }
		}
	    }
	}
    }

  /* methods_count */

  if (_svmm_parse_u16 (env, current, size, class->methods_count) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* methods */
  if (class->methods_count > 0)
    {
      jint methods_count = class->methods_count;
      jint i;

      if (_svmm_cl_zmalloc_methods
	  (env, class_loader_info, methods_count, class->methods) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < methods_count; i++)
	{
	  _svmt_method_info *method = &class->methods[i];

	  /* access_flags, name_index, descriptor_index, attributes_count */

	  if (_svmm_parse_u16 (env, current, size, method->access_flags) !=
	      JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Utf8
	      (env, current, size, class, method->name) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_cp_index_CONSTANT_Utf8
	      (env, current, size, class, method->descriptor) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmm_parse_u16 (env, current, size, method->attributes_count)
	      != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  /* attributes */
	  if (method->attributes_count > 0)
	    {
	      jint attributes_count = method->attributes_count;
	      jint attribute;
	      _svmt_attribute_info **attributes;

	      if (_svmm_cl_malloc_attributes
		  (env, class_loader_info, attributes_count,
		   method->attributes) != JNI_OK)
		{
		  return JNI_ERR;
		}

	      attributes = method->attributes;

	      for (attribute = 0; attribute < attributes_count; attribute++)
		{
		  if (_svmm_parse_method_attribute
		      (env, class_loader_info, current, size, class,
		       attributes[attribute]) != JNI_OK)
		    {
		      return JNI_ERR;
		    }
		}
	    }
	}
    }

  /* attributes_count */

  if (_svmm_parse_u16 (env, current, size, class->attributes_count) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* attributes */
  if (class->attributes_count > 0)
    {
      jint attributes_count = class->attributes_count;
      jint attribute;
      _svmt_attribute_info **attributes;

      if (_svmm_cl_malloc_attributes
	  (env, class_loader_info, attributes_count,
	   class->attributes) != JNI_OK)
	{
	  return JNI_ERR;
	}

      attributes = class->attributes;

      for (attribute = 0; attribute < attributes_count; attribute++)
	{
	  if (_svmm_parse_class_attribute
	      (env, class_loader_info, current, size, class,
	       attributes[attribute]) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  if (size != 0)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  if (CANNOT_DREF (class->this_class) ||
      DREF (class->this_class, tag) != SVM_CONSTANT_Class ||
      CANNOT_DREF (DREF (class->this_class, name)) ||
      DREF (DREF (class->this_class, name), tag) != SVM_CONSTANT_Utf8)
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  class->name = DREF (DREF (class->this_class, name), value);

  if (_svmm_cl_malloc_chars
      (env, class_loader_info,
       DREF (DREF (class->this_class, name), length) + 4,
       class->array_type_name) != JNI_OK)
    {
      return JNI_ERR;
    }

  strcpy (class->array_type_name, "[L");
  strcat (class->array_type_name, class->name);
  strcat (class->array_type_name, ";");

  *pclass = class;
  return JNI_OK;
}
