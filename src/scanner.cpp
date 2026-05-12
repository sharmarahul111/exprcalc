#include "scanner.h"
#include "token.h"
#include <cctype>
std::vector<Token> Scanner::scan_tokens(){
	while(!is_at_end()){
		start = current;
		scan_token();
	}
	
	tokens.push_back(Token(TOKEN_EOF, "EOF"));
	return tokens;
}
void Scanner::scan_token(){
	char c = advance();
	switch (c) {
		case '+':
			add_token(TOKEN_PLUS);
			break;
		case '-':
			add_token(TOKEN_MINUS);
			break;
		case '*':
			add_token(TOKEN_STAR);
			break;
		case '/':
			add_token(TOKEN_SLASH);
			break;
		case '^':
			add_token(TOKEN_EXP);
			break;
		case '%':
			add_token(TOKEN_PERCENT);
			break;
		case '(':
			add_token(TOKEN_LEFT_PAREN);
			break;
		case ')':
			add_token(TOKEN_RIGHT_PAREN);
			break;
		case ',':
			add_token(TOKEN_COMMA);
			break;
		case '.':
			if(std::isdigit(peek()))
				number('.');
			else
				add_token(TOKEN_DOT);
			break;
		case '=':
			add_token(TOKEN_EQUAL);
			break;
		case '|':
			add_token(TOKEN_PIPE);
			break;
		default:
			if (std::isdigit(c)) {
				number();
			} else if (std::isalpha(c)) {
				identifier();
			} else if (c == ' ' || c == '\t' || c == '\r'){
				// ignore white spaces
			} else {
				// TODO: handle unexpected tokens
			}
			
			break;
	}

}
void Scanner::number(char c){ // default = '\0'
	while (std::isdigit(peek())) advance();
	if (peek() == '.' && c != '.') {
		advance(); // consume the .	
		while (std::isdigit(peek())) advance();
	}
	add_token(TOKEN_NUMBER);
}
void Scanner::identifier(){
	while (std::isalnum(peek()) || peek() == '_') advance();
	add_token(TOKEN_IDENTIFIER);
}
void Scanner::add_token(TokenType token_type){
	auto text = std::string(source.substr(start, current-start));
	if (token_type == TOKEN_NUMBER)
		tokens.push_back(Token(token_type, text, std::stod(text)));
	else
		tokens.push_back(Token(token_type, text));
}
bool Scanner::is_at_end(){
	return current >= source.size();
}
char Scanner::advance(){
	current += 1;
	return source[current-1];
}
char Scanner::peek(){
	if (is_at_end()) {
		return '\0';
	} else {
		return source[current];
	}
}
void Scanner::printTokens(std::vector<Token> tokens){
	for (auto token : tokens) {
		std::cout << "Token code: " << token.token_type << ", lexeme = " << token.lexeme;
		if (std::holds_alternative<double>(token.literal))
			std::cout << ", double = " << std::get<double>(token.literal);
		std::cout << std::endl;
	}
}