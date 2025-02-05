#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Constructor WrongCat" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "Copy constructor WrongCat" << std::endl;
	*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Assignation operator WrongCat" << std::endl;
	if (this == &other)
		this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow... I mean, I'm not a cat" << std::endl;
}
