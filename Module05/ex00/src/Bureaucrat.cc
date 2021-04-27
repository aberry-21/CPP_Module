//
// Created by Aaron Berry on 4/25/21.
//

#include <iostream>
#include <string>

#include "includes/Bureaucrat.h"

Bureaucrat::Bureaucrat()
            : name_(),
              grade_() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
            : name_(other.name_),
              grade_(other.grade_) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
            : name_(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException("overestimate");
  }
  if (grade > 150) {
    throw Bureaucrat::GradeTooLowException("too low rating");
  }
  grade_ = grade;
}

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

void Bureaucrat::upGrade()
{
  if (grade_ - 1 < 1) {
    throw Bureaucrat::GradeTooHighException("overestimate");
  }
  --grade_;
}

void Bureaucrat::downGrade()
{
  if (grade_ + 1 > 150) {
    throw Bureaucrat::GradeTooLowException("too low rating");
  }
  ++grade_;
}


Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(
        const Bureaucrat::GradeTooHighException &other) throw() {
  if (this == &other) {
    return *this;
  }
  m_error = other.m_error;
  return *this;
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(
        const Bureaucrat::GradeTooLowException &other) throw() {
  if (this == &other) {
    return *this;
  }
  m_error = other.m_error;
  return *this;
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &target) {
  out << target.getName()
      << " , bureaucrat grade "
      << target.getGrade()
      << std::endl;
  return out;
}

