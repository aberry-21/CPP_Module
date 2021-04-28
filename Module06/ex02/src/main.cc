//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>

#include "includes/A.h"
#include "includes/B.h"
#include "includes/C.h"
#include "includes/Base.h"

inline static Base *generate() {
  int random = rand() % 3;
  if (random == 0) {
    std::cout << "create A class" << std::endl;
    return (new A);
  } else if (random == 1) {
    std::cout << "create B class" << std::endl;
    return (new B);
  } else {
    std::cout << "create C class" << std::endl;
    return (new C);
  }
}

inline static void identify_from_pointer(Base *p) {
  if (dynamic_cast<A*>(p) != nullptr) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p) != nullptr) {
    std::cout << "B" << std::endl;
  } else {
    std::cout << "C" << std::endl;
  }
}

inline static void identify_from_reference(Base &p) {
  if (dynamic_cast<A*>(&p) != nullptr) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(&p) != nullptr) {
    std::cout << "B" << std::endl;
  } else {
    std::cout << "C" << std::endl;
  }
}

int main() {
  srand(time(nullptr));
  Base *base = generate();
  identify_from_pointer(base);
  identify_from_reference(*base);
  return 0;
}
