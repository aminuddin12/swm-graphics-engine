#include "CommandBuffer.h"

namespace swm::graphics {

void CommandBuffer::addCommand(const RenderCommand& command) {
    m_commands.push_back(command);
}

const std::vector<RenderCommand>& CommandBuffer::getCommands() const {
    return m_commands;
}

void CommandBuffer::clear() {
    m_commands.clear();
}

}
