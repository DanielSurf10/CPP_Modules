#include "ScalarConverter.hpp"

void testChar()
{
	std::cout << std::endl;
	std::cout << "Testing char: 'A'" << std::endl;
	ScalarConverter::convert("A");

	std::cout << std::endl;
	std::cout << "Testing char: '0'" << std::endl;
	ScalarConverter::convert("0");

	std::cout << std::endl;
	std::cout << "Testing char: '?'" << std::endl;
	ScalarConverter::convert("?");

	std::cout << std::endl;
	std::cout << "Testing char: ' '" << std::endl;
	ScalarConverter::convert(" ");

	std::cout << std::endl;
	std::cout << "Testing char: '\\n'" << std::endl;
	ScalarConverter::convert("\n");

	std::cout << std::endl;
	std::cout << "Testing char: '.'" << std::endl;
	ScalarConverter::convert(".");

	std::cout << std::endl;
	std::cout << "Testing char: 'nan'" << std::endl;
	ScalarConverter::convert("nan");
}

void testInt()
{
	std::cout << std::endl;
	std::cout << "Testing int: '42'" << std::endl;
	ScalarConverter::convert("42");

	std::cout << std::endl;
	std::cout << "Testing int: '-1234'" << std::endl;
	ScalarConverter::convert("-1234");

	std::cout << std::endl;
	std::cout << "Testing int: '2147483647'" << std::endl;
	ScalarConverter::convert("2147483647");

	std::cout << std::endl;
	std::cout << "Testing int: '-2147483648'" << std::endl;
	ScalarConverter::convert("-2147483648");

	std::cout << std::endl;
	std::cout << "Testing int: 'nan'" << std::endl;
	ScalarConverter::convert("nan");
}

void testFloat()
{
	std::cout << std::endl;
	std::cout << "Testing float: '42.00001f'" << std::endl;
	ScalarConverter::convert("42.00001f");

	std::cout << std::endl;
	std::cout << "Testing float: '-1234.5678f'" << std::endl;
	ScalarConverter::convert("-1234.5678f");

	std::cout << std::endl;
	std::cout << "Testing float: '3.14159f'" << std::endl;
	ScalarConverter::convert("3.14159f");

	std::cout << std::endl;
	std::cout << "Testing float: '-1.2345678e5f'" << std::endl;
	ScalarConverter::convert("-1.2345678e5f");

	std::cout << std::endl;
	std::cout << "Testing float: 'inf'" << std::endl;
	ScalarConverter::convert("inf");

	std::cout << std::endl;
	std::cout << "Testing float: '-inf'" << std::endl;
	ScalarConverter::convert("-inf");

	std::cout << std::endl;
	std::cout << "Testing float: 'nan'" << std::endl;
	ScalarConverter::convert("nan");
}

void testDouble()
{
	std::cout << std::endl;
	std::cout << "Testing double: '42.00001'" << std::endl;
	ScalarConverter::convert("42.00001");

	std::cout << std::endl;
	std::cout << "Testing double: '-1234.5678'" << std::endl;
	ScalarConverter::convert("-1234.5678");

	std::cout << std::endl;
	std::cout << "Testing double: '3.14159'" << std::endl;
	ScalarConverter::convert("3.14159");

	std::cout << std::endl;
	std::cout << "Testing double: '-1.2345678e5'" << std::endl;
	ScalarConverter::convert("-1.2345678e5");

	std::cout << std::endl;
	std::cout << "Testing double: 'inf'" << std::endl;
	ScalarConverter::convert("inf");

	std::cout << std::endl;
	std::cout << "Testing double: '-inf'" << std::endl;
	ScalarConverter::convert("-inf");

	std::cout << std::endl;
	std::cout << "Testing double: 'nan'" << std::endl;
	ScalarConverter::convert("nan");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <value>" << std::endl;
		return 1;
	}

	if (std::string(argv[1]) == "test")
	{
		testChar();
		testInt();
		testFloat();
		testDouble();
	}
	else
		ScalarConverter::convert(argv[1]);

	return 0;
}
