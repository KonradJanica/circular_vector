#include "circularbuffer.h"

#include <iostream>

void Print(circular_buffer<int> input);

void TestMethods();
void TestObjectOperators();
void TestIteratorOperators();
void TestIteratorAccess();

int main() {
  
  TestMethods();

  TestObjectOperators();

  TestIteratorOperators();

  TestIteratorAccess();
}

// Prints all elements in the %circular_buffer
void Print(circular_buffer<int> input) {
  for (size_t x = 0; x < input.size(); ++x) {
    std::cout << input.at(x) << ",";
  }
  std::cout << std::endl;
}

// Test Methods
void TestMethods() {
  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER PUSH_BACK METHOD" << std::endl;

  circular_buffer<int> test1;

  size_t count = 0;
  std::cout << "Pushing back: ";
  for (int x = 0; x < 13; ++x) {
    test1.push_back(x);
    std::cout << x << ",";
    ++count;
  }
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  Print(test1);
  if (count == test1.size())
    std::cout << "Push_back method passes" << std::endl;
  else
    std::cout << "Push_back method fails" << std::endl;

  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER POP_BACK METHOD" << std::endl;

  std::cout << "Popping back: ";
  for (int x = 0; x < 3; ++x) {
    test1.pop_back();
    std::cout << x << ",";
    --count;
  }
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  Print(test1);
  if (count == test1.size())
    std::cout << "Push_back method passes" << std::endl;
  else
    std::cout << "Push_back method fails" << std::endl;

  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER POP_FRONT METHOD" << std::endl;

  std::cout << "Popping front: ";
  for (int x = 0; x < 6; ++x) {
    test1.pop_front();
    std::cout << x << ",";
    --count;
  }
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  Print(test1);
  if (count == test1.size())
    std::cout << "Pop_front method passes" << std::endl;
  else
    std::cout << "Pop_front method fails" << std::endl;

  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER CLEAR METHOD" << std::endl;

  std::cout << "Clearing CIRCULAR_BUFFER...";
  test1.clear();
  count = 0;
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  Print(test1);
  if (test1.size() == 0)
    std::cout << "Clear method passes" << std::endl;
  else
    std::cout << "Clear method fails" << std::endl;

  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER PUSH_FRONT METHOD" << std::endl;

  std::cout << "Pushing front: ";
  for (int x = 0; x < 6; ++x) {
    test1.push_front(x);
    std::cout << x << ",";
    ++count;
  }
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  Print(test1);
  if (count == test1.size())
    std::cout << "Push_front method passes" << std::endl;
  else
    std::cout << "Push_front method fails" << std::endl;

  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER ASSIGN METHOD" << std::endl;

  std::cout << "ASSIGNING CIRCULAR_BUFFER TO: n = 3, val = 4...";
  test1.assign((size_t)3, (int)4);
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  Print(test1);
  if (test1.size() == 3)
    std::cout << "Assign method passes" << std::endl;
  else
    std::cout << "Assign method fails" << std::endl;
  std::cout << "Note: other assign prototype using iterators is used and tested interally" << std::endl;

  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER RESIZE METHOD" << std::endl;

  std::cout << "RESIZING CIRCULAR_BUFFER TO: n = 1, val = 2...";
  test1.resize(1, 2);
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  Print(test1);
  if (test1.size() == 1)
    std::cout << "Resize method passes" << std::endl;
  else
    std::cout << "Resize method fails" << std::endl;

  std::cout << "RESIZING CIRCULAR_BUFFER TO: n = 6, val = 2...";
  test1.resize(6, 2);
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  Print(test1);
  if (test1.size() == 6)
    std::cout << "Resize method passes" << std::endl;
  else
    std::cout << "Resize method fails" << std::endl;

  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER RESERVE METHOD" << std::endl;

  std::cout << "RESERVING CIRCULAR_BUFFER TO: n = 30...";
  test1.reserve(30);
  std::cout << std::endl;
  if (test1.capacity() == 30)
    std::cout << "Reserve method passes" << std::endl;
  else
    std::cout << "Reserve method fails" << std::endl;
  std::cout << "Note: tested and used more thoroughly interally" << std::endl;

  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER SWAP METHOD" << std::endl;

  circular_buffer<int> test2;
  std::cout << "PUSHING BACK [0...9) to test2";
  for (int x = 0; x < 9; ++x) {
    test2.push_back(x);
  }
  std::cout << std::endl;
  std::cout << "Printing test1: ";
  Print(test1);
  std::cout << "Printing test2: ";
  Print(test2);
  std::cout << "SWAPPING..." << std::endl;
  test1.swap(test2);
  std::cout << "Printing test1: ";
  Print(test1);
  std::cout << "Printing test2: ";
  Print(test2);
  std::cout << "Note: tested and used more thoroughly interally" << std::endl;

}

