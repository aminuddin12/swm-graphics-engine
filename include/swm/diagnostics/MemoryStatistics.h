#pragma once
#include <cstdint>

namespace swm::graphics {

struct MemoryStatistics {
    uint64_t systemMemoryUsedBytes{0};
    uint64_t videoMemoryUsedBytes{0};
    uint64_t cachedResourcesCount{0};
};

}
