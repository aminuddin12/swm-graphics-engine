#pragma once
#include "../../render/IRenderer.h"
#include <cstdint>

namespace swm::graphics {

class NullRenderer : public swm::render::IRenderer {
public:
    NullRenderer(uint32_t width, uint32_t height);
    ~NullRenderer() override = default;

    void initialize() override;
    void shutdown() override;
    
    void render(const std::vector<swm::render::RenderPass>& passes, swm::render::RenderContext* context) override;

private:
    uint32_t m_width;
    uint32_t m_height;
};

} // namespace swm::graphics
