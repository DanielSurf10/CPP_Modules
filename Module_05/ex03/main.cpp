#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;
	AForm *tmp;

	std::cout << ("\nROBOTOMY REQUEST") << std::endl;
	try {
		tmp = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << ("Form created successfully!") << std::endl;
		delete tmp;
	} catch (Intern::FormNotFoundException &e) {
		std::cout << ("Form not found!") << std::endl;
	}

	std::cout << ("\nSHRUBBERY CREATION") << std::endl;
	try {
		tmp = someRandomIntern.makeForm("shrubbery creation", "Downtown");
		std::cout << ("Form created successfully!") << std::endl;
		delete tmp;
	} catch (Intern::FormNotFoundException &e) {
		std::cout << ("Form not found!") << std::endl;
	}

	std::cout << ("\nPRESIDENTIAL PARDON") << std::endl;
	try {
		tmp =
		someRandomIntern.makeForm("presidential pardon", "corrupt politician");
		std::cout << ("Form created successfully!") << std::endl;
		delete tmp;
	} catch (Intern::FormNotFoundException &e) {
		std::cout << ("Form not found!") << std::endl;
	}

	std::cout << ("\nTAX EXEMPTION") << std::endl;
	try {
		tmp = someRandomIntern.makeForm("tax exemption", "Bruno Moretti");
		std::cout << ("Form created successfully!") << std::endl;
		delete tmp;
	} catch (Intern::FormNotFoundException &e) {
		std::cout << ("Form not found!") << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
