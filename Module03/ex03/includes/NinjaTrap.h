//
// Created by Aaron Berry on 4/20/21.
//

#ifndef NINJATRAP_H
#define NINJATRAP_H

#include <string>
#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

class NinjaTrap : public ClapTrap{
 public:
  explicit NinjaTrap(const std::string &name);
  NinjaTrap();
  virtual ~NinjaTrap();
  NinjaTrap(NinjaTrap const &other);
  NinjaTrap                &operator=(NinjaTrap const &other);
  void                    RangedAttack(std::string const &target);
  void                    MeleeAttack(std::string const &target);
  void                    TakeDamage(unsigned int amount);
  void                    BeRepaired(unsigned int amount);
  void                    ninjaShoeBox(ClapTrap const &target);
  void                    ninjaShoeBox(FragTrap const &target);
  void                    ninjaShoeBox(ScavTrap const &target);
  void                    ninjaShoeBox(NinjaTrap const &target);
};

#endif  // NINJATRAP_H
