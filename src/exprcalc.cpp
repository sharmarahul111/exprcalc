#include "exprcalc.h"
void ExprCalc::run_prompt(){
	std::cout << "Welcome to exprcalc!!" << std::endl;
	std::string line;
	while(true){
		std::cout << '>';
		std::getline(std::cin, line);
		// TODO: check for white space only characters
		if (line == "") {
			continue;
		}
		run(line);

	}
}
void ExprCalc::run(std::string_view source){
	Scanner scanner(source);
	auto tokens = scanner.scan_tokens();
	for (auto token : tokens) {
		std::cout << "Token code: " << token.token_type << ", lexeme = " << token.lexeme << std::endl;
	}
}