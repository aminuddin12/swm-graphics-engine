#pragma once
#include <cstdint>

namespace swm::graphics {

struct FrameStatistics {
    float frameTimeMilliseconds = 0.0f;
    float cpuRenderTimeMilliseconds = 0.0f;
    float gpuRenderTimeMilliseconds = 0.0f;
};

}
