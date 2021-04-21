//
// Created by Aaron Berry on 4/20/21.
//

#pragma once
#ifndef SUPERTRAP_H
#define SUPERTRAP_H

#include <string>

#include "includes/FragTrap.h"
#include "includes/ScavTrap.h"
#include "includes/NinjaTrap.h"


class SuperTrap : virtual public FragTrap, virtual public NinjaTrap{
 public:
  explicit SuperTrap(const std::string &name);
  SuperTrap();
  virtual ~SuperTrap();
  SuperTrap(SuperTrap const &other);
  SuperTrap               &operator=(SuperTrap const &other);
  void                    RangedAttack(std::string const &target);
  void                    MeleeAttack(std::string const &target);
  void                    TakeDamage(unsigned int amount);
  void                    BeRepaired(unsigned int amount);

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


#endif  // SUPERTRAP_H
