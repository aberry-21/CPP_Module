//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>
#include <cstdlib>

#include "includes/SuperTrap.h"

int main() {
  srand(time(nullptr));
  SuperTrap   c11("SuperTrap");
  std::cout << c11.getHitPoints() << std::endl;
  std::cout << c11.getMaxHitPoints() << std::endl;
  std::cout << c11.getEnergyPoints() << std::endl;
  std::cout << c11.getMaxEnergyPoints() << std::endl;
  std::cout << c11.getLevel() << std::endl;
  std::cout << c11.getName() << std::endl;
  std::cout << c11.getMeleeAttackDamage() << std::endl;
  std::cout << c11.getRangedAttackDamage() << std::endl;
  std::cout << c11.getArmorDamageReduction() << std::endl;
  return (0);
}
