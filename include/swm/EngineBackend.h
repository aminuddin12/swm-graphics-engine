#pragma once

namespace swm::graphics {

enum class EngineBackend {
    Null,
    Blend2D,
    Metal,
    Vulkan,
    OpenGL,
    Direct3D
};

}
