//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>
#include <cstdlib>

#include "includes/FragTrap.h"

int main() {
  srand(time(nullptr));
  FragTrap  object_frag_trap("no name");
  FragTrap  rarity("Rarity");
  FragTrap  pinkie("Pinkie Pie");

  std::cout << "FragTrap attributes :" <<std::endl;
  std::cout << " HitPoints: " << object_frag_trap.getHitPoints() << std::endl;
  std::cout << " MaxHitPoints: " << object_frag_trap.getMaxHitPoints() <<
                                                                    std::endl;
  std::cout << " EnergyPoints: " << object_frag_trap.getEnergyPoints() <<
                                                                    std::endl;
  std::cout << " MaxEnergyPoints: " << object_frag_trap.getMaxEnergyPoints() <<
                                                                    std::endl;
  std::cout << " Level: " << object_frag_trap.getLevel() << std::endl;
  std::cout << " Name: " << object_frag_trap.getName() << std::endl;
  std::cout << " MeleeAttackDamage: " << object_frag_trap.getMeleeAttackDamage()
                                                                   << std::endl;
  std::cout << " RangedAttackDamage: "
            << object_frag_trap.getRangedAttackDamage() << std::endl;
  std::cout << " ArmorDamageReduction: "
            << object_frag_trap.getArmorDamageReduction() << std::endl;

  std::cout << std::endl;
  rarity.RangedAttack(pinkie.getName());
  rarity.MeleeAttack(pinkie.getName());
  pinkie.RangedAttack(pinkie.getName());
  pinkie.MeleeAttack(pinkie.getName());
  std::cout << std::endl;

  std::cout << "rarity attack pinkie (20)" << std::endl;
  pinkie.TakeDamage(20);
  std::cout << "pinkie hit points: " << pinkie.getHitPoints() << std::endl;

  std::cout << "pinkie attack pinkie (50)" << std::endl;
  rarity.TakeDamage(50);
  std::cout << "rarity hit points: " << rarity.getHitPoints() << std::endl;

  std::cout << "pinkie be repaired (2000)" << std::endl;
  pinkie.BeRepaired(2000);
  std::cout << "pinkie hit points: " << pinkie.getHitPoints() << std::endl;

  std::cout << "rarity be repaired (2)" << std::endl;
  rarity.BeRepaired(2);
  std::cout << "rarity hit points: " << rarity.getHitPoints() << std::endl;


  std::cout << "vaulthunterDotExe for (\"Pinkie Pie\")" << std::endl;
  for (int i = 0; i < 5; ++i) {
    rarity.VaulthunterDotExe(pinkie.getName());
  }

  std::cout << "vaulthunterDotExe for (\"Rarity\")" << std::endl;
  for (int i = 0; i < 5; ++i) {
    pinkie.VaulthunterDotExe(rarity.getName());
  }

  return (0);
}
