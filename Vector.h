#pragma once
#include <cstddef>

template<typename T>
class Vector {
    T* data;
    std::size_t size, capacity;

    Vector();

    void push_back(const T& el);
    void pop_back();
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

template<typename T>
void Vector::pop_back()
{
    if(this->size <= 0)
    {
        return;
    } 

    T* smaller_vector = new T[capacity];
    for(size_t i = 0; i < this->size - 1, i++)
    {
        smaller_vector[i] = this->data[i];
    }
    
    delete[] this->vector;
    this->vector = smaller_vector;
    this->size--;
}
