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

Array::Array(const Array& other) : data(nullptr), size(0) {
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

Array Array::operator&(const Array& other) const {
    Array result;
    if (data == nullptr || size == 0) {
        return result;
    }
    if (other.data == nullptr || other.size == 0) {
        return result;
    }

    for (int i = 0; i < size; i++) {
        if (other.contains(data[i]) && !result.contains(data[i])) {
            auto new_data = new int[result.size + 1];
            for (int j = 0; j < result.size; j++) {
                new_data[j] = result.data[j];
            }
            new_data[result.size] = data[i];
            delete[] result.data;
            result.data = new_data;
            result.size++;
        }
    }
    return result;
}

