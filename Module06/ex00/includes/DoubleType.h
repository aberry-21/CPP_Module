//
// Created by Aaron Berry on 4/27/21.
//

#pragma once

#include <string>
#include <iostream>

#include "VariableType.h"

class DoubleType : public VariableType{
 public:
  DoubleType(double value, bool impossible, const std::string &type,
             double maxValue, double minValue);
  DoubleType(DoubleType const &other);
  DoubleType &operator=(DoubleType const &other);
  virtual ~DoubleType();
  void PrintValue() const;
 private:
  void CheckBorderAndNan();
};

