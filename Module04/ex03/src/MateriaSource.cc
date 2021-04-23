//
// Created by Aaron Berry on 4/23/21.
//

#include "includes/MateriaSource.h"

MateriaSource::MateriaSource() : materias_() {
  for (int i = 0; i < 4; ++i) {
    materias_[i] = nullptr;
  }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (int i = 0; i < 4; ++i) {
    materias_[i] = other.materias_[i]->clone();
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    delete materias_[i];
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < 4; ++i) {
    delete materias_[i];
  }
  for (int i = 0; i < 4; ++i) {
    if (other.materias_[i]) {
      materias_[i] = other.materias_[i]->clone();
    } else {
      materias_[i] = nullptr;
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  int i = 0;
  while (materias_[i]) {
    ++i;
  }
  if (i < 4 && materias_[i] != m) {
    materias_[i] = m;
  }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < 4; ++i) {
    if (materias_[i] && materias_[i]->getType() == type) {
      return (materias_[i]->clone());
    }
  }
  return nullptr;
}
