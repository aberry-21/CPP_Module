//
// Created by Aaron Berry on 4/21/21.
//

#include "iostream"
#include "includes/Peon.h"
#include "includes/Sorcerer.h"
#include "includes/Victim.h"

int main() {
  Sorcerer robert("Robert", "the Magnificent");
  Victim jim("Jimmy");
  Peon joe("Joe");
  std::cout << robert << jim << joe;
  robert.Polymorph(jim);
  robert.Polymorph(joe);
  return 0;
}
