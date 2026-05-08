#include "parser.h"
#include "token.h"
Expr* Parser::parse(){
	return expression();
}

bool Parser::match(TokenType t){
	if (is_at_end()) return false;
	if (check(t)) {
		advance();
		return true;
	} else {
		return false;
	}
}
bool Parser::check(TokenType t){
	return peek().token_type == t;
}
Token Parser::peek(){
	return tokens[current];
}
bool Parser::is_at_end(){
	return peek().token_type == TOKEN_EOF;
}
Token Parser::advance(){
	if(!is_at_end()) current++;
	return previous();
}
Token Parser::previous(){
	return tokens[current - 1];
}