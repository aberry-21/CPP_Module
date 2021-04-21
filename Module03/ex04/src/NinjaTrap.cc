//
// Created by Aaron Berry on 4/20/21.
//

#include "includes/NinjaTrap.h"

#include <iostream>

NinjaTrap::NinjaTrap()
: ClapTrap(), max_energy_points_(120), max_hit_points_(60),
hit_points_(60), energy_points_(120),
melee_attack_damage_(60), ranged_attack_damage_(5),
armor_damage_reduction_(0) {
  std::cout << name_ << " NinjaTrap default constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string &name)
: ClapTrap(name), max_energy_points_(120), max_hit_points_(60),
  hit_points_(60), energy_points_(120),
  melee_attack_damage_(60), ranged_attack_damage_(5),
  armor_damage_reduction_(0) {
  std::cout << name_ << " NinjaTrap default constructor called" << std::endl;
}

NinjaTrap::~NinjaTrap() {
  std::cout << name_ << " NinjaTrap default destructor called" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other)
: ClapTrap(other), max_energy_points_(other.max_energy_points_),
  max_hit_points_(other.max_energy_points_),
  hit_points_(other.hit_points_),
  energy_points_(other.energy_points_),
  melee_attack_damage_(other.melee_attack_damage_),
  ranged_attack_damage_(other.armor_damage_reduction_),
  armor_damage_reduction_(other.ranged_attack_damage_) {
  std::cout << name_ << " NinjaTrap default constructor called" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &other) {
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

void NinjaTrap::RangedAttack(const std::string &target) {
  std::cout << "NinjaTrap " << name_ << " attacks " << target
            << " at range, causing " << ranged_attack_damage_
            << " points of damage!" << std::endl;
}

void NinjaTrap::MeleeAttack(const std::string &target) {
  std::cout << "NinjaTrap " << name_ << " attacks " << target
            << ", causing " << melee_attack_damage_
            << " points of damage! (!)" << std::endl;
}

void NinjaTrap::TakeDamage(unsigned int amount) {
  std::cout << "NinjaTrap " << name_ << " take damage: " << amount << std::endl;
  amount -= armor_damage_reduction_;
  hit_points_ -= static_cast<int>(amount);
  if (hit_points_ < 0) {
    hit_points_ = 0;
  }
  std::cout << "NinjaTrap " << name_ << " has hp: " << hit_points_ << std::endl;
}

void NinjaTrap::BeRepaired(unsigned int amount) {
  std::cout << "NinjaTrap " << name_ << " be repaired: " << amount << std::endl;
  hit_points_ += static_cast<int>(amount);
  if (hit_points_ > max_hit_points_) {
    hit_points_ = max_hit_points_;
  }
  std::cout << "NinjaTrap " << name_ << " has hp: " << hit_points_ << std::endl;
}

void NinjaTrap::ninjaShoeBox(const ClapTrap &target) {
  if (energy_points_ < 25) {
    std::cout << "Need more energy points" << std::endl;
  } else {
    std::cout << "NinjaTrap " << name_ << " attacks ClapTrap "
              << target.getName() << std::endl;
    energy_points_ -= 25;
  }
}

void NinjaTrap::ninjaShoeBox(const NinjaTrap &target) {
  if (energy_points_ < 25) {
    std::cout << "Need more energy points" << std::endl;
  } else {
    std::cout << "NinjaTrap " << name_ << " attacks NinjaTrap "
              << target.getName() << std::endl;
    energy_points_ -= 25;
  }
}

void NinjaTrap::ninjaShoeBox(const ScavTrap &target) {
  if (energy_points_ < 25) {
    std::cout << "Need more energy points" << std::endl;
  } else {
    std::cout << "NinjaTrap " << name_ << " attacks ScavTrap "
              << target.getName() << std::endl;
    energy_points_ -= 25;
  }
}

void NinjaTrap::ninjaShoeBox(const FragTrap &target) {
  if (energy_points_ < 25) {
    std::cout << "Need more energy points" << std::endl;
  } else {
    std::cout << "NinjaTrap " << name_ << " attacks FragTrap "
              << target.getName() << std::endl;
    energy_points_ -= 25;
  }
}


int NinjaTrap::getHitPoints() const {
  return hit_points_;
}

void NinjaTrap::setHitPoints(int hitPoints) {
  if (hitPoints < 0) {
    hitPoints = 0;
  }
  hit_points_ = hitPoints;
  if (hit_points_ > max_hit_points_) {
    hit_points_ = 100;
  }
}

int NinjaTrap::getEnergyPoints() const {
  return energy_points_;
}

void NinjaTrap::setEnergyPoints(int energyPoints) {
  if (energyPoints < 0) {
    energyPoints = 0;
  }
  energy_points_ = energyPoints;
  if (energy_points_ > max_energy_points_) {
    energy_points_ = 100;
  }
}

int NinjaTrap::getMeleeAttackDamage() const {
  return melee_attack_damage_;
}

void NinjaTrap::setMeleeAttackDamage(int meleeAttackDamage) {
  if (meleeAttackDamage < 0) {
    meleeAttackDamage = 0;
  }
  melee_attack_damage_ = meleeAttackDamage;
}

int NinjaTrap::getRangedAttackDamage() const {
  return ranged_attack_damage_;
}

void NinjaTrap::setRangedAttackDamage(int rangedAttackDamage) {
  if (rangedAttackDamage < 0) {
    rangedAttackDamage = 0;
  }
  ranged_attack_damage_ = rangedAttackDamage;
}

int NinjaTrap::getArmorDamageReduction() const {
  return armor_damage_reduction_;
}

void NinjaTrap::setArmorDamageReduction(int armorDamageReduction) {
  if (armorDamageReduction < 0) {
    armorDamageReduction = 0;
  }
  armor_damage_reduction_ = armorDamageReduction;
}

int NinjaTrap::getMaxEnergyPoints() const {
  return max_energy_points_;
}

void NinjaTrap::setMaxEnergyPoints(int maxEnergyPoints) {
  max_energy_points_ = maxEnergyPoints;
}

int NinjaTrap::getMaxHitPoints() const {
  return max_hit_points_;
}

void NinjaTrap::setMaxHitPoints(int maxHitPoints) {
  max_hit_points_ = maxHitPoints;
}
