#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string		name;
		bool			is_signed;
		unsigned int	grade_to_sign;
		unsigned int	grade_to_execute;

	public:
		Form();
		Form(std::string name, int grade_sign, int grade_execute);
		Form(const Form &other);
		~Form();

		Form&	operator=(const Form &other);

		std::string		get_name() const;
		bool			get_is_signed() const;
		unsigned int	get_grade_to_sign() const;
		unsigned int	get_grade_to_execute() const;

		void			be_signed(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif
