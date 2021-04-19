//
// Created by Aaron Berry on 4/19/21.
//

#pragma once
#ifndef FIXED_H
#define FIXED_H


class Fixed {
 public:
  Fixed();
  Fixed(Fixed const &other);
  ~Fixed();
  Fixed &operator=(Fixed const &other);
  int getRawBits() const;
  void setRawBits(int rawBits);
 private:
  int               raw_bits_;
  static const int  bits_ = 8;
};


#endif  // FIXED_H
