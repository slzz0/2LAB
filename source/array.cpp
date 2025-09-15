#include "../headers/array.h"

#include "../headers/utilits.h"

void Array::allocateMemory(int array_size) {
    size = array_size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

void Array::freeMemory() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    size = 0;
}

Array::Array(int array_size) : size(array_size) {
    if (array_size <= 0) {
        throw std::invalid_argument("The size of array cannot be a negative number");
    }
    allocateMemory(size);
}

Array::~Array() { freeMemory(); }

Array::Array(const Array& other) {
    if (other.data != nullptr && other.size > 0) {
        size = other.size;
        allocateMemory(other.size);
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
}

Array& Array::operator=(const Array& other) {
    if (this == &other) return *this;
    freeMemory();

    if (other.data != nullptr && other.size > 0) {
        allocateMemory(other.size);
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

bool Array::contains(int value) const {
    if (data == nullptr || size == 0) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}



