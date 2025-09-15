#pragma once

#include <iostream>

class Array {
   private:
    int* data;
    int size;

    void allocateMemory(int size);
    void freeMemory();

   public:
    Array();
    Array(int size);
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array operator&(const Array& other) const;
    bool contains(int value) const;
    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
    friend std::istream& operator>>(std::istream& is, Array& arr);
};
