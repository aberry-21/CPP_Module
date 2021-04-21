//
// Created by Aaron Berry on 4/19/21.
//

#include <iostream>
#include <cstdlib>
#include "includes/FragTrap.h"

//==========================  Static Field  ====================================

char const  FragTrap::responses[5][60] =
        {"Ratattattattatta!", "Laaasers!!", "Powpowpowpow!",
         "Pew-pew, pew-pew-pewpew!",
         "Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!"};

//==============================================================================

FragTrap::FragTrap()
:ClapTrap() {
  max_energy_points_ = 100;
  max_hit_points_ = 100;
  hit_points_ = 100;
  energy_points_ = 100;
  melee_attack_damage_ = 30;
  armor_damage_reduction_ = 5;
  ranged_attack_damage_ = 20;
  std::cout << name_ << " FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
:ClapTrap(name) {
  max_energy_points_ = 100;
  max_hit_points_ = 100;
  hit_points_ = 100;
  energy_points_ = 100;
  melee_attack_damage_ = 30;
  armor_damage_reduction_ = 5;
  ranged_attack_damage_ = 20;
  std::cout << name_ << " FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << name_ << " FragTrap default destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
: ClapTrap(other) {
  std::cout << name_ << " FragTrap default constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)  {
  if (this == &other) {
    return *this;
  }
  max_energy_points_ = other.max_energy_points_;
  max_hit_points_ = other.max_energy_points_;
  name_ = other.name_;
  hit_points_ = other.hit_points_;
  energy_points_ = other.energy_points_;
  level_ = other.level_;
  melee_attack_damage_ = other.melee_attack_damage_;
  armor_damage_reduction_ = other.armor_damage_reduction_;
  ranged_attack_damage_ = other.ranged_attack_damage_;
  return *this;
}

void FragTrap::RangedAttack(const std::string &target) {
  std::cout << "FR4G-TP " << name_ << "attacks " << target
            << " at range, causing " << ranged_attack_damage_
            << " points of damage!" << std::endl;
}

void FragTrap::MeleeAttack(const std::string &target) {
  std::cout << "FR4G-TP " << name_ << "attacks " << target
            << ", causing " << melee_attack_damage_
            << " points of damage!" << std::endl;
}

void FragTrap::TakeDamage(unsigned int amount) {
  std::cout << "FR4G-TP " << name_ << " take damage: " << amount << std::endl;
  amount -= armor_damage_reduction_;
  hit_points_ -= static_cast<int>(amount);
  if (hit_points_ < 0) {
    hit_points_ = 0;
  }
  std::cout << "FR4G-TP " << name_ << " has hp: " << hit_points_ << std::endl;
}

void FragTrap::BeRepaired(unsigned int amount) {
  std::cout << "FR4G-TP " << name_ << " be repaired: " << amount << std::endl;
  hit_points_ += static_cast<int>(amount);
  if (hit_points_ > max_hit_points_) {
    hit_points_ = max_hit_points_;
  }
  std::cout << "FR4G-TP " << name_ << " has hp: " << hit_points_ << std::endl;
}

void FragTrap::VaulthunterDotExe(const std::string &target) {
  if (energy_points_ < 25) {
    std::cout << "No enough energy" << std::endl;
    return;
  }
  static unsigned int seed = time(nullptr);
  int random_index = rand_r(&seed) % 5;
  std::cout << "FR4G-TP " << name_ << "attacks " << target << ": ";
  std::cout << responses[random_index] << std::endl;
  energy_points_ -= 25;
}
