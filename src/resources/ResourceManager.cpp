#include "../../include/swm/resources/ResourceManager.h"

namespace swm::graphics {

ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager() {
}

void ResourceManager::registerLoader(const std::string& type, const std::shared_ptr<ResourceLoader>& loader) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_loaders[type] = loader;
}

std::shared_ptr<Resource> ResourceManager::load(const std::string& type, const std::string& id, const std::string& path) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_loaders.find(type);
    if (it != m_loaders.end()) {
        auto resource = it->second->load(path);
        if (resource) {
            m_cache.add(id, resource);
            return resource;
        }
    }
    return nullptr;
}

std::shared_ptr<Resource> ResourceManager::get(const std::string& id) {
    return m_cache.get(id);
}

void ResourceManager::release(const std::string& id) {
    m_cache.remove(id);
}

}
