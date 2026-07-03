#pragma once
#include "Resource.h"
#include "../math/Color.h"
#include <string>
#include <vector>

namespace swm::graphics {

struct GradientStop {
    float offset;
    Color color;
};

class Gradient : public Resource {
public:
    Gradient(const std::string& id, const std::vector<GradientStop>& stops) : m_id(id), m_stops(stops) {}
    ~Gradient() noexcept override = default;
    const std::string& getId() const override { return m_id; }
    const std::vector<GradientStop>& getStops() const { return m_stops; }
private:
    std::string m_id;
    std::vector<GradientStop> m_stops;
};

}
