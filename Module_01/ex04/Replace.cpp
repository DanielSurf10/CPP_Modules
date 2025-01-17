#include "Replace.hpp"

Replace::Replace(std::string file_name, std::string to_find, std::string replace) :
	_file_name(file_name), _file_stream(file_name.c_str()),
	_to_find(to_find), _replace(replace)
{
}

Replace::~Replace()
{
	if (this->_file_stream.is_open())
		this->_file_stream.close();
}

void	Replace::create_replaced_file()
{
	size_t		pos;
	std::string	new_file_content;

	std::string	out_file_name = this->_file_name + ".replace";
	if (_file_stream.is_open() == 0)
	{
		std::cerr << "Error: could not open the input file" << std::endl;
		return ;
	}

	std::ofstream	out_file_stream(out_file_name.c_str());
	if (out_file_stream.is_open() == 0)
	{
		std::cerr << "Error: could not create the output file" << std::endl;
		return ;
	}

	std::getline(this->_file_stream, new_file_content, '\0');

	pos = new_file_content.find(this->_to_find);
	while (pos != std::string::npos)
	{
		new_file_content.erase(pos, this->_to_find.length());
		new_file_content.insert(pos, this->_replace);
		pos = new_file_content.find(this->_to_find);
	}

	out_file_stream << new_file_content;
	out_file_stream.close();
}
