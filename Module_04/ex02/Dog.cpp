#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Constructor Dog" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	std::cout << "Copy constructor Dog" << std::endl;
	*this = other;
	this->brain = new Brain(*other.brain);
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Assignation operator Dog" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brain = other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor Dog" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (this->brain);
}
