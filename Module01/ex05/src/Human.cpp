//
// Created by Aaron Berry on 4/18/21.
//

#include "includes/Human.hpp"
#include "includes/Brain.hpp"

Human::Human() :brain_(new Brain("human", 30)) {
}

Human::Human(const Human &other) : brain_(new Brain(*other.brain_)){
}

Human::~Human() {
  delete brain_;
}

Brain const &Human::getBrain() const {
  return *brain_;
}

std::string Human::identify() const {
  return (brain_->identify());
}

Human &Human::operator=(const Human &other) {
  if (this == &other)
    return *this;
  this->~Human();
  brain_ = new Brain(*other.brain_);
  return *this;
}
