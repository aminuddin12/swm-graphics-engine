#include "RenderTree.h"
#include "CommandBuffer.h"

namespace swm::graphics {

RenderTree::RenderTree() : m_commandBuffer(std::make_shared<CommandBuffer>()) {
}

void RenderTree::build(const std::shared_ptr<Scene>& scene) {
    m_commandBuffer->clear();
    if (!scene) {
        return;
    }
    RenderCommand cmd;
    cmd.type = RenderCommandType::DrawRect;
    cmd.rect = {0.0f, 0.0f, 1920.0f, 1080.0f};
    cmd.color = {0.0f, 0.0f, 0.0f, 1.0f};
    m_commandBuffer->addCommand(cmd);
}

std::shared_ptr<CommandBuffer> RenderTree::getCommandBuffer() const {
    return m_commandBuffer;
}

}
