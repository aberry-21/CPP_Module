//
// Created by Aaron Berry on 4/22/21.
//

#include "includes/TacticalMarine.h"
#include <iostream>

TacticalMarine::TacticalMarine() {
  std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &other) {
  static_cast<void>(other);
}

TacticalMarine::~TacticalMarine() {
  std::cout << "Aaargh..." << std::endl;
}

TacticalMarine &TacticalMarine::operator=(const TacticalMarine &other) {
  static_cast<void>(other);
  return *this;
}

ISpaceMarine *TacticalMarine::clone() const {
  return (new TacticalMarine(*this));
}

void TacticalMarine::battleCry() const {
  std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const {
  std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const {
  std::cout << "* attacks with a chainsword *" << std::endl;
}
