#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# ifdef DEBUG
#  define DEBUG_MSG(x) std::cout << x << std::endl;
# else
#  define DEBUG_MSG(x)
# endif

# define PRINT_BLUE_BOLD(text) std::cout << "\033[1;34m" << text << "\033[0m" << std::endl;

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria();

		const std::string&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
