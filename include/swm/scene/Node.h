#pragma once
#include "../math/Transform.h"
#include <string>
#include <vector>
#include <memory>

namespace swm::scene {

class Node : public std::enable_shared_from_this<Node> {
public:
    Node();
    virtual ~Node() = default;
    void setTransform(const swm::math::Transform& transform);
    const swm::math::Transform& getTransform() const;
    void setParent(std::shared_ptr<Node> parent);
    std::shared_ptr<Node> getParent() const;
    
    // Core properties for Scene Graph
    uint32_t getId() const { return m_id; }
    void setId(uint32_t id) { m_id = id; }
    
    bool isVisible() const { return m_visible; }
    void setVisible(bool visible) { m_visible = visible; }
    
    float getOpacity() const { return m_opacity; }
    void setOpacity(float opacity) { m_opacity = opacity; }

private:
    uint32_t m_id = 0;
    swm::math::Transform m_transform;
    std::weak_ptr<Node> m_parent;
    bool m_visible = true;
    float m_opacity = 1.0f;
};

}
