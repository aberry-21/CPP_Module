//
// Created by Aaron Berry on 4/20/21.
//

#pragma once
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>
#include "ClapTrap.h"

class ScavTrap : public ClapTrap{
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

 private:
  static const char       responses[5][60];
};


#endif  // SCAVTRAP_H
