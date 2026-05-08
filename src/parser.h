#ifndef PARSER_H
#define PARSER_H

#include<vector>
#include<string>
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
		Token previous();
		Token advance();
		Token consume(TokenType, std::string_view);
		bool is_at_end();
};

#endif