#pragma once
#include "CommandBuffer.h"
#include <string>

namespace swm::render {

enum class RenderPassType {
    Background,
    Graphics,
    Text,
    Overlay,
    Debug,
    Custom
};

class RenderPass {
public:
    RenderPass(RenderPassType type, const std::string& name = "") 
        : m_type(type), m_name(name) {}

    RenderPassType getType() const { return m_type; }
    const std::string& getName() const { return m_name; }

    void setCommandBuffer(const CommandBuffer& buffer) { m_commandBuffer = buffer; }
    const CommandBuffer& getCommandBuffer() const { return m_commandBuffer; }

private:
    RenderPassType m_type;
    std::string m_name;
    CommandBuffer m_commandBuffer;
};

} // namespace swm::render
