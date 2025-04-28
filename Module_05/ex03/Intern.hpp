#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern&	operator=(const Intern &other);
		AForm*	makeForm(std::string form_name, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
