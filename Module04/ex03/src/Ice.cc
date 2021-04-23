//
// Created by Aaron Berry on 4/23/21.
//

#include <iostream>

#include "includes/Ice.h"

Ice::Ice()
    : AMateria("ice") {}

Ice::Ice(const std::string &type)
    : AMateria(type) {}

Ice::Ice(Ice const &other)
    : AMateria(other) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &other) {
  AMateria::operator=(other);
  return (*this);
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName()
            << " *" << std::endl;
  AMateria::use(target);
}

AMateria    *Ice::clone() const {
  return (new Ice(*this));
}

