#include "../headers/menu.h"

#include <iostream>

void taskMenu() {
    std::cout << "\n\t\t\tTASK" << std::endl;
    std::cout << "Create a class Array for one-dimensional arrays." << std::endl;
    std::cout << "Allocate memory for arrays dynamically." << std::endl;
    std::cout << "Provide a copy constructor." << std::endl;
    std::cout << "Overload the & operator for array intersection." << std::endl;
    std::cout << "Define friend functions for stream input/output operations." << std::endl;
    std::cout << "Check the work of all functionality." << std::endl;

    std::cout << "\n\t\t\tMENU" << std::endl;
    std::cout << "1. Enter first array" << std::endl;
    std::cout << "2. Enter second array" << std::endl;
    std::cout << "3. Display arrays" << std::endl;
    std::cout << "4. Find intersection (arr1 & arr2)" << std::endl;
    std::cout << "5. Exit the program" << std::endl;
    std::cout << "Choose an option: ";
}