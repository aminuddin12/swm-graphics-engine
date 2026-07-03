#pragma once
#include "Resource.h"
#include "../math/Color.h"
#include <string>

namespace swm::graphics {

class Brush : public Resource {
public:
    Brush(const std::string& id, const Color& color) : m_id(id), m_color(color) {}
    const std::string& getId() const override { return m_id; }
    const Color& getColor() const { return m_color; }
private:
    std::string m_id;
    Color m_color;
};

}
