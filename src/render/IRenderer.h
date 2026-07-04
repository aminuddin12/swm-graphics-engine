#pragma once
#include "swm/render/RenderPass.h"
#include "swm/render/RenderContext.h"
#include <vector>
#include <memory>

namespace swm::render {

class IRenderer {
public:
    virtual ~IRenderer() = default;
    virtual void initialize() = 0;
    virtual void shutdown() = 0;
    virtual void render(const std::vector<RenderPass>& passes, RenderContext* context) = 0;
};

} // namespace swm::render
