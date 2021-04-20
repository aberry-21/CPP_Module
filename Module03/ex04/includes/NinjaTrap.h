//
// Created by Aaron Berry on 4/20/21.
//

#ifndef NINJATRAP_H
#define NINJATRAP_H

#include <string>
#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

class NinjaTrap : virtual public ClapTrap{
 public:
  explicit NinjaTrap(const std::string &name);
  NinjaTrap();
  virtual ~NinjaTrap();
  NinjaTrap(NinjaTrap const &other);
  NinjaTrap               &operator=(NinjaTrap const &other);
  void                    RangedAttack(std::string const &target);
  void                    MeleeAttack(std::string const &target);
  void                    TakeDamage(unsigned int amount);
  void                    BeRepaired(unsigned int amount);
  void                    ninjaShoeBox(ClapTrap const &target);
  void                    ninjaShoeBox(FragTrap const &target);
  void                    ninjaShoeBox(ScavTrap const &target);
  void                    ninjaShoeBox(NinjaTrap const &target);

  int                     getHitPoints() const;
  void                    setHitPoints(int hitPoints);

  int                     getEnergyPoints() const;
  void                    setEnergyPoints(int energyPoints);

  int                     getMeleeAttackDamage() const;
  void                    setMeleeAttackDamage(int meleeAttackDamage);

  int                     getRangedAttackDamage() const;
  void                    setRangedAttackDamage(int rangedAttackDamage);

  int                     getArmorDamageReduction() const;
  void                    setArmorDamageReduction(int armorDamageReduction);

  int                     getMaxEnergyPoints() const;
  void                    setMaxEnergyPoints(int maxEnergyPoints);

  int                     getMaxHitPoints() const;
  void                    setMaxHitPoints(int maxHitPoints);

 private:
  int                     max_energy_points_;
  int                     max_hit_points_;
  int                     hit_points_;
  int                     energy_points_;
  int                     melee_attack_damage_;
  int                     ranged_attack_damage_;
  int                     armor_damage_reduction_;
};

#endif  // NINJATRAP_H
