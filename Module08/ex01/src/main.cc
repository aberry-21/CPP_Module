//
// Created by Aaron Berry on 4/21/21.
//

#include <iostream>
#include <list>
#include <vector>
#include "includes/Span.h"

int main() {
  {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  try {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (const SpanException &e) {
    std::cout << "error: " << e.what() << std::endl;
  }
  try {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(11);
    sp.addNumber(11);
    sp.addNumber(11);
    sp.addNumber(11);
    sp.addNumber(11);
    sp.addNumber(11);
    sp.addNumber(11);
  } catch (const SpanException &e) {
    std::cout << "error: " << e.what() << std::endl;
  }
}
