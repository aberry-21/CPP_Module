//
// Created by Aaron Berry on 4/17/21.
//

#pragma once
#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <string>

#include "Zombie.hpp"

class ZombieHorde {
  unsigned int              amount_zombie_;
  Zombie                    *zombies_;
  static const char         name_zombie_[10][10];
 public:
  explicit ZombieHorde(unsigned int amountZombie);

  virtual ~ZombieHorde();

  ZombieHorde& operator=(const ZombieHorde &other);

  ZombieHorde(const ZombieHorde &other);

  void announce() const;
};

#endif  // ZOMBIEHORDE_HPP
