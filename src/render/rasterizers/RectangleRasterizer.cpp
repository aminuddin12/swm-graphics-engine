#include "RectangleRasterizer.h"
#include "swm/render/RenderContext.h"
#include "swm/Frame.h"
#include <algorithm>

namespace swm::render::rasterizers {

void RectangleRasterizer::draw(RenderContext* context, const DrawRectangleCommand& cmd) {
    if (!context || !context->getFrame()) return;

    swm::graphics::Frame* frame = context->getFrame();
    uint8_t* buffer = frame->data();
    if (!buffer) return;

    int frameWidth = frame->width();
    int frameHeight = frame->height();
    int stride = frame->stride(); // Assuming bytes per row

    // Calculate bounds with clipping (assuming integer pixels for now)
    int startX = std::max(0, static_cast<int>(cmd.rect.x));
    int startY = std::max(0, static_cast<int>(cmd.rect.y));
    int endX = std::min(frameWidth, static_cast<int>(cmd.rect.x + cmd.rect.width));
    int endY = std::min(frameHeight, static_cast<int>(cmd.rect.y + cmd.rect.height));

    if (startX >= endX || startY >= endY) return;

    // Fast path: pure memory copy loop. No setPixel().
    uint32_t fillPixel = 
        (static_cast<uint32_t>(cmd.fillColor.a) << 24) |
        (static_cast<uint32_t>(cmd.fillColor.r) << 16) |
        (static_cast<uint32_t>(cmd.fillColor.g) << 8) |
        (static_cast<uint32_t>(cmd.fillColor.b)); // ARGB or RGBA depending on PixelFormat. Assuming ARGB32 for now.

    for (int y = startY; y < endY; ++y) {
        uint32_t* rowPtr = reinterpret_cast<uint32_t*>(buffer + (y * stride));
        for (int x = startX; x < endX; ++x) {
            rowPtr[x] = fillPixel;
        }
    }
}

} // namespace swm::render::rasterizers
