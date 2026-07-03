#pragma once
#include "../../render/IRenderer.h"
#include <cstdint>

namespace swm::graphics {

class NullRenderer : public IRenderer {
public:
    NullRenderer(uint32_t width, uint32_t height);
    ~NullRenderer() override = default;

    void initialize() override;
    void shutdown() override;
    std::shared_ptr<Frame> render(const std::shared_ptr<Canvas>& canvas) override;
    void executeCommands(const std::shared_ptr<CommandBuffer>& buffer, const std::shared_ptr<RenderTarget>& target) override;

private:
    uint32_t m_width;
    uint32_t m_height;
};

}
