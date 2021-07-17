//
// Created by 2ToThe10th on 19.05.2021.
//

#ifndef SINGLETON__LONGEVITYMANAGER_H_
#define SINGLETON__LONGEVITYMANAGER_H_

#include <vector>
#include <cstdlib>

#include "SingletonInfoInterface.h"

class LongevityManager {
 public:
  template<typename T>
  static SingletonInfoInterface* AppendToDestroyQueue(SingletonInfoInterface* singleton_info) {
    if (singletons_to_destroy_.empty()) {
      atexit(LongevityManager::DestroyAllSingletons);
    }
    singleton_info->SetId(singletons_to_destroy_.size());
    singletons_to_destroy_.push_back(singleton_info);
    return singleton_info;
  }

  static bool IsDestroyStarted();
 private:
  static bool is_destroy_started;

  static void DestroyAllSingletons();

  static std::vector<SingletonInfoInterface*> singletons_to_destroy_;
};

#endif //SINGLETON__LONGEVITYMANAGER_H_
