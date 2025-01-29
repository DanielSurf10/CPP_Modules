#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	{
		FragTrap	blep("Nestor");

		std::cout << "Health Points tests" << std::endl;

		blep.takeDamage(1);
		blep.beRepaired(2);
		blep.takeDamage(11);
		blep.takeDamage(1);
		std::cout << std::endl;

		std::cout << "Energy tests" << std::endl;

		blep.set_energy_points(0);
		blep.set_hit_points(10);
		blep.attack("You");
		blep.beRepaired(1);
		blep.attack("");
		blep.highFivesGuys();
	}
	std::cout << std::endl;
	std::cout << "Tests done, time to fight." << std::endl;
	std::cout << std::endl;
	{
		ScavTrap	fighterOne("João");
		FragTrap	fighterTwo("Maria");

		fighterOne.attack("Maria");
		fighterTwo.takeDamage(fighterOne.get_attack_damage());
		fighterTwo.attack("João");
		fighterOne.takeDamage(fighterTwo.get_attack_damage());
		fighterOne.guardGate();
		fighterTwo.highFivesGuys();

		std::cout << "\nThe fight ends because one fighter is in defensive mode "
			<< "and the other guy is trying to make peace with a high five" << std::endl;
	}

	return (0);
}
