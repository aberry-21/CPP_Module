//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>

#include "includes/Bureaucrat.h"

int main() {
  Bureaucrat  *bure;

  try {
    bure = new Bureaucrat("Gref", 160);
    std::cout << bure->getName() << std::endl;
  } catch (std::exception & e) {
    bure = nullptr;
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  delete bure;

  try {
    bure = new Bureaucrat("Gref", -1);
    std::cout << bure->getName() << std::endl;
  } catch (std::exception & e) {
    bure = nullptr;
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  delete bure;

  try {
    bure = new Bureaucrat("Gref", 149);
    bure->downGrade();
    bure->downGrade();
    bure->downGrade();
    bure->downGrade();
  } catch (std::exception & e) {
    bure = nullptr;
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  delete bure;

  return 0;
}
