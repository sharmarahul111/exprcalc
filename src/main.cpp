#include<iostream>
#include "token.h"
int main(int argc, const char * argv[]){
	std::cout << "Hello world!!" << std::endl;
	Token t(TOKEN_SLASH, "/");
	std::cout << t.token_type << std::endl << t.lexeme << std::endl;
	return 0;
}