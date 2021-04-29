//
// Created by Aaron Berry on 4/28/21.
//

#pragma once

template<typename T>
void Iter(T (*array), int size, void (*func)(T &)) {
  for (int i = 0; i < size; ++i) {
    func(array[i]);
  }
}

template <typename T>
void Print(T &elem) {
  std::cout << elem << std::endl;
}

template <typename T>
void Print(const T &elem) {
  std::cout << elem << std::endl;
}
