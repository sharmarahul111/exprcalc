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
		virtual void visit_binary_expr(Binary&) = 0;
		virtual void visit_unary_expr(Unary&) = 0;
		virtual void visit_grouping_expr(Grouping&) = 0;
		virtual void visit_literal_expr(Literal&) = 0;
};

class Expr {
	protected:
		virtual void accept(Visitor*)=0;
	public:
		virtual ~Expr(){};
};

class Binary: public Expr {
	public:
		Expr* left {nullptr};
		Token _operator;
		Expr* right {nullptr};
		void accept(Visitor*) override;
		Binary(Token _operator, Expr *left, Expr*right){
			this->_operator = _operator;
			this->left = left;
			this->right = right;
		}
		~Binary(){
			delete left;
			left = nullptr;
			delete right;
			right = nullptr;
		}
};

class Grouping: public Expr {
	public:
		Expr* expr {nullptr};
		void accept(Visitor*) override;
		Grouping(Expr *expr){
			this->expr = expr;
		}
		~Grouping(){
			delete expr;
			expr = nullptr;
		}
};

class Literal: public Expr {
	public:
		std::variant<std::monostate,double> value;
		void accept(Visitor*) override;
		Literal(double v){
			value = v;
		}
};

class Unary: public Expr {
	public:
		Token _operator;
		Expr* right {nullptr};
		Unary(Token _operator, Expr* right){
			this->_operator = _operator;
			this->right = right;
		}
		~Unary(){
			delete right;
			right = nullptr;
		}
		void accept(Visitor*) override;
};

#endif
