#ifndef TOPIT_VECTOR_HPP
#define TOPIT_VECTOR_HPP
#include <cstddef>

namespace topit
{
  template < class T > class Vector
  {
    using value_type = T;
  public:
  private:
    value_type *data_;
    size_t size_, capacity_;
  };
}
#endif