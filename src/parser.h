#ifndef PARSER_H
#define PARSER_H

#include<vector>
#include "token.h"
#include "expr.h"

class Parser {
	private:
		std::vector<Token> tokens;
		size_t current {0};
	public:
		Parser(std::vector<Token> t){
			tokens = t;
		}
		Expr* expression();
		// Expr* equality();
		Expr* term();
		Expr* factor();
		Expr* unary();
		Expr* primary();
};

#endif