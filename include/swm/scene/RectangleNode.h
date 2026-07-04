#pragma once
#include "Node.h"
#include "../math/Size.h"
#include "../math/Color.h"

namespace swm::scene {

class RectangleNode : public Node {
public:
    RectangleNode() = default;

    void setSize(const swm::math::Size& size) { m_size = size; }
    const swm::math::Size& getSize() const { return m_size; }

    void setFillColor(const swm::math::Color& color) { m_fillColor = color; }
    const swm::math::Color& getFillColor() const { return m_fillColor; }

private:
    swm::math::Size m_size;
    swm::math::Color m_fillColor{255, 255, 255, 255};
};

} // namespace swm::scene
