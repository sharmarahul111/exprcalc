#include "scanner.h"
#include "token.h"
std::vector<Token> Scanner::scan_tokens(){
	while(!is_at_end()){
		start = curr;
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
			add_token(TOKEN_DOT);
			break;
		case '=':
			add_token(TOKEN_EQUAL);
			break;
		case '|':
			add_token(TOKEN_PIPE);
			break;
		default:
			// throw some error here
			
			break;
	}

}
void Scanner::add_token(TokenType token_type /*, std::string literal*/){
	auto text = std::string(source.substr(start, curr-start));
	tokens.push_back(Token(token_type, text));
}
bool Scanner::is_at_end(){
	return curr >= source.size();
}
char Scanner::advance(){
	curr += 1;
	return source[curr-1];
}