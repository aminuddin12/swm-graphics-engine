#include "RenderContext.h"
#include "RenderTarget.h"
#include "IRenderer.h"

namespace swm::graphics {

RenderContext::RenderContext() {
}

void RenderContext::setRenderTarget(const std::shared_ptr<RenderTarget>& target) {
    m_target = target;
}

std::shared_ptr<RenderTarget> RenderContext::getRenderTarget() const {
    return m_target;
}

void RenderContext::setRenderer(const std::shared_ptr<IRenderer>& renderer) {
    m_renderer = renderer;
}

std::shared_ptr<IRenderer> RenderContext::getRenderer() const {
    return m_renderer;
}

}
