#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " is alive" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " is alive" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap assignation operator" << std::endl;
	if (this == &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destroying FragTrap " << this->name << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a high five" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
		std::cout << "FragTrap " << this->name << " is already dead" << std::endl;
	else if (this->energy_points == 0)
		std::cout << "FragTrap " << this->name << " has no energy points to attack" << std::endl;
	else
	{
		this->energy_points -= 1;
		if (target.empty())
			std::cout << "FragTrap " << this->name << " swings wildly at nothing, hitting only air" << std::endl;
		else
			std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage" << std::endl;
	}
}
