#pragma once
#include "RenderNode.h"
#include "RenderPass.h"
#include <vector>
#include <memory>

namespace swm::core { class EngineStatistics; }

namespace swm::render {

class RenderCompiler {
public:
    RenderCompiler();

    std::vector<RenderPass> compile(
        const std::vector<std::shared_ptr<RenderNode>>& renderTree,
        swm::core::EngineStatistics& stats
    );

private:
    void compileNodeToBuffer(
        const std::shared_ptr<RenderNode>& node, 
        CommandBuffer& buffer,
        swm::core::EngineStatistics& stats
    );
};

} // namespace swm::render
