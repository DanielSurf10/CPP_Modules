#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat&	operator=(const Cat& other);
		virtual ~Cat();

		void	makeSound() const;
		Brain	*getBrain() const;
};
