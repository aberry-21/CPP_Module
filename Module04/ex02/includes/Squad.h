//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include "ISquad.h"
#include "ISpaceMarine.h"

class Squad : public ISquad {
 public:
  Squad();
  Squad(Squad const &other);
  virtual ~Squad();
  Squad           &operator=(Squad const &other);

  int             getCount() const;
  ISpaceMarine    *getUnit(int index) const;
  int             push(ISpaceMarine *unit);

 private:
  int             size_;
  int             capacity_;
  ISpaceMarine    **units_;
};

