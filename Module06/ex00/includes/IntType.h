//
// Created by Aaron Berry on 4/27/21.
//

#pragma once

#include <string>
#include <iostream>

#include "VariableType.h"

class IntType : public VariableType{
 public:
  IntType(double value, bool impossible, const std::string &type,
          double maxValue, double minValue);
  IntType(IntType const &other);
  IntType &operator=(IntType const &other);
  virtual ~IntType();
  void PrintValue() const;
 private:
  void CheckBorderAndNan();
};
