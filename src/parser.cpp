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
	Expr* expr = factor();
	while(match(TOKEN_PLUS, TOKEN_MINUS)){
		Token op = previous();
		Expr* right = factor();
		expr = new Binary(op, expr, right);
	}
	return expr;
}
Expr* Parser::factor(){
	Expr* expr = unary();
	while(match(TOKEN_STAR, TOKEN_SLASH)){
		Token op = previous();
		Expr* right = unary();
		expr = new Binary(op, expr, right);
	}
	return expr;
}
Expr* Parser::unary(){
	if(match(TOKEN_MINUS)){
		Token op = previous();
		Expr* right = unary();
		return new Unary(op, right);
	}
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
bool Parser::match(TokenType t1, TokenType t2){
	if(match(t1) || match(t2)) return true;
	return false;
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
	if (check(t)) {
		return advance();
	}
	throw ParseError(peek(), msg);
}
