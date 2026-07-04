#pragma once
#include <cstdint>
#include <string>
#include <unordered_map>
#include <memory>

namespace swm::resources {

using ResourceId = uint64_t;

class ResourceRegistry {
public:
    static constexpr ResourceId InvalidId = 0;

    ResourceId registerResource(const std::string& uri) {
        if (m_uriToId.find(uri) != m_uriToId.end()) {
            return m_uriToId[uri];
        }
        
        ResourceId id = ++m_nextId;
        m_uriToId[uri] = id;
        m_idToUri[id] = uri;
        return id;
    }

    std::string getUri(ResourceId id) const {
        auto it = m_idToUri.find(id);
        return it != m_idToUri.end() ? it->second : "";
    }

    ResourceId getId(const std::string& uri) const {
        auto it = m_uriToId.find(uri);
        return it != m_uriToId.end() ? it->second : InvalidId;
    }

private:
    ResourceId m_nextId = 0;
    std::unordered_map<std::string, ResourceId> m_uriToId;
    std::unordered_map<ResourceId, std::string> m_idToUri;
};

} // namespace swm::resources
