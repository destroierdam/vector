#pragma once
#include <cstddef>

template<typename T>
class Vector {
private:
    T* data;
    std::size_t size, capacity;

public:
    Vector();

    Vector& push_back(const T& el);
    Vector& pop_back();
};

template<typename T>
Vector<T>::Vector() {
    this->size = 0;
    this->capacity = 8;
    this->data = new T[this->capacity];
}

template<typename T>
Vector<T>& Vector<T>::push_back(const T& element) {
    this->data[size] = element;
	this->size++;

    return *this;
}

template<typename T>
Vector<T>& Vector<T>::pop_back()
{
    if(this->size <= 0) {
        return *this;
    }
    this->size--;

    return *this;
}
