//
// Created by Aaron Berry on 4/27/21.
//

#include "includes/VariableType.h"

VariableType::VariableType(double value, bool impossible,
                           const std::string &type,
                           double maxValue, double minValue)
              : value_(value), impossible_(impossible),
              type_(type), max_value_(maxValue),
              min_value_(minValue) {}

VariableType::VariableType(const VariableType &other)
              : value_(other.value_), impossible_(other.impossible_),
              type_(other.type_), max_value_(other.max_value_),
              min_value_(other.min_value_) {}

VariableType &VariableType::operator=(const VariableType &other) {
  if (this == &other) {
    return *this;
  }
  value_ = other.value_;
  impossible_ = other.impossible_;
  type_ = other.type_;
  max_value_ = other.max_value_;
  min_value_ = other.min_value_;
  return *this;
}

VariableType::~VariableType() {}

void VariableType::setImpossible(bool impossible) {
  impossible_ = impossible;
}

VariableType::VariableType() {}

bool VariableType::isImpossible() const {
  return impossible_;
}

void VariableType::CheckBorderAndNan() {
  if (value_ > max_value_ || value_ < min_value_) {
    impossible_ = true;
  }
}
