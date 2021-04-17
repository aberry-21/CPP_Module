//
// Created by Aaron Berry on 4/17/21.
//

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
  std::string name_;
  std::string type_;
 public:
  Zombie();

  Zombie(const std::string &name, const std::string &type);

  virtual ~Zombie();

  Zombie& operator=(const Zombie &other);

  Zombie(const Zombie &other);

  const std::string &getName() const;

  void setName(const std::string &name);

  const std::string &getType() const;

  void setType(const std::string &type);

  void announce() const;
};

#endif  // ZOMBIE_HPP
