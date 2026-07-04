cmake_minimum_required(VERSION 3.16)
project(swm_graphics_engine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(swm_graphics_engine STATIC
    src/core/EngineVersion.cpp
    src/core/EngineContext.cpp
    src/core/EngineServices.cpp
    src/core/FrameClock.cpp
    src/core/RenderScheduler.cpp
    src/core/GraphicsEngine.cpp
    src/render/Frame.cpp
    src/render/RenderTarget.cpp
    src/render/SceneCompiler.cpp
    src/render/RenderCompiler.cpp
    src/render/rasterizers/RectangleRasterizer.cpp
    src/render/RendererFactory.cpp
    src/backends/null/NullRenderer.cpp
    src/scene/Node.cpp
    src/scene/Group.cpp
    src/scene/Layer.cpp
    src/scene/Scene.cpp
    src/scene/Camera.cpp
    src/scene/Canvas.cpp
)

target_include_directories(swm_graphics_engine PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
