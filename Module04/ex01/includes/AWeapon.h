//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include <string>

class AWeapon {
 public:
  AWeapon(const std::string &name, int apCost, int damage);
  AWeapon(AWeapon const &other);
  virtual ~AWeapon();
  AWeapon           &operator=(AWeapon const &other);
  virtual void      attack() const = 0;
  int               getApCost() const;
  int               getDamage() const;
  const std::string &getName() const;
 private:
  AWeapon();
  std::string       name_;
  int               ap_cost_;
  int               damage_;
};
