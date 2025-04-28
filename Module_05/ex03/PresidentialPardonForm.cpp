#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form", 25, 5),
	target("default")
{
	DEBUG_MSG("Presidential Pardon Form default constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Form", 25, 5),
	target(target)
{
	DEBUG_MSG("Presidential Pardon Form constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other),
	target(other.target)
{
	DEBUG_MSG("Presidential Pardon Form copy constructor called");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	DEBUG_MSG("Presidential Pardon Form destructor called");
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	DEBUG_MSG("Presidential Pardon Form assignment operator called");
	if (this != &other)
		this->target = other.target;
	return (*this);
}

std::string	PresidentialPardonForm::get_target() const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->validate_grades(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
