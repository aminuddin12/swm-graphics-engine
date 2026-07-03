#pragma once
#include <cstdint>

namespace swm::graphics {

struct FrameRate {
    uint32_t numerator{30};
    uint32_t denominator{1};
};

}
