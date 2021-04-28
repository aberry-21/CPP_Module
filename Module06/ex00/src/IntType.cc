//
// Created by Aaron Berry on 4/27/21.
//

#include "includes/IntType.h"

void IntType::CheckBorderAndNan() {
  VariableType::CheckBorderAndNan();
  if (value_ != value_) {
    impossible_ = true;
  }
}

IntType::IntType(double value, bool impossible, const std::string &type,
                   double maxValue, double minValue) : VariableType(value,
                                                                    impossible,
                                                                    type,
                                                                    maxValue,
                                                                    minValue) {
  this->CheckBorderAndNan();
}

IntType::~IntType() {}

IntType::IntType(const IntType &other)
        : VariableType(other) {}

IntType &IntType::operator=(const IntType &other) {
  VariableType::operator=(other);
  return *this;
}

void IntType::PrintValue() const {
  std::cout << type_ << ": ";
  if (impossible_) {
    std::cout << "impossible";
  } else {
    std::cout << static_cast<int>(value_);
  }
  std::cout << std::endl;
}
