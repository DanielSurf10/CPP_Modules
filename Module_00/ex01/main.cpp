/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:17:35 by danbarbo          #+#    #+#             */
/*   Updated: 2024/07/01 21:21:52 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	print_header()
{
	std::cout << std::endl;
	std::cout << "📞 Welcome to Your Awesome PhoneBook 📖" << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------USAGE------------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
}

int main()
{
	PhoneBook	phonebook = PhoneBook();

	print_header();
	do
	{
		std::string	input;
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);

		if (std::cin.good() && !input.empty())
		{
			if (input.compare("ADD") == 0)
				phonebook.add_contact();
			else if (input.compare("SEARCH") == 0)
				phonebook.search();
			else if (input.compare("EXIT") == 0)
				break;
			else
				continue;
			std::cout << "\n";
			print_header();
		}
	}
	while (std::cin.good());

	return (0);
}
