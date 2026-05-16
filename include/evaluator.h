#ifndef EVALUATOR_H
#define EVALUATOR_H

#include<cmath>
#include "token.h"
#include "expr.h"
#include "library.h"

// runtime error
struct EvaluationError {
	Token token;
	std::string_view message;
	EvaluationError(Token t, std::string_view msg){
		token = t;
		message = msg;
	}
};
class Evaluator: public Visitor {
	private:
		Context ctx;
		Value visit_binary_expr(Binary&);
		Value visit_grouping_expr(Grouping&);
		Value visit_literal_expr(Literal&);
		Value visit_unary_expr(Unary&);
		Value visit_function_expr(Function&);
		Value visit_constant_expr(Constant&);
		Value visit_variable_expr(Variable&);
	public:
		Evaluator(Context ctx){
			this->ctx = ctx;
		};
		Value evaluate(Expr*);
};

#endif