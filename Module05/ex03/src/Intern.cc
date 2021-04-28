//
// Created by Aaron Berry on 4/27/21.
//

#include "includes/Intern.h"
#include "includes/PresidentialPardonForm.h"
#include "includes/RobotomyRequestForm.h"
#include "includes/ShrubberyCreationForm.h"

char const Intern::all_forms[3][20] = {
          "shrubbery creation",
          "robotomy request",
          "presidential pardon"
        };

const Intern::constructor Intern::all_constructors[3] = {
          &Intern::NewShrubberyCreationForm,
          &Intern::NewRobotomyRequestForm,
          &Intern::NewPresidentialPardonForm,
        };

Intern::Intern() {
}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {
  static_cast<void>(other);
}

Intern &Intern::operator=(const Intern &other) {
  static_cast<void>(other);
  return *this;
}

Form *Intern::NewPresidentialPardonForm(const std::string &target) const {
  return (new PresidentialPardonForm(target));
}

Form *Intern::NewRobotomyRequestForm(const std::string &target) const {
  return (new RobotomyRequestForm(target));
}

Form *Intern::NewShrubberyCreationForm(const std::string &target) const {
  return (new ShrubberyCreationForm(target));
}


Form*   Intern::makeForm(std::string const &form_name,
                         std::string const &target) {
  for (int i = 0; i < 3; ++i) {
    if (form_name == all_forms[i]) {
      Form *form = (this->*all_constructors[i])(target);
      std::cout << "Intern creates " << form->getName() << std::endl;
      return form;
    }
  }
  std::cout << "Intern doesn't create " << form_name << std::endl;
  throw Intern::FormNotExistException("Not found this form");
}

Intern::FormNotExistException &Intern::FormNotExistException::operator=(
        const Intern::FormNotExistException &other) throw() {
  m_error = other.m_error;
  return *this;
}
