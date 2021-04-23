//
// Created by Aaron Berry on 4/21/21.
//

#include "includes/AMateria.h"
#include "includes/Cure.h"
#include "includes/Ice.h"
#include "includes/ICharacter.h"
#include "includes/Character.h"
#include "includes/IMateriaSource.h"
#include "includes/MateriaSource.h"

int main()
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete src;
  delete bob;
  delete me;
  return 0;
}
