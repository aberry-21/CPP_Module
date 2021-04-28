//
// Created by Aaron Berry on 4/27/21.
//

#pragma once

#include <string>
#include <iostream>

#include "VariableType.h"

class FloatType : public VariableType{
 public:
  FloatType(double value, bool impossible, const std::string &type,
            double maxValue, double minValue);
  FloatType(FloatType const &other);
  FloatType &operator=(FloatType const &other);
  virtual ~FloatType();
  void PrintValue() const;
 private:
  void CheckBorderAndNan();
};
