#include "swm/render/SceneCompiler.h"
#include "swm/scene/Scene.h"
#include "swm/scene/Layer.h"
#include "swm/scene/RectangleNode.h"
#include "swm/render/RenderRectangleNode.h"
#include "swm/core/EngineStatistics.h"

namespace swm::render {

SceneCompiler::SceneCompiler() = default;

std::vector<std::shared_ptr<RenderNode>> SceneCompiler::compile(
    const std::shared_ptr<swm::scene::Scene>& scene,
    swm::core::EngineStatistics& stats
) {
    std::vector<std::shared_ptr<RenderNode>> renderTree;
    if (!scene) return renderTree;

    for (const auto& layer : scene->getLayers()) {
        if (!layer->isVisible() || layer->getOpacity() <= 0.0f) continue;

        stats.render.sceneNodeCount++;
        
        auto compiledLayer = compileNode(layer, stats);
        if (compiledLayer) {
            renderTree.push_back(compiledLayer);
        }
    }

    return renderTree;
}

std::shared_ptr<RenderNode> SceneCompiler::compileNode(
    const std::shared_ptr<swm::scene::Node>& node,
    swm::core::EngineStatistics& stats
) {
    if (!node->isVisible() || node->getOpacity() <= 0.0f) return nullptr;

    std::shared_ptr<RenderNode> renderNode;

    if (auto rectNode = std::dynamic_pointer_cast<swm::scene::RectangleNode>(node)) {
        auto rNode = std::make_shared<RenderRectangleNode>();
        rNode->setSize(rectNode->getSize());
        rNode->setFillColor(rectNode->getFillColor());
        renderNode = rNode;
    } else {
        renderNode = std::make_shared<RenderNode>(RenderNodeType::Group);
    }

    renderNode->setId(node->getId());
    renderNode->setTransform(node->getTransform());
    renderNode->setOpacity(node->getOpacity());
    stats.render.renderNodeCount++;

    // Since we don't have a getChildren on base Node right now except if it's a Group...
    // Actually we need to handle Group recursively.
    if (auto groupNode = std::dynamic_pointer_cast<swm::scene::Group>(node)) {
        for (const auto& child : groupNode->getChildren()) {
            stats.render.sceneNodeCount++;
            auto compiledChild = compileNode(child, stats);
            if (compiledChild) {
                renderNode->addChild(compiledChild);
            }
        }
    }

    return renderNode;
}

} // namespace swm::render
