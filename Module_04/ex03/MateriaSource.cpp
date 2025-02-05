#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	DEBUG_MSG("MateriaSource: Default Constructor called");
	for (int i = 0; i < 4; i++)
		this->materiaInventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	DEBUG_MSG("MateriaSource: Copy Constructor called");
	for (int i = 0; i < 4; i++)
	{
		if (other.materiaInventory[i])
			this->materiaInventory[i] = other.materiaInventory[i]->clone();
		else
			this->materiaInventory[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	DEBUG_MSG("MateriaSource: Assignation operator called");
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->materiaInventory[i])
			delete this->materiaInventory[i];
		if (other.materiaInventory[i])
			this->materiaInventory[i] = other.materiaInventory[i]->clone();
		else
			this->materiaInventory[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	DEBUG_MSG("MateriaSource: Destructor called");
	for (int i = 0; i < 4; i++)
	{
		if (this->materiaInventory[i])
		{
			delete this->materiaInventory[i];
			this->materiaInventory[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->materiaInventory[i])
		{
			DEBUG_MSG("Materia " << materia->getType() << " learned in slot " << i << ".");
			this->materiaInventory[i] = materia;
			return;
		}
	}
	DEBUG_MSG("Materia inventory is full, " << materia->getType() << " not learned.");
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materiaInventory[i]
			&& this->materiaInventory[i]->getType().compare(type) == 0)
			{
				DEBUG_MSG("Materia " << type << " created from slot " << i << ".");
				return (this->materiaInventory[i]->clone());
			}
	}
	DEBUG_MSG("Materia " << type << " not found.");
	return (NULL);
}
