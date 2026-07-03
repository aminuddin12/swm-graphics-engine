#pragma once
#include "Group.h"

namespace swm::graphics {

class Layer : public Group {
public:
    Layer();
    void setOpacity(float opacity);
    float getOpacity() const;
    void setVisible(bool visible);
    bool isVisible() const;
private:
    float m_opacity{1.0f};
    bool m_visible{true};
};

}
