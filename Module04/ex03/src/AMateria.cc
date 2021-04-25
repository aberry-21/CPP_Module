//
// Created by Aaron Berry on 4/23/21.
//

#include "includes/AMateria.h"

AMateria::AMateria(const std::string &type)
          : type_(type),
            xp_(0) {}

AMateria::AMateria(const AMateria &other)
          : type_(other.type_),
            xp_(other.xp_) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other) {
  if (this == &other) {
    return *this;
  }
  type_ = other.type_;
  xp_ = other.xp_;
  return *this;
}

const std::string &AMateria::getType() const {
  return type_;
}

uint32_t AMateria::getXp() const {
  return xp_;
}

void AMateria::use(const ICharacter &target) {
  static_cast<void>(target);
  xp_ += 10;
}
