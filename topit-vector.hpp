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
    using size_type = size_t;

  public:
    Vector();
    Vector(const Vector< value_type > &);
    Vector< value_type > &operator=(const Vector< value_type > &);
    value_type &operator[](size_type) noexcept;
    const value_type &operator[](size_type) const noexcept;
    ~Vector();

    void pushback(const value_type &);
    void pushfront(const value_type &);
    void popback();

    bool empty() const noexcept;
    size_type getSize() const noexcept;
    size_type getCapacity() const noexcept;

    void swap(Vector< value_type > &other) noexcept;

  private:
    explicit Vector(size_type);
    value_type *data_;
    size_type size_, capacity_;
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
  bool Vector< T >::empty() const noexcept
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

  template < class T >
  void Vector< T >::popback()
  {
    --size_;
  }

  template < class T >
  void Vector< T >::pushfront(const T &value)
  {
    if (size_ == capacity_) {
      capacity_ = size_ ? (capacity_ * 1.5) : 2;
    }

    T *tmp_data_ = new T[capacity_];
    if (size_ > 1) {
      size_t j = 1;
      for (size_t i = 0; i < size_; ++i) {
        tmp_data_[j] = data_[i];
        j++;
      }
    }
    tmp_data_[0] = value;
    ++size_;

    data_ = tmp_data_;
  }
}

#endif