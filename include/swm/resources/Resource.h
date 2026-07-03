#pragma once
#include <string>

namespace swm::graphics {

class Resource {
public:
    virtual ~Resource() = default;
    virtual const std::string& getId() const = 0;
};

}
