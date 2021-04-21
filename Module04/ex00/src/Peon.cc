//
// Created by Aaron Berry on 4/21/21.
//

#include "iostream"
#include "includes/Peon.h"
#include "includes/Victim.h"

Peon::Peon()
    : Victim() {}

Peon::~Peon() {
  std::cout << "Bleuark ..." << std::endl;
}

Peon::Peon(const Peon &other)
    : Victim(other) {}

Peon &Peon::operator=(const Peon &other) {
  if (this == &other) {
    return *this;
  }
  Victim::setName(other.getName());
  return *this;
}

Peon::Peon(const std::string &name)
    : Victim(name) {
  std::cout << "Zog zog." << std::endl;
}

void Peon::getPolymorphed() const {
  std::cout << Victim::getName() << " has been turned into a pink pony!"
            << std::endl;
}
