#pragma once

#include <iostream>

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
        //Display the current value
        std::cout << "The current value is: ";
        if (typeID == binary) {
            //Display the integer as a 32 bit binary number
            std::cout << std::bitset<32>(storedValue.GetValue()) << "\n";
        }
        else {
            std::cout << storedValue.GetValue() << "\n";
        }

        //Display the options for the user from the StoredValue operations and add a Quit option.
        std::cout << "Please select an operation to perform by entering the number for the option:\n";
        vector<string> options;
        for (const auto& operation : storedValue.operations) {
            options.push_back(operation.first.display_name);
        }

        options.push_back("Quit");

        //User selects the operation to perform such as Clear, *, +, -, /, Quit
        int operationID = get_option(options);

        //If Quit, exit the loop and end the program.
        if (operationID == options.size() - 1) {
            running = false;
            std::cout << "Goodbye\n";
            break;
        }

        //Get the other binary, integer, or floating point number from the user to perform the operation.
        std::string prompt = storedValue.operations[operationID].second;
        bool isBinary = typeID == binary;
        T otherValue = get_t_input<T>(prompt, isBinary);

        //Perform the selected operation with the other value.
        storedValue.PerformOperation(otherValue, storedValue.operations[operationID].first.function);
    };
}