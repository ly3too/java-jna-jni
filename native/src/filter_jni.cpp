#include "jni_demo_Filter.h"
#include "filter.hpp"
#include <string>
#include <exception>

using namespace std;

/*
 * Class:     jni_demo_Filter
 * Method:    create_jni_filter
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_jni_1demo_Filter_create_1jni_1filter
    (JNIEnv *env, jclass cls, jstring s) {
    try {
        const char *str = env->GetStringUTFChars(s, 0);
        string name = str;
        env->ReleaseStringUTFChars(s, str);
        return reinterpret_cast<jlong>(create_filter(name));
    } catch (...) {
        return 0;
    }
}

/*
 * Class:     jni_demo_Filter
 * Method:    init
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_jni_1demo_Filter_init
    (JNIEnv *env, jclass cls, jlong ref, jstring conf) {
    try {
        const char *str = env->GetStringUTFChars(conf, 0);
        string conf_str = str;
        env->ReleaseStringUTFChars(conf, str);
        auto filter = reinterpret_cast<Filter *>(ref);
        filter->init(conf_str);

    } catch (exception &e) {
        env->ThrowNew(env->FindClass("java/lang/Exception"), e.what());

    } catch (...) {

        env->ThrowNew(env->FindClass("java/lang/Exception"), "other exception");
    }
}

/*
 * Class:     jni_demo_Filter
 * Method:    filter
 * Signature: (J[B)Z
 */
JNIEXPORT jboolean JNICALL Java_jni_1demo_Filter_filter
    (JNIEnv *env, jclass cls, jlong ref, jbyteArray byte_arr) {
    try {
        auto filter = reinterpret_cast<Filter *>(ref);

        auto length = (size_t) env->GetArrayLength(byte_arr);
        jbyte* pBytes = env->GetByteArrayElements(byte_arr, nullptr);

        bool ret = filter->filter(reinterpret_cast<const char *>(pBytes), length);
        env->ReleaseByteArrayElements(byte_arr, pBytes, JNI_ABORT);
        return static_cast<jboolean >(ret);

    } catch (exception &e) {
        env->ThrowNew(env->FindClass("java/lang/Exception"), e.what());

    } catch (...) {

        env->ThrowNew(env->FindClass("java/lang/Exception"), "other exception");
    }
    return 0;
}

/*
 * Class:     jni_demo_Filter
 * Method:    destroy
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_jni_1demo_Filter_destroy
    (JNIEnv *env, jclass cls, jlong ref) {
    auto *filter = reinterpret_cast<Filter *>(ref);
    delete filter;
}
