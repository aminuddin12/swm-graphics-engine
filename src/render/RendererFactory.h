#pragma once
#include "../../include/swm/EngineBackend.h"
#include <memory>
#include <cstdint>

namespace swm::render { class IRenderer; }

namespace swm::graphics {

class RendererFactory {
public:
    static std::shared_ptr<swm::render::IRenderer> create(EngineBackend backend, uint32_t width, uint32_t height);
};

}
