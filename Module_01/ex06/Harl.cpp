#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "DEBUG" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
					"I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough!"
					"If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years"
					"and you just started working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR" << std::endl;
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int			level_int = 0;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(levels[i]) == 0)
		{
			level_int = i + 1;
			break;
		}
	}

	switch (level_int)
	{
		case DEBUG:
			debug();
			// fall through

		case INFO:
			info();
			// fall through

		case WARNING:
			warning();
			// fall through

		case ERROR:
			error();
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
