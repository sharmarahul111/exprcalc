#ifndef EXPR_H
#define EXPR_H

#include "token.h"
#include <variant>

class Visitor {
	protected:
		virtual void visit_binary_expr() = 0;
		virtual void visit_unary_expr() = 0;
		virtual void visit_grouping_expr() = 0;
		virtual void visit_literal_expr() = 0;
};

class Expr {
	protected:
		virtual void accept(Visitor)=0;
};

class Binary: Expr {
	Expr* left {nullptr};
	Token _operator;
	Expr* right {nullptr};
};

class Grouping: Expr {
	Expr* expr {nullptr};
};

class Literal: Expr {
	std::variant<std::monostate,double> value;
};

class Unary: Expr {
	Token _operator;
	Expr* right {nullptr};
};

#endif