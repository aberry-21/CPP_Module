//
// Created by Aaron Berry on 4/27/21.
//

#pragma once

#include <string>

#include "Form.h"

class ShrubberyCreationForm : public Form {
 public:
  explicit ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &other);
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
  virtual ~ShrubberyCreationForm();
 private:
  void            beExecuted() const;
};
