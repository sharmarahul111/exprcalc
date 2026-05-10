#ifndef LIBRARY_H
#define LIBRARY_H

#include<string>
#include<unordered_map>
#include<cmath>

struct Context {
	std::unordered_map<std::string, double> constants;
	std::unordered_map<std::string, double> variables;
};
Context library();

#endif
