#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl(void);
		~Harl();

		void complain(std::string level);

		enum ComplaintLevel
		{
			DEBUG = 1,
			INFO,
			WARNING,
			ERROR
		};
};

#endif
