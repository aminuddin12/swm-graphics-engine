#include "../../include/swm/scene/Scene.h"
#include <algorithm>

namespace swm::graphics {

Scene::Scene() {
}

void Scene::addLayer(std::shared_ptr<Layer> layer) {
    if (layer) {
        m_layers.push_back(layer);
    }
}

void Scene::removeLayer(std::shared_ptr<Layer> layer) {
    m_layers.erase(
        std::remove(m_layers.begin(), m_layers.end(), layer),
        m_layers.end()
    );
}

const std::vector<std::shared_ptr<Layer>>& Scene::getLayers() const {
    return m_layers;
}

}
