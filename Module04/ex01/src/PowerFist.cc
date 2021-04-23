//
// Created by Aaron Berry on 4/22/21.
//

#include <iostream>
#include "includes/PowerFist.h"

PowerFist::PowerFist()
          : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const &other)
          : AWeapon(other) {}

PowerFist::~PowerFist() {}

PowerFist &PowerFist::operator=(PowerFist const &other) {
  if (this == &other)
    return (*this);
  AWeapon::operator=(other);
  return (*this);
}

void PowerFist::attack() const {
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
