//
// Created by Aaron Berry on 4/16/21.
//


#include <iostream>
#include <string>

#include "../includes/PhoneBook.hpp"

int main() {
  std::cout << "Welcome to Phonebook!" << std::endl;
  std::string input;
  PhoneBook phoneBook;
  while (true) {
    std::cout << "Choose the command:\nADD;\nSEARCH;\nEXIT;\n";
    if (!std::getline(std::cin, input))
      break;
    if (input == "ADD") {
      if (phoneBook.AddContact())
        break;
    } else if (input == "SEARCH") {
      if (phoneBook.SearchContact())
        break;
    } else if (input == "EXIT") {
      break;
    } else {
      std::cout << "Unknown command" << std::endl;
    }
  }
  return 0;
}
