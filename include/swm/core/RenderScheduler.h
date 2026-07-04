#pragma once

namespace swm::core {

enum class RenderSchedulerMode {
    Immediate,
    Deferred,
    Continuous,
    FixedFPS
};

class RenderScheduler {
public:
    virtual ~RenderScheduler() = default;
    virtual void setMode(RenderSchedulerMode mode) = 0;
    virtual RenderSchedulerMode getMode() const = 0;
    virtual void requestFrame() = 0;
};

} // namespace swm::core
