#pragma once
#include "RenderCommand.h"
#include <vector>

namespace swm::render {

class CommandBuffer {
public:
    CommandBuffer() = default;

    void addCommand(const RenderCommand& cmd) {
        m_commands.push_back(cmd);
    }

    const std::vector<RenderCommand>& getCommands() const {
        return m_commands;
    }

    void clear() {
        m_commands.clear();
    }

    size_t size() const {
        return m_commands.size();
    }

private:
    std::vector<RenderCommand> m_commands;
};

} // namespace swm::render
