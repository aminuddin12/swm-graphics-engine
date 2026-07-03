#pragma once
#include "../../include/swm/math/Rect.h"
#include "../../include/swm/math/Color.h"
#include <string>

namespace swm::graphics {

enum class RenderCommandType {
    DrawRect,
    DrawText,
    DrawImage
};

struct RenderCommand {
    RenderCommandType type;
    Rect rect;
    Color color;
    std::string text;
    std::string resourceId;
};

}
