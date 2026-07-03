#pragma once
#include "../math/Transform.h"
#include <string>
#include <vector>
#include <memory>

namespace swm::graphics {

class Node : public std::enable_shared_from_this<Node> {
public:
    Node();
    virtual ~Node() = default;
    void setTransform(const Transform& transform);
    const Transform& getTransform() const;
    void setParent(std::shared_ptr<Node> parent);
    std::shared_ptr<Node> getParent() const;
private:
    Transform m_transform;
    std::weak_ptr<Node> m_parent;
};

}
