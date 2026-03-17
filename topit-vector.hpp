#ifndef TOPIT_VECTOR_HPP
#define TOPIT_VECTOR_HPP
#include <cstddef>

namespace topit
{
  template < class T > class Vector
  {
    using value_type = T;

  public:
    Vector();
    Vector(const Vector< value_type > &) = delete;
    ~Vector();
    Vector< value_type > &operator=(const Vector< value_type > &) = delete;

    bool empty();

  private:
    value_type *data_;
    size_t size_, capacity_;
  };

  template < class T >
  Vector< T >::Vector():
    data_(nullptr),
    size_(0),
    capacity_(0)
  {}

  template < class T >
  Vector< T >::~Vector(){
    delete data_;
    size_ = 0;
    capacity_ = 0;
  }

  template < class T >
  bool Vector< T >::empty()
  {
    return !size_;
  }
}
#endif