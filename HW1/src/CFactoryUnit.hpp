//
// Created by 2ToThe10th on 25.04.2021.
//

#ifndef HW_SRC_CFACTORYUNIT_HPP_
#define HW_SRC_CFACTORYUNIT_HPP_

#include <memory>

class CArmyFactory {
 public:
  template<typename S, template<class T> class Allocator>
  S* Create() {
    Allocator<S> allocator;
    S* soldier = allocator.allocate(1);
    allocator.construct(soldier);
    soldier->setColor("red");
    return soldier;
  }
};

#endif //HW_SRC_CFACTORYUNIT_HPP_
