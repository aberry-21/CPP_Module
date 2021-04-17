//
// Created by Aaron Berry on 4/17/21.
//

#include "../includes/ZombieEvent.hpp"
#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent(const std::string &type) : type_(type) {}

ZombieEvent::ZombieEvent() {}

ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType(const std::string &type) {
  type_ = type;
}

Zombie *ZombieEvent::newZombie(const std::string& name) {
  return new Zombie(name, type_);
}

Zombie *ZombieEvent::randomChump() {
  Zombie *zombie_prt;
  std::string name_zombie[10] =
          {"ZOMBIE1", "ZOMBIE2", "ZOMBIE3", "ZOMBIE4", "ZOMBIE5",
           "ZOMBIE6", "ZOMBIE7", "ZOMBIE8", "ZOMBIE9", "ZOMBIE10"};
  srand(time(nullptr));
  zombie_prt = newZombie(name_zombie[rand() % 10]);
  zombie_prt->announce();
  return zombie_prt;
}
