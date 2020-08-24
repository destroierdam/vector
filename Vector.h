#pragma once
#include <cstddef>
#include <utility>
#include <iostream>
template<typename T>
class Vector {
private:
	T* data;
	std::size_t size, capacity;

	void copy(const Vector& other) { // O(size)
		this->data = new T[other.capacity];

		for (size_t i = 0; i < other.size; i++) {
			this->data[i] = other.data[i];
		}

		this->size = other.size;
		this->capacity = other.capacity;
	}

	void resize() {
		this->capacity *= 2;
		T* bigger_buffer = new T[this->capacity];

		for (size_t i = 0; i < this->size; i++) {
			bigger_buffer[i] = this->data[i];
		}

		this->destroy();
		this->data = bigger_buffer;
	}

	void move(Vector&& other) { // O(1)
		this->data = other.data;
		this->size = other.size;
		this->capacity = other.capacity;
		other.data = nullptr;
	}

	void destroy() {
		delete[] this->data;
	}

public:
	Vector();
	Vector(const Vector& other);
	Vector(Vector&& other);
	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other);
	const T& operator[](std::size_t idx) const;
	T& operator[](std::size_t idx);
	~Vector();

	void push_back(const T& newObject);
	void pop_back();
	size_t length() const;
};

template<typename T>
Vector<T>::Vector() { // O(1)
	std::cout << "Vector()" << std::endl;
	this->size = 0;
	this->capacity = 8;
	this->data = new T[this->capacity];
}

template<typename T>
Vector<T>::Vector(const Vector& other) {
	std::cout << "Vector(const Vector& other)" << std::endl;
	this->copy(other);
}

template<typename T>
Vector<T>::Vector(Vector&& other) {
	std::cout << "Vector(Vector&& other)" << std::endl;
	this->move(std::forward<Vector>(other));
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	std::cout << "operator=(const Vector<T>& other)" << std::endl;
	if (this != &other) {
		this->destroy();
		this->copy(other);
	}

	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) {
	std::cout << "operator=(Vector&& other)" << std::endl;
	if (this != &other) {
		this->destroy();
		this->move(std::forward<Vector>(other));
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector() {
	std::cout << "~Vector()" << std::endl;
	this->destroy();
}

template<typename T>
void Vector<T>::push_back(const T& newObject) {
	if (this->size >= this->capacity) {
		this->resize();
	}
	this->data[size] = newObject;
	this->size++;
}

template<typename T>
void Vector<T>::pop_back() {
	if (this->size <= 0) {
		return;
	}
	this->size--;
}

template<typename T>
size_t Vector<T>::length() const {
	return this->size;
}

template<typename T>
const T& Vector<T>::operator[](std::size_t idx) const {
	return this->data[idx];
}

template<typename T>
T& Vector<T>::operator[](std::size_t idx) {
	return this->data[idx];
}
