#include "scanner.h"
#include "token.h"
std::vector<Token> Scanner::scan_tokens(std::string_view source){
	std::vector<Token> tokens;
	for (size_t i=0; i<source.length(); i++) {
		tokens.push_back(Token(TOKEN_STAR, "*"));
	}

	return tokens;
}