#pragma once
#include <cstdint>
#include <atomic>

namespace swm::core {

struct RenderStatistics {
    std::atomic<uint64_t> commandCount{0};
    std::atomic<uint64_t> sceneNodeCount{0};
    std::atomic<uint64_t> renderNodeCount{0};
    std::atomic<uint64_t> dirtyNodeCount{0};
    std::atomic<uint64_t> dirtyRegionCount{0};
};

struct FrameStatistics {
    std::atomic<uint64_t> frameCount{0};
    std::atomic<uint64_t> renderCount{0};
    std::atomic<uint64_t> lastRenderDurationNs{0};
    std::atomic<uint64_t> peakRenderDurationNs{0};
    std::atomic<uint64_t> averageRenderDurationNs{0};
    std::atomic<uint64_t> frameMemoryBytes{0};
    std::atomic<uint64_t> lastTimestampNs{0};
};

struct ResourceStatistics {
    std::atomic<uint32_t> imageCount{0};
    std::atomic<uint32_t> fontCount{0};
    std::atomic<uint32_t> svgCount{0};
    std::atomic<uint32_t> textureCount{0};
    std::atomic<uint32_t> videoCount{0};
    std::atomic<uint32_t> animationCount{0};
};

class EngineStatistics {
public:
    RenderStatistics render;
    FrameStatistics frame;
    ResourceStatistics resource;

    void reset() {
        render.commandCount = 0;
        render.sceneNodeCount = 0;
        render.renderNodeCount = 0;
        render.dirtyNodeCount = 0;
        render.dirtyRegionCount = 0;

        frame.frameCount = 0;
        frame.renderCount = 0;
        frame.lastRenderDurationNs = 0;
        frame.peakRenderDurationNs = 0;
        frame.averageRenderDurationNs = 0;
        frame.frameMemoryBytes = 0;
        frame.lastTimestampNs = 0;

        resource.imageCount = 0;
        resource.fontCount = 0;
        resource.svgCount = 0;
        resource.textureCount = 0;
        resource.videoCount = 0;
        resource.animationCount = 0;
    }
};

} // namespace swm::core
