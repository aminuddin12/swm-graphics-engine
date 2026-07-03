#pragma once
#include "Layer.h"
#include <memory>
#include <vector>

namespace swm::graphics {

class Scene {
public:
    Scene();
    void addLayer(std::shared_ptr<Layer> layer);
    void removeLayer(std::shared_ptr<Layer> layer);
    const std::vector<std::shared_ptr<Layer>>& getLayers() const;
private:
    std::vector<std::shared_ptr<Layer>> m_layers;
};

}
