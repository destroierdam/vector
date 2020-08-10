#pragma once
#include <cstddef>

template<typename T>
class Vector {
    T* data;
    std::size_t size, capacity;

    Vector();
};

template<typename T>
Vector<T>::Vector() {
    this->size = 0;
    this->capacity = 8;
    this->data = new T[this->capacity];
}
