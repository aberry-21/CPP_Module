//
// Created by Aaron Berry on 4/18/21.
//

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
  std::string          owner_;
  unsigned int         iq_;
 public:
  Brain();

  explicit Brain(const std::string &owner, unsigned int iq);

  virtual ~Brain();

  Brain(const Brain &other);

  Brain& operator=(const Brain &other);

  const std::string &getOwner() const;

  void setOwner(const std::string &owner);

  unsigned int getIq() const;

  void setIq(unsigned int iq);

  std::string identify() const;
};

#endif  // BRAIN_HPP
