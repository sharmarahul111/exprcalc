#include "library.h"

Context library(){
	Context ctx;
	ctx.constants["pi"] = 3.141592653897932;
	ctx.constants["G"] = 6.6743e-11;
	return ctx;
}