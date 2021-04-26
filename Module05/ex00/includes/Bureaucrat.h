//
// Created by Aaron Berry on 4/25/21.
//

#pragma once

#include <string>

class Bureaucrat {
 public:
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(Bureaucrat const &other);
  Bureaucrat &operator=(Bureaucrat const &other);
  virtual ~Bureaucrat();

  const std::string   &getName() const;
  int                 getGrade() const;

  void                upGrade();
  void                downGrade();

  class GradeTooHighException: public std::exception {
   public:
    GradeTooHighException()
              throw() {};
    GradeTooHighException(GradeTooHighException const &other)
              throw() : m_error(other.m_error) {};
    GradeTooHighException &operator=(const GradeTooHighException &other)
              throw();
    virtual ~GradeTooHighException()
              throw() {};
    explicit GradeTooHighException(const std::string& error)
              : m_error(error) {}
    const char *what() const
              throw() { return m_error.c_str(); }

   private:
    std::string m_error;
  };

  class GradeTooLowException: public std::exception {
   public:
    GradeTooLowException()
              throw() {};
    GradeTooLowException(GradeTooLowException const &other)
              throw() : m_error(other.m_error) {};
    GradeTooLowException &operator=(const GradeTooLowException &other)
              throw();
    virtual ~GradeTooLowException()
              throw() {};
    explicit GradeTooLowException(const std::string& error)
              : m_error(error) {}
    const char *what() const
              throw() { return m_error.c_str(); }
   private:
    std::string m_error;
  };

 private:
  Bureaucrat();
  std::string     name_;
  int             grade_;
};
