/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:14:00 by danbarbo          #+#    #+#             */
/*   Updated: 2024/07/01 21:14:55 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : contacts_count(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string	PhoneBook::get_input(std::string type)
{
	std::string	input = "";

	do
	{
		std::cout << type << ": ";
		std::getline(std::cin, input);
	}
	while (std::cin.good() && input.empty());

	if (!std::cin.good())
		exit(0);

	return (input);
}

void	PhoneBook::add_contact()
{
	std::string	input = "";
	std::string	name = "";
	std::string	lastName = "";
	std::string	nickName = "";
	std::string	phoneNumber = "";
	std::string	darkestSecret = "";
	Contact		contact;

	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Add contact" << std::endl;

	name = this->get_input("Name");
	lastName = this->get_input("Last name");
	nickName = this->get_input("Nickname");
	phoneNumber = this->get_input("Phone number");
	darkestSecret = this->get_input("Darkest secret");

	contact = Contact(name, lastName, nickName, phoneNumber, darkestSecret);

	this->contacts[this->contacts_count % 8] = contact;
	this->contacts_count++;
}

Contact	PhoneBook::get_contact(int index)
{
	return (this->contacts[index % 8]);
}

std::string	format_value(const std::string& value)
{
	if (value.length() > 10)
		return (value.substr(0, 9) + ".");
	return (value);
}

void	PhoneBook::search()
{
	int			i = 0;
	std::string	input = "";

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Search contact" << std::endl;

	if (this->contacts_count == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return ;
	}

	std::cout << "Index|First Name| Last Name|  Nickname" << std::endl;
	while (i < this->contacts_count && i < 8)
	{
		Contact contact = this->get_contact(i);
		std::cout << std::setw(5) << i + 1 << "|";
		std::cout << std::setw(10) << format_value(contact.get_firstName()) << "|";
		std::cout << std::setw(10) << format_value(contact.get_lastName()) << "|";
		std::cout << std::setw(10) << format_value(contact.get_nickname()) << std::endl;
		i++;
	}

	std::cout << "----------------------------------------" << std::endl;

	do
	{
		std::cout << "Enter an index: ";
		std::getline(std::cin, input);
	}
	while (std::cin.good()
		&& (input.empty() || input.find_first_not_of("0123456789") != std::string::npos
		|| std::atoi(input.c_str()) == 0 || std::atoi(input.c_str()) > this->contacts_count));

	if (!std::cin.good())
		exit(0);

	std::cout << "----------------------------------------" << std::endl;

	i = std::atoi(input.c_str());
	if (i > 0 && i <= this->contacts_count)
	{
		Contact	contact = this->get_contact(i - 1);

		std::cout << "Contact details" << std::endl;
		std::cout << "First Name: " << contact.get_firstName() << std::endl;
		std::cout << "Last Name: " << contact.get_lastName() << std::endl;
		std::cout << "Nickname: " << contact.get_nickname() << std::endl;
		std::cout << "Phone number: " << contact.get_phoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contact.get_darkestSecret() << std::endl;
	}
}
