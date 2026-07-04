#pragma once
#include "../math/Matrix4.h"
#include "../math/Vector3.h"

namespace swm::scene {

class Camera {
public:
    Camera();
    void setProjectionMatrix(const swm::math::Matrix4& projection);
    const swm::math::Matrix4& getProjectionMatrix() const;
    void setViewMatrix(const swm::math::Matrix4& view);
    const swm::math::Matrix4& getViewMatrix() const;
private:
    swm::math::Matrix4 m_projection;
    swm::math::Matrix4 m_view;
};

}
