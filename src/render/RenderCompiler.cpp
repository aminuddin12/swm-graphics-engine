#include "swm/render/RenderCompiler.h"
#include "swm/render/RenderRectangleNode.h"
#include "swm/core/EngineStatistics.h"

namespace swm::render {

RenderCompiler::RenderCompiler() = default;

std::vector<RenderPass> RenderCompiler::compile(
    const std::vector<std::shared_ptr<RenderNode>>& renderTree,
    swm::core::EngineStatistics& stats
) {
    std::vector<RenderPass> passes;
    
    // For now, we put everything into a single Graphics pass.
    // Future expansion: sort nodes into Background, Text, Overlay passes etc.
    RenderPass graphicsPass(RenderPassType::Graphics, "MainGraphics");
    CommandBuffer buffer;

    for (const auto& rootNode : renderTree) {
        compileNodeToBuffer(rootNode, buffer, stats);
    }

    graphicsPass.setCommandBuffer(buffer);
    passes.push_back(graphicsPass);

    return passes;
}

void RenderCompiler::compileNodeToBuffer(
    const std::shared_ptr<RenderNode>& node, 
    CommandBuffer& buffer,
    swm::core::EngineStatistics& stats
) {
    if (!node) return;

    if (node->getType() == RenderNodeType::Rectangle) {
        auto rectNode = std::static_pointer_cast<RenderRectangleNode>(node);
        
        RenderCommand cmd;
        cmd.type = RenderCommandType::DrawRectangle;
        
        DrawRectangleCommand drawRect;
        // The rect coordinates should be transformed. 
        // For now we just use the raw size, assuming position is in Transform.
        // A complete engine would multiply rect by transform here, or pass transform to rasterizer.
        auto transform = rectNode->getTransform();
        // Assuming translation is handled here for this primitive phase
        drawRect.rect.x = transform.translation.x;
        drawRect.rect.y = transform.translation.y;
        drawRect.rect.width = rectNode->getSize().width;
        drawRect.rect.height = rectNode->getSize().height;
        drawRect.fillColor = rectNode->getFillColor();
        
        cmd.data = drawRect;
        buffer.addCommand(cmd);
        stats.render.commandCount++;
    }

    // Recursively compile children
    for (const auto& child : node->getChildren()) {
        compileNodeToBuffer(child, buffer, stats);
    }
}

} // namespace swm::render
