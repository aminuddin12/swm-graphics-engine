#include "../../include/swm/GraphicsEngine.h"
#include "EngineContext.h"
#include "../render/RendererFactory.h"
#include "../render/IRenderer.h"
#include "swm/render/SceneCompiler.h"
#include "swm/render/RenderCompiler.h"
#include "swm/render/RenderContext.h"
#include "swm/scene/Document.h"
#include "swm/scene/Stage.h"
#include "swm/scene/Canvas.h"

namespace swm::graphics {

GraphicsEngine::GraphicsEngine(const EngineConfiguration& config)
    : m_config(config), m_context(std::make_shared<EngineContext>(config)) {
    m_renderer = RendererFactory::create(m_config.backend, m_config.width, m_config.height);
    m_frame = std::make_shared<Frame>(m_config.width, m_config.height, PixelFormat::RGBA8);
}

GraphicsEngine::~GraphicsEngine() {
    shutdown();
}

void GraphicsEngine::initialize() {
    m_context->initialize();
    m_renderer->initialize();
}

void GraphicsEngine::load(const std::shared_ptr<swm::scene::Document>& document) {
    m_document = document;
}

void GraphicsEngine::start() {
    m_context->start();
}

void GraphicsEngine::update() {
    // Usually updates animations, physics, etc.
}

void GraphicsEngine::stop() {
    m_context->stop();
}

void GraphicsEngine::shutdown() {
    if (m_renderer) {
        m_renderer->shutdown();
    }
    m_context->shutdown();
}

std::shared_ptr<Frame> GraphicsEngine::render() {
    m_statistics.reset(); // Reset for this frame

    if (!m_document || m_document->getStages().empty()) return m_frame;
    auto stage = m_document->getStages().front();
    if (stage->getCanvases().empty()) return m_frame;
    auto canvas = stage->getCanvases().front();
    auto scene = canvas->getScene();

    // 1. Compile Scene to RenderTree
    swm::render::SceneCompiler sceneCompiler;
    auto renderTree = sceneCompiler.compile(scene, m_statistics);

    // 2. Compile RenderTree to RenderPasses
    swm::render::RenderCompiler renderCompiler;
    auto passes = renderCompiler.compile(renderTree, m_statistics);

    // 3. Render Passes
    swm::render::RenderContext renderContext(m_frame.get());
    m_renderer->render(passes, &renderContext);

    m_statistics.frame.frameCount++;
    return m_frame;
}

const swm::core::EngineStatistics& GraphicsEngine::getStatistics() const {
    return m_statistics;
}

std::shared_ptr<swm::core::RenderScheduler> GraphicsEngine::getScheduler() const {
    return m_scheduler;
}

} // namespace swm::graphics
