//
// Created by 2ToThe10th on 19.05.2021.
//

#include <stdexcept>
#include "SingletonInfoInterface.h"
#include "LongevityManager.h"

void SingletonInfoInterface::SetLongevity(unsigned int longevity) {
  if (LongevityManager::IsDestroyStarted()) {
    throw std::runtime_error("destroy already started");
  }
  longevity_ = longevity;
}

void SingletonInfoInterface::SetId(size_t id) {
  id_ = id;
}
