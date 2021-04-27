//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>

#include "includes/Bureaucrat.h"
#include "includes/PresidentialPardonForm.h"
#include "includes/RobotomyRequestForm.h"
#include "includes/ShrubberyCreationForm.h"

int main() {
  srand(time(nullptr));
  Bureaucrat  *bure;
  Form        *form_p;
  Form        *form_r;
  Form        *form_s;

  bure = new Bureaucrat("Gref", 1);
  form_p = new ShrubberyCreationForm("tree_file");
  form_r = new RobotomyRequestForm("roboto");
  form_s = new PresidentialPardonForm("Presidential");
  bure->executeForm(*form_p);
  bure->executeForm(*form_r);
  bure->executeForm(*form_s);
  std::cout << std::endl;
  bure->signForm(*form_p);
  bure->signForm(*form_r);
  bure->signForm(*form_s);
  std::cout << std::endl;
  bure->executeForm(*form_p);
  bure->executeForm(*form_r);
  bure->executeForm(*form_s);
  std::cout << std::endl;
  delete form_p;
  delete form_r;
  delete form_s;
  delete bure;
  return 0;
}
