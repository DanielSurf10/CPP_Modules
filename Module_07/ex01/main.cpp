#include "iter.hpp"

int	main()
{
	int			array[5] = {1, 2, 3, 4, 5};
	double		array2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	array3[5] = {"Hello", "World", "!", "42", "!"};

	// Test with int array
	std::cout << "Test with int array:" << std::endl;
	iter(array, 5, print_value<int>);
	std::cout << std::endl;

	std::cout << "After doubling:" << std::endl;
	iter(array, 5, double_value<int>);
	iter(array, 5, print_value<int>);
	std::cout << std::endl;

	std::cout << std::endl;

	// Test with double array
	std::cout << "Test with double array:" << std::endl;
	iter(array2, 5, print_value<double>);
	std::cout << std::endl;

	std::cout << "After doubling:" << std::endl;
	iter(array2, 5, double_value<double>);
	iter(array2, 5, print_value<double>);
	std::cout << std::endl;

	std::cout << std::endl;

	// Test with string array
	std::cout << "Test with string array:" << std::endl;
	iter(array3, 5, print_value<std::string>);
	std::cout << std::endl;

	std::cout << std::endl;


	return (0);
}
