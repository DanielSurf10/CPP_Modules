/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:00:08 by danbarbo          #+#    #+#             */
/*   Updated: 2024/07/01 21:00:28 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() :
	firstName(""),
	lastName(""),
	nickname(""),
	phoneNumber(""),
	darkestSecret("")
{
}

Contact::~Contact()
{
}

Contact::Contact(std::string firstName, std::string lastName,
					std::string nickname, std::string phoneNumber,
					std::string darkestSecret) :
	firstName(firstName),
	lastName(lastName),
	nickname(nickname),
	phoneNumber(phoneNumber),
	darkestSecret(darkestSecret)
{
}

std::string	Contact::get_firstName()
{
	return (this->firstName);
}

std::string	Contact::get_lastName()
{
	return (this->lastName);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

std::string	Contact::get_phoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::get_darkestSecret()
{
	return (this->darkestSecret);
}
