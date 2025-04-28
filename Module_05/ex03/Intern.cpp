#include "Intern.hpp"

Intern::Intern()
{
	DEBUG_MSG("Intern default constructor called");
}

Intern::Intern(const Intern &other)
{
	DEBUG_MSG("Intern copy constructor called");
	(void)other;
}

Intern::~Intern()
{
	DEBUG_MSG("Intern destructor called");
}

Intern&	Intern::operator=(const Intern &other)
{
	DEBUG_MSG("Intern assignment operator called");
	(void)other;
	return (*this);
}

AForm*	Intern::makeForm(std::string form_name, std::string target)
{
	const std::string	form_names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int		i = -1;
	AForm*	form = NULL;

	for (int j = 0; j < 3; j++)
	{
		if (form_name == form_names[j])
			i = j;
	}

	if (i == -1)
		throw FormNotFoundException();

	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			break;
	}

	return (form);
}

const char*	Intern::FormNotFoundException::what() const throw()
{
	return ("Invalid form request");
}
