//
// Created by Aaron Berry on 4/27/21.
//

#include <cmath>

#include "includes/FloatType.h"

void FloatType::CheckBorderAndNan() {
  VariableType::CheckBorderAndNan();
  if (value_ >= std::numeric_limits<double>::infinity() ||
      value_ <= -std::numeric_limits<double>::infinity()) {
    impossible_ = false;
  }
}

FloatType::FloatType(double value, bool impossible, const std::string &type,
                 double maxValue, double minValue) : VariableType(value,
                                                                  impossible,
                                                                  type,
                                                                  maxValue,
                                                                  minValue) {
  this->CheckBorderAndNan();
}

FloatType::~FloatType() {}

FloatType::FloatType(const FloatType &other)
        : VariableType(other) {}

FloatType &FloatType::operator=(const FloatType &other) {
  VariableType::operator=(other);
  return *this;
}

void FloatType::PrintValue() const {
  std::cout << type_ << ": ";
  if (impossible_) {
    std::cout << "impossible";
  } else {
    std::cout << static_cast<float>(value_);
    if ((value_ - floor(value_)) == 0) {
      std::cout << ".0";
    }
    std::cout << 'f';
  }
  std::cout << std::endl;
}

