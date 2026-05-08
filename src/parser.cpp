#include "parser.h"
#include "expr.h"
#include "token.h"
Expr* Parser::parse(){
		return expression();
}
Expr* Parser::expression(){
	return term();
}
Expr* Parser::term(){
	return factor();
}
Expr* Parser::factor(){
	return unary();
}
Expr* Parser::unary(){
	return primary();
}

Expr* Parser::primary(){
	if (match(TOKEN_NUMBER)) {
		double value = std::get<double>(previous().literal);
		return new Literal(value);
	} else if (match(TOKEN_IDENTIFIER)) {
		// check if it's constant or function call
	} else if (match(TOKEN_LEFT_PAREN)) {
		Expr* expr = expression();
		consume(TOKEN_RIGHT_PAREN, "No closing ) found.");
		return new Grouping(expr);
	}
	// throw expected expression
	throw ParseError(peek(), "Expected expression.");
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
Token Parser::consume(TokenType t, std::string_view msg){
	if (match(t)) {
		advance();
	}
	throw ParseError(peek(), msg);
}