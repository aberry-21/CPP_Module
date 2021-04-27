//
// Created by Aaron Berry on 4/27/21.
//

#include <iostream>
#include <string>

#include "includes/RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
                    : Form("RobotomyRequestForm", 72, 45) {
  setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(
        const RobotomyRequestForm &other) : Form(other) {
  setTarget(other.getTarget());
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  Form::operator=(other);
  setTarget(other.getTarget());
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExecuted() const {
  std::cout << "Brrrrrrrrrr......" << std::endl << getTarget();
  if (rand() % 2) {
    std::cout << " The robotization is a failure";
  } else {
    std::cout << " has been robotomized!";
  }
  std::cout << std::endl;
}
