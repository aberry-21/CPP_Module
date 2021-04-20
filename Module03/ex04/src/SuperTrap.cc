//
// Created by Aaron Berry on 4/20/21.
//

#include "includes/SuperTrap.h"

#include <iostream>

SuperTrap::SuperTrap()
: ClapTrap(),
max_energy_points_(NinjaTrap::getMaxEnergyPoints()),
max_hit_points_(FragTrap::getMaxHitPoints()),
hit_points_(FragTrap::getHitPoints()),
energy_points_(NinjaTrap::getEnergyPoints()),
melee_attack_damage_(NinjaTrap::getMeleeAttackDamage()),
ranged_attack_damage_(FragTrap::getRangedAttackDamage()),
armor_damage_reduction_(FragTrap::getArmorDamageReduction()) {
  std::cout << name_ << " SuperTrap default constructor called" << std::endl;
}

SuperTrap::SuperTrap(const std::string &name)
: ClapTrap(name),max_energy_points_(NinjaTrap::getMaxEnergyPoints()),
  max_hit_points_(FragTrap::getMaxHitPoints()),
  hit_points_(FragTrap::getHitPoints()),
  energy_points_(NinjaTrap::getEnergyPoints()),
  melee_attack_damage_(NinjaTrap::getMeleeAttackDamage()),
  ranged_attack_damage_(FragTrap::getRangedAttackDamage()),
  armor_damage_reduction_(FragTrap::getArmorDamageReduction()) {
  std::cout << name_ << " SuperTrap default constructor called" << std::endl;
}

SuperTrap::~SuperTrap() {
  std::cout << name_ << " SuperTrap default destructor called" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &other)
: ClapTrap(other), max_energy_points_(other.max_energy_points_),
  max_hit_points_(other.max_energy_points_),
  hit_points_(other.hit_points_),
  energy_points_(other.energy_points_),
  melee_attack_damage_(other.melee_attack_damage_),
  ranged_attack_damage_(other.armor_damage_reduction_),
  armor_damage_reduction_(other.ranged_attack_damage_) {
  std::cout << name_ << " SuperTrap default constructor called" << std::endl;
}

SuperTrap &SuperTrap::operator=(const SuperTrap &other)  {
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

void SuperTrap::RangedAttack(const std::string &target) {
  FragTrap::RangedAttack(target);
}

void SuperTrap::MeleeAttack(const std::string &target) {
  NinjaTrap::RangedAttack(target);
}

void SuperTrap::TakeDamage(unsigned int amount) {
  std::cout << "SuperTrap " << name_ << " take damage: " << amount << std::endl;
  amount -= armor_damage_reduction_;
  hit_points_ -= static_cast<int>(amount);
  if (hit_points_ < 0) {
    hit_points_ = 0;
  }
  std::cout << "SuperTrap " << name_ << " has hp: " << hit_points_ << std::endl;
}

void SuperTrap::BeRepaired(unsigned int amount) {
  std::cout << "SuperTrap " << name_ << " be repaired: " << amount << std::endl;
  hit_points_ += static_cast<int>(amount);
  if (hit_points_ > max_hit_points_) {
    hit_points_ = max_hit_points_;
  }
  std::cout << "SuperTrap " << name_ << " has hp: " << hit_points_ << std::endl;
}

int SuperTrap::getHitPoints() const {
  return hit_points_;
}

void SuperTrap::setHitPoints(int hitPoints) {
  if (hitPoints < 0) {
    hitPoints = 0;
  }
  hit_points_ = hitPoints;
  if (hit_points_ > max_hit_points_) {
    hit_points_ = 100;
  }
}

int SuperTrap::getEnergyPoints() const {
  return energy_points_;
}

void SuperTrap::setEnergyPoints(int energyPoints) {
  if (energyPoints < 0) {
    energyPoints = 0;
  }
  energy_points_ = energyPoints;
  if (energy_points_ > max_energy_points_) {
    energy_points_ = 100;
  }
}

int SuperTrap::getMeleeAttackDamage() const {
  return melee_attack_damage_;
}

void SuperTrap::setMeleeAttackDamage(int meleeAttackDamage) {
  if (meleeAttackDamage < 0) {
    meleeAttackDamage = 0;
  }
  melee_attack_damage_ = meleeAttackDamage;
}

int SuperTrap::getRangedAttackDamage() const {
  return ranged_attack_damage_;
}

void SuperTrap::setRangedAttackDamage(int rangedAttackDamage) {
  if (rangedAttackDamage < 0) {
    rangedAttackDamage = 0;
  }
  ranged_attack_damage_ = rangedAttackDamage;
}

int SuperTrap::getArmorDamageReduction() const {
  return armor_damage_reduction_;
}

void SuperTrap::setArmorDamageReduction(int armorDamageReduction) {
  if (armorDamageReduction < 0) {
    armorDamageReduction = 0;
  }
  armor_damage_reduction_ = armorDamageReduction;
}

int SuperTrap::getMaxEnergyPoints() const {
  return max_energy_points_;
}

void SuperTrap::setMaxEnergyPoints(int maxEnergyPoints) {
  max_energy_points_ = maxEnergyPoints;
}

int SuperTrap::getMaxHitPoints() const {
  return max_hit_points_;
}

void SuperTrap::setMaxHitPoints(int maxHitPoints) {
  max_hit_points_ = maxHitPoints;
}
