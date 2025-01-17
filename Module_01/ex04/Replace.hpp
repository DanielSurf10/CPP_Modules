#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace
{
	private:
		std::string		_file_name;
		std::ifstream	_file_stream;
		std::string		_to_find;
		std::string		_replace;

	public:
		Replace(std::string file_name, std::string to_find, std::string replace);
		~Replace();

		void	create_replaced_file();
};

#endif
