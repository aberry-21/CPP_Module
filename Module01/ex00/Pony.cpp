//
// Created by Aaron Berry on 4/17/21.
//

#include "Pony.hpp"

#include <iostream>

Pony &Pony::operator=(const Pony &other) {
  std::cout << "Operator = Pony object !" << std::endl;
  if (this == &other)
    return *this;
  age_ = other.age_;
  height_ = other.height_;
  color_ = other.color_;
  full_name_ = other.full_name_;
  nickname_ = other.nickname_;
  gender_ = other.gender_;
  return *this;
}

Pony::Pony(const Pony &other)
        : age_(other.age_), height_(other.height_),
        color_(other.color_), full_name_(other.full_name_),
        nickname_(other.nickname_), gender_(other.gender_) {
  std::cout << "Copy Pony object !" << std::endl;
}

Pony::Pony(int age, int height, const std::string &color,
           const std::string &fullName, const std::string &nickname,
           const std::string &gender) : age_(age), height_(height),
                                        color_(color), full_name_(fullName),
                                        nickname_(nickname), gender_(gender) {
  std::cout << "Create Pony object !" << std::endl;
}

Pony::Pony() {
  std::cout << "Create Pony object !" << std::endl;
}

Pony::~Pony() {
  std::cout << "Delete Pony object !" << std::endl;
}

int Pony::getAge() const {
  return age_;
}

void Pony::setAge(int age) {
  std::cout << "Set Pony age!" << std::endl;
  if (age < 0 || age > 150) {
    std::cout << "Impossible age!\nSet age 0!" << std::endl;
    age = 0;
  }
  age_ = age;
}

int Pony::getHeight() const {
  return height_;
}

void Pony::setHeight(int height) {
  std::cout << "Set Pony height!" << std::endl;
  if (height < 0 || height > 1500) {
    std::cout << "Impossible height!\nSet height 0!" << std::endl;
    height = 0;
  }
  height_ = height;
}

const std::string &Pony::getColor() const {
  return color_;
}

void Pony::setColor(const std::string &color) {
  std::cout << "Set Pony color!" << std::endl;
  color_ = color;
}

const std::string &Pony::getFullName() const {
  return full_name_;
}

void Pony::setFullName(const std::string &fullName) {
  std::cout << "Set Pony full name !" << std::endl;
  full_name_ = fullName;
}

const std::string &Pony::getNickname() const {
  return nickname_;
}

void Pony::setNickname(const std::string &nickname) {
  std::cout << "Set Pony nickname !" << std::endl;
  nickname_ = nickname;
}

const std::string &Pony::getGender() const {
  return gender_;
}

void Pony::setGender(const std::string &gender) {
  std::cout << "Set Pony gender !" << std::endl;
  gender_ = gender;
}

void Pony::SayName() const {
  std::cout << "My name is ";
  std::cout << getFullName() << std::endl;
}

void Pony::PonyWent() const {
  std::cout << "I went!!" << std::endl;
}

void Pony::Eating() const {
  std::cout << "I eating!!" << std::endl;
}
