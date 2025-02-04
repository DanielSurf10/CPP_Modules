#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		std::cout << "\nSubject test\n" << std::endl;

		const Animal	*alpha = new Animal();
		const Animal	*beta = new Dog();
		const Animal	*gamma = new Cat();
		std::cout << std::endl;

		std::cout << alpha->getType() << " " << std::endl;
		std::cout << beta->getType() << " " << std::endl;
		std::cout << gamma->getType() << " " << std::endl;
		std::cout << std::endl;

		alpha->makeSound();
		beta->makeSound();
		gamma->makeSound();

		std::cout << std::endl;

		delete alpha;
		delete beta;
		delete gamma;
	}

	std::cout << "\nWrong animal test\n" << std::endl;
	{
		const WrongCat		*delta = new WrongCat();
		const WrongAnimal	*epsilon = new WrongCat();
		const Animal		*zeta = new Dog();
		std::cout << std::endl;

		std::cout << delta->getType() << " " << std::endl;
		std::cout << epsilon->getType() << " " << std::endl;
		std::cout << zeta->getType() << " " << std::endl;
		std::cout << std::endl;

		delta->makeSound();
		epsilon->makeSound();
		zeta->makeSound();

		std::cout << std::endl;

		delete delta;
		delete epsilon;
		delete zeta;
	}

	return (0);
}
