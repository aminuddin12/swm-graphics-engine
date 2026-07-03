#include "../../include/swm/GraphicsEngine.h"
#include "EngineContext.h"
#include "../render/RendererFactory.h"
#include "../render/IRenderer.h"

namespace swm::graphics {

GraphicsEngine::GraphicsEngine(const EngineConfiguration& config)
    : m_config(config), m_context(std::make_shared<EngineContext>(config)) {
}

GraphicsEngine::~GraphicsEngine() {
    shutdown();
}

void GraphicsEngine::initialize() {
    m_context->initialize();
}

void GraphicsEngine::start() {
    m_context->start();
}

void GraphicsEngine::stop() {
    m_context->stop();
}

void GraphicsEngine::shutdown() {
    m_context->shutdown();
}

std::shared_ptr<Frame> GraphicsEngine::render(const std::shared_ptr<Canvas>& canvas) {
    auto renderer = RendererFactory::create(m_config.backend, m_config.width, m_config.height);
    renderer->initialize();
    auto frame = renderer->render(canvas);
    renderer->shutdown();
    return frame;
}

}
