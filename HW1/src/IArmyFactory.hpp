//
// Created by 2ToThe10th on 25.04.2021.
//

#ifndef TYPELISTERASE_SRC_IARMYFACTORY_HPP_
#define TYPELISTERASE_SRC_IARMYFACTORY_HPP_

#include <string>
#include <memory>
class Soldier {
 protected:
  explicit Soldier(std::string type);
  std::string type_;
};

class Infantry: Soldier {
 public:
  Infantry();
};

class Archer: Soldier {
 public:
  Archer();
};

class Cavalry: Soldier {
 public:
  Cavalry();
};

class IArmyFactory {
 public:
  template<typename S>
  std::shared_ptr<S> Create() {
    return std::make_shared<S>();
  }
};

#endif //TYPELISTERASE_SRC_IARMYFACTORY_HPP_
