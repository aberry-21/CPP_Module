//
// Created by Aaron Berry on 4/27/21.
//

#include <cmath>

#include "includes/DoubleType.h"

void DoubleType::CheckBorderAndNan() {
  VariableType::CheckBorderAndNan();
  if (value_ >= std::numeric_limits<double>::infinity()) {
    impossible_ = true;
  }
}

DoubleType::DoubleType(double value, bool impossible, const std::string &type,
                       double maxValue, double minValue)
                     : VariableType(value, impossible, type, maxValue,
                                    minValue) {
  this->CheckBorderAndNan();
}

DoubleType::~DoubleType() {}

DoubleType::DoubleType(const DoubleType &other)
        : VariableType(other) {}

DoubleType &DoubleType::operator=(const DoubleType &other) {
  VariableType::operator=(other);
  return *this;
}

void DoubleType::PrintValue() const {
  std::cout << type_ << ": ";
  if (impossible_) {
    std::cout << "impossible";
  } else {
    std::cout << static_cast<double>(value_);
    if ((value_ - floor(value_)) == 0) {
      std::cout << ".0";
    }
  }
  std::cout << std::endl;
}
