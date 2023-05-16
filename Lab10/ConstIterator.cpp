//
// Created by darleet on 5/16/23.
//

#include "ConstIterator.h"

template<typename T>
ConstIterator<T>::~ConstIterator() = default;

template<typename T>
typename ConstIterator<T>::reference ConstIterator<T>::operator*() const {
    return *ptr_;
}

template<typename T>
typename ConstIterator<T>::pointer ConstIterator<T>::operator->() const {
    return &(*ptr_);
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator++() {
    ++ptr_;
    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator++(int) {
    ConstIterator<T> tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
ConstIterator<T> &ConstIterator<T>::operator--() {
    --ptr_;
    return *this;
}

template<typename T>
ConstIterator<T> ConstIterator<T>::operator--(int) {
    ConstIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool ConstIterator<T>::operator==(const ConstIterator &other) const {
    return ptr_ == other.ptr_;
}

template<typename T>
bool ConstIterator<T>::operator!=(const ConstIterator &other) const {
    return !(*this == other);
}

template class ConstIterator<int>;