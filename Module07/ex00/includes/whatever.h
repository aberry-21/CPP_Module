//
// Created by Aaron Berry on 4/28/21.
//

#pragma once

template<typename T>
T Min(const T &x, const T &y) {
  return (x < y ? x : y);
}

template<typename T>
T  Max(const T &x, const T &y) {
  return (x > y ? x : y);
}

template<typename T>
void Swap(T &x, T &y) {
  T tmp = x;
  x = y;
  y = tmp;
}
