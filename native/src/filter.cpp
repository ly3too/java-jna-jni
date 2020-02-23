#include "filter.hpp"
#include <cstdint>

using namespace std;

/**
 * i64_gt filter, test a value greater than m_th
 */
class I64GreaterFilter: public Filter{
public:
    I64GreaterFilter(): m_th(0) {
    }

    /**
     * set up the th
     * @param conf string
     */
    void init(const string &conf) override {
        m_th = stoll(conf);
    }

    /**
     * do the test
     * @param data asicc representation of a int value
     * @param len
     * @return
     */
    bool filter(const char *data, std::size_t len) override {
        int64_t val = stoll(string(data, len));
        return val > m_th;
    }

    ~I64GreaterFilter() override = default;

private:
    int64_t m_th;
};

/**
 * filter factory
 * @param name
 * @return
 */
Filter *create_filter(const std::string &name) {
    if (name == "i64_gt") {
        return new I64GreaterFilter();
    }

    return nullptr;
}