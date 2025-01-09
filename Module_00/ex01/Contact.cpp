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
	_firstName(""),
	_lastName(""),
	_nickname(""),
	_phoneNumber(""),
	_darkestSecret("")
{
}

Contact::~Contact()
{
}

Contact::Contact(std::string firstName, std::string lastName,
					std::string nickname, std::string phoneNumber,
					std::string darkestSecret) :
	_firstName(firstName),
	_lastName(lastName),
	_nickname(nickname),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
}

std::string	Contact::get_firstName()
{
	return (this->_firstName);
}

std::string	Contact::get_lastName()
{
	return (this->_lastName);
}

std::string	Contact::get_nickname()
{
	return (this->_nickname);
}

std::string	Contact::get_phoneNumber()
{
	return (this->_phoneNumber);
}

std::string	Contact::get_darkestSecret()
{
	return (this->_darkestSecret);
}
