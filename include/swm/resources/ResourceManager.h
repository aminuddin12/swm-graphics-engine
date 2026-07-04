#pragma once
#include "Resource.h"
#include "ResourceLoader.h"
#include "ResourceRegistry.h"
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

namespace swm::resources {

class ResourceManager {
public:
  ResourceManager(ResourceRegistry &registry) : m_registry(registry) {}

  void registerLoader(const std::string &type,
                      const std::shared_ptr<ResourceLoader> &loader) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_loaders[type] = loader;
  }

  template <typename T>
  std::shared_ptr<T> load(const std::string &type, const std::string &uri) {
    std::lock_guard<std::mutex> lock(m_mutex);
    ResourceId id = m_registry.registerResource(uri);

    if (auto it = m_cache.find(id); it != m_cache.end()) {
      return std::static_pointer_cast<T>(it->second);
    }

    auto loaderIt = m_loaders.find(type);
    if (loaderIt != m_loaders.end()) {
      auto resource = loaderIt->second->load(uri);
      if (resource) {
        m_cache[id] = resource;
        return std::static_pointer_cast<T>(resource);
      }
    }

    return nullptr;
  }

  void unload(ResourceId id) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_cache.erase(id);
  }

  void clearCache() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_cache.clear();
  }

private:
  ResourceRegistry &m_registry;
  std::unordered_map<ResourceId, std::shared_ptr<Resource>> m_cache;
  std::unordered_map<std::string, std::shared_ptr<ResourceLoader>> m_loaders;
  std::mutex m_mutex;
};

} // namespace swm::resources
