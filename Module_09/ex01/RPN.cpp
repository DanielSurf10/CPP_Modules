#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string input) : input(input) {}

RPN::RPN(const RPN &other) : input(other.input) {}

RPN &RPN::operator==(const RPN &other) {
	if (this != &other)
		this->input = other.input;
	return (*this);
}

RPN::~RPN() {}

void	RPN::perform() {
	int		num;
	char	operator;

	for (std::string::const_iterator it = this->input.begin(); it != this->input.end(); it++) {
		if (std::isspace(*it))
			continue;
	}
}

int RPN::atoi(const std::string &str) {
	int value;
	std::istringstream iss(str);

	iss >> value;

	if (iss.fail())
		throw std::invalid_argument("bad input - " + str);
	return (value);
}
