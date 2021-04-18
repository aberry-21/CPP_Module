//
// Created by Aaron Berry on 4/18/21.
//

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
  std::string   owner_;
  short         iq_;
 public:
  Brain();

  explicit Brain(const std::string &owner, short iq);

  virtual ~Brain();

  Brain(const Brain &other);

  Brain& operator=(const Brain &other);

  const std::string &getOwner() const;

  void setOwner(const std::string &owner);

  short getIq() const;

  void setIq(short iq);

  std::string identify() const;
};

#endif  // BRAIN_HPP
