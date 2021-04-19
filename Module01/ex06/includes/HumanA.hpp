//
// Created by Aaron Berry on 4/18/21.
//

#pragma once
#ifndef UNNECESSARY_VIOLENCE_HUMANA_HPP
#define UNNECESSARY_VIOLENCE_HUMANA_HPP

#include <string>
#include "includes/Weapon.hpp"

class HumanA {
  std::string   name_;
  const Weapon  &weapon_;

 public:
  HumanA(const std::string &name, const Weapon &weapon);

  virtual ~HumanA();

  const std::string &getName() const;

  const Weapon &getWeapon() const;

  void attack() const;
};


#endif  // UNNECESSARY_VIOLENCE_HUMANA_HPP
