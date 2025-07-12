#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
	private:
		std::string		input;
		std::stack<int>	stack;

		RPN();

	public:
		RPN(const std::string input);
		RPN(const RPN &other);
		RPN &operator==(const RPN &other);
		~RPN();

		void	perform();
};

#endif
