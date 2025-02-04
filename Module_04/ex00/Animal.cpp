#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Contructor Animal" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor Animal" << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal &other)
{
	std::cout << "Assignation operator Animal" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor Animal" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Grrrrr" << std::endl;
}
