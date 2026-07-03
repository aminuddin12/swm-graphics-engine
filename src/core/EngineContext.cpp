#include "EngineContext.h"
#include "EngineServices.h"
#include "FrameClock.h"
#include "RenderScheduler.h"

namespace swm::graphics {

EngineContext::EngineContext(const EngineConfiguration& config)
    : m_config(config),
      m_services(std::make_shared<EngineServices>()),
      m_clock(std::make_shared<FrameClock>()),
      m_scheduler(std::make_shared<RenderScheduler>()) {
}

EngineContext::~EngineContext() {
    shutdown();
}

void EngineContext::initialize() {
    m_scheduler->start();
}

void EngineContext::start() {
    m_clock->reset();
}

void EngineContext::stop() {
}

void EngineContext::shutdown() {
    m_scheduler->stop();
}

const EngineConfiguration& EngineContext::getConfiguration() const {
    return m_config;
}

std::shared_ptr<EngineServices> EngineContext::getServices() const {
    return m_services;
}

std::shared_ptr<FrameClock> EngineContext::getClock() const {
    return m_clock;
}

std::shared_ptr<RenderScheduler> EngineContext::getScheduler() const {
    return m_scheduler;
}

}
