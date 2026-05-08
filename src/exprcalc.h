#ifndef EXPRCALC_H
#define EXPRCALC_H

#include<iostream>
#include<string>
#include<vector>
#include "parser.h"
#include "scanner.h"
class ExprCalc {
	public:
		void run_prompt();
		void run(std::string_view source);
};

#endif