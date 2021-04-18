//
// Created by Aaron Berry on 4/18/21.
//

#include "includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name_(name) {}

HumanB::~HumanB() {}

const Weapon *HumanB::getWeapon() const {
  return weapon_;
}

void HumanB::setWeapon(const Weapon &weapon) {
  weapon_ = &weapon;
}

const std::string &HumanB::getName() const {
  return name_;
}

void HumanB::attack() const {
  std::cout << "HumanB " << getName() << " attacks with his "
            << getWeapon()->getType() << std::endl;
}
