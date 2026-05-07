#include "scanner.h"
#include "token.h"
std::vector<Token> Scanner::scan_tokens(std::string_view source){
	std::vector<Token> tokens;
	for (size_t i=0; i<source.length(); i++) {
		switch (static_cast<char>(source[i])) {
			case '+':
				tokens.push_back(Token(TOKEN_PLUS, "+"));
				break;
			case '-':
				tokens.push_back(Token(TOKEN_MINUS, "-"));
				break;
			case '*':
				tokens.push_back(Token(TOKEN_STAR, "*"));
				break;
			case '/':
				tokens.push_back(Token(TOKEN_SLASH, "/"));
				break;
			case '^':
				tokens.push_back(Token(TOKEN_EXP, "^"));
				break;
			case '%':
				tokens.push_back(Token(TOKEN_PERCENT, "%"));
				break;
			case '(':
				tokens.push_back(Token(TOKEN_LEFT_PAREN, "("));
				break;
			case ')':
				tokens.push_back(Token(TOKEN_RIGHT_PAREN, ")"));
				break;
			case ',':
				tokens.push_back(Token(TOKEN_COMMA, ","));
				break;
			case '.':
				tokens.push_back(Token(TOKEN_DOT, "."));
				break;
			case '=':
				tokens.push_back(Token(TOKEN_EQUAL, "="));
				break;
			case '|':
				tokens.push_back(Token(TOKEN_PIPE, "|"));
				break;
			default:
				// throw some error here
				continue;
		}
	}
	tokens.push_back(Token(TOKEN_EOF, "EOF"));

	return tokens;
}