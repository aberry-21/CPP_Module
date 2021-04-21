//
// Created by Aaron Berry on 4/21/21.
//

#include "includes/Sorcerer.h"
#include "iostream"

Sorcerer::Sorcerer()
        : name_(), title_() {}

Sorcerer::~Sorcerer() {
  std::cout << name_ << ", " << title_
            << ", is dead. Consequences will never be the same!" <<std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &other)
        : name_(other.name_), title_(other.title_) {}

Sorcerer &Sorcerer::operator=(const Sorcerer &other) {
  if (this == &other) {
    return *this;
  }
  name_ = other.name_;
  title_ = other.title_;
  return *this;
}

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
        : name_(name), title_(title) {
  std::cout << name_ << ", " << title_ << ", is born!" <<std::endl;
}

const std::string &Sorcerer::getName() const {
  return name_;
}

void Sorcerer::setName(const std::string &name) {
  name_ = name;
}

const std::string &Sorcerer::getTitle() const {
  return title_;
}

void Sorcerer::setTitle(const std::string &title) {
  title_ = title;
}

std::ostream &operator<<(std::ostream &out, Sorcerer const &sorcerer) {
  out << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle()
      << ", and I like ponies!" << std::endl;
  return (out);
}

void Sorcerer::Polymorph(const Victim &victim) const {
  victim.getPolymorphed();
}
