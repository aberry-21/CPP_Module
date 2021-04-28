//
// Created by Aaron Berry on 4/28/21.
//

#pragma once

#include <string>

struct Data {
  std::string str1;
  int         n;
  std::string str2;
};

void *serialize();

Data *deserialize(void *raw);
