//
// Created by 2ToThe10th on 19.05.2021.
//

#include <algorithm>
#include "LongevityManager.h"

bool LongevityManager::is_destroy_started = false;
std::vector<SingletonInfoInterface *>
    LongevityManager::singletons_to_destroy_ = std::vector<SingletonInfoInterface *>();

bool LongevityManager::IsDestroyStarted() {
  return is_destroy_started;
}

void LongevityManager::DestroyAllSingletons() {
  is_destroy_started = true;
  std::sort(singletons_to_destroy_.begin(),
            singletons_to_destroy_.end(),
            [](SingletonInfoInterface *l, SingletonInfoInterface *r) {
              if (l->longevity_ == r->longevity_) {
                return l->id_ > r->id_;
              }
              return l->longevity_ < r->longevity_;
            });
  for (auto *singleton_info: singletons_to_destroy_) {
    singleton_info->DestroySingleton();
    delete singleton_info;
  }
}
