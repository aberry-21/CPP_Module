//
// Created by Aaron Berry on 4/19/21.
//

#pragma once
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>

class FragTrap {
 public:
  explicit FragTrap(const std::string &name);
  FragTrap();
  virtual ~FragTrap();
  FragTrap(FragTrap const &other);
  FragTrap                &operator=(FragTrap const &other);
  void                    RangedAttack(std::string const & target);
  void                    MeleeAttack(std::string const & target);
  void                    TakeDamage(unsigned int amount);
  void                    BeRepaired(unsigned int amount);
  void                    VaulthunterDotExe(std::string const &target);

  const std::string       &getName() const;
  void                    setName(const std::string &name);

  int                     getHitPoints() const;
  void                    setHitPoints(int hitPoints);

  int                     getEnergyPoints() const;
  void                    setEnergyPoints(int energyPoints);

  int                     getLevel() const;
  void                    setLevel(int level);

  int                     getMeleeAttackDamage() const;
  void                    setMeleeAttackDamage(int meleeAttackDamage);

  int                     getRangedAttackDamage() const;
  void                    setRangedAttackDamage(int rangedAttackDamage);

  int                     getArmorDamageReduction() const;
  void                    setArmorDamageReduction(int armorDamageReduction);

  int                      getMaxEnergyPoints() const;
  void                     setMaxEnergyPoints(int maxEnergyPoints);

  int                      getMaxHitPoints() const;
  void                     setMaxHitPoints(int maxHitPoints);

 private:
  static const char       responses[5][60];
  int                     max_energy_points_;
  int                     max_hit_points_;
  std::string             name_;
  int                     hit_points_;
  int                     energy_points_;
  int                     level_;
  int                     melee_attack_damage_;
  int                     ranged_attack_damage_;
  int                     armor_damage_reduction_;
};


#endif  // FRAGTRAP_H
