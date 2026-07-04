#pragma once
#include "../math/Matrix4.h"
#include "../math/Rect.h"
#include "../math/Size.h"

namespace swm::graphics { class Frame; }
namespace swm::scene { class Camera; }

namespace swm::render {

class RenderContext {
public:
    RenderContext(swm::graphics::Frame* frame) : m_frame(frame) {}

    swm::graphics::Frame* getFrame() const { return m_frame; }

    void setViewport(const swm::math::Rect& viewport) { m_viewport = viewport; }
    const swm::math::Rect& getViewport() const { return m_viewport; }

    void setClipRect(const swm::math::Rect& clip) { m_clipRect = clip; }
    const swm::math::Rect& getClipRect() const { return m_clipRect; }

    void setCamera(const swm::scene::Camera* camera) { m_camera = camera; }
    const swm::scene::Camera* getCamera() const { return m_camera; }

    void setTransform(const swm::math::Matrix4& transform) { m_transform = transform; }
    const swm::math::Matrix4& getTransform() const { return m_transform; }
    
    void setDpi(float dpi) { m_dpi = dpi; }
    float getDpi() const { return m_dpi; }

private:
    swm::graphics::Frame* m_frame = nullptr;
    swm::math::Rect m_viewport;
    swm::math::Rect m_clipRect;
    const swm::scene::Camera* m_camera = nullptr;
    swm::math::Matrix4 m_transform;
    float m_dpi = 96.0f;
};

} // namespace swm::render
