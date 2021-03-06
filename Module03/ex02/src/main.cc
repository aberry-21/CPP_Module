//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>
#include <cstdlib>

#include "includes/FragTrap.h"
#include "includes/ScavTrap.h"

int main() {
  srand(time(nullptr));
  FragTrap *rarity = new FragTrap("Rarity");
  ScavTrap *pinkie = new ScavTrap("Pinkie Pie");

  std::cout << std::endl;
  rarity->RangedAttack(pinkie->getName());
  rarity->MeleeAttack(pinkie->getName());
  pinkie->RangedAttack(pinkie->getName());
  pinkie->MeleeAttack(pinkie->getName());
  std::cout << std::endl;

  std::cout << "rarity attack pinkie (20)" << std::endl;
  pinkie->TakeDamage(20);
  std::cout << "pinkie hit points: " << pinkie->getHitPoints() << std::endl;

  std::cout << "pinkie attack pinkie (50)" << std::endl;
  rarity->TakeDamage(50);
  std::cout << "rarity hit points: " << rarity->getHitPoints() << std::endl;

  std::cout << "pinkie be repaired (2000)" << std::endl;
  pinkie->BeRepaired(2000);
  std::cout << "pinkie hit points: " << pinkie->getHitPoints() << std::endl;

  std::cout << "rarity be repaired (2)" << std::endl;
  rarity->BeRepaired(2);
  std::cout << "rarity hit points: " << rarity->getHitPoints() << std::endl;


  std::cout << "vaulthunterDotExe for (\"Pinkie Pie\")" << std::endl;
  for (int i = 0; i < 5; ++i) {
    rarity->VaulthunterDotExe(pinkie->getName());
  }

  std::cout << "vaulthunterDotExe for (\"Rarity\")" << std::endl;
  for (int i = 0; i < 5; ++i) {
    pinkie->ChallengeNewcomer(rarity->getName());
  }

  delete rarity;
  delete pinkie;
  return (0);
}
