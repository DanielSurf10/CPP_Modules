#include "AForm.hpp"

AForm::AForm() :
	name("default"),
	is_signed(false),
	grade_to_sign(150),
	grade_to_execute(150)
{
	DEBUG_MSG("AForm default constructor called");
}

AForm::AForm(std::string name, int grade_sign, int grade_execute) :
	name(name),
	is_signed(false),
	grade_to_sign(grade_sign),
	grade_to_execute(grade_execute)
{
	DEBUG_MSG("AForm constructor called");

	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) :
	name(other.name),
	is_signed(other.is_signed),
	grade_to_sign(other.grade_to_sign),
	grade_to_execute(other.grade_to_execute)
{
	DEBUG_MSG("AForm copy constructor called");
}

AForm::~AForm()
{
	DEBUG_MSG("AForm destructor called");
}

AForm&	AForm::operator=(const AForm &other)
{
	DEBUG_MSG("AForm assignment operator called");
	if (this != &other)
		this->is_signed = other.is_signed;
	return (*this);
}

void AForm::validate_grades(const Bureaucrat &executor) const
{
	if (!this->is_signed)
		throw FormNotSignedException();

	if (executor.get_grade() > this->grade_to_execute)
		throw GradeTooLowException();

	std::cout << executor.get_name() << " executed " << this->name << std::endl;
}

std::string	AForm::get_name() const
{
	return (this->name);
}

bool	AForm::get_is_signed() const
{
	return (this->is_signed);
}

unsigned int	AForm::get_grade_to_sign() const
{
	return (this->grade_to_sign);
}

unsigned int	AForm::get_grade_to_execute() const
{
	return (this->grade_to_execute);
}

void	AForm::be_signed(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.get_grade() > this->grade_to_sign)
		throw GradeTooLowException();
	this->is_signed = true;
	std::cout << bureaucrat.get_name() << " signed " << this->name << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream&	operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm name: " << form.get_name() << std::endl;
	out << "Is signed: " << (form.get_is_signed() ? "yes" : "no") << std::endl;
	out << "Grade to sign: " << form.get_grade_to_sign() << std::endl;
	out << "Grade to execute: " << form.get_grade_to_execute() << std::endl;
	out << std::endl;
	return (out);
}
