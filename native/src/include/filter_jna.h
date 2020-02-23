//
// Created by ly3too on 20-2-23.
//

#ifndef JNI_DEMO_FILTER_JNA_H
#define JNI_DEMO_FILTER_JNA_H

#ifdef _WIN32
#define JNA_EXPORT __declspec(dllexport)
#else
#define JNA_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

JNA_EXPORT void *create_jna_filter(const char *name);

JNA_EXPORT int filter_init(void *filter, const char * conf);

JNA_EXPORT int filter_filter(void *filter, const char *data, int32_t len);

JNA_EXPORT void filter_destroy(void *filter);

#ifdef __cplusplus
}
#endif
#endif //JNI_DEMO_FILTER_JNA_H
