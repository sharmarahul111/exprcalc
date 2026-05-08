#include "expr.h"
void Binary::accept(Visitor* v){
	v->visit_binary_expr(*this);
}
void Literal::accept(Visitor* v){
	v->visit_literal_expr(*this);
}
void Grouping::accept(Visitor* v){
	v->visit_grouping_expr(*this);
}
void Unary::accept(Visitor* v){
	v->visit_unary_expr(*this);
}