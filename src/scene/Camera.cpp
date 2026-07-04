#include "swm/scene/Camera.h"

namespace swm::scene {

Camera::Camera() {
}

void Camera::setProjectionMatrix(const swm::math::Matrix4& projection) {
    m_projection = projection;
}

const swm::math::Matrix4& Camera::getProjectionMatrix() const {
    return m_projection;
}

void Camera::setViewMatrix(const swm::math::Matrix4& view) {
    m_view = view;
}

const swm::math::Matrix4& Camera::getViewMatrix() const {
    return m_view;
}

}
