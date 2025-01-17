#include "Replace.hpp"

Replace::Replace(std::string file_name, std::string to_find, std::string replace)
	: _file_name(file_name), _to_find(to_find), _replace(replace)
{
	this->_file_stream = std::ifstream(file_name.c_str());
}

Replace::~Replace()
{
	if (this->_file_stream.is_open())
		this->_file_stream.close();
}

void	Replace::create_replaced_file()
{
	unsigned int	pos;
	std::string		new_file_content;
	std::string		new_file_name = this->_file_name + ".replace";
	std::ofstream	new_file_stream;

	if (_file_stream.is_open() == 0)
	{
		std::cerr << "Error: could not open the input file" << std::endl;
		return ;
	}

	new_file_stream = std::ofstream(new_file_name.c_str());
	if (new_file_stream.is_open() == 0)
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

	new_file_stream << new_file_content;
	new_file_stream.close();
}
