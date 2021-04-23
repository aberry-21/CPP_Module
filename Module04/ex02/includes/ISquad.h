//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "ISpaceMarine.h"

class ISquad {
 public:
  virtual ~ISquad() {}
  virtual int getCount() const = 0;
  virtual ISpaceMarine* getUnit(int) const = 0;
  virtual int push(ISpaceMarine*) = 0;
};
