#ifndef AFORM_HPP
# define AFORM_HPP

# ifdef DEBUG
#  define DEBUG_MSG(x) std::cout << x << std::endl;
# else
#  define DEBUG_MSG(x)
# endif

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string		name;
		bool			is_signed;
		unsigned int	grade_to_sign;
		unsigned int	grade_to_execute;

	protected:
		void	validate_grades(const Bureaucrat &executor) const;

	public:
		AForm();
		AForm(std::string name, int grade_sign, int grade_execute);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm&	operator=(const AForm &other);

		std::string		get_name() const;
		bool			get_is_signed() const;
		unsigned int	get_grade_to_sign() const;
		unsigned int	get_grade_to_execute() const;

		void			be_signed(const Bureaucrat &bureaucrat);

		virtual void	execute(const Bureaucrat &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif
