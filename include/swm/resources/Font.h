#pragma once
#include "Resource.h"
#include <string>

namespace swm::graphics {

class Font : public Resource {
public:
    Font(const std::string& id, const std::string& family, float size) : m_id(id), m_family(family), m_size(size) {}
    ~Font() noexcept override {}
    const std::string& getId() const override { return m_id; }
    const std::string& getFamily() const { return m_family; }
    float getSize() const { return m_size; }
private:
    std::string m_id;
    std::string m_family;
    float m_size;
};

}