// Test %circular_buffer object relational operators
void TestObjectOperators() {
  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER OBJECT RELATIONAL OPERATORS" << std::endl;

  circular_buffer<int> test1;
  circular_buffer<int> test2;

  // TESTING %circular_buffer == operator
  test1.clear();
  test1.resize(5, 1);
  test2.clear();
  test2.resize(5, 1);

  if (test1 == test2)
    std::cout << "== operator passes" << std::endl;
  else
    std::cout << "== operator fails" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(5,1);
  test2.resize(5,2);

  if (test1 == test2)
    std::cout << "== operator fails" << std::endl;
  else
    std::cout << "== operator passes" << std::endl;

  // TESTING %circular_buffer < operator
  test1.clear();
  test2.clear();
  test1.resize(5,1);
  test2.resize(5,2);

  if (test1 < test2)
    std::cout << "< operator passes" << std::endl;
  else
    std::cout << "< operator fails" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(3,3);
  test2.resize(5,2);

  if (test1 < test2)
    std::cout << "< operator fails" << std::endl;
  else
    std::cout << "< operator passes" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(5,2);
  test2.resize(5,2);

  if (test1 < test2)
    std::cout << "< operator fails" << std::endl;
  else
    std::cout << "< operator passes" << std::endl;

  // TESTING %circular_buffer > operator
  test1.clear();
  test2.clear();
  test1.resize(5,1);
  test2.resize(5,2);

  if (test1 > test2)
    std::cout << "> operator fails" << std::endl;
  else
    std::cout << "> operator passes" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(3,3);
  test2.resize(5,2);

  if (test1 > test2)
    std::cout << "> operator passes" << std::endl;
  else
    std::cout << "> operator fails" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(5,2);
  test2.resize(5,2);

  if (test1 > test2)
    std::cout << "> operator fails" << std::endl;
  else
    std::cout << "> operator passes" << std::endl;

  // TESTING %circular_buffer <= operator
  test1.clear();
  test2.clear();
  test1.resize(5,1);
  test2.resize(5,2);

  if (test1 <= test2)
    std::cout << "<= operator passes" << std::endl;
  else
    std::cout << "<= operator fails" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(3,3);
  test2.resize(5,2);

  if (test1 <= test2)
    std::cout << "<= operator fails" << std::endl;
  else
    std::cout << "<= operator passes" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(5,2);
  test2.resize(5,2);

  if (test1 <= test2)
    std::cout << "<= operator passes" << std::endl;
  else
    std::cout << "<= operator fails" << std::endl;

  // TESTING %circular_buffer >= operator
  test1.clear();
  test2.clear();
  test1.resize(5,1);
  test2.resize(5,2);

  if (test1 >= test2)
    std::cout << ">= operator fails" << std::endl;
  else
    std::cout << ">= operator passes" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(3,3);
  test2.resize(5,2);

  if (test1 >= test2)
    std::cout << ">= operator passes" << std::endl;
  else
    std::cout << ">= operator fails" << std::endl;

  test1.clear();
  test2.clear();
  test1.resize(5,2);
  test2.resize(5,2);

  if (test1 >= test2)
    std::cout << ">= operator passes" << std::endl;
  else
    std::cout << ">= operator fails" << std::endl;
}

