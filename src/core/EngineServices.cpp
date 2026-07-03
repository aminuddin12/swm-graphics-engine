#include "EngineServices.h"

namespace swm::graphics {

EngineServices::EngineServices()
    : m_resourceManager(std::make_shared<ResourceManager>()) {
}

std::shared_ptr<ResourceManager> EngineServices::getResourceManager() const {
    return m_resourceManager;
}

}
