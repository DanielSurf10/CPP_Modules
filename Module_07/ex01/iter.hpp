#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void	iter(T *array, unsigned int length, F func)
{
	if (!array || !func)
		return;

	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	print_double(T &value)
{
	std::cout << value * 2 << " ";
}

template <typename T>
void	print_value(T &value)
{
	std::cout << value << " ";
}

template <typename T>
void	double_value(T &value)
{
	value *= 2;
}

#endif
