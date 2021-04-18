//
// Created by Aaron Berry on 4/18/21.
//

#include "includes/Human.hpp"
#include <iostream>


int main() {
  Human bob;
  Human bob1;

  bob1 = bob;
  std::cout << bob1.identify() << std::endl;


  std::cout << bob.identify() << std::endl;
  std::cout << bob.getBrain().identify() << std::endl;
}
