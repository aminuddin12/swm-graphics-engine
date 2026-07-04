#pragma once
#include <string>

namespace swm::graphics { 
    class Frame; 
    struct Rect;
}

namespace swm::render {

class IDebugOverlay {
public:
    virtual ~IDebugOverlay() = default;

    virtual void drawBoundingBox(swm::graphics::Frame* frame, const swm::graphics::Rect& rect, const std::string& label = "") = 0;
    virtual void drawText(swm::graphics::Frame* frame, int x, int y, const std::string& text) = 0;
    virtual void drawCrosshair(swm::graphics::Frame* frame, int x, int y) = 0;
};

} // namespace swm::render
