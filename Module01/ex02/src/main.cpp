//
// Created by Aaron Berry on 4/17/21.
//

#include <iostream>
#include "../includes/ZombieEvent.hpp"

int main() {
  ZombieEvent generator_zombie("Sber");
  Zombie      zombie_alone;
  Zombie      *zombie_random;
  Zombie      *zombie_1;
  Zombie      *zombie_2;

  zombie_alone.setName("Bill");
  zombie_alone.setType("Microsoft");

  zombie_random = generator_zombie.newZombie("No name");
  zombie_random->announce();
  delete zombie_random;

  zombie_1 = generator_zombie.randomChump();
  zombie_alone.announce();

  zombie_2 = generator_zombie.newZombie("Gref");
  zombie_2->announce();

  delete zombie_1;
  delete zombie_2;
  return 0;
}
