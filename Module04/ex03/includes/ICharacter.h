//
// Created by Aaron Berry on 4/23/21.
//

#pragma once

#include <string>

#include "AMateria.h"

class AMateria;

class ICharacter {
 public:
  virtual ~ICharacter() {}
  virtual std::string const & getName() const = 0;
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, const ICharacter& target) = 0;
};
