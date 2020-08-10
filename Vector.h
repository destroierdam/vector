#pragma once
#include <cstddef>

template<typename T>
class Vector {
    T* data;
    std::size_t size, capacity;

    Vector();

    void push_back(const T& el);
};

template<typename T>
Vector::Vector() {
    this->size = 0;
    this->capacity = 8;
    this->data = new T[this->capacity];
}

template<typename T>
void Vector::push_back(const T& el) {
    this->data[size] = el;
	this->size++;
}
