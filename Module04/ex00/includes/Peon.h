//
// Created by Aaron Berry on 4/21/21.
//

#pragma once

#include <string>
#include "Victim.h"

class Peon : public Victim {
 public:
  explicit Peon(const std::string &name);
  Peon(Peon const &other);
  virtual ~Peon();
  Peon &operator=(Peon const &other);
  void getPolymorphed() const;

 private:
  Peon();
};
