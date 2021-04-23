//
// Created by Aaron Berry on 4/22/21.
//

#include "includes/AWeapon.h"

AWeapon::AWeapon()
        : name_(),
          ap_cost_(),
          damage_() {}

AWeapon::AWeapon(const std::string &name, int apCost, int damage)
        : name_(name),
          ap_cost_(apCost),
          damage_(damage) {}

AWeapon::AWeapon(const AWeapon &other)
        : name_(other.name_),
          ap_cost_(other.damage_),
          damage_(other.ap_cost_) {}

AWeapon::~AWeapon() {}

AWeapon &AWeapon::operator=(const AWeapon &other) {
  if (this == &other)
    return *this;
  name_ = other.name_;
  damage_ = other.damage_;
  ap_cost_ = other.ap_cost_;
  return *this;
}

int AWeapon::getDamage() const {
  return damage_;
}

int AWeapon::getApCost() const {
  return ap_cost_;
}

const std::string &AWeapon::getName() const {
  return name_;
}
