/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_VMClass */

#ifndef _Included_java_lang_VMClass
#define _Included_java_lang_VMClass
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * Class:     java_lang_VMClass
 * Method:    isInitialized
 * Signature: (Ljava/lang/Class;)Z
 */
  JNIEXPORT static jboolean JNICALL Java_java_lang_VMClass_isInitialized
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    setInitialized
 * Signature: (Ljava/lang/Class;)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMClass_setInitialized
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    step7
 * Signature: (Ljava/lang/Class;)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMClass_step7
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    step8
 * Signature: (Ljava/lang/Class;)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMClass_step8
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    isInstance
 * Signature: (Ljava/lang/Class;Ljava/lang/Object;)Z
 */
  JNIEXPORT static jboolean JNICALL Java_java_lang_VMClass_isInstance
    (JNIEnv *, jclass, jclass, jobject);

/*
 * Class:     java_lang_VMClass
 * Method:    isAssignableFrom
 * Signature: (Ljava/lang/Class;Ljava/lang/Class;)Z
 */
  JNIEXPORT static jboolean JNICALL Java_java_lang_VMClass_isAssignableFrom
    (JNIEnv *, jclass, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    isInterface
 * Signature: (Ljava/lang/Class;)Z
 */
  JNIEXPORT static jboolean JNICALL Java_java_lang_VMClass_isInterface
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    getName
 * Signature: (Ljava/lang/Class;)Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL Java_java_lang_VMClass_getName
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    getSuperclass
 * Signature: (Ljava/lang/Class;)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL Java_java_lang_VMClass_getSuperclass
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    getInterfaces
 * Signature: (Ljava/lang/Class;)[Ljava/lang/Class;
 */
  JNIEXPORT static jobjectArray JNICALL Java_java_lang_VMClass_getInterfaces
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    getModifiers
 * Signature: (Ljava/lang/Class;)I
 */
  JNIEXPORT static jint JNICALL Java_java_lang_VMClass_getModifiers
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaringClass
 * Signature: (Ljava/lang/Class;)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL Java_java_lang_VMClass_getDeclaringClass
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaredClasses
 * Signature: (Ljava/lang/Class;Z)[Ljava/lang/Class;
 */
  JNIEXPORT static jobjectArray JNICALL
    Java_java_lang_VMClass_getDeclaredClasses (JNIEnv *, jclass, jclass,
					       jboolean);

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaredFields
 * Signature: (Ljava/lang/Class;Z)[Ljava/lang/reflect/Field;
 */
  JNIEXPORT static jobjectArray JNICALL
    Java_java_lang_VMClass_getDeclaredFields (JNIEnv *, jclass, jclass,
					      jboolean);

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaredMethods
 * Signature: (Ljava/lang/Class;Z)[Ljava/lang/reflect/Method;
 */
  JNIEXPORT static jobjectArray JNICALL
    Java_java_lang_VMClass_getDeclaredMethods (JNIEnv *, jclass, jclass,
					       jboolean);

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaredConstructors
 * Signature: (Ljava/lang/Class;Z)[Ljava/lang/reflect/Constructor;
 */
  JNIEXPORT static jobjectArray JNICALL
    Java_java_lang_VMClass_getDeclaredConstructors (JNIEnv *, jclass, jclass,
						    jboolean);

/*
 * Class:     java_lang_VMClass
 * Method:    getClassLoader
 * Signature: (Ljava/lang/Class;)Ljava/lang/ClassLoader;
 */
  JNIEXPORT static jobject JNICALL Java_java_lang_VMClass_getClassLoader
    (JNIEnv *, jclass, jclass);

/*
 * Class:     java_lang_VMClass
 * Method:    loadArrayClass
 * Signature: (Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class;
  JNIEXPORT static jclass JNICALL Java_java_lang_VMClass_loadArrayClass
    (JNIEnv *, jclass, jstring, jobject);
 */

/*
 * Class:     java_lang_VMClass
 * Method:    throwException
 * Signature: (Ljava/lang/Throwable;)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMClass_throwException
    (JNIEnv *, jclass, jthrowable);

#ifdef __cplusplus
}
#endif
#endif