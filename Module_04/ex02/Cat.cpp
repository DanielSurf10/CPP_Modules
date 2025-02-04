#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Constructor Cat" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "Copy constructor Cat" << std::endl;
	*this = other;
	this->brain = new Brain(*other.brain);
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Assignation operator Cat" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brain = other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destructor AAnimal" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (this->brain);
}
