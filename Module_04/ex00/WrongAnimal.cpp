#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Constructor WrongAnimal" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy constructor WrongAnimal" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignment operator" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Kwak" << std::endl;
}
