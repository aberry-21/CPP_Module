//
// Created by Aaron Berry on 4/25/21.
//

#include <iostream>
#include <string>

#include "includes/Form.h"
#include "includes/Bureaucrat.h"

Form::Form(const std::string &name, int grade_sign, int grade_exec)
      :name_(name),
       signed_(false),
       target_() {
  if (grade_sign < 1 || grade_exec < 1) {
    throw Form::GradeTooHighException("overestimate");
  }
  if (grade_exec > 150 || grade_sign > 150) {
    throw Form::GradeTooLowException("too low rating");
  }
  grade_sign_ = grade_sign;
  grade_exec_ = grade_exec;
}

Form::Form(Form const &other)
      :name_(other.name_),
       grade_sign_(other.grade_sign_),
       grade_exec_(other.grade_exec_),
       signed_(other.signed_),
       target_(other.target_) {}

Form &Form::operator=(Form const &other) {
  if (this == &other) {
    return *this;
  }
  name_ = other.name_;
  grade_sign_ = other.grade_sign_;
  grade_exec_ = other.grade_exec_;
  signed_ = other.signed_;
  target_ = other.target_;
  return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
  return name_;
}

bool Form::getSigned() const {
  return signed_;
}

int Form::getGradeSign() const {
  return grade_sign_;
}

int Form::getGradeExec() const {
  return grade_exec_;
}

void Form::beSigned(Bureaucrat const &target) {
  if (target.getGrade() <= grade_sign_) {
      signed_ = true;
  } else {
      throw Form::GradeTooLowException("Need more grade");
  }
}

void Form::execute(const Bureaucrat &executor) const {
  if (!signed_) {
    throw Form::FormNotSignedException("Form dont signed");
  }
  if (executor.getGrade() > grade_exec_) {
    throw Form::FormNotSignedException("Need more grade");
  }
  beExecuted();
}

void Form::setTarget(const std::string &target) {
  target_ = target;
}

const std::string &Form::getTarget() const {
  return target_;
}

std::ostream &operator<<(std::ostream &out, Form const &target) {
  out << target.getName() << " is ";
  target.getSigned() ? out << "signed." : out << " not signed.";
  out << " Requiered sign grade is "
      << target.getGradeSign()
      << ". Requiered exec grade is "
      << target.getGradeExec();
  return (out);
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(
        const Form::GradeTooHighException &other) throw() {
  if (this == &other) {
    return *this;
  }
  m_error = other.m_error;
  return *this;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(
        const Form::GradeTooLowException &other) throw() {
  if (this == &other) {
    return *this;
  }
  m_error = other.m_error;
  return *this;
}

Form::FormNotSignedException &Form::FormNotSignedException::operator=(
        const Form::FormNotSignedException &other) throw() {
  if (this == &other) {
    return *this;
  }
  m_error = other.m_error;
  return *this;
}
