//
// Created by Aaron Berry on 4/18/21.
//

#include <iostream>
#include "includes/Human.hpp"

int main() {
  Human bob;

  std::cout << bob.identify() << std::endl;
  std::cout << bob.getBrain().identify() << std::endl;
}
