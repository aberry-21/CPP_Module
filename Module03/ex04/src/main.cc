//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>
#include <cstdlib>

#include "includes/SuperTrap.h"
#include "includes/FragTrap.h"
#include "includes/NinjaTrap.h"

static void PrintAttributes(ClapTrap const &obj) {
  std::cout << " HitPoints: " << obj.getHitPoints() << std::endl;
  std::cout << " MaxHitPoints: " << obj.getMaxHitPoints() <<
            std::endl;
  std::cout << " EnergyPoints: " << obj.getEnergyPoints() <<
            std::endl;
  std::cout << " MaxEnergyPoints: " << obj.getMaxEnergyPoints() <<
            std::endl;
  std::cout << " Level: " << obj.getLevel() << std::endl;
  std::cout << " Name: " << obj.getName() << std::endl;
  std::cout << " MeleeAttackDamage: " << obj.getMeleeAttackDamage()
            << std::endl;
  std::cout << " RangedAttackDamage: "
            << obj.getRangedAttackDamage() << std::endl;
  std::cout << " ArmorDamageReduction: "
            << obj.getArmorDamageReduction() << std::endl;
  std::cout << std::endl;
}

int main() {
  srand(time(nullptr));
  SuperTrap   object_super_trap("SuperTrap");
  NinjaTrap   object_ninja_trap("Ninjatrap");
  FragTrap   object_frag_trap("Fragtrap");

  std::cout << "NinjaTrap attributes :" <<std::endl;
  PrintAttributes(object_ninja_trap);
  std::cout << "FragTrap attributes :" <<std::endl;
  PrintAttributes(object_frag_trap);
  std::cout << "SuperTrap attributes :" <<std::endl;
  PrintAttributes(object_super_trap);

  std::cout << "FragTrap and SuperTrap rangedAttack :" <<std::endl;
  object_super_trap.RangedAttack("FragTrap");
  object_frag_trap.RangedAttack("SuperTrap");
  std::cout << std::endl;

  std::cout << "SuperTrap and NinjaTrap meleeAttack :" <<std::endl;
  object_super_trap.MeleeAttack("NinjaTrap");
  object_ninja_trap.MeleeAttack("SuperTrap");
  std::cout << std::endl;

  return (0);
}
