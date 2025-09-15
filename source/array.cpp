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

Array::Array() : data(nullptr), size(0) {}
Array::Array(int array_size) : data(nullptr), size(0) {
    if (size <= 0) {
        throw std::invalid_argument("The size of array cannot be a negative number");
    }
    allocateMemory(size);
}

Array::~Array() { freeMemory(); }

Array::Array(const Array& other) : data(nullptr), size(0) {
    if (other.data != nullptr && other.size > 0) {
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
    if (data == nullptr || other.data == nullptr || size == 0 || other.size == 0) {
        return result;
    }

    for (int i = 0; i < size; i++) {
        if (other.contains(data[i])) {
            if (!result.contains(data[i])) {
                int* new_data = new int[result.size + 1];
                for (int j = 0; j < result.size; j++) {
                    new_data[j] = result.data[j];
                }
                new_data[result.size] = data[i];
                delete[] result.data;
                result.data = new_data;
                result.size++;
            }
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
    os << "[";
    for (int i = 0; i < arr.size; i++) {
        os << arr.data[i];
        if (i < arr.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Array& arr) {
    arr.freeMemory();
    std::cout << "Enter the size of array: ";
    int new_size = validInt();

    if (new_size <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    arr.allocateMemory(new_size);
    std::cout << "Enter " << new_size << " elements:\n";
    for (int i = 0; i < new_size; i++) {
        std::cout << "Element " << i + 1 << ": ";
        arr.data[i] = validInt();
    }
    return is;
}