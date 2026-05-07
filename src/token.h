#include<string>
typedef enum {
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_STAR,
	TOKEN_SLASH
} TokenType;
struct Token {
	TokenType token_type;
	std::string lexeme;
	// int literal;
	Token(TokenType token_type, std::string lexeme){
		this->token_type = token_type;
		this->lexeme = lexeme;
	}
};