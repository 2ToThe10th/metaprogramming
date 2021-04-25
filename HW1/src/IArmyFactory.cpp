//
// Created by 2ToThe10th on 25.04.2021.
//

#include "IArmyFactory.hpp"

#include <utility>

Soldier::Soldier(std::string type) : type_(std::move(type)) {}

Infantry::Infantry() : Soldier("Infantry") {}

Archer::Archer() : Soldier("Archer") {}

Cavalry::Cavalry() : Soldier("Cavalry") {}
