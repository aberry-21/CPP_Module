//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>

#include "includes/Bureaucrat.h"
#include "includes/Intern.h"

int main() {
  srand(time(nullptr));
  Intern  intern;
  Form*   shrubbery;
  Form*   robotomy;
  Form*   presidential;

  shrubbery = intern.makeForm("shrubbery creation", "tree");
  robotomy = intern.makeForm("robotomy request", "req");
  presidential = intern.makeForm("presidential pardon", "par");
  try {
    shrubbery = intern.makeForm("__", "__");
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  delete presidential;
  delete shrubbery;
  delete robotomy;
  return 0;
}
