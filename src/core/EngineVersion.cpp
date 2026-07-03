#include "../../include/swm/EngineVersion.h"

namespace swm::graphics {

uint32_t EngineVersion::getMajor() {
    return 1;
}

uint32_t EngineVersion::getMinor() {
    return 0;
}

uint32_t EngineVersion::getPatch() {
    return 0;
}

uint32_t EngineVersion::getBuild() {
    return 100;
}

std::string EngineVersion::getGitHash() {
    return "abcdef0123456789";
}

std::string EngineVersion::getVersionString() {
    return "1.0.0.100";
}

}
