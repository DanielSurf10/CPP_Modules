#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap	blop("Valentina");

		std::cout << "\nHealth Points tests" << std::endl;
		blop.takeDamage(1);
		blop.beRepaired(2);
		blop.takeDamage(11);
		blop.takeDamage(1);
		std::cout << std::endl;

		std::cout << "Energy tests" << std::endl;

		blop.set_energy_points(0);
		blop.set_hit_points(10);
		blop.attack("you");
		blop.beRepaired(1);
		blop.attack("a ghost");
		blop.guardGate();
	}

	std::cout << std::endl;
	std::cout << "Tests done, time to fight." << std::endl;
	std::cout << std::endl;

	{
		ScavTrap	fighterOne("Zorro");
		ScavTrap	fighterTwo("Penelope");

		std::cout << std::endl;

		fighterOne.attack("Penelope");
		fighterTwo.takeDamage(fighterOne.get_attack_damage());
		fighterTwo.attack("Zorro");
		fighterOne.takeDamage(fighterTwo.get_attack_damage());
		fighterOne.guardGate();
		fighterTwo.guardGate();

		std::cout << "The fight ends because both fighters are in defensive mode...\n" << std::endl;
	}
	return (0);
}
