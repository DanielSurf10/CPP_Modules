#include "AMateria.hpp"

AMateria::AMateria() : type("no_type")
{
	DEBUG_MSG("AMateria: Default Constructor called");
}

AMateria::AMateria(const std::string& type) : type(type)
{
	DEBUG_MSG("AMateria: Parametric Constructor called");
}

AMateria::AMateria(const AMateria& other)
{
	DEBUG_MSG("AMateria: Copy Constructor called");
	this->type = other.type;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	DEBUG_MSG("AMateria: Assignation operator called");
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AMateria::~AMateria()
{
	DEBUG_MSG("AMateria: Destructor called");
}

const std::string&	AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Materia used at " << target.getName() << std::endl;
}
