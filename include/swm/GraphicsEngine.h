#pragma once
#include "EngineConfiguration.h"
#include "Frame.h"
#include "core/EngineStatistics.h"
#include "core/RenderScheduler.h"
#include <memory>

namespace swm::scene { class Document; }
namespace swm::render { class IRenderer; }

namespace swm::graphics {

class EngineContext;

class GraphicsEngine {
public:
    GraphicsEngine(const EngineConfiguration& config);
    ~GraphicsEngine();

    void initialize();
    void load(const std::shared_ptr<swm::scene::Document>& document);
    void start();
    void update();
    std::shared_ptr<Frame> render();
    void stop();
    void shutdown();

    const swm::core::EngineStatistics& getStatistics() const;
    std::shared_ptr<swm::core::RenderScheduler> getScheduler() const;

private:
    EngineConfiguration m_config;
    std::shared_ptr<EngineContext> m_context;
    swm::core::EngineStatistics m_statistics;
    std::shared_ptr<swm::core::RenderScheduler> m_scheduler;
    std::shared_ptr<swm::scene::Document> m_document;
    std::shared_ptr<swm::render::IRenderer> m_renderer;
    std::shared_ptr<Frame> m_frame;
};

}
