#pragma once
#include <vector>
#include <memory>
#include "../math/Transform.h"

namespace swm::render {

enum class RenderNodeType {
    Group,
    Rectangle,
    Text,
    Image,
    // ...
};

class RenderNode {
public:
    RenderNode(RenderNodeType type = RenderNodeType::Group) : m_type(type) {}
    virtual ~RenderNode() = default;

    RenderNodeType getType() const { return m_type; }
    void setId(uint32_t id) { m_id = id; }
    uint32_t getId() const { return m_id; }

    void setTransform(const swm::math::Transform& transform) { m_transform = transform; }
    const swm::math::Transform& getTransform() const { return m_transform; }

    void setOpacity(float opacity) { m_opacity = opacity; }
    float getOpacity() const { return m_opacity; }

    void addChild(std::shared_ptr<RenderNode> child) { m_children.push_back(child); }
    const std::vector<std::shared_ptr<RenderNode>>& getChildren() const { return m_children; }

private:
    uint32_t m_id = 0;
    RenderNodeType m_type;
    swm::math::Transform m_transform;
    float m_opacity = 1.0f;
    std::vector<std::shared_ptr<RenderNode>> m_children;
};

} // namespace swm::render
