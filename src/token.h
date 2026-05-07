#ifndef TOKEN_H
#define TOKEN_H

#include<string>
#include <variant>
typedef enum {
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_STAR,
	TOKEN_SLASH,
	TOKEN_EXP,
	TOKEN_PERCENT,
	TOKEN_LEFT_PAREN,
	TOKEN_RIGHT_PAREN,
	TOKEN_COMMA,
	TOKEN_NUMBER,
	TOKEN_STRING,
	TOKEN_IDENTIFIER,
	TOKEN_DOT,
	TOKEN_EQUAL,
	TOKEN_EOF,
	TOKEN_PIPE
} TokenType;
struct Token {
	TokenType token_type;
	std::string lexeme;
	std::variant<std::monostate, double, std::string> literal;
	Token(TokenType token_type, std::string lexeme){
		this->token_type = token_type;
		this->lexeme = lexeme;
	}
	Token(TokenType token_type, std::string lexeme, double literal){
		this->token_type = token_type;
		this->lexeme = lexeme;
		this->literal = literal;
	}

};

#endif