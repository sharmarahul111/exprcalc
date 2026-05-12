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
			// std::cout << "Binary and left right deleted" << std::endl;
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
			// std::cout << "Grouping and expr deleted" << std::endl;
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
				// std::cout << "Literal deleted" << std::endl;
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
			// std::cout << "Unary and right deleted" << std::endl;
		}
		Value accept(Visitor*) override;
};

// TODO: find a better way to hold arguments
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
				// std::cout << "Function arg["<<i<<"] deleted" << std::endl;
			}
			// std::cout << "Function deleted" << std::endl;
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
		~Constant(){
			// std::cout << "Constant deleted" << std::endl;
		}
	};
	
	class Variable: public Expr {
		public:
		Token name;
		Environment& env;
		Variable(Token name, Environment& env):env(env){
			this->name = name;
		}
		Value accept(Visitor*) override;
		~Variable(){
			// std::cout << "Variable deleted" << std::endl;
		}
};

#endif
