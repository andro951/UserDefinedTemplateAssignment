/*
Author - Isaac Richards
Date - 06AUG23
Assignment - Standard Template Library Assignment
Description - An example program that acts similar to a calculator.  It allows the user to select between binary, integer and floating point numbers 
and then perform basic math operations on them.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include "StoredValue.h"
#include "Menu.h"
#include "CalculatorFunctions.h"

int main() {
    //Ask the user to select binary, integer, or floating point number.
    //The program will save this choice and use it for the rest of the program.
    //There is not currently a way to switch between types without restarting the program.
    std::cout << "Hello, this program is designed to act similar to a calculator.\n";
    std::cout << "Please enter the type of value you would like to use by entering the number for the option:\n";
    std::vector<std::string> typeNames = { "binary", "integer", "floating point number" };
    int typeID = get_option(typeNames);

    //Based on the type selected, get the input from the user and call the Calculator function which contains the main loop of the program.
    switch (typeID) {
        case binary:
            Calculator(typeID, get_binary_input("Please enter a binary number:"));
		    break;

        case integer:
            Calculator(typeID, get_integer_input("Please enter an integer:"));
            break;

        case floatingPoint:
            Calculator(typeID, get_float_input("Please enter a floating point number:"));
            break;

        default:
            break;
    }
}