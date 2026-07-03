#pragma once
#include <cstdint>

namespace swm::graphics {

struct RendererStatistics {
    uint64_t drawCalls{0};
    uint64_t primitivesCount{0};
    uint64_t renderPasses{0};
};

}
