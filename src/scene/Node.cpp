#include "swm/scene/Node.h"

namespace swm::scene {

Node::Node() {
}

void Node::setTransform(const swm::math::Transform& transform) {
    m_transform = transform;
}

const swm::math::Transform& Node::getTransform() const {
    return m_transform;
}

void Node::setParent(std::shared_ptr<Node> parent) {
    m_parent = parent;
}

std::shared_ptr<Node> Node::getParent() const {
    return m_parent.lock();
}

}
