//
// Created by Aaron Berry on 4/22/21.
//

#include <iostream>

#include "includes/RadScorpion.h"

RadScorpion::RadScorpion()
        : Enemy(80, "RadScorpion") {
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &other)
        : Enemy(other) {
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
  std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &RadScorpion::operator=(RadScorpion const &other) {
  if (this == &other)
    return *this;
  Enemy::operator=(other);
  return *this;
}
