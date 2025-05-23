#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm &other);

		std::string	get_target() const;
		void		execute(const Bureaucrat &executor) const;
};

#endif
