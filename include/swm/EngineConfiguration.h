#pragma once
#include "EngineBackend.h"
#include "PixelFormat.h"
#include <cstdint>

namespace swm::graphics {

struct EngineConfiguration {
    uint32_t width{1920};
    uint32_t height{1080};
    EngineBackend backend{EngineBackend::Null};
    PixelFormat pixelFormat{PixelFormat::RGBA8};
};

}
