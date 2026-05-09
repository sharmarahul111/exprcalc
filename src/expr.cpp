#include "expr.h"
Value Binary::accept(Visitor* v){
	return v->visit_binary_expr(*this);
}
Value Literal::accept(Visitor* v){
	return v->visit_literal_expr(*this);
}
Value Grouping::accept(Visitor* v){
	return v->visit_grouping_expr(*this);
}
Value Unary::accept(Visitor* v){
	return v->visit_unary_expr(*this);
}