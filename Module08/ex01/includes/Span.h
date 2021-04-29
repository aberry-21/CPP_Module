//
// Created by Aaron Berry on 4/29/21.
//

#pragma once

#include <set>
#include <string>

class SpanException: public std::exception {
 public:
  SpanException()
  throw() {}
  SpanException(SpanException const &other)
  throw() : m_error(other.m_error) {}
  SpanException &operator=(const SpanException &other)
  throw() { std::exception::operator=(other); return *this; }
  virtual ~SpanException()
  throw() {}
  explicit SpanException(const std::string& error)
      : m_error(error) {}
  const char *what() const
  throw() { return m_error.c_str(); }
 private:
  std::string m_error;
};

class Span {
 public:
  explicit Span(u_int32_t size);
  virtual ~Span();
  Span(Span const &other);
  Span &operator=(Span const &other);
  void addNumber(int value);
  int shortestSpan() const;
  int longestSpan() const;
 private:
  std::multiset<int>  storage_;
  u_int32_t           size_;
};
