#pragma once
#include <memory>
#include <vector>
#include <string>

namespace swm::scene {

class Canvas;

class Stage {
public:
    Stage() = default;

    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }

    void addCanvas(std::shared_ptr<Canvas> canvas) { m_canvases.push_back(canvas); }
    const std::vector<std::shared_ptr<Canvas>>& getCanvases() const { return m_canvases; }

private:
    std::string m_name;
    std::vector<std::shared_ptr<Canvas>> m_canvases;
};

} // namespace swm::scene
