#include "../../include/swm/scene/Group.h"
#include <algorithm>

namespace swm::graphics {

Group::Group() {
}

void Group::addChild(std::shared_ptr<Node> child) {
    if (child) {
        child->setParent(shared_from_this());
        m_children.push_back(child);
    }
}

void Group::removeChild(std::shared_ptr<Node> child) {
    if (child) {
        m_children.erase(
            std::remove(m_children.begin(), m_children.end(), child),
            m_children.end()
        );
        child->setParent(nullptr);
    }
}

const std::vector<std::shared_ptr<Node>>& Group::getChildren() const {
    return m_children;
}

}
