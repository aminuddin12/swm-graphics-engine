#pragma once

namespace swm::graphics {

struct Vector2 {
    float x = 0.0f;
    float y = 0.0f;

    Vector2() = default;
    Vector2(float xVal, float yVal) : x(xVal), y(yVal) {}
};

}
