#pragma once
#include "swm/render/RenderCommand.h"

namespace swm::graphics { class Frame; }
namespace swm::render { class RenderContext; }

namespace swm::render::rasterizers {

class RectangleRasterizer {
public:
    static void draw(RenderContext* context, const DrawRectangleCommand& cmd);
};

} // namespace swm::render::rasterizers
