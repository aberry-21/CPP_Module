//
// Created by Aaron Berry on 4/23/21.
//

#pragma once

#include <string>
#include <cstdint>

#include "ICharacter.h"

class ICharacter;

class AMateria {
 public:
  explicit AMateria(std::string const &type);
  AMateria(AMateria const &other);
  virtual ~AMateria();
  AMateria            &operator=(AMateria const &other);
  const std::string   &getType() const;  // Returns the materia type
  uint32_t            getXp() const;  // Returns the Materia's XP
  virtual AMateria*   clone() const = 0;
  virtual void        use(const ICharacter &target);

 private:
  std::string type_;
  uint32_t    xp_;
};
