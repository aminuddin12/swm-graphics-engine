#pragma once
#include "../../include/swm/EngineConfiguration.h"
#include <memory>

namespace swm::graphics {

class EngineServices;
class FrameClock;
class RenderScheduler;

class EngineContext {
public:
    explicit EngineContext(const EngineConfiguration& config);
    ~EngineContext();

    void initialize();
    void start();
    void stop();
    void shutdown();

    const EngineConfiguration& getConfiguration() const;
    std::shared_ptr<EngineServices> getServices() const;
    std::shared_ptr<FrameClock> getClock() const;
    std::shared_ptr<RenderScheduler> getScheduler() const;

private:
    EngineConfiguration m_config;
    std::shared_ptr<EngineServices> m_services;
    std::shared_ptr<FrameClock> m_clock;
    std::shared_ptr<RenderScheduler> m_scheduler;
};

}
