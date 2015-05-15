#include "circularbuffer.h"

#include <iostream>

int main() {
  circular_buffer<int> test;

  // Test push back
  for (int x = 0; x < 13; ++x) {
    test.push_front(x);
  }
  for (size_t x = 0; x < test.size(); ++x) {
    std::cout << test[x] << ",";
  }
  std::cout << std::endl;

  test.pop_front();
  test.pop_back();
  test.pop_back();
  std::cout << test.size() << std::endl;
  std::cout << test.back() << std::endl;
  
  circular_buffer<int>::iterator it = test.begin();
  while (it != test.end()) {
    std::cout << *it << ",";
    ++it;
  }
}
