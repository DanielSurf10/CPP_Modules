#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
		
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &other);

		std::string	getTarget() const;
		void		execute(const Bureaucrat &executor) const;
};

#endif
