#pragma once
#include "RenderNode.h"
#include <memory>
#include <vector>

namespace swm::scene { 
    class Scene; 
    class Node;
}
namespace swm::core { class EngineStatistics; }

namespace swm::render {

class SceneCompiler {
public:
    SceneCompiler();

    std::vector<std::shared_ptr<RenderNode>> compile(
        const std::shared_ptr<swm::scene::Scene>& scene,
        swm::core::EngineStatistics& stats
    );

private:
    std::shared_ptr<RenderNode> compileNode(
        const std::shared_ptr<swm::scene::Node>& node,
        swm::core::EngineStatistics& stats
    );
};

} // namespace swm::render
