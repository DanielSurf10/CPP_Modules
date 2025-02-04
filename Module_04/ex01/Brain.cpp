#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor Brain" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		if (i % 2 == 0)
			ideas[i] = "chase tail";
		else
			ideas[i] = "nap in the sun";
	}
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy constructor Brain" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = copy.ideas[i];
}

Brain	&Brain::operator=(const Brain &copy)
{
	std::cout << "Assignation operator Brain" << std::endl;
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; ++i)
		ideas[i] = copy.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor Brain" << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	return (ideas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	ideas[index] = idea;
}
