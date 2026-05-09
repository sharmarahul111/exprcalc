#include "evaluator.h"
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