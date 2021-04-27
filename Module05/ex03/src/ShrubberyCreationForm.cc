//
// Created by Aaron Berry on 4/27/21.
//

#include <fstream>

#include "includes/ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
                      : Form("ShrubberyCreationForm", 145, 137) {
  setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(
        const ShrubberyCreationForm &other) : Form(other) {
  setTarget(other.getTarget());
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  Form::operator=(other);
  setTarget(other.getTarget());
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beExecuted() const {
  std::ofstream ofs(getTarget() + "_shrubbery", std::ofstream::out);
  if (ofs.is_open()) {
    ofs << "        _-_          " << std::endl;
    ofs << "     /~~   ~~\\       " << std::endl;
    ofs << "  /~~         ~~\\    " << std::endl;
    ofs << " {               }   " << std::endl;
    ofs << "  \\  _-     -_  /    " << std::endl;
    ofs << "    ~  \\\\ //  ~      " << std::endl;
    ofs << " _- -   | | _- _     " << std::endl;
    ofs << "   _ -  | |   -_     " << std::endl;
    ofs << "       // \\\\         " << std::endl;
  }
  ofs.close();
}
