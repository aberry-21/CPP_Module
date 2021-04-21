//
// Created by Aaron Berry on 4/20/21.
//

#pragma once
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>
#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap{
 public:
  explicit ScavTrap(const std::string &name);
  ScavTrap();
  virtual ~ScavTrap();
  ScavTrap(ScavTrap const &other);
  ScavTrap                &operator=(ScavTrap const &other);
  void                    RangedAttack(std::string const & target);
  void                    MeleeAttack(std::string const & target);
  void                    TakeDamage(unsigned int amount);
  void                    BeRepaired(unsigned int amount);
  void                    ChallengeNewcomer(std::string const &target);

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
  static const char       responses[5][60];
  int                     max_energy_points_;
  int                     max_hit_points_;
  int                     hit_points_;
  int                     energy_points_;
  int                     melee_attack_damage_;
  int                     ranged_attack_damage_;
  int                     armor_damage_reduction_;
};


#endif  // SCAVTRAP_H
