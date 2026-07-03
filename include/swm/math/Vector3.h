#pragma once

namespace swm::graphics {

struct Vector3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    Vector3() = default;
    Vector3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}
};

}
