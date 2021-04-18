//
// Created by Aaron Berry on 4/18/21.
//

#include "includes/Weapon.hpp"

const std::string &Weapon::getType() const {
  return type_;
}

void Weapon::setType(const std::string &type) {
  type_ = type;
}

Weapon::Weapon(const std::string &type) : type_(type) {}

Weapon::~Weapon() {}

Weapon::Weapon(const Weapon &other) : type_(other.type_) {}

Weapon &Weapon::operator=(const Weapon &other) {
  if (this == &other)
    return *this;
  type_ = other.type_;
  return *this;
}
