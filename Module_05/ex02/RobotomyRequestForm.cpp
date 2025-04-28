#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", 72, 45),
	target("default")
{
	DEBUG_MSG("RobotomyRequestForm default constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request Form", 72, 45),
	target(target)
{
	DEBUG_MSG("RobotomyRequestForm constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other),
	target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Robotomy Request Form assignment operator called" << std::endl;
	if (this != &other)
		this->target = other.target;
	return (*this);
}

std::string	RobotomyRequestForm::get_target() const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->validate_grades(executor);
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << "Success! " << this->target << " is now a proud member of the robot revolution!" << std::endl;
	else
		std::cout << "Alas! The attempt to robotomize " << this->target << " has fizzled out spectacularly." << std::endl;
}
