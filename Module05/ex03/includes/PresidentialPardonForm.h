//
// Created by Aaron Berry on 4/27/21.
//

#pragma once

#include <string>

#include "Form.h"

class PresidentialPardonForm : public Form {
 public:
  explicit PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(PresidentialPardonForm const &other);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
  virtual ~PresidentialPardonForm();
 private:
  void            beExecuted() const;
};
