//
// Created by Aaron Berry on 4/27/21.
//

#include "includes/CharType.h"
#include <string>
#include <iostream>

void CharType::CheckBorderAndNan() {
  VariableType::CheckBorderAndNan();
  if (value_ != value_) {
    impossible_ = true;
  }
  if (value_ < 32 || value_ > 126) {
    printable_ = false;
  }
}

CharType::CharType(double value, bool impossible, const std::string &type,
                   double maxValue, double minValue) : VariableType(value,
                                                                    impossible,
                                                                    type,
                                                                    maxValue,
                                                                    minValue) {
  printable_ = true;
  this->CheckBorderAndNan();
}

CharType::~CharType() {}

CharType::CharType(const CharType &other)
        : VariableType(other) {}

CharType &CharType::operator=(const CharType &other) {
  VariableType::operator=(other);
  return *this;
}

void CharType::PrintValue() const {
  std::cout << type_ << ": ";
  if (impossible_) {
    std::cout << "impossible";
  } else if (!printable_) {
    std::cout << "Non displayable";
  } else {
    std::cout << "'" << static_cast<char>(value_) << "'";
  }
  std::cout << std::endl;
}
