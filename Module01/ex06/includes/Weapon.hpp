//
// Created by Aaron Berry on 4/18/21.
//

#pragma once
#ifndef UNNECESSARY_VIOLENCE_WEAPON_HPP
#define UNNECESSARY_VIOLENCE_WEAPON_HPP

#include <string>

class Weapon {
  std::string   type_;

 public:
  Weapon(const Weapon &other);

  Weapon &operator=(const Weapon &other);

  virtual ~Weapon();

  explicit Weapon(const std::string &type);

  const std::string &getType() const;

  void setType(const std::string &type);
};


#endif  // UNNECESSARY_VIOLENCE_WEAPON_HPP
