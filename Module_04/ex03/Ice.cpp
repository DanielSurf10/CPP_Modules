#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	DEBUG_MSG("Ice: Default Constructor called");
}

Ice::Ice(const Ice& other): AMateria("ice")
{
	DEBUG_MSG("Ice: Copy Constructor called");
	*this = other;
}

Ice&	Ice::operator=(const Ice& other)
{
	DEBUG_MSG("Ice: Assignation Operator called");
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Ice::~Ice()
{
	DEBUG_MSG("Ice: Destructor called");
}

AMateria*	Ice::clone() const
{
	DEBUG_MSG("Ice: Clone called");
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
