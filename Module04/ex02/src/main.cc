//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>

#include "includes/ISpaceMarine.h"
#include "includes/ISquad.h"
#include "includes/Squad.h"
#include "includes/TacticalMarine.h"
#include "includes/AssaultTerminator.h"

int     main() {
  ISpaceMarine* bob = new TacticalMarine;
  ISpaceMarine* jim = new AssaultTerminator;
  ISquad* vlc = new Squad;
  vlc->push(bob);
  vlc->push(jim);
  for (int i = 0; i < vlc->getCount(); ++i)
  {
    ISpaceMarine* cur = vlc->getUnit(i);
    cur->battleCry();
    cur->rangedAttack();
    cur->meleeAttack();
  }
  delete vlc;
  ISquad *squad = new Squad;
  ISpaceMarine *unit = new AssaultTerminator;
  for (int i = 0; i < 100; ++i)
    squad->push(new TacticalMarine);
  squad->push(unit);
  squad->push(unit);
  delete squad;
  return 0;
}
