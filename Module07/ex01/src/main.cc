//
// Created by Aaron Berry on 4/21/21.
//

#include <string>
#include <iostream>

#include "includes/Iter.h"

int main() {
  int array_int[2] = {2, 1};
  float array_float[2] = {2.3f, 1.33f};
  double array_double[2] = {2.2, 1.1};
  char array_char[2] = {'s', 'c'};
  bool array_bool[2] = {true, false};
  std::string array_string[2] = {"some string", "sssstring"};
  std::cout << "__________int__________" << std::endl;
  iter(array_int, 2, print);
  std::cout << "__________float__________" << std::endl;
  iter(array_float, 2, print);
  std::cout << "__________double__________" << std::endl;
  iter(array_double, 2, print);
  std::cout << "__________char__________" << std::endl;
  iter(array_char, 2, print);
  std::cout << "__________bool__________" << std::endl;
  iter(array_bool, 2, print);
  std::cout << "__________string__________" << std::endl;
  iter(array_string, 2, print);
  return 0;
}