#include "exprcalc.h"
void ExprCalc::run_prompt(){
	std::cout << "Welcome to exprcalc!!" << std::endl;
	std::string line;
	while(true){
		std::cout << "> ";
		std::getline(std::cin, line);
		// TODO: check for white space only characters
		if (line == "") {
			continue;
		}
		run(line);

	}
}
void ExprCalc::run(std::string_view source){
	Expr* expr {nullptr};
	Scanner scanner(source);
	Evaluator evaluator;
	auto tokens = scanner.scan_tokens();
	Parser parser(tokens);
	try {
		expr = parser.parse();
	} catch (ParseError pe) {
		std::cout << "SYNTAX ERROR: " << pe.message << std::endl;
		return;
	}
	// Print Abstract Syntax Tree
	// printExpr(expr);

	// Evaluate the results
	try {
		Value v = evaluator.evaluate(expr);
		if (std::holds_alternative<double>(v)) {
			std::cout << "ANSWER: "
			<< std::get<double>(v) << std::endl;
		} else {
			std::cout << "Answer not of type double" << std::endl;
		}
	} catch (EvaluationError ee) {
		std::cout << "EVALUATION ERROR: " << ee.message << std::endl;
		return;
	}

	// TODO: remember to deallocate parser Expr* memory
	// for (auto token : tokens) {
	// 	std::cout << "Token code: " << token.token_type << ", lexeme = " << token.lexeme;
	// 	if (std::holds_alternative<double>(token.literal))
	// 		std::cout << ", double = " << std::get<double>(token.literal);
	// 	std::cout << std::endl;
	// }
}