#include "exprcalc.h"
void ExprCalc::run_prompt(){
	std::cout << "Welcome to exprcalc!!" << std::endl;
	std::string line;
	while(true){
		std::cout << '>';
		std::getline(std::cin, line);
		std::cout << "Given data: " << line << std::endl;
		

	}
}