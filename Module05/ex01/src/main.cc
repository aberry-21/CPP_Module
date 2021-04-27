//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>

#include "../includes/Bureaucrat.h"
#include "../includes/Form.h"

int main() {
  Bureaucrat  *bure;
  Form        *form;

  try {
    bure = new Bureaucrat("Gref", 160);
    std::cout << bure->getName() << std::endl;
  } catch (std::exception & e) {
    bure = nullptr;
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  delete bure;
  try {
    form = new Form("Gref.doc", -160, 120);
    std::cout << form->getName() << std::endl;
  } catch (std::exception & e) {
    form = nullptr;
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  delete form;


  bure = new Bureaucrat("Gref", 90);
  form = new Form("Gref.doc", 100, 110);

  std::cout << *bure << std::endl;
  std::cout << *form << std::endl;


  bure->signForm(*form);
  bure->signForm(*form);
  bure->signForm(*form);

  delete form;
  delete bure;
  return 0;
}
