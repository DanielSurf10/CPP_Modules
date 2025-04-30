#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other) {
	(void) other;
	return *this;
}

void ScalarConverter::convert(const std::string &str) {
	char	c;
	int		i;
	float	f;
	double	d;

	f = atof(str.c_str());
	d = static_cast<double>(f);
	i = static_cast<int>(f);

	if (i < -128 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout <<"char: Non displayable" << std::endl;
	else
	{
		c = static_cast<char>(i);
		std::cout << "char: '" << c << "'" << std::endl;
	}

	if (std::isnan(d) || d > INT_MAX || d < INT_MIN)
		std::cout <<"int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;


	std::cout << "float: ";
	if (!isinf(f)
		&& f == static_cast<int>(f))
		std::cout << f << ".0f" << std::endl;
	else {
		if (isinff(f) > 0)
			std::cout << "+";
		std::cout << f << "f" << std::endl;
	}

	std::cout << "double: ";
	if (!isinf(f)
		&& d == static_cast<int>(d))
		std::cout << d << ".0" << std::endl;
	else {
		if (isinff(d) > 0)
			std::cout << "+";
		std::cout << d << std::endl;
	}
}
