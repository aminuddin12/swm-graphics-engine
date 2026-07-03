#include "NullRenderer.h"
#include "../../../include/swm/scene/Canvas.h"
#include "../../../include/swm/scene/Scene.h"
#include "../../render/RenderTarget.h"
#include "../../render/CommandBuffer.h"
#include "../../render/RenderTree.h"

namespace swm::graphics {

NullRenderer::NullRenderer(uint32_t width, uint32_t height)
    : m_width(width), m_height(height) {
}

void NullRenderer::initialize() {
}

void NullRenderer::shutdown() {
}

std::shared_ptr<Frame> NullRenderer::render(const std::shared_ptr<Canvas>& canvas) {
    auto frame = std::make_shared<Frame>(m_width, m_height, PixelFormat::RGBA8);
    Color clearColor{0.0f, 0.0f, 0.0f, 1.0f};
    if (canvas) {
        clearColor = canvas->getClearColor();
    }
    uint8_t* data = frame->getData();
    uint8_t r = static_cast<uint8_t>(clearColor.r * 255.0f);
    uint8_t g = static_cast<uint8_t>(clearColor.g * 255.0f);
    uint8_t b = static_cast<uint8_t>(clearColor.b * 255.0f);
    uint8_t a = static_cast<uint8_t>(clearColor.a * 255.0f);
    for (uint32_t i = 0; i < m_width * m_height * 4; i += 4) {
        data[i] = r;
        data[i + 1] = g;
        data[i + 2] = b;
        data[i + 3] = a;
    }
    return frame;
}

void NullRenderer::executeCommands(const std::shared_ptr<CommandBuffer>& buffer, const std::shared_ptr<RenderTarget>& target) {
    if (!target) {
        return;
    }
    uint8_t* data = target->getBufferData();
    uint32_t width = target->getWidth();
    uint32_t height = target->getHeight();
    for (uint32_t i = 0; i < width * height * 4; i += 4) {
        data[i] = 0;
        data[i + 1] = 0;
        data[i + 2] = 255;
        data[i + 3] = 255;
    }
}

}
