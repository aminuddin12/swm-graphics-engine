#pragma once
#include <string>
#include <cstdint>

namespace swm::graphics {

class EngineVersion {
public:
    static uint32_t getMajor();
    static uint32_t getMinor();
    static uint32_t getPatch();
    static uint32_t getBuild();
    static std::string getGitHash();
    static std::string getVersionString();
};

}
