#include "Form.hpp"

Form::Form() :
	name("default"),
	is_signed(false),
	grade_to_sign(150),
	grade_to_execute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int grade_sign, int grade_execute) :
	name(name),
	is_signed(false),
	grade_to_sign(grade_sign),
	grade_to_execute(grade_execute)
{
	std::cout << "Form constructor called" << std::endl;

	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) :
	name(other.name),
	is_signed(other.is_signed),
	grade_to_sign(other.grade_to_sign),
	grade_to_execute(other.grade_to_execute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		this->is_signed = other.is_signed;
	return (*this);
}

std::string	Form::get_name() const
{
	return (this->name);
}

bool	Form::get_is_signed() const
{
	return (this->is_signed);
}

unsigned int	Form::get_grade_to_sign() const
{
	return (this->grade_to_sign);
}

unsigned int	Form::get_grade_to_execute() const
{
	return (this->grade_to_execute);
}

void	Form::be_signed(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() > this->grade_to_sign)
		throw GradeTooLowException();
	this->is_signed = true;
	std::cout << bureaucrat.get_name() << " signed " << this->name << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream&	operator<<(std::ostream &out, const Form &form)
{
	out << "Form name: " << form.get_name() << std::endl;
	out << "Is signed: " << (form.get_is_signed() ? "yes" : "no") << std::endl;
	out << "Grade to sign: " << form.get_grade_to_sign() << std::endl;
	out << "Grade to execute: " << form.get_grade_to_execute() << std::endl;
	out << std::endl;
	return (out);
}
