#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->name << " is alive" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->name << " has been copied" << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap " << this->name << " has been assigned" << std::endl;
	if (this != &other)
	{
		this->name = other.get_name();
		this->hit_points = other.get_hit_points();
		this->energy_points = other.get_energy_points();
		this->attack_damage = other.get_attack_damage();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destroying ScavTrap " << this->name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
		std::cout << "ScavTrap " << this->name << " is already dead" << std::endl;
	else if (this->energy_points == 0)
		std::cout << "ScavTrap " << this->name << " has no energy points to attack" << std::endl;
	else
	{
		this->energy_points -= 1;
		if (target.empty())
			std::cout << "ScavTrap " << this->name << " flails around aimlessly, attacking nothing but thin air" << std::endl;
		else
			std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}
