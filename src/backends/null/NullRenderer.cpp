#include "NullRenderer.h"
#include "../../render/rasterizers/RectangleRasterizer.h"
#include "swm/render/RenderContext.h"
#include "swm/Frame.h"

namespace swm::graphics {

NullRenderer::NullRenderer(uint32_t width, uint32_t height)
    : m_width(width), m_height(height) {
}

void NullRenderer::initialize() {
}

void NullRenderer::shutdown() {
}

void NullRenderer::render(const std::vector<swm::render::RenderPass>& passes, swm::render::RenderContext* context) {
    if (!context || !context->getFrame()) return;
    
    // Clear frame first
    context->getFrame()->clear();

    for (const auto& pass : passes) {
        for (const auto& cmd : pass.getCommandBuffer().getCommands()) {
            switch (cmd.type) {
                case swm::render::RenderCommandType::DrawRectangle:
                    if (std::holds_alternative<swm::render::DrawRectangleCommand>(cmd.data)) {
                        swm::render::rasterizers::RectangleRasterizer::draw(
                            context, 
                            std::get<swm::render::DrawRectangleCommand>(cmd.data)
                        );
                    }
                    break;
                // Add more shapes here later
                default:
                    break;
            }
        }
    }
}

} // namespace swm::graphics
