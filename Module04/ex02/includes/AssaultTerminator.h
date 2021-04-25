//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "ISpaceMarine.h"

class AssaultTerminator : public ISpaceMarine {
 public:
  AssaultTerminator();
  AssaultTerminator(AssaultTerminator const &other);
  virtual ~AssaultTerminator();
  AssaultTerminator  &operator=(const AssaultTerminator &other);

  ISpaceMarine    *clone() const;
  void            battleCry() const;
  void            rangedAttack() const;
  void            meleeAttack() const;
};
