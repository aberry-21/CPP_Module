//
// Created by Aaron Berry on 4/27/21.
//

#pragma once

#include <string>
#include <iostream>

class VariableType {
 public:
  VariableType(double value, bool impossible, const std::string &type,
               double maxValue, double minValue);
  VariableType(VariableType const &other);
  VariableType &operator=(VariableType const &other);
  virtual ~VariableType();
  virtual void PrintValue() const = 0;
  virtual void CheckBorderAndNan();
  void setImpossible(bool impossible);
  bool isImpossible() const;

 protected:
  double           value_;
  bool             impossible_;
  std::string      type_;
  double           max_value_;
  double           min_value_;
 private:
  VariableType();
};
