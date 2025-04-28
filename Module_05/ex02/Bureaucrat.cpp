#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	DEBUG_MSG("Bureaucrat default constructor called");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	DEBUG_MSG("Bureaucrat constructor called");
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	DEBUG_MSG("Bureaucrat copy constructor called");
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{
	DEBUG_MSG("Bureaucrat destructor called");
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	DEBUG_MSG("Bureaucrat copy assignment operator called");
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

std::string	Bureaucrat::get_name() const
{
	return (this->name);
}

unsigned int	Bureaucrat::get_grade() const
{
	return (this->grade);
}

void	Bureaucrat::increment_grade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrement_grade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.be_signed(*this);
		std::cout << this->name << " signed " << form.get_name() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << form.get_name() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.get_name() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't execute " << form.get_name() << " because " << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade();
	return (out);
}
