#include "RenderTarget.h"

namespace swm::graphics {

RenderTarget::RenderTarget(uint32_t width, uint32_t height, PixelFormat format, RenderTargetType type)
    : m_width(width), m_height(height), m_format(format), m_type(type), m_buffer(width * height * 4, 0) {
}

uint32_t RenderTarget::getWidth() const {
    return m_width;
}

uint32_t RenderTarget::getHeight() const {
    return m_height;
}

PixelFormat RenderTarget::getPixelFormat() const {
    return m_format;
}

RenderTargetType RenderTarget::getType() const {
    return m_type;
}

uint8_t* RenderTarget::getBufferData() {
    return m_buffer.data();
}

const uint8_t* RenderTarget::getBufferData() const {
    return m_buffer.data();
}

}
