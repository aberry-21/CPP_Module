//
// Created by Aaron Berry on 4/29/21.
//

#include "includes/Span.h"
Span::Span(u_int32_t size) : size_(size) {}

Span::~Span() {
  storage_.clear();
}

Span::Span(const Span &other) : storage_(other.storage_), size_(other.size_) {}

Span &Span::operator=(const Span &other) {
  if (this == &other) {
    return *this;
  }
  size_ = other.size_;
  storage_.clear();
  storage_ = other.storage_;
  return *this;
}

void Span::addNumber(int value) {
  if (storage_.size() >= size_) {
    throw SpanException("Storage is full.");
  }
  storage_.insert(value);
}

int Span::shortestSpan() const {
  if (storage_.size() != size_ || size_ == 1) {
    throw SpanException("Storage is not full.");
  }
  std::multiset<int>::const_iterator low = storage_.cbegin();
  std::multiset<int>::const_iterator fast = storage_.cbegin();
  std::multiset<int>::const_iterator end = storage_.end();
  ++fast;
  int shorsspan = longestSpan();
  for (; fast != end; ++fast, ++low) {
    if (shorsspan > *fast - *low) {
      shorsspan = *fast - *low;
    }
  }
  return shorsspan;
}

int Span::longestSpan() const {
  if (storage_.size() != size_ || size_ == 1) {
    throw SpanException("Storage is not full.");
  }
  std::multiset<int>::const_iterator begin = storage_.cbegin();
  std::multiset<int>::const_iterator end = storage_.cend();
  --end;
  return (*end - *begin);
}
