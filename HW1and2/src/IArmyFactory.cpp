//
// Created by 2ToThe10th on 25.04.2021.
//

#include "IArmyFactory.hpp"

#include <utility>

Soldier::Soldier(std::string type) : type_(std::move(type)) {}

void Soldier::setColor(std::string color) {
  color_ = std::move(color);
}
const std::string &Soldier::getColor() {
  return color_;
}

Infantry::Infantry() : Soldier("Infantry") {}

Archer::Archer() : Soldier("Archer") {}

Cavalry::Cavalry() : Soldier("Cavalry") {}