void TestIteratorOperators() {
  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER ITERATOR RELATIONAL OPERATORS" << std::endl;

  // TESTING CIRCULAR_BUFFER ITERATORS
  circular_buffer<int> test1;
  test1.resize(10, 4);

  // Testing == operator
  circular_buffer<int>::iterator it = test1.begin();
  circular_buffer<int>::iterator it2 = test1.begin()+1;
  if (it == it2)
    std::cout << "iterator == operator fails" << std::endl;
  else
    std::cout << "iterator == operator passes" << std::endl;
  --it2;
  if (it == it2)
    std::cout << "iterator == operator passes" << std::endl;
  else
    std::cout << "iterator == operator fails" << std::endl;

  // Testing > operator
  it = test1.begin();
  it2 = test1.begin();
  if (it > it2)
    std::cout << "iterator > operator fails" << std::endl;
  else
    std::cout << "iterator > operator passes" << std::endl;
  ++it;
  if (it > it2)
    std::cout << "iterator > operator passes" << std::endl;
  else
    std::cout << "iterator > operator fails" << std::endl;
  --it;
  ++it2;
  if (it > it2)
    std::cout << "iterator > operator fails" << std::endl;
  else
    std::cout << "iterator > operator passes" << std::endl;

  // Testing < operator
  it = test1.begin();
  it2 = test1.begin();
  if (it < it2)
    std::cout << "iterator < operator fails" << std::endl;
  else
    std::cout << "iterator < operator passes" << std::endl;
  ++it2;
  if (it < it2)
    std::cout << "iterator < operator passes" << std::endl;
  else
    std::cout << "iterator < operator fails" << std::endl;
  it = test1.begin();
  it2 = test1.begin();
  ++it;
  if (it < it2)
    std::cout << "iterator < operator fails" << std::endl;
  else
    std::cout << "iterator < operator passes" << std::endl;

  // Testing <= operator
  it = test1.begin();
  it2 = test1.begin();
  if (it <= it2)
    std::cout << "iterator <= operator passes" << std::endl;
  else
    std::cout << "iterator <= operator fails" << std::endl;
  ++it2;
  if (it <= it2)
    std::cout << "iterator <= operator passes" << std::endl;
  else
    std::cout << "iterator <= operator fails" << std::endl;
  it = test1.begin();
  it2 = test1.begin();
  ++it;
  if (it <= it2)
    std::cout << "iterator <= operator fails" << std::endl;
  else
    std::cout << "iterator <= operator passes" << std::endl;

  // Testing >= operator
  it = test1.begin();
  it2 = test1.begin();
  if (it >= it2)
    std::cout << "iterator >= operator passes" << std::endl;
  else
    std::cout << "iterator >= operator fails" << std::endl;
  ++it2;
  if (it >= it2)
    std::cout << "iterator >= operator fails" << std::endl;
  else
    std::cout << "iterator >= operator passes" << std::endl;
  it = test1.begin();
  it2 = test1.begin();
  ++it;
  if (it >= it2)
    std::cout << "iterator >= operator passes" << std::endl;
  else
    std::cout << "iterator >= operator fails" << std::endl;
  
}

void TestIteratorAccess() {
  std::cout << "======================================================" << std::endl;
  std::cout << "TESTING CIRCULAR_BUFFER ITERATOR LOOP ELEMENT ACCESS" << std::endl;

  circular_buffer<int> test1;
  test1.resize(6, 4);
  std::cout << "Mutating circular_buffer to 6 elements of value 4" << std::endl;

  circular_buffer<int>::iterator it = test1.begin();

  std::cout << "Printing circular_buffer: ";
  size_t count = 0;
  while (it != test1.end()) {
    std::cout << *it << ",";
    ++it;
    ++count;
  }
  std::cout << std::endl;

  if (count == test1.size())
    std::cout << "Iterator access passes" << std::endl;
  else
    std::cout << "Iterator access fails" << std::endl;

  test1.clear();
  count = 0;
  std::cout << "Mutating circular_buffer to [0...13)" << std::endl;
  for (int x = 0; x < 13; ++x) {
    test1.push_back(x);
    std::cout << x << ",";
  }
  it = test1.begin();
  std::cout << std::endl;
  std::cout << "Printing circular_buffer: ";
  while (it != test1.end()) {
    std::cout << *it << ",";
    ++it;
    ++count;
  }
  std::cout << std::endl;

  if (count == test1.size())
    std::cout << "Iterator access passes" << std::endl;
  else
    std::cout << "Iterator access fails" << std::endl;
}
