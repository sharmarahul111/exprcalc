#ifndef ASTPRINTER_H
#define ASTPRINTER_H

#include<iostream>
#include<string>
#include<vector>
#include "../token.h"
#include "../expr.h"
using Exprs = std::vector<Expr*>;
class ASTPrinter: public Visitor {
	private:
		Value parenthesize(std::string, Exprs);
		Value visit_binary_expr(Binary&);
		Value visit_grouping_expr(Grouping&);
		Value visit_literal_expr(Literal&);
		Value visit_unary_expr(Unary&);
	public:
		std::string print(Expr*);
};
void printExpr(Expr* exp);

#endif