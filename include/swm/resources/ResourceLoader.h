#pragma once
#include "Resource.h"
#include <memory>
#include <string>

namespace swm::graphics {

class ResourceLoader {
public:
    virtual ~ResourceLoader() = default;
    virtual std::shared_ptr<Resource> load(const std::string& path) = 0;
};

}
