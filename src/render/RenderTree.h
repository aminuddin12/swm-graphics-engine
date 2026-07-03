#pragma once
#include <memory>

namespace swm::graphics {

class Scene;
class CommandBuffer;

class RenderTree {
public:
    RenderTree();
    ~RenderTree() = default;
    void build(const std::shared_ptr<Scene>& scene);
    std::shared_ptr<CommandBuffer> getCommandBuffer() const;
private:
    std::shared_ptr<CommandBuffer> m_commandBuffer;
};

}
