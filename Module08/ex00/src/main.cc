//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>
#include <list>

#include "includes/Easyfind.h"

int main() {
  std::list<int> list1(5);
  for (int i = 0; i < 5; ++i) {
    list1.push_back(i);
  }
  try {
    std::cout << *Easyfind(list1, 4) << std::endl;
    std::cout << *Easyfind(list1, 10) << std::endl;
  } catch (std::exception &e) {
    std::cout << "exception caught: " << e.what() << std::endl;
  }
  std::list<double> list2(5);
  for (int i = 0; i < 5; ++i) {
    list2.push_back(i);
  }
  try {
    std::cout << *Easyfind(list1, 2) << std::endl;
    std::cout << *Easyfind(list1, 10) << std::endl;
  } catch (std::exception &e) {
    std::cout << "exception caught: " << e.what() << std::endl;
  }
  return 0;
}
