//
// Created by Aaron Berry on 4/28/21.
//

#pragma once

#include <string>

class NotFoundException: public std::exception {
 public:
  NotFoundException()
  throw() {}
  NotFoundException(NotFoundException const &other)
  throw() : m_error(other.m_error) {}
  NotFoundException &operator=(const NotFoundException &other)
  throw() { std::exception::operator=(other); return *this; }
  virtual ~NotFoundException()
  throw() {}
  explicit NotFoundException(const std::string& error)
          : m_error(error) {}
  const char *what() const
  throw() { return m_error.c_str(); }
 private:
  std::string m_error;
};

template<typename T>
typename T::iterator Easyfind(T &target, const int elem) {
  typename T::iterator iter;
  iter = std::find(target.begin(), target.end(), elem);
  if (iter == target.end())
    throw NotFoundException("Not found elem");
  return (iter);
}
