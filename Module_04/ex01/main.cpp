#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	{
		std::cout << "\n  SUBJECT TESTS  \n" << std::endl;

		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}

	{
		std::cout << "\n  MORE TESTS  \n" << std::endl;

		const int arraySize = 4;
		Animal *animals[arraySize];

		for (int i = 0; i < arraySize / 2; ++i) {
			animals[i * 2] = new Dog();
			animals[i * 2 + 1] = new Cat();
		}
		std::cout << std::endl;

		std::cout << "\nDeleting animals\n" << std::endl;

	/* Delete animals */
		for (int i = 0; i < arraySize; ++i) {
			delete animals[i];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "\n  COPY TESTS  \n" << std::endl;

		const Dog *dog = new Dog();
		const Dog *dog2 = new Dog(*dog);

		dog->getBrain()->setIdea(0, "Literally nothing");
		std::cout << "-> dog idea: " << dog->getBrain()->getIdea(0) << std::endl;

		std::cout << "\nDeleting dogs\n" << std::endl;
		delete dog;
		std::cout << "-> dog2 idea: " << dog2->getBrain()->getIdea(0) << std::endl;
		delete dog2;
	}

	{
		std::cout << "\n  ASSIGNING TESTS  \n" << std::endl;

		std::cout << "\nAssigning\n" << std::endl;
		Dog original;
		{
			Dog copy = original;
			std::cout << copy.getType() << std::endl;
			copy.makeSound();
		}
		std::cout << "\n" << original.getType() << std::endl;
		original.makeSound();
	}

	return (0);
}
