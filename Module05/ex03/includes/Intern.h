//
// Created by Aaron Berry on 4/27/21.
//

#pragma once
#include <string>
#include "Form.h"

class Intern {
 public:
  Intern();
  virtual ~Intern();
  Intern(Intern const &other);
  Intern  &operator=(Intern const &other);
  Form *makeForm(const std::string &form_name, const std::string &target);

  class FormNotExistExecption : public std::exception {
   public:
    FormNotExistExecption()
              throw() {}
    FormNotExistExecption(FormNotExistExecption const &other)
              throw() : m_error(other.m_error) {}
    FormNotExistExecption &operator=(const FormNotExistExecption &other)
              throw();
    virtual ~FormNotExistExecption()
              throw() {}
    explicit FormNotExistExecption(const std::string& error)
              : m_error(error) {}
    const char *what() const
              throw() { return m_error.c_str(); }

   private:
    std::string m_error;
  };

 private:
  Form *NewPresidentialPardonForm(std::string const &target) const;
  Form *NewRobotomyRequestForm(std::string const &target) const;
  Form *NewShrubberyCreationForm(std::string const &target) const;
  typedef Form *(Intern::*constructor)(const std::string &target) const;
  static const char                all_forms[3][20];
  static const constructor         all_constructors[3];
};
