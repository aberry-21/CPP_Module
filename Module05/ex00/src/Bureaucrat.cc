//
// Created by Aaron Berry on 4/25/21.
//

#include "includes/Bureaucrat.h"

Bureaucrat::Bureaucrat()
            : name_(),
              grade_() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
            : name_(other.name_),
              grade_(other.grade_) {}

Bureaucrat::Bureaucrat(const std::string& name)
            : name_(name),
              grade_() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
            : name_(name),
              grade_(grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this == &other) {
    return *this;
  }
  name_ = other.name_;
  grade_ = other.grade_;
  return *this;
}

const std::string &Bureaucrat::getName() const {
  return name_;
}

int Bureaucrat::getGrade() const {
  return grade_;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
