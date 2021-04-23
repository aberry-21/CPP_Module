//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "AWeapon.h"
#include "Enemy.h"
#include <string>

class Character {
 public:
  explicit Character(const std::string &name);
  Character(Character const &other);
  virtual ~Character();
  Character           &operator=(Character const &other);

  const std::string   &getName() const;
  int                 getAp() const;
  AWeapon             *getWeapon() const;

  void                recoverAP();
  void                equip(AWeapon *weapon);
  void                attack(Enemy *enemy);

 private:
  Character();
  std::string     name_;
  int             ap_;
  AWeapon         *weapon_;
};

std::ostream    &operator<<(std::ostream &out, Character const &character);
