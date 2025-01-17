#include "Replace.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <to_find> <replace>";
		return (1);
	}

	Replace	file(argv[1], argv[2], argv[3]);
	file.create_replaced_file();

	return (0);
}
