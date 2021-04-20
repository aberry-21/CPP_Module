//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>
#include <cstdlib>

#include "includes/FragTrap.h"
#include "includes/ScavTrap.h"
#include "includes/NinjaTrap.h"

int main() {
  srand(time(nullptr));
  FragTrap *rarity = new FragTrap("Rarity");
  ScavTrap *pinkie = new ScavTrap("Pinkie Pie");
  NinjaTrap *rainbow_dash = new NinjaTrap("Rainbow Dash");
  ClapTrap *no_name = new ClapTrap("NO NAME");

  std::cout << std::endl;
  rarity->RangedAttack(pinkie->getName());
  rarity->MeleeAttack(pinkie->getName());
  pinkie->RangedAttack(pinkie->getName());
  pinkie->MeleeAttack(pinkie->getName());
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "rarity attack pinkie (20)" << std::endl;
  pinkie->TakeDamage(20);
  std::cout << "pinkie hit points: " << pinkie->getHitPoints() << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "pinkie attack rarity (50)" << std::endl;
  rarity->TakeDamage(50);
  std::cout << "rarity hit points: " << rarity->getHitPoints() << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "pinkie attack rainbow_dash (50)" << std::endl;
  rainbow_dash->TakeDamage(50);
  std::cout << "rainbow_dash hit points: "
                                << rainbow_dash->getHitPoints() << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "pinkie be repaired (2000)" << std::endl;
  pinkie->BeRepaired(2000);
  std::cout << "pinkie hit points: " << pinkie->getHitPoints() << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "rarity be repaired (2)" << std::endl;
  rarity->BeRepaired(2);
  std::cout << "rarity hit points: " << rarity->getHitPoints() << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "rainbow_dash be repaired (2)" << std::endl;
  rainbow_dash->BeRepaired(2);
  std::cout << "rainbow_dash hit points: "
                                  << rainbow_dash->getHitPoints() << std::endl;
  std::cout << std::endl;

  std::cout << "vaulthunterDotExe for (\"Pinkie Pie\")" << std::endl;
  for (int i = 0; i < 5; ++i) {
    rarity->VaulthunterDotExe(pinkie->getName());
  }

  std::cout << "vaulthunterDotExe for (\"Rarity\")" << std::endl;
  for (int i = 0; i < 5; ++i) {
    pinkie->ChallengeNewcomer(rarity->getName());
  }

  rainbow_dash->ninjaShoeBox(*pinkie);
  rainbow_dash->ninjaShoeBox(*rainbow_dash);
  rainbow_dash->ninjaShoeBox(*rarity);
  rainbow_dash->ninjaShoeBox(*no_name);

  delete rarity;
  delete pinkie;
  delete rainbow_dash;
  delete no_name;
  return (0);
}
