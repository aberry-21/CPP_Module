//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "Enemy.h"

class SuperMutant : public Enemy {
 public:
  SuperMutant();
  SuperMutant(SuperMutant const &other);
  virtual ~SuperMutant();
  SuperMutant     &operator=(SuperMutant const &other);
  void            takeDamage(int damage);
};
