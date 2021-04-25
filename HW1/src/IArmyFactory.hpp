//
// Created by 2ToThe10th on 25.04.2021.
//

#ifndef TYPELISTERASE_SRC_IARMYFACTORY_HPP_
#define TYPELISTERASE_SRC_IARMYFACTORY_HPP_

#include <string>
#include <memory>
class Soldier {
 public:
  void setColor(std::string color);
  const std::string& getColor();
 protected:
  explicit Soldier(std::string type);
  std::string type_;
  std::string color_;
};

class Infantry: public Soldier {
 public:
  Infantry();
};

class Archer: public Soldier {
 public:
  Archer();
};

class Cavalry: public Soldier {
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
