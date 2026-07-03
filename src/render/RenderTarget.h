#pragma once
#include "../../include/swm/PixelFormat.h"
#include <cstdint>
#include <vector>

namespace swm::graphics {

enum class RenderTargetType {
    FrameBuffer,
    CpuBuffer,
    GpuBuffer,
    SharedMemory,
    ObsOutput,
    PngOutput
};

class RenderTarget {
public:
    RenderTarget(uint32_t width, uint32_t height, PixelFormat format, RenderTargetType type);
    ~RenderTarget() = default;

    uint32_t getWidth() const;
    uint32_t getHeight() const;
    PixelFormat getPixelFormat() const;
    RenderTargetType getType() const;
    uint8_t* getBufferData();
    const uint8_t* getBufferData() const;

private:
    uint32_t m_width;
    uint32_t m_height;
    PixelFormat m_format;
    RenderTargetType m_type;
    std::vector<uint8_t> m_buffer;
};

}
