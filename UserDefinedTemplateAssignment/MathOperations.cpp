

#include "Function.h"
#include "MathOperations.h"



std::vector<Function> operations = {
	Function("+", *Add),
	Function("-", *Subtract),
	Function("*", *Multiply),
	Function("/", *Divide)
};