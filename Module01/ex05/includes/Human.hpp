//
// Created by Aaron Berry on 4/18/21.
//

#pragma once
#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>
#include "includes/Brain.hpp"

class Human {
  Brain const *brain_;

 public:
  Human(const Human &other);

  virtual ~Human();

  Human();

  Brain const &getBrain() const;

  std::string identify() const;

  Human &operator=(const Human &other);
};

#endif  // HUMAN_HPP
