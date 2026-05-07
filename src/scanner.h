#ifndef SCANNER_H
#define SCANNER_H

#include<vector>
#include "token.h"
class Scanner {
	int start {0};
	int end {0};
	int curr {0};
	// int line {0};
	public:
		std::vector<Token> scan_tokens(std::string_view source);
};

#endif