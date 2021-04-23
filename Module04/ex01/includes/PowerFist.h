//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "AWeapon.h"

class PowerFist : public AWeapon {
 public:
  PowerFist();
  PowerFist(PowerFist const &other);
  virtual ~PowerFist();
  PowerFist     &operator=(PowerFist const &other);
  void          attack() const;
};
