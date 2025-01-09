#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << " is alive!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}
