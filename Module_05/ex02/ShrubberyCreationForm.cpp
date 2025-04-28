#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137),
	target("default")
{
	DEBUG_MSG("Shrubbery Creation Form default constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery_Creation_Form", 145, 137),
	target(target)
{
	DEBUG_MSG("Shrubbery Creation Form constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other),
	target(other.target)
{
	DEBUG_MSG("Shrubbery Creation Form copy constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	DEBUG_MSG("Shrubbery Creation Form destructor called");
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	DEBUG_MSG("Shrubbery Creation Form assignment operator called");
	if (this != &other)
		this->target = other.target;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->validate_grades(executor);

	std::ofstream	file((this->target + "_shrubbery").c_str());
	if (!file)
		throw std::runtime_error("Failed to open file");

	file << "----------------------|\n";
	file << "|         _-_         |\n";
	file << "|      /~~   ~~\\      |\n";
	file << "|   /~~         ~~\\   |\n";
	file << "|  {               }  |\n";
	file << "|   \\  _-     -_  /   |\n";
	file << "|    \\~  \\\\ //  ~/    |\n";
	file << "|         | |         |\n";
	file << "|         | |         |\n";
	file << "|        // \\\\        |\n";
	file << "----------------------|\n";

	file.close();
}
