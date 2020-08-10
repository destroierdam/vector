#pragma once
#include <cstddef>

template<typename T>
class Vector {
private:
    T* data;
    std::size_t size, capacity;
 
    void copy(const Vector& other);
    void destroy();
public:
    Vector();

    Vector& push_back(const T& el);
    Vector& pop_back();
};

template<typename T>
void copy(const Vector& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    for(std::size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

template<typename T>
void Vector<T>::destroy() {
    delete[] this->data;
}

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
