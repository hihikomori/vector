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
  std::cout << v.getSize();
  bool c = (v.getSize() == 1);
  return c;
}

int main()
{
  using test_t = bool (*)();
  using pair_t = std::pair< const char *, test_t >;
  pair_t tests[] = {{"default vector is empty", testDefauilVector},
                    {"vector with any value is not empty", testVectorWithValue},
                    {"getsize return actual size of vector", testGetSize}};

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
