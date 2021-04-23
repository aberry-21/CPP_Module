//
// Created by Aaron Berry on 4/22/21.
//

#include <iostream>

#include "includes/AssaultTerminator.h"

AssaultTerminator::AssaultTerminator() {
  std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &other) {
  static_cast<void>(other);
}

AssaultTerminator::~AssaultTerminator() {
  std::cout << "I’ll be back..." << std::endl;
}

AssaultTerminator &AssaultTerminator::operator=(
                                              const AssaultTerminator &other) {
  static_cast<void>(other);
  return(*this);
}

ISpaceMarine *AssaultTerminator::clone() const {
  return (new AssaultTerminator(*this));
}

void AssaultTerminator::battleCry() const {
  std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
  std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
  std::cout << "* attacks with chainfists *" << std::endl;
}