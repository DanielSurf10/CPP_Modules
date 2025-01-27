#include <iostream>
#include <cstdlib>
#include "Point.hpp"

void test1()
{
	if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
}

void test2()
{
	if (bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15)))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
}

int main()
{
	test1();
	test2();

	return (0);
}
