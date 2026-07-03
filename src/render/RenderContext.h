#pragma once
#include <memory>

namespace swm::graphics {

class RenderTarget;
class IRenderer;

class RenderContext {
public:
    RenderContext();
    ~RenderContext() = default;
    void setRenderTarget(const std::shared_ptr<RenderTarget>& target);
    std::shared_ptr<RenderTarget> getRenderTarget() const;
    void setRenderer(const std::shared_ptr<IRenderer>& renderer);
    std::shared_ptr<IRenderer> getRenderer() const;
private:
    std::shared_ptr<RenderTarget> m_target;
    std::shared_ptr<IRenderer> m_renderer;
};

}
