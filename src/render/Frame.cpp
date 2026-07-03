#include "../../include/swm/Frame.h"

namespace swm::graphics {

Frame::Frame(uint32_t width, uint32_t height, PixelFormat format)
    : m_width(width), m_height(height), m_format(format), m_data(width * height * 4, 0) {
}

uint32_t Frame::getWidth() const {
    return m_width;
}

uint32_t Frame::getHeight() const {
    return m_height;
}

uint32_t Frame::getStride() const {
    return m_width * 4;
}

PixelFormat Frame::getPixelFormat() const {
    return m_format;
}

uint64_t Frame::getTimestamp() const {
    return m_timestamp;
}

void Frame::setTimestamp(uint64_t timestamp) {
    m_timestamp = timestamp;
}

const uint8_t* Frame::getData() const {
    return m_data.data();
}

uint8_t* Frame::getData() {
    return m_data.data();
}

}
