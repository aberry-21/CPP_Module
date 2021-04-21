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

  int                      getLevel() const;
  void                     setLevel(int level);

  virtual int             getHitPoints() const;
  virtual void            setHitPoints(int hitPoints);

  virtual int             getEnergyPoints() const;
  virtual void            setEnergyPoints(int energyPoints);


  virtual int             getMeleeAttackDamage() const;
  virtual void            setMeleeAttackDamage(int meleeAttackDamage);

  virtual int             getRangedAttackDamage() const;
  virtual void            setRangedAttackDamage(int rangedAttackDamage);

  virtual int             getArmorDamageReduction() const;
  virtual void            setArmorDamageReduction(int armorDamageReduction);

  virtual int             getMaxEnergyPoints() const;
  virtual void            setMaxEnergyPoints(int maxEnergyPoints);

  virtual int             getMaxHitPoints() const;
  virtual void            setMaxHitPoints(int maxHitPoints);

 protected:
  int                     level_;
  std::string             name_;

 private:
  int                     max_energy_points_;
  int                     max_hit_points_;
  int                     hit_points_;
  int                     energy_points_;
  int                     melee_attack_damage_;
  int                     ranged_attack_damage_;
  int                     armor_damage_reduction_;
};


#endif  // CLAPTRAP_H
