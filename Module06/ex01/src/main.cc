//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>

#include "includes/Data.h"

int main() {
  srand(time(nullptr));
  void *raw = serialize();
  Data *data_prt = deserialize(raw);
  std::cout << "______________main________________" << std::endl;
  std::cout << data_prt->str1 << std::endl;
  std::cout << data_prt->n << std::endl;
  std::cout << data_prt->str2 << std::endl;
  std::cout << "__________________________________" << std::endl;
  delete data_prt;
  delete static_cast<char *>(raw);
  return 0;
}
