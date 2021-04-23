//
// Created by Aaron Berry on 4/22/21.
//

#include <iostream>
#include "includes/PlasmaRifle.h"

PlasmaRifle::PlasmaRifle()
            : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &other)
            : AWeapon(other) {}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &other) {
  if (this == &other)
    return (*this);
  AWeapon::operator=(other);
  return (*this);
}

void PlasmaRifle::attack() const {
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
