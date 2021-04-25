//
// Created by Aaron Berry on 4/23/21.
//

#pragma once

#include <string>

#include "AMateria.h"

class Cure : public AMateria {
 public:
  Cure();
  explicit Cure(std::string const &type);
  Cure(Cure const &other);
  virtual ~Cure();
  Cure                 &operator=(Cure const &other);
  AMateria*           clone() const;
  void                use(const ICharacter &target);
};
