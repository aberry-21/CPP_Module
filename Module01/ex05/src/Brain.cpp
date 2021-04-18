//
// Created by Aaron Berry on 4/18/21.
//

#include "includes/Brain.hpp"

#include <string>
#include <iostream>
#include <sstream>

Brain::Brain() {}

Brain::Brain(const std::string &owner, short iq) : owner_(owner), iq_(iq) {}

Brain::~Brain() {}

Brain::Brain(const Brain &other) : owner_(other.owner_), iq_(other.iq_) {}

Brain &Brain::operator=(const Brain &other) {
  if (this == &other)
    return *this;
  owner_ = other.owner_;
  iq_ = other.iq_;
  return *this;
}

const std::string &Brain::getOwner() const {
  return owner_;
}

void Brain::setOwner(const std::string &owner) {
  owner_ = owner;
}

short Brain::getIq() const {
  return iq_;
}

void Brain::setIq(short iq) {
  iq_ = iq;
}

std::string Brain::identify() const {
  std::ostringstream address;
  address << (void const *)this;
  return address.str();
}
