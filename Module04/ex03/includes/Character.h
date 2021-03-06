//
// Created by Aaron Berry on 4/23/21.
//

#pragma once

# include <string>

# include "AMateria.h"
# include "ICharacter.h"

class Character : public ICharacter {
 public:
  explicit Character(const std::string& name);
  Character(Character const &other);
  virtual ~Character();
  Character           &operator=(Character const &other);
  std::string const   &getName() const;
  void                equip(AMateria* m);
  void                unequip(int idx);
  void                use(int idx, const ICharacter& target);

 private:
  std::string         name_;
  AMateria            *inventory_[4];
};
