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
: max_energy_points_(100), max_hit_points_(100), name_("No name"),
  hit_points_(100), energy_points_(100), level_(1),
  melee_attack_damage_(30), ranged_attack_damage_(20),
  armor_damage_reduction_(5) {
  std::cout << name_ << " FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
: max_energy_points_(100), max_hit_points_(100), name_(name),
  hit_points_(100), energy_points_(100), level_(1),
  melee_attack_damage_(30), ranged_attack_damage_(20),
  armor_damage_reduction_(5) {
  std::cout << name_ << " FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << name_ << " FragTrap default destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
: max_energy_points_(other.max_energy_points_),
  max_hit_points_(other.max_energy_points_),
  name_(other.name_), hit_points_(other.hit_points_),
  energy_points_(other.energy_points_), level_(other.level_),
  melee_attack_damage_(other.melee_attack_damage_),
  ranged_attack_damage_(other.armor_damage_reduction_),
  armor_damage_reduction_(other.ranged_attack_damage_) {
  std::cout << name_ << " FragTrap default constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  if (this == &other) {
    return *this;
  }
  name_ = other.name_;
  hit_points_ = other.hit_points_;
  max_energy_points_ = other.max_energy_points_;
  max_hit_points_ = other.max_hit_points_;
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

const std::string &FragTrap::getName() const {
  return name_;
}

void FragTrap::setName(const std::string &name) {
  name_ = name;
}

int FragTrap::getHitPoints() const {
  return hit_points_;
}

void FragTrap::setHitPoints(int hitPoints) {
  if (hitPoints < 0) {
    hitPoints = 0;
  }
  hit_points_ = hitPoints;
  if (hit_points_ > max_hit_points_) {
    hit_points_ = 100;
  }
}

int FragTrap::getEnergyPoints() const {
  return energy_points_;
}

void FragTrap::setEnergyPoints(int energyPoints) {
  if (energyPoints < 0) {
    energyPoints = 0;
  }
  energy_points_ = energyPoints;
  if (energy_points_ > max_energy_points_) {
    energy_points_ = 100;
  }
}

int FragTrap::getLevel() const {
  return level_;
}

void FragTrap::setLevel(int level) {
  if (level < 0) {
    level = 0;
  }
  level_ = level;
}

int FragTrap::getMeleeAttackDamage() const {
  return melee_attack_damage_;
}

void FragTrap::setMeleeAttackDamage(int meleeAttackDamage) {
  if (meleeAttackDamage < 0) {
    meleeAttackDamage = 0;
  }
  melee_attack_damage_ = meleeAttackDamage;
}

int FragTrap::getRangedAttackDamage() const {
  return ranged_attack_damage_;
}

void FragTrap::setRangedAttackDamage(int rangedAttackDamage) {
  if (rangedAttackDamage < 0) {
    rangedAttackDamage = 0;
  }
  ranged_attack_damage_ = rangedAttackDamage;
}

int FragTrap::getArmorDamageReduction() const {
  return armor_damage_reduction_;
}

void FragTrap::setArmorDamageReduction(int armorDamageReduction) {
  if (armorDamageReduction < 0) {
    armorDamageReduction = 0;
  }
  armor_damage_reduction_ = armorDamageReduction;
}

int FragTrap::getMaxEnergyPoints() const {
  return max_energy_points_;
}

void FragTrap::setMaxEnergyPoints(int maxEnergyPoints) {
  max_energy_points_ = maxEnergyPoints;
}

int FragTrap::getMaxHitPoints() const {
  return max_hit_points_;
}

void FragTrap::setMaxHitPoints(int maxHitPoints) {
  max_hit_points_ = maxHitPoints;
}


