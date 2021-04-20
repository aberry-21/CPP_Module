//
// Created by Aaron Berry on 4/20/21.
//

#include <iostream>
#include <cstdlib>

#include "includes/ScavTrap.h"

//==========================  Static Field  ====================================

char const  ScavTrap::responses[5][60] =
        {"Wheeeee!", "Yahooooo!!", "Yipe!", "Yikes!", "Yeehaw"};

//==============================================================================

ScavTrap::ScavTrap()
: ClapTrap() {
  std::cout << name_ << " ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
: ClapTrap(name) {
  std::cout << name_ << " ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << name_ << " ScavTrap default destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
: ClapTrap(other) {
  std::cout << name_ << " ScavTrap default constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this == &other) {
    return *this;
  }
  name_ = other.name_;
  hit_points_ = other.hit_points_;
  energy_points_ = other.energy_points_;
  level_ = other.level_;
  melee_attack_damage_ = other.melee_attack_damage_;
  armor_damage_reduction_ = other.armor_damage_reduction_;
  ranged_attack_damage_ = other.ranged_attack_damage_;
  max_energy_points_ = other.max_energy_points_;
  max_hit_points_ = other.max_energy_points_;
  return *this;
}

void ScavTrap::RangedAttack(const std::string &target) {
  std::cout << "ScavTrap " << name_ << "attacks " << target
            << " at range, causing " << ranged_attack_damage_
            << " points of damage!" << std::endl;
}

void ScavTrap::MeleeAttack(const std::string &target) {
  std::cout << "ScavTrap " << name_ << "attacks " << target
            << ", causing " << melee_attack_damage_
            << " points of damage!" << std::endl;
}

void ScavTrap::TakeDamage(unsigned int amount) {
  std::cout << "ScavTrap " << name_ << " take damage: " << amount << std::endl;
  amount -= armor_damage_reduction_;
  hit_points_ -= static_cast<int>(amount);
  if (hit_points_ < 0) {
    hit_points_ = 0;
  }
  std::cout << "ScavTrap " << name_ << " has hp: " << hit_points_ << std::endl;
}

void ScavTrap::BeRepaired(unsigned int amount) {
  std::cout << "ScavTrap " << name_ << " be repaired: " << amount << std::endl;
  hit_points_ += static_cast<int>(amount);
  if (hit_points_ > max_hit_points_) {
    hit_points_ = max_hit_points_;
  }
  std::cout << "ScavTrap " << name_ << " has hp: " << hit_points_ << std::endl;
}

void ScavTrap::ChallengeNewcomer(const std::string &target) {
  if (energy_points_ < 25) {
    std::cout << "No enough energy" << std::endl;
    return;
  }
  static unsigned int seed = time(nullptr);
  int random_index = rand_r(&seed) % 5;
  std::cout << "ScavTrap " << name_ << "attacks " << target << ": ";
  std::cout << responses[random_index] << std::endl;
  energy_points_ -= 25;
}
