#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>

class RPN {
	private:
		std::stack<int>	stack;
		std::string		input;

		RPN();

	public:
		RPN(char *input);
		RPN(const RPN &other);
		RPN &operator==(const RPN &other);
		~RPN();

		int	perform();
		std::stack<int>& getStack();
};

#endif
