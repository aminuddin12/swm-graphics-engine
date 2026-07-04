#include "swm/Frame.h"
#include <algorithm>

namespace swm::graphics {

Frame::Frame(uint32_t width, uint32_t height, PixelFormat format)
    : m_width(width), m_height(height), m_format(format) {
    size_t size = height * stride();
    m_data.resize(size, 0);
}

uint32_t Frame::stride() const {
    uint32_t bytesPerPixel = 4; // default for RGBA8888 or BGRA8888
    return m_width * bytesPerPixel;
}

void Frame::clear() {
    std::fill(m_data.begin(), m_data.end(), 0);
}

}
