#pragma once
#include <iostream>

#include "../headers/utilits.h"


class Array {
   private:
    int* data = nullptr;
    int size = 0;

    void allocateMemory(int size);
    void freeMemory();

   public:
    Array() = default;
    explicit Array(int array_size);
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array operator&(const Array& other) const;
    bool contains(int value) const;

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
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

    friend std::istream& operator>>(std::istream& is, Array& arr) {
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
};
