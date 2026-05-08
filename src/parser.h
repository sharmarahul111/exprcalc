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
		Expr* parse();
		Expr* expression();
		Expr* term();
		Expr* factor();
		Expr* unary();
		Expr* primary();
		Token peek();
		bool check(TokenType);
		bool match(TokenType);
		bool match(TokenType, TokenType);
		Token advance();
		Token consume();
		Token previous();
		bool is_at_end();
};

#endif