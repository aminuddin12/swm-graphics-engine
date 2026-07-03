#include "../../include/swm/scene/Node.h"

namespace swm::graphics {

Node::Node() {
}

void Node::setTransform(const Transform& transform) {
    m_transform = transform;
}

const Transform& Node::getTransform() const {
    return m_transform;
}

void Node::setParent(std::shared_ptr<Node> parent) {
    m_parent = parent;
}

std::shared_ptr<Node> Node::getParent() const {
    return m_parent.lock();
}

}
