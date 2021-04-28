//
// Created by Aaron Berry on 4/27/21.
//

#pragma once

#include <string>
#include <iostream>

#include "VariableType.h"

class CharType : public VariableType {
 public:
  CharType(double value, bool impossible, const std::string &type,
           double maxValue, double minValue);
  CharType(CharType const &other);
  CharType &operator=(CharType const &other);
  virtual ~CharType();
  void PrintValue() const;
 private:
  void CheckBorderAndNan();
  bool             printable_;
};
