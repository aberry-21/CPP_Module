//
// Created by Aaron Berry on 4/28/21.
//

#pragma once

#include <new>
#include <string>

class ArrayIndexException: public std::exception {
 public:
  ArrayIndexException()
  throw() {}
  ArrayIndexException(ArrayIndexException const &other)
  throw() : m_error(other.m_error) {}
  ArrayIndexException &operator=(const ArrayIndexException &other)
  throw() { std::exception::operator=(other), return *this; }
  virtual ~ArrayIndexException()
  throw() {}
  explicit ArrayIndexException(const std::string& error)
  : m_error(error) {}
  const char *what() const
  throw() { return m_error.c_str(); }
 private:
  std::string m_error;
};

template <class T>
class Array {
 public:
  Array() : data_(nullptr), len_(0) {}

  explicit Array(unsigned int len) {
    if (len <= 0) {
      throw ArrayIndexException("Len must be more than 0");
    }
    len_ = len;
    try {
      data_ = new T[len_]();
    } catch (std::bad_alloc& ba) {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
  }

  Array(Array const &other) {
    len_ = other.len_;
    try {
      data_ = new T[len_]();
    } catch (std::bad_alloc& ba) {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
      return;
    }
    for (size_t i = 0; i < len_; ++i) {
      data_[i] = other.data_[i];
    }
  }

  Array &operator=(Array const &other) {
    if (this == &other) {
      return *this;
    }
    len_ = other.len_;
    T *tmp_data = data_;
    try {
      data_ = new T[len_]();
    } catch (std::bad_alloc& ba) {
      std::cerr << "bad_alloc caught: " << ba.what() << '\n';
      data_ = tmp_data;
      return *this;
    }
    for (size_t i = 0; i < len_; ++i) {
      data_[i] = other.data_[i];
    }
    delete tmp_data;
    return *this;
  }

  virtual ~Array() {
    delete [] data_;
  }

  T& operator[](unsigned int index) {
    if (index >= len_) {
      throw ArrayIndexException("Index must be less than len");
    }
    return data_[index];
  }

  size_t getLen() const {
    return len_;
  }

  T *getData() const {
    return data_;
  }

 private:
  T       *data_;
  size_t  len_;
};
