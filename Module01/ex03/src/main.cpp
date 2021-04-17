//
// Created by Aaron Berry on 4/17/21.
//

#include <iostream>
#include <string>

#include "includes/ZombieHorde.hpp"

int main() {
  ZombieHorde *horde;

  std::cout << "Amount zombies = 0:" << std::endl;
  horde = new ZombieHorde(0);
  horde->announce();
  delete horde;

  std::cout << std::endl;

  std::cout << "Amount zombies = 10:" << std::endl;
  horde = new ZombieHorde(10);
  horde->announce();
  delete horde;

  std::cout << std::endl;

  std::cout << "Amount zombies = 100:" << std::endl;
  horde = new ZombieHorde(100);
  horde->announce();
  delete horde;

  std::cout << std::endl;
  return 0;
}
