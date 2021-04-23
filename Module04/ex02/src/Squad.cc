//
// Created by Aaron Berry on 4/22/21.
//

#include <cstddef>
#include "includes/Squad.h"
#include <cstring>
#include <iostream>

static void DeleteUnits(ISpaceMarine **units, int size) {
  for (int i = 0; i < size; ++i) {
    delete units[i];
  }
  delete units;
}

Squad::Squad()
      : size_(0), capacity_(10) {
  units_ = new ISpaceMarine*[capacity_];
}

Squad::Squad(const Squad &other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  units_ = (capacity_ != 0) ? new ISpaceMarine*[capacity_] : other.units_;
  for (int i = 0; i < size_; ++i) {
    units_[i] = other.units_[i];
  }
}

Squad::~Squad() {
  std::cout << size_;
  DeleteUnits(units_, size_);
}

Squad &Squad::operator=(const Squad &other) {
  if (this == &other)
    return *this;
  size_ = other.size_;
  capacity_ = other.capacity_;
  DeleteUnits(units_, size_);
  units_ = (capacity_ != 0) ? new ISpaceMarine*[capacity_] : other.units_;
  for (int i = 0; i < size_; ++i) {
    units_[i] = other.units_[i];
  }
  return *this;
}

int Squad::getCount() const {
  return size_;
}

ISpaceMarine *Squad::getUnit(int index) const {
  return ((index < 0 || index >= size_) ? nullptr : units_[index]);
}

static bool UnitAlreadyInTheSquad(ISpaceMarine **units, int size,
                                  ISpaceMarine *target) {
  for (int i = 0; i < size; ++i) {
    if (units[i] == target) {
      return true;
    }
  }
  return false;
}

int Squad::push(ISpaceMarine *unit) {
  if (unit != nullptr && !UnitAlreadyInTheSquad(units_, size_, unit)) {
    ++size_;
    if (size_ > capacity_) {
      capacity_ *= 2;
      ISpaceMarine **new_array_units = new ISpaceMarine*[capacity_];
      std::memcpy(new_array_units, units_, sizeof(void*) * size_);
      delete[] units_;
      units_ = new_array_units;
    }
    units_[size_ - 1] = unit;
  }
  return size_;
}
