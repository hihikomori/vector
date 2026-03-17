#include <iostream>
#include "topit-vector.hpp"

bool testDefauilVector()
{
  topit::Vector< int > v;
  bool c = v.empty();
  return c;
}

int main()
{
  using test_t = bool(*)();
  using pair_t = std::pair< const char*, test_t >;
  pair_t tests[] = {
    {"default vector is empty", testDefauilVector}
  };
  const size_t count = sizeof(tests) / sizeof(pair_t);
  std::cout << std::boolalpha;
  for(size_t i = 0; i < count; ++i) {
    bool res = tests[i].second();
    std::cout << tests[i].first << "Result =" << res << '\n';
  }
}
