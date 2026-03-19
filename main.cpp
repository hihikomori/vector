#include <iostream>
#include "topit-vector.hpp"

bool testDefauilVector()
{
  topit::Vector< int > v;
  bool c = v.empty();
  return c;
}

bool testVectorWithValue()
{
  topit::Vector< int > v;
  bool c1 = v.empty();
  v.pushback(12);
  bool c2 = v.empty();
  return c1 && (!c2);
}

bool testGetSize()
{
  topit::Vector< int > v;
  v.pushback(2);
  bool c = (v.getSize() == 1);
  return c;
}

bool testCopyConstructor()
{
  topit::Vector< int > v;
  v.pushback(2);
  v.pushback(3);
  bool c = (v.getSize() == 2) && (v[1] == 3);
  topit::Vector< int > copied(v);

  bool c1 = (v.getSize() == 2) && (v[1] == 3);
  return c && c1;
}

bool testOperatorAt()
{
  topit::Vector< int > v;
  for (size_t i = 0; i < 5; ++i) {
    v.pushback(i);
  }

  bool c = true;
  for (size_t i = 0; i < v.getSize(); ++i) {
    c = (v[i] == i) && c;
  }

  return c;
}

bool testOperatorCopy()
{
  topit::Vector< int > v;
  for (size_t i = 0; i < 3; ++i) {
    v.pushback(i);
  }

  topit::Vector< int > v2;
  for (size_t i = 0; i < 4; ++i) {
    v2.pushback(i * 2);
  }

  bool c = (v.getSize() == 3 && v2.getSize() == 4) && (v[2] == 2 && v2[3] == 6);

  v2 = v;
  bool c2 = (v2.getSize() == 3 && v2[2] == 2) && !(v.empty());

  return c && c2;
}

int main()
{
  using test_t = bool (*)();
  using pair_t = std::pair< const char *, test_t >;
  pair_t tests[] = {{"default vector is empty", testDefauilVector},
                    {"vector with any value is not empty", testVectorWithValue},
                    {"getsize return actual size of vector", testGetSize},
                    {"copy constructor copy data_, size_ and capacity_", testCopyConstructor},
                    {"operator[] allows to view elem on pos", testOperatorAt},
                    {"copy operator does not delete copyble and copy it", testOperatorCopy}};

  const size_t count = sizeof(tests) / sizeof(pair_t);

  bool pass = true;
  std::cout << std::boolalpha;
  for (size_t i = 0; i < count; ++i) {
    bool res = tests[i].second();
    std::cout << tests[i].first << "Result = " << res << '\n';
    pass = pass && res;
  }
  std::cout << pass << '\n';
}
