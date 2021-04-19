//
// Created by Aaron Berry on 4/18/21.
//

#include "includes/HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, const Weapon &weapon) : name_(name),
                                                          weapon_(weapon) {}

HumanA::~HumanA() {}

const std::string &HumanA::getName() const {
  return name_;
}

const Weapon &HumanA::getWeapon() const {
  return weapon_;
}

void HumanA::attack() const {
  std::cout << "HumanA " << getName() << " attacks with his "
            << getWeapon().getType() << std::endl;
}
