#ifndef SCANNER_H
#define SCANNER_H

#include <cstddef>
#include<vector>
#include<cctype>
#include "token.h"
class Scanner {
	std::size_t start {0};
	std::size_t curr {0};
	std::string_view source;
	std::vector<Token> tokens;
	// int line {0};
	bool is_at_end();
	char advance();
	void add_token(TokenType token_type);
	void number();
	void identifier();
	char peek();
	// void string();
	public:
		Scanner()=default;
		Scanner(std::string_view src){
			source = src;
		}
		std::vector<Token> scan_tokens();
		void scan_token();
};

#endif