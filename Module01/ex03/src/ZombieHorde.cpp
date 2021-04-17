//
// Created by Aaron Berry on 4/17/21.
//

#include "includes/ZombieHorde.hpp"
#include <iostream>

const char ZombieHorde::name_zombie_[10][10] =
          {"ZOMBIE1", "ZOMBIE2", "ZOMBIE3", "ZOMBIE4", "ZOMBIE5",
           "ZOMBIE6", "ZOMBIE7", "ZOMBIE8", "ZOMBIE9", "ZOMBIE10"};

ZombieHorde::ZombieHorde(unsigned int amountZombie) : amount_zombie_(
        amountZombie) {
  if (amount_zombie_ == 0) {
    std::cout << "Error amount Zombies! Set default: 1" << std::endl;
    amount_zombie_ = 1;
  }
  zombies_ = new Zombie[amount_zombie_];

  for (unsigned int i = 0; i < amount_zombie_; ++i) {
    zombies_[i].setType("Sber");
    zombies_[i].setName(name_zombie_[rand() % 10]);
  }
}

ZombieHorde::~ZombieHorde() {
  delete [] zombies_;
}

ZombieHorde::ZombieHorde(const ZombieHorde &other) {
  *this = other;
}

ZombieHorde &ZombieHorde::operator=(const ZombieHorde &other) {
  if (this == &other)
    return *this;
  this->~ZombieHorde();
  amount_zombie_ = other.amount_zombie_;
  zombies_ = new Zombie[amount_zombie_];
  for (unsigned int i = 0; i < amount_zombie_; ++i) {
    zombies_[i] = other.zombies_[i];
  }
  return *this;
}

void ZombieHorde::announce() const {
  for (unsigned int i = 0; i < amount_zombie_; ++i) {
      zombies_[i].announce();
  }
}
