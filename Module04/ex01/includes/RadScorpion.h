//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "Enemy.h"

class RadScorpion : public Enemy {
 public:
  RadScorpion();
  RadScorpion(RadScorpion const &other);
  virtual ~RadScorpion();
  RadScorpion &operator=(RadScorpion const &other);
};
