#pragma once
#include <cstdint>
#include <atomic>

namespace swm::core {

class SceneRevision {
public:
    SceneRevision() = default;
    
    uint64_t get() const { return m_revision.load(std::memory_order_acquire); }
    void increment() { m_revision.fetch_add(1, std::memory_order_release); }
    bool operator==(const SceneRevision& other) const { return get() == other.get(); }
    bool operator!=(const SceneRevision& other) const { return get() != other.get(); }
    bool operator<(const SceneRevision& other) const { return get() < other.get(); }

private:
    std::atomic<uint64_t> m_revision{0};
};

} // namespace swm::core
