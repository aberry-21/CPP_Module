//
// Created by Aaron Berry on 4/22/21.
//

#include <iostream>

#include "includes/SuperMutant.h"

SuperMutant::SuperMutant()
            : Enemy(170, "Super Mutant") {
  std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &other)
            : Enemy(other) {
  std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant() {
  std::cout << "Aaargh..." << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &other) {
  if (this == &other)
    return *this;
  Enemy::operator=(other);
  return *this;
}

void    SuperMutant::takeDamage(int damage) {
  Enemy::takeDamage(damage - 3);
}
