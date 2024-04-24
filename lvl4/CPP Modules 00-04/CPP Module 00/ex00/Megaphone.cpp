/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:08:53 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/24 13:29:21 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // C++ Standard Library's Input/Output Stream Library
#include <cctype>	// toupper();

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j] != '\0'; j++)
				std::cout << static_cast<char>(toupper(argv[i][j]));
		}	
	}
	std::cout << std::endl;
}
