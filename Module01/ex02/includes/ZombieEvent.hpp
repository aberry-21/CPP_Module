//
// Created by Aaron Berry on 4/17/21.
//

#pragma once
#include <iostream>
#include <string>
#include "../includes/Zombie.hpp"

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP


class ZombieEvent {
  std::string type_;
 public:
  explicit ZombieEvent(const std::string &type);

  ZombieEvent();

  virtual ~ZombieEvent();

  void setZombieType(const std::string &type);

  Zombie *newZombie(const std::string& name);

  Zombie *randomChump();
};


#endif  // ZOMBIEEVENT_HPP
