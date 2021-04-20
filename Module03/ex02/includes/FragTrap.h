//
// Created by Aaron Berry on 4/19/21.
//

#pragma once
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>
#include "ClapTrap.h"

class FragTrap : public ClapTrap{
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

 private:
  static const char       responses[5][60];
};


#endif  // FRAGTRAP_H
