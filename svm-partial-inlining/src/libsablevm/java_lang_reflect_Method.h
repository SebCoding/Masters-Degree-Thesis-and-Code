/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_reflect_Method */

#ifndef _Included_java_lang_reflect_Method
#define _Included_java_lang_reflect_Method
#ifdef __cplusplus
extern "C"
{
#endif
/* Inaccessible static: array_00024Ljava_00024lang_00024Object */
/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetDeclaringClass
 * Signature: ([B)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL
    Java_java_lang_reflect_Method_nativeGetDeclaringClass (JNIEnv *, jclass,
							   jbyteArray);

/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetName
 * Signature: ([B)Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL Java_java_lang_reflect_Method_nativeGetName
    (JNIEnv *, jclass, jbyteArray);

/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetModifiers
 * Signature: ([B)I
 */
  JNIEXPORT static jint JNICALL
    Java_java_lang_reflect_Method_nativeGetModifiers (JNIEnv *, jclass,
						      jbyteArray);

/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetExceptionTypes
 * Signature: ([B)[Ljava/lang/Class;
 */
  JNIEXPORT static jobjectArray JNICALL
    Java_java_lang_reflect_Method_nativeGetExceptionTypes (JNIEnv *, jclass,
							   jbyteArray);

/*
 * Class:     java_lang_reflect_Method
 * Method:    invokeNative
 * Signature: ([B[CCLjava/lang/Object;[Ljava/lang/Object;Ljava/lang/Object;)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_reflect_Method_invokeNative
    (JNIEnv *, jclass, jbyteArray, jcharArray, jchar, jobject, jobjectArray,
     jobject);

/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetDescriptor
 * Signature: ([B)Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_java_lang_reflect_Method_nativeGetDescriptor (JNIEnv *, jclass,
						       jbyteArray);

#ifdef __cplusplus
}
#endif
#endif
