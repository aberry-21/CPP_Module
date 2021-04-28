//
// Created by Aaron Berry on 4/28/21.
//

#pragma once

template<typename T>
void iter(T (*array), int size, void (*func)(T &))
{
  for (int i = 0; i < size; ++i) {
    func(array[i]);
  }
}

template <typename T>
void    print(T &elem)
{
  std::cout << elem << std::endl;
}