/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_VMClassLoader */

#ifndef _Included_java_lang_VMClassLoader
#define _Included_java_lang_VMClassLoader
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeDefineClass
 * Signature: ([BLjava/lang/String;[BIILjava/security/ProtectionDomain;)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL
    Java_java_lang_VMClassLoader_nativeDefineClass (JNIEnv *, jclass,
						    jbyteArray, jstring,
						    jbyteArray, jint, jint,
						    jobject);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeDefineArray
 * Signature: ([BLjava/lang/String;Ljava/lang/Class;)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL
    Java_java_lang_VMClassLoader_nativeDefineArray (JNIEnv *, jclass,
						    jbyteArray, jstring,
						    jclass);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    newClassLoaderVmData
 * Signature: (Ljava/lang/ClassLoader;)[B
 */
  JNIEXPORT static jbyteArray JNICALL
    Java_java_lang_VMClassLoader_newClassLoaderVmData (JNIEnv *, jclass,
						       jobject);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    getArray
 * Signature: (Ljava/lang/Class;)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL Java_java_lang_VMClassLoader_getArray
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    getPrimitiveArray
 * Signature: (C)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL
    Java_java_lang_VMClassLoader_getPrimitiveArray (JNIEnv *, jclass, jchar);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    linkClass
 * Signature: (Ljava/lang/Class;)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMClassLoader_linkClass
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    initializeClass
 * Signature: (Ljava/lang/Class;)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMClassLoader_initializeClass
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeLoadClass
 * Signature: (Ljava/lang/String;Z)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL Java_java_lang_VMClassLoader_nativeLoadClass
    (JNIEnv *, jclass, jstring, jboolean);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeCreateArray
 * Signature: (Ljava/lang/String;Z)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL
    Java_java_lang_VMClassLoader_nativeCreateArray (JNIEnv *, jclass, jstring,
						    jboolean);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeGetResource
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_java_lang_VMClassLoader_nativeGetResource (JNIEnv *, jclass,
						    jstring);

/*
 * Class:     java_lang_VMClassLoader
 * Method:    getPrimitiveClass
 * Signature: (C)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL
    Java_java_lang_VMClassLoader_getPrimitiveClass (JNIEnv *, jclass, jchar);

#ifdef __cplusplus
}
#endif
#endif
