#pragma once
#include <cstdint>

namespace swm::graphics {

struct EngineStatistics {
    uint64_t uptimeNanoseconds{0};
    uint64_t totalFramesRendered{0};
};

}
