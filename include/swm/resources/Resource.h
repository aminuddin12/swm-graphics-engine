#pragma once
#include <string>

namespace swm::resources {

class Resource {
public:
  virtual ~Resource() noexcept {}
  virtual const std::string &getId() const = 0;
};

} // namespace swm::resources
