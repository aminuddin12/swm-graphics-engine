#pragma once
#include "Resource.h"
#include <string>

namespace swm::graphics {

class Image : public Resource {
public:
    Image(const std::string& id, const std::string& path) : m_id(id), m_path(path) {}
    ~Image() noexcept override = default;
    const std::string& getId() const override { return m_id; }
    const std::string& getPath() const { return m_path; }
private:
    std::string m_id;
    std::string m_path;
};

}
