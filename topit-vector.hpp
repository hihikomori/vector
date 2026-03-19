#include <cstddef>
#include <cassert>
#ifndef TOPIT_VECTOR_HPP
#define TOPIT_VECTOR_HPP

namespace topit
{
  template < class T > class Vector
  {
    using value_type = T;

  public:
    Vector();
    Vector(const Vector< value_type > &);
    ~Vector();
    Vector< value_type > &operator=(const Vector< value_type > &) = delete;

    bool empty();
    void pushback(const T &);
    size_t getSize();
    size_t getCapacity();
    value_type &operator[](size_t) noexcept;
    const value_type &operator[](size_t) const noexcept;

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

  template < class T > Vector< T >::~Vector()
  {
    delete data_;
    size_ = 0;
    capacity_ = 0;
  }

  template < class T > bool Vector< T >::empty()
  {
    return !size_;
  }

  template < class T > void Vector< T >::pushback(const T &val)
  {
    if (size_ == capacity_) {
      size_t new_cap = size_ ? capacity_ * 1.5 : 2;
      T *tmp_data_ = new T[new_cap];
      for (size_t i = 0; i < size_; ++i) {
        tmp_data_[i] = data_[i];
      }
      data_ = tmp_data_;
    }

    data_[size_++] = val;
  }

  template < class T > size_t Vector< T >::getSize()
  {
    return size_;
  }

  template < class T >
  Vector< T >::Vector(const Vector< T > &other):
    data_(new T[other.size_]),
    size_(other.size_),
    capacity_(other.capacity_)
  {
    for(size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }

  template < class T > T &Vector< T >::operator[](size_t id) noexcept
  {
    return data_[id];
  }

  template < class T > const T &Vector< T >::operator[](size_t id) const noexcept
  {
    return data_[id];
  }
}

#endif