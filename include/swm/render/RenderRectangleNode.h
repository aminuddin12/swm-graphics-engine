#pragma once
#include "RenderNode.h"
#include "../math/Size.h"
#include "../math/Color.h"

namespace swm::render {

class RenderRectangleNode : public RenderNode {
public:
    RenderRectangleNode() : RenderNode(RenderNodeType::Rectangle) {}

    void setSize(const swm::math::Size& size) { m_size = size; }
    const swm::math::Size& getSize() const { return m_size; }

    void setFillColor(const swm::math::Color& color) { m_fillColor = color; }
    const swm::math::Color& getFillColor() const { return m_fillColor; }

private:
    swm::math::Size m_size;
    swm::math::Color m_fillColor;
};

} // namespace swm::render
