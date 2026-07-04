#pragma once
#include "../../include/swm/resources/ResourceManager.h"
#include <memory>

namespace swm::graphics {

class EngineServices {
public:
    EngineServices();
    ~EngineServices() = default;
    
    swm::resources::ResourceRegistry& getRegistry() { return m_registry; }
    std::shared_ptr<swm::resources::ResourceManager> getResourceManager() const;
private:
    swm::resources::ResourceRegistry m_registry;
    std::shared_ptr<swm::resources::ResourceManager> m_resourceManager;
};

}
