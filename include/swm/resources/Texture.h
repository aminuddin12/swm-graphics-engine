#pragma once
#include "Resource.h"
#include <cstdint>
#include <string>

namespace swm::graphics {

class Texture : public Resource {
public:
    Texture(const std::string& id, uint32_t width, uint32_t height) : m_id(id), m_width(width), m_height(height) {}
    ~Texture() noexcept override = default;
    const std::string& getId() const override { return m_id; }
    uint32_t getWidth() const { return m_width; }
    uint32_t getHeight() const { return m_height; }
private:
    std::string m_id;
    uint32_t m_width;
    uint32_t m_height;
};

}
