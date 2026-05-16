#ifndef EXPRCALC_H
#define EXPRCALC_H

#include<iostream>
#include<string>
#include<vector>
#include<variant>
#include<unordered_map>
#include "parser.h"
#include "scanner.h"
#include "evaluator.h"
#include "globals.h"
#include "tools/astprinter.h"
class ExprCalc {
	public:
		void run_prompt();
		void run(std::string_view source, Environment& env);
};

#endif