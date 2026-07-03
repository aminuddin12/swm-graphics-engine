#pragma once
#include <memory>
#include "Resource.h"

namespace swm::graphics {

class ResourceHandle {
public:
    ResourceHandle() = default;
    explicit ResourceHandle(std::shared_ptr<Resource> resource) : m_resource(resource) {}
    std::shared_ptr<Resource> getResource() const { return m_resource; }
    bool isValid() const { return m_resource != nullptr; }
private:
    std::shared_ptr<Resource> m_resource;
};

}
