//
// Created by Aaron Berry on 4/25/21.
//

#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.h"

class Bureaucrat;
class Form;

class Form {
 public:
  Form(const std::string &name, int grade_sign, int grade_exec);
  Form(Form const &other);
  Form &operator=(Form const &other);
  virtual ~Form();

  const std::string  &getName() const;
  bool               getSigned() const;
  int                getGradeSign() const;
  int                getGradeExec() const;

  void               beSigned(Bureaucrat const &target);
  void               execute(Bureaucrat const &executor) const;
  void               setTarget(const std::string &target);
  const std::string  &getTarget() const;

  class GradeTooHighException : public std::exception {
   public:
    GradeTooHighException()
              throw() {}
    GradeTooHighException(GradeTooHighException const &other)
              throw() : m_error(other.m_error) {}
    GradeTooHighException &operator=(const GradeTooHighException &other)
              throw();
    virtual ~GradeTooHighException()
              throw() {}
    explicit GradeTooHighException(const std::string& error)
              : m_error(error) {}
    const char *what() const
              throw() { return m_error.c_str(); }

   private:
    std::string m_error;
  };

  class GradeTooLowException : public std::exception {
   public:
    GradeTooLowException()
              throw() {}
    GradeTooLowException(GradeTooLowException const &other)
              throw() : m_error(other.m_error) {}
    GradeTooLowException &operator=(const GradeTooLowException &other)
              throw();
    virtual ~GradeTooLowException()
              throw() {}
    explicit GradeTooLowException(const std::string& error)
              : m_error(error) {}
    const char *what() const
              throw() { return m_error.c_str(); }
   private:
    std::string m_error;
  };

  class FormNotSignedException : public std::exception {
   public:
    FormNotSignedException()
    throw() {}
    FormNotSignedException(FormNotSignedException const &other)
    throw() : m_error(other.m_error) {}
    FormNotSignedException &operator=(const FormNotSignedException &other)
    throw();
    virtual ~FormNotSignedException()
    throw() {}
    explicit FormNotSignedException(const std::string& error)
            : m_error(error) {}
    const char *what() const
    throw() { return m_error.c_str(); }
   private:
    std::string m_error;
  };

 private:
  Form();
  virtual void      beExecuted() const = 0;
  std::string       name_;
  int               grade_sign_;
  int               grade_exec_;
  bool              signed_;
  std::string       target_;
};

std::ostream &operator<<(std::ostream &out, const Form &target);
