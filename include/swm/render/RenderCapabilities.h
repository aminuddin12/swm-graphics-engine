#pragma once
#include <bitset>
#include <string>

namespace swm::render {

enum class RenderFeature {
    Gradient,
    Shadow,
    Blur,
    SVG,
    Video,
    GPUTexture,
    Clipping,
    Mask,
    Count // Must be last
};

struct BackendInfo {
    std::string name;
    std::string version;
    std::string vendor;
    std::string api;
    std::string driver;
    std::string platform;
    std::string threadingModel;
    std::string simd;
    uint32_t maxTextureSize = 0;
    uint32_t alignment = 0;
};

class RenderCapabilities {
public:
    RenderCapabilities() = default;

    void enableFeature(RenderFeature feature) {
        m_features.set(static_cast<size_t>(feature));
    }

    bool supports(RenderFeature feature) const {
        return m_features.test(static_cast<size_t>(feature));
    }

    void setBackendInfo(const BackendInfo& info) {
        m_backendInfo = info;
    }

    const BackendInfo& getBackendInfo() const {
        return m_backendInfo;
    }

private:
    std::bitset<static_cast<size_t>(RenderFeature::Count)> m_features;
    BackendInfo m_backendInfo;
};

} // namespace swm::render
