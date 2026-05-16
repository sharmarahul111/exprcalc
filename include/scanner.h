#ifndef SCANNER_H
#define SCANNER_H

#include <cstddef>
#include<vector>
#include<cctype>
#include<iostream>
#include "token.h"
class Scanner {
	std::size_t start {0};
	std::size_t current {0};
	std::string_view source;
	std::vector<Token> tokens;
	bool is_at_end();
	char advance();
	void add_token(TokenType token_type);
	void add_token(TokenType token_type, double literal);
	void number(char c='\0');
	void identifier();
	char peek();
	public:
	Scanner()=default;
	Scanner(std::string_view src){
		source = src;
	}
	std::vector<Token> scan_tokens();
	void scan_token();
	static void printTokens(std::vector<Token>);
};

#endif