#include "FrameClock.h"

namespace swm::graphics {

FrameClock::FrameClock() : m_startTime(std::chrono::steady_clock::now()) {
}

void FrameClock::setFrameRate(const FrameRate& fps) {
    m_fps = fps;
}

FrameRate FrameClock::getFrameRate() const {
    return m_fps;
}

FrameTime FrameClock::tick() {
    m_frameCount++;
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(now - m_startTime).count();
    return FrameTime{m_frameCount, Timestamp{static_cast<uint64_t>(elapsed)}};
}

FrameTime FrameClock::getCurrentTime() const {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(now - m_startTime).count();
    return FrameTime{m_frameCount, Timestamp{static_cast<uint64_t>(elapsed)}};
}

void FrameClock::reset() {
    m_frameCount = 0;
    m_startTime = std::chrono::steady_clock::now();
}

}
