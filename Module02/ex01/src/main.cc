//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>

#include "includes/Fixed.h"

int main() {
  Fixed a;
  Fixed b(a);
  Fixed c;
  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  return 0;
}
