#include "exprcalc.h"
#include "globals.h"
#include "library.h"
void ExprCalc::run_prompt(){
	std::cout << "exprcalc v0.2" << std::endl;
	std::cout << "Press Ctrl+C to exit." << std::endl;
	std::string line;
	Environment env;
	env.variables["ans"] = 0;
	while(true){
		std::cout << "> ";
		std::getline(std::cin, line);
		// TODO: check for white space only characters
		if (line == "") {
			continue;
		}
		run(line, env);

	}
}
void ExprCalc::run(std::string_view source, Environment& env){
	// TODO: add help statement to show all available
	// operations, constants and function calls
	Expr* expr {nullptr};
	Scanner scanner(source);
	Evaluator evaluator(library());
	auto tokens = scanner.scan_tokens();
	Parser parser(tokens, env);
	try {
		expr = parser.parse();
	} catch (ParseError pe) {
		std::cout << "SYNTAX ERROR: " << pe.message << std::endl;
		return;
	}
	// Print Abstract Syntax Tree
	printExpr(expr);

	// Evaluate the results
	try {
		Value v = evaluator.evaluate(expr);
		if (std::holds_alternative<double>(v)) {
			double answer = std::get<double>(v);
			env.variables["ans"] = answer;
			std::cout
			<< answer << std::endl;
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