//
// Created by Aaron Berry on 4/23/21.
//

#include <iostream>

#include "includes/Character.h"

static void DeleteInventory(AMateria **inventory) {
  for (int i = 0; i < 4; ++i) {
    delete inventory[i];
  }
}

Character::Character(const std::string& name)
          : name_(name) {
    for (int i = 0; i < 4; ++i) {
      inventory_[i] = nullptr;
    }
  }

Character::Character(const Character &other)
          : name_(other.name_) {
  for (int i = 0; i < 4; ++i) {
    if (inventory_[i]) {
      inventory_[i] = other.inventory_[i]->clone();
    }
  }
}

Character::~Character() {
  for (int i = 0; i < 4; ++i) {
      delete inventory_[i];
  }
}


Character &Character::operator=(const Character &other) {
  if (this == &other) {
    return *this;
  }
  std::cout << "Good!";
  name_ = other.name_;
  DeleteInventory(inventory_);
  for (int i = 0; i < 4; ++i) {
    if (other.inventory_[i]) {
      inventory_[i] = other.inventory_[i]->clone();
    } else {
      inventory_[i] = nullptr;
    }
  }
  return *this;
}

std::string const &Character::getName() const {
  return name_;
}

void Character::equip(AMateria *m) {
  int i = 0;
  while (inventory_[i] && inventory_[i] != m) {
    ++i;
  }
  if (i < 4 && inventory_[i] != m) {
    inventory_[i] = m;
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    inventory_[idx] = nullptr;
  }
}

void Character::use(int idx, const ICharacter &target) {
  if (idx >= 0 && idx < 4) {
    if (inventory_[idx])
      inventory_[idx]->use(target);
  }
}
