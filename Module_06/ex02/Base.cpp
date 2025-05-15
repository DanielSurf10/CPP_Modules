#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int		randNum = rand() % 3;
	Base	*base;

	if (randNum == 0)
		base = new A();
	else if (randNum == 1)
		base = new B();
	else
		base = new C();
	return (base);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception&) {}

	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception&) {}

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception&) {}
}
