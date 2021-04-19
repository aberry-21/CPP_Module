//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>

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
