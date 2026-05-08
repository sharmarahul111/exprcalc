#include "exprcalc.h"
#include <variant>
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
	// TODO: remember to deallocate parser Expr* memory
	for (auto token : tokens) {
		std::cout << "Token code: " << token.token_type << ", lexeme = " << token.lexeme;
		if (std::holds_alternative<double>(token.literal))
			std::cout << ", double = " << std::get<double>(token.literal);
		std::cout << std::endl;
	}
}