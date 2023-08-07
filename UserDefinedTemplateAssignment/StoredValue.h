/*
Author - Isaac Richards
Date - 06AUG23
Assignment - Standard Template Library Assignment
Description - Used to store a value like a calculator does when performing operations.
The value is intended to be a number such as an integer, or floating point number.
*/

#pragma once

#include <vector>
#include <string>
#include "Function.h"
#include "MathOperations.h"

template <typename StoredType>
class StoredValue {
private:
	StoredType value;

public:
	StoredValue(StoredType value) : value(value) {};
	StoredType GetValue() { return value; }
	void SetValue(StoredType newValue) { value = newValue; }
	template <typename OtherType>
	StoredType PerformOperation(OtherType otherValue, StoredType (*operation)(StoredType, StoredType)) {
		value = operation(value, static_cast<StoredType>(otherValue));
		return GetValue();
	}

	std::vector<std::pair<Function<StoredType>, std::string>> operations = {
		{ Function<StoredType>("Clear", Clear<StoredType>), "Please enter a new value: " },
		{ Function<StoredType>("+", Add<StoredType>), "Please enter a value to add: " },
		{ Function<StoredType>("-", Subtract<StoredType>), "Please enter a value to subtract: " },
		{ Function<StoredType>("*", Multiply<StoredType>), "Please enter a value to multiply by: " },
		{ Function<StoredType>("/", Divide<StoredType>), "Please enter a value to divide by: " }
	};
};