//
// Created by Aaron Berry on 4/13/21.
//

#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char *argv[]) {
  if (argc < 2)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  for (int i = 1; i < argc; ++i) {
    size_t size = strlen(argv[i]);
    for (size_t j = 0; j < size; ++j) {
      std::cout << static_cast<char>(toupper(argv[i][j]));
    }
  }
  std::cout << std::endl;
  return 0;
}
