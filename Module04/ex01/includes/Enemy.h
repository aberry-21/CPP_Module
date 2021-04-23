//
// Created by Aaron Berry on 4/22/21.
//

#pragma once

#include <string>

class Enemy {
 public:
  Enemy(int hitPoint, const std::string &type);
  Enemy(Enemy const &other);
  virtual ~Enemy();
  Enemy               &operator=(Enemy const &other);
  virtual void        takeDamage(int damage);
  int                 getHitPoint() const;
  const std::string   &getType() const;

 private:
  Enemy();
  int                 hit_point_;
  std::string         type_;
};
