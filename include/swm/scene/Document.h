#pragma once
#include <memory>
#include <vector>
#include <string>

namespace swm::scene {

class Stage;

class Document {
public:
    Document() = default;
    
    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }

    void addStage(std::shared_ptr<Stage> stage) { m_stages.push_back(stage); }
    const std::vector<std::shared_ptr<Stage>>& getStages() const { return m_stages; }

private:
    std::string m_name;
    std::vector<std::shared_ptr<Stage>> m_stages;
};

} // namespace swm::scene
