#pragma once
#include <string>

namespace swm::graphics {

class Resource {
public:
  virtual ~Resource();
  noexcept = default;
  virtual const std::string &getId() const = 0;
};

} // namespace swm::graphics
