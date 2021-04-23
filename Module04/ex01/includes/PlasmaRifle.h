//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "AWeapon.h"

class PlasmaRifle : public AWeapon {
 public:
  PlasmaRifle();
  PlasmaRifle(PlasmaRifle const &other);
  virtual ~PlasmaRifle();
  PlasmaRifle     &operator=(PlasmaRifle const &other);
  void            attack() const;
};
