#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	DEBUG_MSG("Cure: Default Constructor called");
}

Cure::Cure(const Cure& other): AMateria("cure")
{
	DEBUG_MSG("Cure: Copy Constructor called");
	*this = other;
}

Cure&	Cure::operator=(const Cure& other)
{
	DEBUG_MSG("Cure: Assignation operator called");
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cure::~Cure()
{
	DEBUG_MSG("Cure: Destructor called");
}

AMateria*	Cure::clone() const
{
	DEBUG_MSG("Cure: Clone called");
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
