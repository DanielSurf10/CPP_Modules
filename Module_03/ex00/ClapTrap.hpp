#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;

	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	set_name(const std::string name);
		void	set_hit_points(unsigned int hit_points);
		void	set_energy_points(unsigned int energy_points);
		void	set_attack_damage(unsigned int attack_damage);

		std::string		get_name() const;
		unsigned int	get_hit_points() const;
		unsigned int	get_energy_points() const;
		unsigned int	get_attack_damage() const;

};

#endif
