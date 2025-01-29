#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name("NoName"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << this->name << " is alive" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << this->name << " is alive" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap " << this->name << " has been copied" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap " << this->name << " has been assigned" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destroying ClapTrap " << this->name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points to attack" << std::endl;
	else
	{
		this->energy_points -= 1;
		if (target.empty())
			std::cout << "ClapTrap " << this->name << " swings wildly at the air, unsure of what to attack" << std::endl;
		else
			std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
	else if (amount > this->hit_points)
	{
		this->hit_points = 0;
		std::cout << "ClapTrap " << this->name << " has been killed" << std::endl;
	}
	else
	{
		this->hit_points -= amount;
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " has no energy points to be repaired" << std::endl;
	else
	{
		this->energy_points -= 1;
		this->hit_points += amount;
		std::cout << "ClapTrap " << this->name << " has been repaired by " << amount << " points" << std::endl;
	}
}

void	ClapTrap::set_name(const std::string name)
{
	this->name = name;
}

void	ClapTrap::set_hit_points(unsigned int hit_points)
{
	this->hit_points = hit_points;
}

void	ClapTrap::set_energy_points(unsigned int energy_points)
{
	this->energy_points = energy_points;
}

void	ClapTrap::set_attack_damage(unsigned int attack_damage)
{
	this->attack_damage = attack_damage;
}

std::string	ClapTrap::get_name() const
{
	return this->name;
}

unsigned int	ClapTrap::get_hit_points() const
{
	return this->hit_points;
}

unsigned int	ClapTrap::get_energy_points() const
{
	return this->energy_points;
}

unsigned int	ClapTrap::get_attack_damage() const
{
	return this->attack_damage;
}
