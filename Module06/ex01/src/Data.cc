//
// Created by Aaron Berry on 4/28/21.
//

#include <string>
#include <iostream>

#include "includes/Data.h"

static char RandomChar() {
  static char alpha[63] =
          "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789";
  static int alpha_len = strlen(alpha);
  return alpha[rand() % alpha_len];
}
static char RandomInt() {
  return rand() % INT64_MAX;
}

void *serialize() {
  char *bits_line = new char (8 + 4 + 8);
  for (int i = 0; i < 8; ++i) {
    bits_line[i] = RandomChar();
  }
  bits_line[8] = '\0';
  std::cout << "serialize str1: " << bits_line << std::endl;
  int nbr = RandomInt();
  std::cout << "serialize n: " << nbr << std::endl;
  *reinterpret_cast<int*>(bits_line + 8) = nbr;
  std::cout << "serialize str1: ";
  for (int i = 12; i < 20; ++i) {
    bits_line[i] = RandomChar();
    std::cout << bits_line[i];
  }
  std::cout << std::endl;
  return (reinterpret_cast<void*>(bits_line));
}

Data *deserialize(void *raw) {
  char *bits_line = reinterpret_cast<char*>(raw);
  Data *prt = new Data;
  prt->str1 = std::string((bits_line), 8);
  prt->n = *reinterpret_cast<int*>(bits_line + 8);
  prt->str2 = std::string((bits_line + 12), 8);
  return prt;
}
