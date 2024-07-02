/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:05:03 by danbarbo          #+#    #+#             */
/*   Updated: 2024/07/01 20:50:11 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[]) {

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				std::cout << (char) toupper(argv[i][j]);
			}
		}
	}

	std::cout << std::endl;

	return (0);
}
