#include "astprinter.h"
#include <string>
#include <variant>

Value ASTPrinter::visit_binary_expr(Binary& binary){
	return parenthesize(binary._operator.lexeme, Exprs{binary.left, binary.right});
}
Value ASTPrinter::visit_literal_expr(Literal& literal){
	if (std::holds_alternative<double>(literal.value)) {
		return Value{std::to_string(std::get<double>(literal.value))};
	}
	return Value {"Unknown literal value"};
}
Value ASTPrinter::visit_unary_expr(Unary& unary){
	return parenthesize(unary._operator.lexeme, Exprs{unary.right});
}
Value ASTPrinter::visit_grouping_expr(Grouping& grouping){
	return parenthesize("group", Exprs{grouping.expr});
}
Value ASTPrinter::visit_function_expr(Function& function){
	std::string value = function.name.lexeme+"(";
	for (size_t i=0;i<function.args.size();i++) {
		auto str = function.args[i]->accept(this);
		if(i!=0) value += ",";
		if (std::holds_alternative<std::string>(str)) {
			value += std::get<std::string>(str);
		}
	}
	value += ")";
	return value;
}
Value ASTPrinter::visit_constant_expr(Constant& constant){
	return constant.name.lexeme;
}
Value ASTPrinter::visit_variable_expr(Variable& variable){
	return variable.name.lexeme;
}
Value ASTPrinter::parenthesize(std::string name, Exprs expr){
	std::string value = "(" + name;
	for (auto val : expr) {
		auto str = val->accept(this);
		value += " ";
		if (std::holds_alternative<std::string>(str)) {
			value += std::get<std::string>(str);
		}
		// val->accept(this);
	}
	value += ")";
	return Value(value);
}
std::string ASTPrinter::print(Expr* expr){
	auto x = expr->accept(this);
	if (std::holds_alternative<std::string>(x)) {
		return std::get<std::string>(x);
	} else return std::string("expr accept didn't return string");
}

void printExpr(Expr *expr){
	std::cout << ASTPrinter().print(expr) << std::endl;
}