#pragma once
#include "../math/Matrix4.h"
#include "../math/Vector3.h"

namespace swm::graphics {

class Camera {
public:
    Camera();
    void setProjectionMatrix(const Matrix4& projection);
    const Matrix4& getProjectionMatrix() const;
    void setViewMatrix(const Matrix4& view);
    const Matrix4& getViewMatrix() const;
private:
    Matrix4 m_projection;
    Matrix4 m_view;
};

}
