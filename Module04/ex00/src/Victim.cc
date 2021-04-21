//
// Created by Aaron Berry on 4/21/21.
//

#include "iostream"
#include "includes/Victim.h"

Victim::Victim()
      : name_() {}

Victim::~Victim() {
  std::cout << "Victim " << name_ << " just died for no apparent reason!"
            <<std::endl;
}

Victim::Victim(const Victim &other)
      : name_(other.name_) {}

Victim &Victim::operator=(const Victim &other) {
  if (this == &other) {
    return *this;
  }
  name_ = other.name_;
  return *this;
}

Victim::Victim(const std::string &name)
      : name_(name) {
  std::cout << "Some random victim called " << name_
            << " just appeared!" <<std::endl;
}

const std::string &Victim::getName() const {
  return name_;
}

void Victim::setName(const std::string &name) {
  name_ = name;
}

void Victim::getPolymorphed() const {
  std::cout << name_ << " has been turned into a cute little sheep!"
            << std::endl;
}

std::ostream &operator<<(std::ostream &out, Victim const &victim) {
  out << "I'm " << victim.getName() << " and I like otters!" << std::endl;
  return (out);
}
