//
// Created by Aaron Berry on 4/23/21.
//

#pragma once

#include <string>

#include "AMateria.h"

class IMateriaSource {
 public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(std::string const & type) = 0;
};
