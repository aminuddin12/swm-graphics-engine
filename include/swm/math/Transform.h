#pragma once
#include "Vector3.h"

namespace swm::math {

struct Transform {
    Vector3 translation;
    Vector3 rotation;
    Vector3 scale = Vector3(1.0f, 1.0f, 1.0f);
};

}
