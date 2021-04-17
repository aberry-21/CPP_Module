//
// Created by Aaron Berry on 4/17/21.
//

#pragma once
#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
  int           age_;
  int           height_;
  std::string   color_;
  std::string   full_name_;
  std::string   nickname_;
  std::string   gender_;

 public:
  int getAge() const;

  void setAge(int age);

  int getHeight() const;

  void setHeight(int height);

  const std::string &getColor() const;

  void setColor(const std::string &color);

  const std::string &getFullName() const;

  void setFullName(const std::string &fullName);

  const std::string &getNickname() const;

  void setNickname(const std::string &nickname);

  const std::string &getGender() const;

  void setGender(const std::string &gender);

  ~Pony();

  Pony();

  Pony(int age, int height, const std::string &color,
       const std::string &fullName, const std::string &nickname,
       const std::string &gender);

  Pony& operator=(const Pony &other);

  Pony(const Pony &other);

  void SayName() const;

  void PonyWent() const;

  void Eating() const;
};


#endif  // PONY_HPP
