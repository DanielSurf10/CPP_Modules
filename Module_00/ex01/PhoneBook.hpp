/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:10:43 by danbarbo          #+#    #+#             */
/*   Updated: 2024/07/01 21:13:53 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <string>

class PhoneBook
{
private:
	int		contacts_count;
	Contact	contacts[8];

	std::string	get_input(std::string type);
	std::string	get_print_string(std::string str);

public:
	PhoneBook();
	~PhoneBook();

	void	add_contact();
	Contact	get_contact(int index);
	void	search();
};

#endif
