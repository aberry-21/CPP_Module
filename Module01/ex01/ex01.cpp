//
// Created by Aaron Berry on 4/17/21.
//

#include <iostream>

void memoryLeak() {
  std::string *panther = new std::string("String panther");
  std::cout << *panther << std::endl;
  delete panther;
}

int main() {
  memoryLeak();
  return 0;
}
