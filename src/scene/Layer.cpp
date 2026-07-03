#include "../../include/swm/scene/Layer.h"

namespace swm::graphics {

Layer::Layer() {
}

void Layer::setOpacity(float opacity) {
    m_opacity = opacity;
}

float Layer::getOpacity() const {
    return m_opacity;
}

void Layer::setVisible(bool visible) {
    m_visible = visible;
}

bool Layer::isVisible() const {
    return m_visible;
}

}
