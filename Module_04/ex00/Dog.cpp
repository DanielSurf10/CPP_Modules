#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Constructor Dog" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Copy constructor Dog" << std::endl;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Assignation operator Dog" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor Dog" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
