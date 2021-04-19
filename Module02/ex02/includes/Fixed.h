//
// Created by Aaron Berry on 4/19/21.
//

#pragma once
#ifndef FIXED_H
#define FIXED_H

class Fixed {
 public:
  Fixed();
  Fixed(int const &i_value);
  Fixed(float const &f_value);
  Fixed(Fixed const &other);
  ~Fixed();
  Fixed             &operator=(Fixed const &other);
  int               getRawBits() const;
  void              setRawBits(int rawBits);
  int               toInt() const;
  float             toFloat() const;
 private:
  int               raw_bits_;
  static const int  bits_ = 8;
};

std::ostream  &operator<<(std::ostream &out, Fixed const &value);
#endif  // FIXED_H
