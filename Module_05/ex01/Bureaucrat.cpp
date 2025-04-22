#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	std::cout << "Copy constructor called" << std::endl;
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

void	Bureaucrat::signForm(Form &form)
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
