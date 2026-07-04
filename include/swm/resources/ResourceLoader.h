#pragma once
#include <memory>
#include <string>

namespace swm::resources {
class Resource;

class ResourceLoader {
public:
    virtual ~ResourceLoader() = default;
    virtual std::shared_ptr<Resource> load(const std::string& path) = 0;
};

}
