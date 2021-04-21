//
// Created by Aaron Berry on 4/21/21.
//

#pragma once

#include <string>
#include "Victim.h"

class Sorcerer {
 public:
  Sorcerer(const std::string &name, const std::string &title);
  Sorcerer(Sorcerer const &other);
  virtual ~Sorcerer();
  Sorcerer          &operator=(Sorcerer const &other);
  void              Polymorph(Victim const &victim) const;

  const std::string &getName() const;
  void              setName(const std::string &name);

  const std::string &getTitle() const;
  void              setTitle(const std::string &title);

 private:
  Sorcerer();
  std::string       name_;
  std::string       title_;
};

std::ostream      &operator<<(std::ostream &out, Sorcerer const &sorcerer);
