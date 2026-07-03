#pragma once
#include "RenderCommand.h"
#include <vector>

namespace swm::graphics {

class CommandBuffer {
public:
    void addCommand(const RenderCommand& command);
    const std::vector<RenderCommand>& getCommands() const;
    void clear();
private:
    std::vector<RenderCommand> m_commands;
};

}
