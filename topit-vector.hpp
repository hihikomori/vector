#include <cassert>
#include <cstddef>
#ifndef TOPIT_VECTOR_HPP
#define TOPIT_VECTOR_HPP

namespace topit
{
  template < class T >
  class Vector
  {
    using value_type = T;

  public:
    Vector();
    Vector(const Vector< value_type > &);
    ~Vector();
    Vector< value_type > &operator=(const Vector< value_type > &);

    bool empty();
    void pushback(const T &);
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;
    value_type &operator[](size_t) noexcept;
    const value_type &operator[](size_t) const noexcept;
    void swap(Vector< T > &other) noexcept;

    void popback();

  private:
    explicit Vector(size_t);
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
  Vector< T >::Vector(size_t k):
    data_(new T[k]),
    size_(k),
    capacity_(k)
  {}

  template < class T >
  Vector< T >::~Vector()
  {
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
  void Vector< T >::pushback(const T &val)
  {
    if (size_ == capacity_) {
      size_t new_cap = size_ ? (capacity_ * 1.5) : 2;
      T *tmp_data_ = new T[new_cap];
      capacity_ = new_cap;
      for (size_t i = 0; i < size_; ++i) {
        tmp_data_[i] = data_[i];
      }
      data_ = tmp_data_;
    }

    data_[size_++] = val;
  }

  template < class T >
  size_t Vector< T >::getSize() const noexcept
  {
    return size_;
  }

  template < class T >
  Vector< T >::Vector(const Vector< T > &other):
    Vector(other.getSize())
  {
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }

  template < class T >
  T &Vector< T >::operator[](size_t id) noexcept
  {
    return data_[id];
  }

  template < class T >
  const T &Vector< T >::operator[](size_t id) const noexcept
  {
    return data_[id];
  }

  template < class T >
  Vector< T > &Vector< T >::operator=(const Vector< T > &other)
  {
    if (this == &other) {
      return *this;
    }

    Vector< T > cpy(other);
    swap(cpy);
    return *this;
  }

  template < class T >
  void Vector< T >::swap(Vector< T > &other) noexcept
  {
    std::swap(other.data_, data_);
    std::swap(other.size_, size_);
    std::swap(other.capacity_, capacity_);
  }

  template < class T >
  size_t Vector< T >::getCapacity() const noexcept
  {
    return capacity_;
  }
}

#endif