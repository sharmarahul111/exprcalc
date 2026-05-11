#ifndef LIBRARY_H
#define LIBRARY_H

#include "expr.h"
#include <functional>
#include<string>
#include<unordered_map>
#include<cmath>

using VariableArgs = std::function<Value(const std::vector<Value>&)>;
struct Context {
	std::unordered_map<std::string, double> constants;
	std::unordered_map<std::string, VariableArgs> functions;
};
Context library();

#endif
