#include <string>

class Filter {
public:
    virtual void init(const std::string &conf) = 0;
    virtual bool filter(const char *data, std::size_t len) = 0;
    virtual ~Filter() = 0;
};

/**
 * filter factory
 * @param name
 * @return
 */
Filter *create_filter(const std::string &name);