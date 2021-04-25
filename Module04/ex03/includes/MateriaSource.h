//
// Created by Aaron Berry on 4/23/21.
//

#pragma once

#include <string>
#include <cstdint>

#include "IMateriaSource.h"
#include "AMateria.h"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  MateriaSource(MateriaSource const &other);
  virtual ~MateriaSource();
  MateriaSource   &operator=(MateriaSource const &other);
  void            learnMateria(AMateria *m);
  AMateria        *createMateria(std::string const &type);

 private:
  AMateria    *materias_[4];
};
