//
// Created by Aaron Berry on 4/23/21.
//

#include <iostream>

#include "includes/Cure.h"

Cure::Cure()
      : AMateria("cure") {}

Cure::Cure(const std::string &type)
      : AMateria(type) {}

Cure::Cure(Cure const &other)
      : AMateria(other) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &other) {
  AMateria::operator=(other);
  return (*this);
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
  AMateria::use(target);
}

AMateria    *Cure::clone() const {
  return (new Cure(*this));
}
