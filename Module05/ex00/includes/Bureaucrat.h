//
// Created by Aaron Berry on 4/25/21.
//

#pragma once

#include <string>

class Bureaucrat {
 public:
  Bureaucrat(const std::string &name, int grade);
  explicit Bureaucrat(const std::string& name);
  Bureaucrat();
  Bureaucrat(Bureaucrat const &other);
  Bureaucrat &operator=(Bureaucrat const &other);
  virtual ~Bureaucrat();

  const std::string   &getName() const;
  int                 getGrade() const;

  class GradeTooHighException: public std::exception {
   public:
    virtual ~GradeTooHighException() throw();
    explicit GradeTooHighException(const std::string& error)
      : m_error(error) {}
    const char  *what() const throw() { return m_error.c_str(); }

   private:
    std::string m_error;
  };

  class GradeTooLowException: public std::exception {
   public:
    virtual ~GradeTooLowException() throw();
    explicit GradeTooLowException(const std::string& error)
      : m_error(error) {}
    const char *what() const throw() { return m_error.c_str(); }

   private:
    std::string m_error;
  };
 private:
  std::string     name_;
  int             grade_;
};
