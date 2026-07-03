#include "../../include/swm/scene/Canvas.h"

namespace swm::graphics {

Canvas::Canvas() {
}

void Canvas::setSize(const Size& size) {
    m_size = size;
}

const Size& Canvas::getSize() const {
    return m_size;
}

void Canvas::setClearColor(const Color& color) {
    m_clearColor = color;
}

const Color& Canvas::getClearColor() const {
    return m_clearColor;
}

void Canvas::setScene(std::shared_ptr<Scene> scene) {
    m_scene = scene;
}

std::shared_ptr<Scene> Canvas::getScene() const {
    return m_scene;
}

void Canvas::setCamera(std::shared_ptr<Camera> camera) {
    m_camera = camera;
}

std::shared_ptr<Camera> Canvas::getCamera() const {
    return m_camera;
}

}
