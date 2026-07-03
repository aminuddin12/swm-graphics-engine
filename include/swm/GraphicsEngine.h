#pragma once
#include "EngineConfiguration.h"
#include "scene/Scene.h"
#include "scene/Canvas.h"
#include "Frame.h"
#include <memory>

namespace swm::graphics {

class EngineContext;

class GraphicsEngine {
public:
    GraphicsEngine(const EngineConfiguration& config);
    ~GraphicsEngine();

    void initialize();
    void start();
    void stop();
    void shutdown();

    std::shared_ptr<Frame> render(const std::shared_ptr<Canvas>& canvas);

private:
    EngineConfiguration m_config;
    std::shared_ptr<EngineContext> m_context;
};

}
