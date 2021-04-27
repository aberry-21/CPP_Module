//
// Created by Aaron Berry on 4/27/21.
//

#include <iostream>
#include <string>

#include "includes/PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
        : Form("PresidentialPardonForm", 25, 5) {
  setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(
        const PresidentialPardonForm &other) : Form(other) {
  setTarget(other.getTarget());
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  Form::operator=(other);
  setTarget(other.getTarget());
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beExecuted() const {
  std::cout << "Tells us " << getTarget()
            << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
