//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>
#include "includes/CharType.h"
#include "includes/IntType.h"
#include "includes/FloatType.h"
#include "includes/DoubleType.h"

class BadValueException {
 public:
  explicit BadValueException(const std::string& error)
          : m_error(error) {}
  const char* getError() { return m_error.c_str(); }
 private:
  std::string m_error;
};

static double GetValue(const char *argv) {
  if (strlen(argv) == 0) {
    throw BadValueException("Invalid value");
  }
  if (strlen(argv) == 3) {
    if (argv[0] == '\'' && argv[2] == '\'') {
      return (static_cast<double>(argv[1]));
    }
  }
  char *prt_end = nullptr;
  double value = strtod(argv, &prt_end);
  size_t size = strlen(prt_end);
  if (size > 0) {
    if (size > 1) {
      throw BadValueException("Invalid value");
    } else {
      if (prt_end[0] != 'f')
        throw BadValueException("Invalid value");
    }
  }
  return value;
}

static void PrintAllType(double value, bool impossible) {
  CharType v_char(value, impossible, "char",
                  std::numeric_limits<char>::max(),
                  std::numeric_limits<char>::min());
  v_char.PrintValue();
  IntType v_int(value, impossible, "int",
                std::numeric_limits<int>::max(),
                std::numeric_limits<int>::min());
  v_int.PrintValue();
  FloatType v_float(value, impossible, "float",
                    std::numeric_limits<float>::max(),
                    -std::numeric_limits<float>::max());
  v_float.PrintValue();
  DoubleType v_double(value, impossible, "double",
                      std::numeric_limits<double>::max(),
                      -std::numeric_limits<double>::max());
  v_double.PrintValue();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "error: bad arguments"<< std::endl;
    return (1);
  }
  double value;
  bool impossible = false;
  try {
    value = GetValue(argv[1]);
  } catch (BadValueException &e) {
    impossible = true;
  }
  PrintAllType(value, impossible);
  return 0;
}
