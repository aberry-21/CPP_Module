//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>

#include "includes/Array.h"

int main() {
  try {
    Array<int> number(10);
    std::cout << "_______Base int array_____"<< std::endl;
    std::cout << number[3] << std::endl;
    number[3] = 3;
    std::cout << number[3] << std::endl;
    std::cout << number.getLen() << std::endl;
    std::cout << "_______Copy int array_____"<< std::endl;
    Array<int> number_copy;
    number_copy = number;
    std::cout << number_copy[3] << std::endl;
    number_copy[3] = 4;
    std::cout << number_copy[3] << std::endl;
    std::cout << number_copy.getLen() << std::endl;
    std::cout << "_______New int array_____"<< std::endl;
    Array<int> number_new(number);
    std::cout << number_new[3] << std::endl;
    number_new[3] = 5;
    std::cout << number_new[3] << std::endl;
    std::cout << number_new.getLen() << std::endl;
    std::cout << number_new[3131];
  } catch (std::exception &e) {
    std::cerr << "exception caught: " << e.what() << '\n';
  }
  try {
    Array<float> number(10);
    std::cout << "_______Base int array_____"<< std::endl;
    std::cout << number[3] << std::endl;
    number[3] = 3.2;
    std::cout << number[3] << std::endl;
    std::cout << number.getLen() << std::endl;
    std::cout << "_______Copy int array_____"<< std::endl;
    Array<float> number_copy;
    number_copy = number;
    std::cout << number_copy[3] << std::endl;
    number_copy[3] = 4.3;
    std::cout << number_copy[3] << std::endl;
    std::cout << number_copy.getLen() << std::endl;
    std::cout << "_______New int array_____"<< std::endl;
    Array<float> number_new(number);
    std::cout << number_new[3] << std::endl;
    number_new[3] = 5.2;
    std::cout << number_new[3] << std::endl;
    std::cout << number_new.getLen() << std::endl;
    std::cout << number_new[3131];
  } catch (std::exception &e) {
    std::cerr << "exception caught: " << e.what() << '\n';
  }
  try {
    Array<std::string> number(10);
    std::cout << "_______Base int array_____"<< std::endl;
    std::cout << number[3] << std::endl;
    number[3] = "base string";
    std::cout << number[3] << std::endl;
    std::cout << number.getLen() << std::endl;
    std::cout << "_______Copy int array_____"<< std::endl;
    Array<std::string> number_copy;
    number_copy = number;
    std::cout << number_copy[3] << std::endl;
    number_copy[3] = "copy string";
    std::cout << number_copy[3] << std::endl;
    std::cout << number_copy.getLen() << std::endl;
    std::cout << "_______New int array_____"<< std::endl;
    Array<std::string> number_new(number);
    std::cout << number_new[3] << std::endl;
    number_new[3] = "new string";
    std::cout << number_new[3] << std::endl;
    std::cout << number_new.getLen() << std::endl;
    std::cout << number_new[3131];
  } catch (std::exception &e) {
    std::cerr << "exception caught: " << e.what() << '\n';
  }
  return 0;
}
