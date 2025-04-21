#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << std::endl;
	std::cout << "Test increment a high grade and cout." << std::endl;
	{
		try {
			Bureaucrat john("High Grade Bure", 1);
			std::cout << john << std::endl;

			john.increment_grade();
			std::cout << john << std::endl;

			john.decrement_grade();
			std::cout << john << std::endl;

		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Test decrement a low grade and cout." << std::endl;
	{
		try {
			Bureaucrat john("Low Grade Bure", 150);
			std::cout << john << std::endl;

			john.decrement_grade();
			std::cout << john << std::endl;

			john.increment_grade();
			std::cout << john << std::endl;

		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Now different grade" << std::endl;
	{
		try {
			Bureaucrat john("Mid Grade", 75);
			std::cout << john << std::endl;

			john.increment_grade();
			std::cout << john << std::endl;

			john.decrement_grade();
			std::cout << john << std::endl;

			while (john.get_grade() > 42)
				john.increment_grade();
			std::cout << john << std::endl;

		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	return (0);
}
