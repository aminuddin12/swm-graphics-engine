#pragma once
#include "Resource.h"
#include "ResourceCache.h"
#include "ResourceLoader.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <mutex>

namespace swm::graphics {

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();
    void registerLoader(const std::string& type, const std::shared_ptr<ResourceLoader>& loader);
    std::shared_ptr<Resource> load(const std::string& type, const std::string& id, const std::string& path);
    std::shared_ptr<Resource> get(const std::string& id);
    void release(const std::string& id);
private:
    ResourceCache m_cache;
    std::unordered_map<std::string, std::shared_ptr<ResourceLoader>> m_loaders;
    std::mutex m_mutex;
};

}
