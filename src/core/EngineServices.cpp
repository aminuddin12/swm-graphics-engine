#include "EngineServices.h"

namespace swm::graphics {

EngineServices::EngineServices()
    : m_resourceManager(std::make_shared<swm::resources::ResourceManager>(m_registry)) {
}

std::shared_ptr<swm::resources::ResourceManager> EngineServices::getResourceManager() const {
    return m_resourceManager;
}

}
