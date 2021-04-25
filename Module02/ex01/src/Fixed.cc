//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>

#include <cmath>

#include "includes/Fixed.h"

Fixed::Fixed() : raw_bits_()  {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : raw_bits_(other.raw_bits_) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Assignation operator called" << std::endl;
  if (this == &other)
    return (*this);
  raw_bits_ = other.raw_bits_;
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return raw_bits_;
}

void Fixed::setRawBits(int rawBits) {
  std::cout << "setRawBits member function called" << std::endl;
  raw_bits_ = rawBits;
}


/*
 * Принцип данного типа заключается в фиксированном сдвиге числа на N бит,
 * в результате чего дробное число можно представить целым
 * и оно будет иметь точность 2^N после точки
 * (1 << bits_) -> (1 << 8) -> 256
 * 8388607 - max value int
 */

int Fixed::toInt() const {
  return (raw_bits_ >> bits_);
}

float Fixed::toFloat() const {
  return (static_cast<float>(raw_bits_) / static_cast<float>(1 << bits_));
}

Fixed::Fixed(const float &f_value) {
  std::cout << "Float constructor called" << std::endl;
  raw_bits_ = static_cast<int>(roundf((f_value * (1 << bits_))));
}

Fixed::Fixed(const int &i_value) {
  std::cout << "Int constructor called" << std::endl;
  raw_bits_ = (i_value << bits_);
}

std::ostream  &operator<<(std::ostream &out, Fixed const &value) {
  out << value.toFloat();
  return (out);
}
