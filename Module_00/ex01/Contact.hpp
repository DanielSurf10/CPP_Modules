/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:57:55 by danbarbo          #+#    #+#             */
/*   Updated: 2024/07/01 21:13:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact();
	~Contact();
	Contact(std::string firstName, std::string lastName,
		std::string nickname, std::string phoneNumber,
		std::string darkestSecret
	);

	// Getters
	std::string	get_firstName();
	std::string	get_lastName();
	std::string	get_nickname();
	std::string	get_phoneNumber();
	std::string	get_darkestSecret();
};

#endif
