#pragma once
#include "PixelFormat.h"
#include <cstdint>
#include <vector>

namespace swm::graphics {

class Frame {
public:
    Frame(uint32_t width, uint32_t height, PixelFormat format);
    
    uint32_t width() const { return m_width; }
    uint32_t height() const { return m_height; }
    uint32_t stride() const;
    PixelFormat pixelFormat() const { return m_format; }
    
    uint64_t timestamp() const { return m_timestamp; }
    void setTimestamp(uint64_t timestamp) { m_timestamp = timestamp; }
    
    const uint8_t* data() const { return m_data.data(); }
    uint8_t* data() { return m_data.data(); }

    void clear();

private:
    uint32_t m_width;
    uint32_t m_height;
    PixelFormat m_format;
    uint64_t m_timestamp = 0;
    std::vector<uint8_t> m_data;
};

}
