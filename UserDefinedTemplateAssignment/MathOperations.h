/*
Author - Isaac Richards
Date - 06AUG23
Assignment - Standard Template Library Assignment
Description - Basic math operations that can be used with the calculator program.
*/

#pragma once

#include <vector>

template <typename T>
T Clear(T a, T b) {
	return b;
}

template <typename T>
T Add(T a, T b) {
	return a + b;
}

template <typename T>
T Subtract(T a, T b) {
	return a - b;
}

template <typename T>
T Multiply(T a, T b) {
	return a * b;
}

template <typename T>
T Divide(T a, T b) {
	return a / b;
}