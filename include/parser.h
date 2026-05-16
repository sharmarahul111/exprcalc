#ifndef PARSER_H
#define PARSER_H

#include<vector>
#include<string>
#include "globals.h"
#include "token.h"
#include "expr.h"
#include "library.h"

struct ParseError {
	Token token;
	std::string_view message;
	ParseError(Token t, std::string_view msg){
		token = t;
		message = msg;
	}
};

class Parser {
	private:
		std::vector<Token> tokens;
		Environment& env;
		size_t current {0};
	public:
		Parser(std::vector<Token> t, Environment& env): env(env){
			tokens = t;
		}
		Expr* parse();
		Expr* expression();
		Expr* term();
		Expr* factor();
		Expr* exponent();
		Expr* unary();
		Expr* primary();
		Expr* function();
		Expr* identifier();
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