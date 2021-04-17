//
// Created by Aaron Berry on 4/17/21.
//

#include "../includes/Zombie.hpp"
#include <iostream>


Zombie::Zombie() {}

Zombie::Zombie(const std::string &name, const std::string &type)
: name_(name), type_(type) {}

Zombie::~Zombie() {}

Zombie &Zombie::operator=(const Zombie &other) {
  if (this == &other)
    return *this;
  name_ = other.name_;
  type_ = other.type_;
  return *this;
}

Zombie::Zombie(const Zombie &other) : name_(other.name_),
                                      type_(other.type_) {}

const std::string &Zombie::getName() const {
  return name_;
}

void Zombie::setName(const std::string &name) {
  name_ = name;
}

const std::string &Zombie::getType() const {
  return type_;
}

void Zombie::setType(const std::string &type) {
  type_ = type;
}

void Zombie::announce() const {
  std::cout << "<" << getName() <<
                  " (" << getType() << ")> Braiiiiiiinnnssss ..." << std::endl;
}
