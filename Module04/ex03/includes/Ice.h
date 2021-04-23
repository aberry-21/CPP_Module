//
// Created by Aaron Berry on 4/23/21.
//

#pragma once

#include "AMateria.h"

class Ice : public AMateria {
 public:
  Ice();
  explicit Ice(std::string const &type);
  Ice(Ice const &other);
  virtual ~Ice();
  Ice                 &operator=(Ice const &other);
  AMateria*           clone() const;
  void                use(ICharacter &target);
};
