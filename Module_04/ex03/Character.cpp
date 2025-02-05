#include "Character.hpp"

Character::Character() : name("no_name")
{
	DEBUG_MSG("Character: Default Constructor called");
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	DEBUG_MSG("Character: Parametric Constructor called");
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	DEBUG_MSG("Character: Copy Constructor called");

	// *this = other;

	this->name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other)
{
	DEBUG_MSG("Character: Assignation Operator called");
	if (this == &other)
		return (*this);
	this->name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	DEBUG_MSG("Character: Destructor called");
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

const std::string&	Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			DEBUG_MSG("Character " << this->name << " equiped with materia " << m->getType() << "at index " << i << ".");
			this->inventory[i] = m;
			break ;
		}
		if (i == 3)
		{
			DEBUG_MSG("Character " << this->name << " can not equip. Invetory is full.");
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !this->inventory[idx])
	{
		DEBUG_MSG("Character " << this->name << " can not unequip. Invalid index.");
		return ;
	}
	DEBUG_MSG("Character " << this->name << " unequiped with materia " << this->inventory[idx]->getType() << " at index " << idx << ".");
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !this->inventory[idx])
	{
		DEBUG_MSG("Character " << this->name << " can not use. Invalid index");
		return ;
	}
	DEBUG_MSG("Character " << this->name << " using materia " << this->inventory[idx]->getType() << " at index " << idx << ".");
	this->inventory[idx]->use(target);
}

AMateria	*Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= 4)
		return (NULL);
	return (this->inventory[idx]);
}
