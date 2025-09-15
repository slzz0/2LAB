#include "../headers/program.h"

#include <iostream>

#include "../headers/array.h"
#include "../headers/menu.h"
#include "../headers/utilits.h"
using namespace std;

void runProgram() {
    Array arr1;
    Array arr2;
    
    int choice;
    taskMenu();

    while (true) {
        cout << "\nSelect a task MENU option: ";
        choice = validInt();

        switch (choice) {
            case 1:
                cout << "\nEnter first array:" << endl;
                cin >> arr1;
                break;
            case 2:
                cout << "\nEnter second array:" << endl;
                cin >> arr2;
                break;
            case 3:
                cout << "First array: " << arr1 << endl;
                cout << "Second array: " << arr2 << endl;
                break;
            case 4: {
                Array intersection = arr1 & arr2;
                cout << "Intersection (&) of arrays: " << intersection << endl;
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                return;
            default:
                cout << "Error: you have selected an incorrect MENU option" << endl;
                break;
        }
    }
}