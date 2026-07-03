#pragma once
#include "Timestamp.h"
#include <cstdint>

namespace swm::graphics {

struct FrameTime {
    uint64_t frameNumber = 0;
    Timestamp timestamp;
};

}
