#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(char *input) : input(input) {
	if (this->input.empty())
		throw std::invalid_argument("bad input - empty input");
}

RPN::RPN(const RPN &other) {
	(void) other;
}

RPN &RPN::operator==(const RPN &other) {
	(void) other;
	return (*this);
}

RPN::~RPN() {}

std::stack<int>& RPN::getStack() {
	return this->stack;
}

int	RPN::perform() {
	int result;

	for (std::string::iterator it = this->input.begin(); it != this->input.end(); it++) {

		if ((!std::isdigit(*it) && !std::isspace(*it) && *it != '+' && *it != '-' && *it != '*' && *it != '/'))
			throw std::invalid_argument("bad input - " + this->input);

		if (std::isspace(*it))
			continue;

		if (*it == '+' || *it == '-' || *it == '*' || *it == '/') {

			if (this->stack.size() < 2)
				throw std::invalid_argument("not enough operands for operation - " + this->input);

			int num1 = this->stack.top();
			this->stack.pop();
			int num2 = this->stack.top();
			this->stack.pop();

			switch (*it) {
				case '+':
					result = num2 + num1;
					break;
				case '-':
					result = num2 - num1;
					break;
				case '*':
					result = num2 * num1;
					break;
				case '/':
					if (num1 == 0)
						throw std::invalid_argument("division by zero - " + this->input);
					result = num2 / num1;
					break;
				default:
					throw std::invalid_argument("unknown operator - " + this->input);
			}

			this->stack.push(result);
			continue;
		}

		int value;
		std::string valuestr = std::string(it, this->input.end());
		std::istringstream iss(valuestr);

		iss >> value;

		if (iss.fail() || value < 0 || value > 9)
			throw std::invalid_argument("bad input - " + this->input);

		this->stack.push(value);
	}

	if (this->stack.size() != 1)
		throw std::invalid_argument("not enough operations - " + this->input);

	result = this->stack.top();
	this->stack.pop();

	return (result);
}
