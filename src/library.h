#ifndef LIBRARY_H
#define LIBRARY_H

#include "expr.h"
#include <functional>
#include<string>
#include<unordered_map>
#include<cmath>

struct Context {
	std::unordered_map<std::string, double> constants;
	std::unordered_map<std::string, std::function<double(double)>> unaryFn;
};
Context library();

#endif
