#pragma once
#include "PixelFormat.h"
#include <cstdint>
#include <vector>

namespace swm::graphics {

class Frame {
public:
    Frame(uint32_t width, uint32_t height, PixelFormat format);
    uint32_t getWidth() const;
    uint32_t getHeight() const;
    uint32_t getStride() const;
    PixelFormat getPixelFormat() const;
    uint64_t getTimestamp() const;
    void setTimestamp(uint64_t timestamp);
    const uint8_t* getData() const;
    uint8_t* getData();
private:
    uint32_t m_width;
    uint32_t m_height;
    PixelFormat m_format;
    uint64_t m_timestamp = 0;
    std::vector<uint8_t> m_data;
};

}
