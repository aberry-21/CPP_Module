//
// Created by Aaron Berry on 4/18/21.
//

#pragma once
#ifndef UNNECESSARY_VIOLENCE_HUMANB_HPP
#define UNNECESSARY_VIOLENCE_HUMANB_HPP

#include <string>
#include "includes/Weapon.hpp"

class HumanB {
  std::string   name_;
  const Weapon  *weapon_;

 public:
  explicit HumanB(const std::string &name);

  virtual ~HumanB();

  const Weapon *getWeapon() const;

  void setWeapon(const Weapon &weapon);

  const std::string &getName() const;

  void attack() const;
};

#endif  // UNNECESSARY_VIOLENCE_HUMANB_HPP
