#pragma once
#include "../math/Size.h"
#include "../math/Color.h"
#include <memory>

namespace swm::scene {

class Scene;
class Camera;

class Canvas {
public:
    Canvas();
    void setSize(const swm::math::Size& size);
    const swm::math::Size& getSize() const;
    void setClearColor(const swm::math::Color& color);
    const swm::math::Color& getClearColor() const;
    void setScene(std::shared_ptr<Scene> scene);
    std::shared_ptr<Scene> getScene() const;
    void setCamera(std::shared_ptr<Camera> camera);
    std::shared_ptr<Camera> getCamera() const;
private:
    swm::math::Size m_size;
    swm::math::Color m_clearColor;
    std::shared_ptr<Scene> m_scene;
    std::shared_ptr<Camera> m_camera;
};

}
