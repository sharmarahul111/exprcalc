#ifndef EXPR_H
#define EXPR_H

#include "token.h"
#include <variant>
class Binary;
class Unary;
class Literal;
class Grouping;

class Visitor {
	public:
		virtual void visit_binary_expr(Binary) = 0;
		virtual void visit_unary_expr(Unary) = 0;
		virtual void visit_grouping_expr(Grouping) = 0;
		virtual void visit_literal_expr(Literal) = 0;
};

class Expr {
	protected:
		virtual void accept(Visitor*)=0;
};

class Binary: public Expr {
	Expr* left {nullptr};
	Token _operator;
	Expr* right {nullptr};
	public:
		void accept(Visitor*) override;
};

class Grouping: public Expr {
	Expr* expr {nullptr};
	void accept(Visitor*) override;
};

class Literal: public Expr {
	std::variant<std::monostate,double> value;
	public:
	void accept(Visitor*) override;
	Literal(double v){
		value = v;
	}
};

class Unary: public Expr {
	Token _operator;
	Expr* right {nullptr};
	public:
		void accept(Visitor*) override;
};

#endif