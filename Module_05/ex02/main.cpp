#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void shruberryTests() {
	/* ShrubberyCreationForm tests */
	std::cout << "==== SHRUBBERY CREATION FORM TESTS ====" << std::endl;
	std::cout << "\n=== LOW GRADE TO SIGN FORM ===" << std::endl;
	{
		AForm *a = new ShrubberyCreationForm("home");
		Bureaucrat b("Serj", 150);
		try {
			b.signForm(*a);
			b.executeForm(*a);
		} catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		delete a;
	}
	std::cout << "\n=== LOW GRADE TO EXECUTE FORM ===" << std::endl;
	{
		AForm *a = new ShrubberyCreationForm("home");
		Bureaucrat b("Daron", 140);
		try {
			b.signForm(*a);
			b.executeForm(*a);
		} catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		delete a;
	}
	std::cout << "\n=== CREATING A SHRUBBERY CREATION FORM ==="
			<< std::endl;
	{
		AForm *a = new ShrubberyCreationForm("home");
		Bureaucrat b("Shavo", 130);
		Bureaucrat c("John", 1);
		try {
			b.signForm(*a);
			b.executeForm(*a);
		} catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		delete a;
	}
}

void robotomyTests() {
	/* RobotomyRequestForm tests */
	std::cout << "\n\n==== ROBOTOMY REQUEST FORM TESTS ====" << std::endl;
	std::cout << "\n== LOW GRADE TO SIGN FORM ===" << std::endl;
	{
	AForm *a = new RobotomyRequestForm("home");
	Bureaucrat b("Freddie", 73);

	b.signForm(*a); // Grade should be equal or higher than 72!
	b.executeForm(*a);

	delete a;
	}
	std::cout << "\n=== LOW GRADE TO EXECUTE FORM ===" << std::endl;
	{
	AForm *a = new RobotomyRequestForm("home");
	Bureaucrat b("Brian", 48);

	b.signForm(*a);
	b.executeForm(*a); // Grade should be equal or higher than 45!

	delete a;
	}
	std::cout << "\n=== CREATING A ROBOTOMY REQUEST FORM ===" << std::endl;
	{
	AForm *a = new RobotomyRequestForm("Arthur");
	Bureaucrat b("Roger", 42);
	Bureaucrat c("Mike", 5);

	b.signForm(*a);
	c.executeForm(*a);
	delete a;
	}
}

void presidentialTests() {
	/* PresidentialPardonForm tests */
	std::cout << "\n\n==== PRESIDENTIAL REQUEST FORM TESTS ===="
			<< std::endl;
	std::cout << "\n== LOW GRADE TO SIGN FORM ===" << std::endl;
	{
		AForm *a = new PresidentialPardonForm("Renato");
		try {
			Bureaucrat b("Hermes", 73);

			b.signForm(*a);
			b.executeForm(*a);
		} catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		delete a;
	}
	std::cout << "\n=== LOW GRADE TO EXECUTE FORM ===" << std::endl;
	{
		AForm *a = new PresidentialPardonForm("pardon");
		try {
			Bureaucrat b("Linus", 48);

			b.signForm(*a);
			b.executeForm(*a);
		} catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		delete a;
	}
	std::cout << "\n=== CREATING A PRESIDENTIAL REQUEST FORM ==="
			<< std::endl;
	{
		AForm *a = new PresidentialPardonForm("James");
		try {
			Bureaucrat b("Bjarne", 42);
			Bureaucrat c("Stroustrup", 5);

			b.signForm(*a);
			c.executeForm(*a);
		} catch (const std::exception &e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		delete a;
	}
}

int main(void) {
	shruberryTests();
	robotomyTests();
	presidentialTests();

	return (0);
}
