#pragma once
#include "../math/Size.h"
#include "../math/Color.h"
#include <memory>

namespace swm::graphics {

class Scene;
class Camera;

class Canvas {
public:
    Canvas();
    void setSize(const Size& size);
    const Size& getSize() const;
    void setClearColor(const Color& color);
    const Color& getClearColor() const;
    void setScene(std::shared_ptr<Scene> scene);
    std::shared_ptr<Scene> getScene() const;
    void setCamera(std::shared_ptr<Camera> camera);
    std::shared_ptr<Camera> getCamera() const;
private:
    Size m_size;
    Color m_clearColor;
    std::shared_ptr<Scene> m_scene;
    std::shared_ptr<Camera> m_camera;
};

}
