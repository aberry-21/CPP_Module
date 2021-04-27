//
// Created by Aaron Berry on 4/27/21.
//

#pragma once

#include <string>

#include "Form.h"

class RobotomyRequestForm : public Form {
 public:
  explicit RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(RobotomyRequestForm const &other);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
  virtual ~RobotomyRequestForm();
 private:
  void            beExecuted() const;
};

