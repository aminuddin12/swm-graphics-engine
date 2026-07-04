#include "RendererFactory.h"
#include "../backends/null/NullRenderer.h"

namespace swm::graphics {

std::shared_ptr<swm::render::IRenderer> RendererFactory::create(EngineBackend backend, uint32_t width, uint32_t height) {
    if (backend == EngineBackend::Null) {
        return std::make_shared<NullRenderer>(width, height);
    }
    return std::make_shared<NullRenderer>(width, height);
}

}
