#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap blip("Jack");

	std::cout << "Messages tests" << std::endl;
	blip.attack("You");
	blip.attack("");
	blip.takeDamage(10);
	blip.beRepaired(10);

	std::cout << std::endl;
	std::cout << "Health Points tests" << std::endl;

	blip.takeDamage(1);
	blip.beRepaired(2);
	blip.takeDamage(11);
	blip.takeDamage(1);

	std::cout << std::endl;
	std::cout << "Energy tests" << std::endl;

	blip.set_energy_points(0);
	blip.set_hit_points(10);

	blip.attack("You again");
	blip.beRepaired(1);
	blip.attack("A ghost");

	return (0);
}
