//
// Created by Aaron Berry on 4/17/21.
//

#include <iostream>

int main() {
  std::string message = "HI THIS IS BRAIN";
  std::string *message_pointer = &message;
  std::string &message_reference = message;

  std::cout << std::endl;
  std::cout << "Original:" << std::endl;
  std::cout << message << std::endl;

  std::cout << std::endl;
  std::cout << "Pointer:" << std::endl;
  std::cout << *message_pointer << std::endl;

  std::cout << std::endl;
  std::cout << "Reference:" << std::endl;
  std::cout << message_reference << std::endl;

  std::cout << std::endl;
  return 0;
}
