#include "filter_jna.h"
#include "filter.hpp"
#include <string>
#include <exception>

using namespace std;

void *create_jna_filter(const char *name) {
    try {
        return reinterpret_cast<void *>(create_filter(name));
    } catch (...) {
        return nullptr;
    }
}



int filter_init(void *ref, const char * conf) {
    try {
        auto filter = reinterpret_cast<Filter *>(ref);
        filter->init(conf);
        return 0;
    } catch (...) {
        return -1;
    }
}

int filter_filter(void *ref, const char *data, int32_t len) {
    try {
        auto filter = reinterpret_cast<Filter *>(ref);
        return filter->filter(data, len);

    } catch (...) {
        return 0;
    }
}

void filter_destroy(void *ref) {
    auto *filter = reinterpret_cast<Filter *>(ref);
    delete filter;
}
