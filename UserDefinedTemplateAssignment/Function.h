/*
Author - Isaac Richards
Date - 15JUL23
Assignment - Object Oriented Math Library Program
Description - Function stores a pointer to a function and a display name for the function.  Function is meant to be used in a vector of
    Function objects for a menu.

Update 06AUG23 - Changed the return type from void to T and added 2 arguments of type T.
*/

#pragma once
#include <string>

using namespace std;

template <typename T>
class Function {
public:
    string display_name;
    T (*function)(T value, T other);

    Function(const string& name, T (*func)(T value, T other)) : display_name(name), function(func) {}
};