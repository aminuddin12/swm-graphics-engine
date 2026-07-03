#pragma once
#include "../../include/swm/timing/FrameRate.h"
#include "../../include/swm/timing/FrameTime.h"
#include <chrono>

namespace swm::graphics {

class FrameClock {
public:
    FrameClock();
    ~FrameClock() = default;
    void setFrameRate(const FrameRate& fps);
    FrameRate getFrameRate() const;
    FrameTime tick();
    FrameTime getCurrentTime() const;
    void reset();
private:
    FrameRate m_fps;
    uint64_t m_frameCount{0};
    std::chrono::steady_clock::time_point m_startTime;
};

}
