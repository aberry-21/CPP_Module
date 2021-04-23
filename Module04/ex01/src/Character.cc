//
// Created by Aaron Berry on 4/22/21.
//

#include <iostream>

#include "includes/Character.h"

Character::Character()
        : name_(),
          ap_(),
          weapon_(nullptr) {}

Character::Character(const std::string &name)
          : name_(name), ap_(40), weapon_(nullptr) {}

Character::Character(const Character &other)
          : name_(other.name_),
            ap_(other.ap_),
            weapon_(other.weapon_) {}

Character::~Character() {}

Character &Character::operator=(const Character &other) {
  if (this == &other)
    return *this;
  name_ = other.name_;
  ap_ = other.ap_;
  weapon_ = other.weapon_;
  return *this;
}

const std::string &Character::getName() const {
  return name_;
}

int Character::getAp() const {
  return ap_;
}

AWeapon *Character::getWeapon() const {
  return weapon_;
}

void    Character::recoverAP() {
  if (ap_ + 10 > 40) {
    ap_ = 40;
  } else {
    ap_ += 10;
  }
}

void    Character::equip(AWeapon *weapon) {
  weapon_ = weapon;
}

void    Character::attack(Enemy *enemy) {
  if (weapon_ == nullptr || enemy == nullptr)
    return ;
  if (ap_ < weapon_->getApCost()) {
    std::cout << "No AP" << std::endl;
    return ;
  } else {
    ap_ -= weapon_->getApCost();
  }
  std::cout << name_ << " attacks " << enemy->getType() << " with a "
            << weapon_->getName() << std::endl;
  weapon_->attack();
  enemy->takeDamage(weapon_->getDamage());
  if (enemy->getHitPoint() <= 0) {
    delete enemy;
  }
}

std::ostream    &operator<<(std::ostream &out, Character const &character) {
  out << character.getName() << " has " << character.getAp() << " AP";
  if (character.getWeapon() == nullptr) {
    out << " and is unarmed";
  } else {
    out << " and wields a " << character.getWeapon()->getName();
  }
  out << std::endl;
  return out;
}
