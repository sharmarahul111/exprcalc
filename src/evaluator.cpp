#include "evaluator.h"
#include "expr.h"
#include <cmath>

Value Evaluator::evaluate(Expr* expr){
	// hey Hisenberg, do something!!
	return expr->accept(this);
}

Value Evaluator::visit_literal_expr(Literal& literal){
	if (std::holds_alternative<double>(literal.value)) {
		return std::get<double>(literal.value);
	}
	// TODO: send something useful than a empty token
	throw EvaluationError(Token(),"Only double values allowed for now");
}

Value Evaluator::visit_binary_expr(Binary& binary){
	auto left = std::get<double>(binary.left->accept(this));
	auto right = std::get<double>(binary.right->accept(this));
	switch (binary._operator.token_type) {
		case TOKEN_PLUS: return left+right;
		case TOKEN_MINUS: return left-right;
		case TOKEN_STAR: return left*right;
		case TOKEN_SLASH:
			if (right == 0)
				throw EvaluationError(binary._operator, "Can't divide by zero!");
			return left/right;
		case TOKEN_EXP: return std::pow(left, right);
		default:
			throw EvaluationError(binary._operator, "Unknown binary operator.");

	}
}

Value Evaluator::visit_unary_expr(Unary& unary){
	Value v = unary.right->accept(this);
	if (std::holds_alternative<double>(v)) {
		return -(std::get<double>(v));
	}
	throw EvaluationError(unary._operator,"Only double values allowed for now");
}

Value Evaluator::visit_grouping_expr(Grouping& grouping){
	return grouping.expr->accept(this);
}

Value Evaluator::visit_function_expr(Function& function){
	std::vector<Value> args;
	std::string name = function.name.lexeme;
	for (auto expr : function.args) {
		args.push_back(expr->accept(this));
	}
	size_t len = args.size();
	if(len == 0){
		if(ctx.nullaryFn.find(name) != ctx.nullaryFn.end()){
			return ctx.nullaryFn[name]();
		} else throw EvaluationError(function.name, "Call to unknown function");
	} else if(len == 1){
		if(ctx.unaryFn.find(name) != ctx.unaryFn.end()){
			double x = std::get<double>(args[0]);
			return ctx.unaryFn[name](x);
		} else throw EvaluationError(function.name, "Call to unknown function");
	} else if(len == 2){
		if(ctx.binaryFn.find(name) != ctx.binaryFn.end()){
			double x = std::get<double>(args[0]);
			double y = std::get<double>(args[1]);
			return ctx.binaryFn[name](x,y);
		} else throw EvaluationError(function.name, "Call to unknown function");
	} else {
		throw EvaluationError(function.name, "Call to unknown function");
	}
}

Value Evaluator::visit_constant_expr(Constant& constant){
	return constant.value;
}

Value Evaluator::visit_variable_expr(Variable& variable){
	if (variable.env.variables.find(variable.name.lexeme) != variable.env.variables.end()) {
		return variable.env.variables[variable.name.lexeme];
	}
	throw EvaluationError(
		variable.name,
		"Variable value of \""+variable.name.lexeme+"\" not found."
	);
}