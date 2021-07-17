//
// Created by 2ToThe10th on 19.05.2021.
//

#ifndef SINGLETON__SINGLETONINFOINTERFACE_H_
#define SINGLETON__SINGLETONINFOINTERFACE_H_

class SingletonInfoInterface {
 public:
  friend class LongevityManager;

  void SetLongevity(unsigned longevity);

  virtual ~SingletonInfoInterface() = default;

 protected:
  virtual void DestroySingleton() = 0;

 private:
  unsigned longevity_ = 0;
  size_t id_ = 0;

 private:
  void SetId(size_t id);
};

#endif //SINGLETON__SINGLETONINFOINTERFACE_H_
