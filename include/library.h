#ifndef LIBRARY_H
#define LIBRARY_H

#include "expr.h"
#include <functional>
#include<string>
#include<unordered_map>
#include<cmath>

struct Context {
	std::unordered_map<std::string, double> constants;
	std::unordered_map<std::string, std::function<double()>> nullaryFn;
	std::unordered_map<std::string, std::function<double(double)>> unaryFn;
	std::unordered_map<std::string, std::function<double(double,double)>> binaryFn;
};
Context library();

#endif
