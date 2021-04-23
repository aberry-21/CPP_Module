//
// Created by Aaron Berry on 4/22/21.
//

#include "includes/Enemy.h"

Enemy::Enemy()
      : hit_point_(),
        type_() {}

Enemy::Enemy(int hitPoint, const std::string &type)
      : hit_point_(hitPoint),
        type_(type) {}

Enemy::Enemy(const Enemy &other)
      : hit_point_(other.hit_point_),
        type_(other.type_){}

Enemy::~Enemy() {}

Enemy &Enemy::operator=(const Enemy &other) {
  if (this == &other)
    return *this;
  hit_point_ = other.hit_point_;
  type_ = other.type_;
  return *this;
}

int Enemy::getHitPoint() const {
  return hit_point_;
}

const std::string &Enemy::getType() const {
  return type_;
}

void    Enemy::takeDamage(int damage) {
  if (damage < 0)
    return ;
  if (hit_point_ - damage < 0) {
    hit_point_ = 0;
  } else {
    hit_point_ -= damage;
  }
}