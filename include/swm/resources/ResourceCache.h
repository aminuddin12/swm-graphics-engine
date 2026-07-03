#pragma once
#include "Resource.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <mutex>

namespace swm::graphics {

class ResourceCache {
public:
    void add(const std::string& id, const std::shared_ptr<Resource>& resource) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_cache[id] = resource;
    }
    std::shared_ptr<Resource> get(const std::string& id) {
        std::lock_guard<std::mutex> lock(m_mutex);
        auto it = m_cache.find(id);
        if (it != m_cache.end()) {
            return it->second;
        }
        return nullptr;
    }
    void remove(const std::string& id) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_cache.erase(id);
    }
    void clear() {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_cache.clear();
    }
private:
    std::unordered_map<std::string, std::shared_ptr<Resource>> m_cache;
    std::mutex m_mutex;
};

}
