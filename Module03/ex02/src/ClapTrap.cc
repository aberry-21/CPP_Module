//
// Created by Aaron Berry on 4/20/21.
//

#include <iostream>
#include <cstdlib>
#include "includes/ClapTrap.h"

ClapTrap::ClapTrap()
        : max_energy_points_(100), max_hit_points_(100), name_("No name"),
          hit_points_(100), energy_points_(100), level_(1),
          melee_attack_damage_(30), ranged_attack_damage_(20),
          armor_damage_reduction_(3) {
  std::cout << name_ << " ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
        : max_energy_points_(100), max_hit_points_(100), name_(name),
          hit_points_(100), energy_points_(100), level_(1),
          melee_attack_damage_(30), ranged_attack_damage_(20),
          armor_damage_reduction_(3) {
  std::cout << name_ << " ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << name_ << " ClapTrap default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
        : max_energy_points_(other.max_energy_points_),
          max_hit_points_(other.max_energy_points_),
          name_(other.name_), hit_points_(other.hit_points_),
          energy_points_(other.energy_points_), level_(other.level_),
          melee_attack_damage_(other.melee_attack_damage_),
          ranged_attack_damage_(other.armor_damage_reduction_),
          armor_damage_reduction_(other.ranged_attack_damage_) {
  std::cout << name_ << " ClapTrap default constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
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

void ClapTrap::RangedAttack(const std::string &target) {
  std::cout << "FR4G-TP " << name_ << "attacks " << target
            << " at range, causing " << ranged_attack_damage_
            << " points of damage!" << std::endl;
}

void ClapTrap::MeleeAttack(const std::string &target) {
  std::cout << "FR4G-TP " << name_ << "attacks " << target
            << ", causing " << melee_attack_damage_
            << " points of damage!" << std::endl;
}

void ClapTrap::TakeDamage(unsigned int amount) {
  std::cout << "FR4G-TP " << name_ << " take damage: " << amount << std::endl;
  amount -= armor_damage_reduction_;
  hit_points_ -= static_cast<int>(amount);
  if (hit_points_ < 0) {
    hit_points_ = 0;
  }
  std::cout << "FR4G-TP " << name_ << " has hp: " << hit_points_ << std::endl;
}

void ClapTrap::BeRepaired(unsigned int amount) {
  std::cout << "FR4G-TP " << name_ << " be repaired: " << amount << std::endl;
  hit_points_ += static_cast<int>(amount);
  if (hit_points_ > max_hit_points_) {
    hit_points_ = max_hit_points_;
  }
  std::cout << "FR4G-TP " << name_ << " has hp: " << hit_points_ << std::endl;
}

const std::string &ClapTrap::getName() const {
  return name_;
}

void ClapTrap::setName(const std::string &name) {
  name_ = name;
}

int ClapTrap::getHitPoints() const {
  return hit_points_;
}

void ClapTrap::setHitPoints(int hitPoints) {
  if (hitPoints < 0) {
    hitPoints = 0;
  }
  hit_points_ = hitPoints;
  if (hit_points_ > max_hit_points_) {
    hit_points_ = 100;
  }
}

int ClapTrap::getEnergyPoints() const {
  return energy_points_;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
  if (energyPoints < 0) {
    energyPoints = 0;
  }
  energy_points_ = energyPoints;
  if (energy_points_ > max_energy_points_) {
    energy_points_ = 100;
  }
}

int ClapTrap::getLevel() const {
  return level_;
}

void ClapTrap::setLevel(int level) {
  if (level < 0) {
    level = 0;
  }
  level_ = level;
}

int ClapTrap::getMeleeAttackDamage() const {
  return melee_attack_damage_;
}

void ClapTrap::setMeleeAttackDamage(int meleeAttackDamage) {
  if (meleeAttackDamage < 0) {
    meleeAttackDamage = 0;
  }
  melee_attack_damage_ = meleeAttackDamage;
}

int ClapTrap::getRangedAttackDamage() const {
  return ranged_attack_damage_;
}

void ClapTrap::setRangedAttackDamage(int rangedAttackDamage) {
  if (rangedAttackDamage < 0) {
    rangedAttackDamage = 0;
  }
  ranged_attack_damage_ = rangedAttackDamage;
}

int ClapTrap::getArmorDamageReduction() const {
  return armor_damage_reduction_;
}

void ClapTrap::setArmorDamageReduction(int armorDamageReduction) {
  if (armorDamageReduction < 0) {
    armorDamageReduction = 0;
  }
  armor_damage_reduction_ = armorDamageReduction;
}