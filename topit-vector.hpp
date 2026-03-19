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
    void pushback(const T&);
    size_t getSize();
    size_t getCapacity();

    void popback();
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

  template < class T >
  void Vector< T >::pushback(const T&)
  {}

  template < class T >
  size_t Vector< T >::getSize()
  {
    return 0;
  }

}
#endif