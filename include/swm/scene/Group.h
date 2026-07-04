#pragma once
#include "Node.h"
#include <vector>
#include <memory>

namespace swm::scene {

class Group : public Node {
public:
    Group();
    void addChild(std::shared_ptr<Node> child);
    void removeChild(std::shared_ptr<Node> child);
    const std::vector<std::shared_ptr<Node>>& getChildren() const;
private:
    std::vector<std::shared_ptr<Node>> m_children;
};

}
