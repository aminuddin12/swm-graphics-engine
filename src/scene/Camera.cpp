#include "../../include/swm/scene/Camera.h"

namespace swm::graphics {

Camera::Camera() {
}

void Camera::setProjectionMatrix(const Matrix4& projection) {
    m_projection = projection;
}

const Matrix4& Camera::getProjectionMatrix() const {
    return m_projection;
}

void Camera::setViewMatrix(const Matrix4& view) {
    m_view = view;
}

const Matrix4& Camera::getViewMatrix() const {
    return m_view;
}

}
