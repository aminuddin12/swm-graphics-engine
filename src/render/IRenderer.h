#pragma once
#include "../../include/swm/Frame.h"
#include <memory>

namespace swm::graphics {

class Canvas;
class RenderTarget;
class CommandBuffer;

class IRenderer {
public:
    virtual ~IRenderer() = default;
    virtual void initialize() = 0;
    virtual void shutdown() = 0;
    virtual std::shared_ptr<Frame> render(const std::shared_ptr<Canvas>& canvas) = 0;
    virtual void executeCommands(const std::shared_ptr<CommandBuffer>& buffer, const std::shared_ptr<RenderTarget>& target) = 0;
};

}
