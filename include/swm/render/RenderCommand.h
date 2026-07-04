#pragma once
#include "../math/Rect.h"
#include "../math/Color.h"
#include <variant>

namespace swm::render {

enum class RenderCommandType {
    DrawRectangle,
    DrawEllipse,
    DrawLine,
    DrawText,
    DrawImage,
    DrawSvg,
    DrawVideo
};

struct DrawRectangleCommand {
    swm::math::Rect rect;
    swm::math::Color fillColor;
};

// Stubs for others
struct DrawEllipseCommand { swm::math::Rect bounds; };
struct DrawLineCommand { float x1, y1, x2, y2; };
struct DrawTextCommand { /* ... */ };
struct DrawImageCommand { /* ... */ };
struct DrawSvgCommand { /* ... */ };
struct DrawVideoCommand { /* ... */ };

struct RenderCommand {
    RenderCommandType type;
    std::variant<
        DrawRectangleCommand,
        DrawEllipseCommand,
        DrawLineCommand,
        DrawTextCommand,
        DrawImageCommand,
        DrawSvgCommand,
        DrawVideoCommand
    > data;
};

} // namespace swm::render
