#ifndef EXPR_H
#define EXPR_H

// #include <iostream>
#include <variant>
#include<string>
#include<vector>
#include "globals.h"
#include "token.h"
class Binary;
class Unary;
class Literal;
class Grouping;
class Function;
class Constant;
class Variable;

using Value = std::variant<std::monostate, std::string, double>;
class Visitor {
	public:
		virtual Value visit_binary_expr(Binary&) = 0;
		virtual Value visit_unary_expr(Unary&) = 0;
		virtual Value visit_grouping_expr(Grouping&) = 0;
		virtual Value visit_literal_expr(Literal&) = 0;
		virtual Value visit_function_expr(Function&) = 0;
		virtual Value visit_constant_expr(Constant&) = 0;
		virtual Value visit_variable_expr(Variable&) = 0;
};

class Expr {
	public:
		virtual Value accept(Visitor*)=0;
		virtual ~Expr(){};
};

class Binary: public Expr {
	public:
		Expr* left {nullptr};
		Token _operator;
		Expr* right {nullptr};
		Value accept(Visitor*) override;
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
		Value accept(Visitor*) override;
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
			Value accept(Visitor*) override;
			Literal(double v){
				value = v;
			}
			~Literal(){
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
		Value accept(Visitor*) override;
};

class Function: public Expr {
	public:
		Token name;
		std::vector<Expr *> args;
		Function(Token name, std::vector<Expr*> args){
			this->name = name;
			this->args = args;
		}
		~Function(){
			for (size_t i=0; i<args.size(); i++) {
				delete args[i];
				args[i] = nullptr;
			}
		}
		Value accept(Visitor*) override;
	};
	
	class Constant: public Expr {
		public:
		Token name;
		double value;
		Constant(Token name, double value){
			this->name = name;
			this->value = value;
		}
		Value accept(Visitor*) override;
		~Constant(){}
	};
	
	class Variable: public Expr {
		public:
		Token name;
		Environment& env;
		Variable(Token name, Environment& env):env(env){
			this->name = name;
		}
		Value accept(Visitor*) override;
		~Variable(){}
};

#endif
