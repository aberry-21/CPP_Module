//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "ISpaceMarine.h"

class TacticalMarine : public ISpaceMarine {
 public:
  TacticalMarine();
  TacticalMarine(TacticalMarine const &other);
  virtual ~TacticalMarine();
  TacticalMarine  &operator=(const TacticalMarine &other);

  ISpaceMarine    *clone() const;
  void            battleCry() const;
  void            rangedAttack() const;
  void            meleeAttack() const;
};
