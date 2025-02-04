#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Constructor Cat" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Copy constructor Cat" << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Assignation operator Cat" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor Animal" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
