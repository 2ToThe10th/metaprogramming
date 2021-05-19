//
// Created by 2ToThe10th on 19.05.2021.
//

#ifndef SINGLETON__SINGLETONHANDLER_HPP_
#define SINGLETON__SINGLETONHANDLER_HPP_
#include <stdexcept>
#include "SingletonInfoInterface.h"
#include "LongevityManager.h"

template<typename T>
class SingletonInfo;

template<typename T>
class SingletonHandler {
 public:
  SingletonHandler() = delete;
  ~SingletonHandler() = delete;
  SingletonHandler(const SingletonHandler &) = delete;
  SingletonHandler &operator=(const SingletonHandler &) = delete;

  static T &Instance() {
    if (!instance) {
      if (is_destroy) {
        OnDeadReferences();
      } else {
        if (!info) {
          info = new SingletonInfo<T>();
        }
        LongevityManager::AppendToDestroyQueue<T>(info);
        instance = new T();
      }
    }
    return *instance;
  }

  static void SetLongevity(unsigned longevity) {
    if (!info) {
      info = new SingletonInfo<T>();
    }
    info->SetLongevity(longevity);
  }

  friend class SingletonInfo<T>;

 private:
  static void Destroy() {
    if (instance) {
      is_destroy = true;
      delete instance;
    }
  }

  static void OnDeadReferences() {
    throw std::runtime_error("singleton deleted already");
  }

 private:
  static T *instance;
  static SingletonInfo<T> *info;
  static bool is_destroy;
};

template<typename T>
T *SingletonHandler<T>::instance = nullptr;

template<typename T>
SingletonInfo<T> *SingletonHandler<T>::info = nullptr;

template<typename T>
bool SingletonHandler<T>::is_destroy = false;

template<typename T>
class SingletonInfo : public SingletonInfoInterface {
 public:
  explicit SingletonInfo() : SingletonInfoInterface() {}
 private:

  void DestroySingleton() override {
    SingletonHandler<T>::Destroy();
  }
};

#endif //SINGLETON__SINGLETONHANDLER_HPP_
