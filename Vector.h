#pragma once
#include <cstddef>

template<typename T>
class Vector {
    T* data;
    std::size_t size, capacity;
};
