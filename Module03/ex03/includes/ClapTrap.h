//
// Created by Aaron Berry on 4/20/21.
//

#pragma once
#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
 public:
  explicit ClapTrap(const std::string &name);
  ClapTrap();
  virtual ~ClapTrap();
  ClapTrap(ClapTrap const &other);
  ClapTrap                &operator=(ClapTrap const &other);
  virtual void            RangedAttack(std::string const & target);
  virtual void            MeleeAttack(std::string const & target);
  virtual void            TakeDamage(unsigned int amount);
  virtual void            BeRepaired(unsigned int amount);

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

 protected:
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


#endif  // CLAPTRAP_H
