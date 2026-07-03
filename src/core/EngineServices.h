#pragma once
#include "../../include/swm/resources/ResourceManager.h"
#include <memory>

namespace swm::graphics {

class EngineServices {
public:
    EngineServices();
    ~EngineServices() = default;
    std::shared_ptr<ResourceManager> getResourceManager() const;
private:
    std::shared_ptr<ResourceManager> m_resourceManager;
};

}
