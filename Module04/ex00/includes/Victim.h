//
// Created by Aaron Berry on 4/21/21.
//

#pragma once

#include <string>

class Victim {
 public:
  explicit Victim(const std::string &name);
  Victim(Victim const &other);
  virtual ~Victim();
  Victim            &operator=(Victim const &other);

  const std::string &getName() const;
  void              setName(const std::string &name);

  virtual void      getPolymorphed() const;

 private:
  std::string       name_;

 protected:
  Victim();
};

std::ostream      &operator<<(std::ostream &out, Victim const &Victim);


