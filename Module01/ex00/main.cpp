//
// Created by Aaron Berry on 4/17/21.
//

#include <iostream>

#include "Pony.hpp"

static void ponyOnTheStack() {
  std::cout << "ponyOnTheStack" << std::endl;
  std::cout << "__________" << std::endl;
  Pony  pony_stack;
  pony_stack.setNickname("Pppppony");
  pony_stack.setAge(12);
  pony_stack.setColor("black");
  pony_stack.setFullName("black pony");
  pony_stack.setGender("man");
  pony_stack.setHeight(100);
  pony_stack.SayName();
  pony_stack.Eating();
  pony_stack.PonyWent();
  std::cout << "__________" << std::endl;
}

static void ponyOnTheHeap() {
  std::cout << "ponyOnTheHeap" << std::endl;
  std::cout << "__________" << std::endl;
  Pony *pony_stack = new Pony(12, 22, "white", "White pony",
                                          "wwwwhite", "woman");
  pony_stack->SayName();
  pony_stack->Eating();
  pony_stack->PonyWent();
  delete pony_stack;
  std::cout << "__________" << std::endl;
}

int main() {
  ponyOnTheStack();
  std::cout << "\n" << std::endl;
  ponyOnTheHeap();
  return 0;
}
