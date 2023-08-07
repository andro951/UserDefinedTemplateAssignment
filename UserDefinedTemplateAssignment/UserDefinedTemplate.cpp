/*
Author - Isaac Richards
Date - 06AUG23
Assignment - Standard Template Library Assignment
Description - 
*/

/*
One advantage to using templates is that it allows us to write algorithms that can be used with many types of data. 
    This is known as generic programming.

In this assignment, you will write a generic template to be used in a calculator program for programmers that follows the Assignment 
    Formatting Guidelines and these requirements:

Your template shall allow the input of binary, integer and floating point information.
The template shall do basic math operations (+,-,*,/) on input values.
Write a full program that implements your UDT and prints out the answer in the same format as input by the user (binary, decimal or floating point).
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include "StoredValue.h"
#include "Menu.h"

enum TypeNameID {
    binary,
    integer,
    floatingPoint
};

template <typename T>
void Calculator(int typeID, T value) {
    StoredValue<T> storedValue(value);
    bool running = true;
    while (running) {
        std::cout << "The current value is: ";
        if (typeID == binary) {
			std::cout << std::bitset<32>(storedValue.GetValue()) << "\n";
		}
        else {
			std::cout << storedValue.GetValue() << "\n";
		}

        std::cout << "Please select an operation to perform by entering the number for the option:\n";

        vector<string> options;
        for (const auto& operation : storedValue.operations) {
            options.push_back(operation.first.display_name);
        }

        options.push_back("Quit");
        int operationID = get_option(options);
        if (operationID == options.size() - 1) {
			running = false;
            std::cout << "Goodbye\n";
			break;
		}

        std::string prompt = storedValue.operations[operationID].second;
        bool isBinary = typeID == binary;
        T otherValue = get_t_input<T>(prompt, isBinary);
        storedValue.PerformOperation(otherValue, storedValue.operations[operationID].first.function);
    };
}

int main() {
    std::cout << "Hello, this program is designed to act similar to a calculator.\n";

    std::vector<std::string> typeNames = { "binary", "integer", "floating point number" };

    std::cout << "Please enter the type of value you would like to use by entering the number for the option:\n";
    int typeID = get_option(typeNames);

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