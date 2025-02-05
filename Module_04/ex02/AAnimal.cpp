#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "Contructor AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Copy constructor AAnimal" << std::endl;
	*this = other;
}

AAnimal&	AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Assignation operator AAnimal" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor AAnimal" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
