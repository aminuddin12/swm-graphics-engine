#pragma once
#include "../../include/swm/EngineBackend.h"
#include <memory>
#include <cstdint>

namespace swm::graphics {

class IRenderer;

class RendererFactory {
public:
    static std::shared_ptr<IRenderer> create(EngineBackend backend, uint32_t width, uint32_t height);
};

}
