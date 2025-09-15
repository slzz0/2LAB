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

    friend Array operator&(const Array& lhs, const Array& rhs) {
        Array result;
        if (lhs.data == nullptr || lhs.size == 0) {
            return result;
        }
        if (rhs.data == nullptr || rhs.size == 0) {
            return result;
        }

        for (int i = 0; i < lhs.size; i++) {
            if (rhs.contains(lhs.data[i]) && !result.contains(lhs.data[i])) {
                auto new_data = new int[result.size + 1];
                for (int j = 0; j < result.size; j++) {
                    new_data[j] = result.data[j];
                }
                new_data[result.size] = lhs.data[i];
                delete[] result.data;
                result.data = new_data;
                result.size++;
            }
        }
        return result;
    }
};
