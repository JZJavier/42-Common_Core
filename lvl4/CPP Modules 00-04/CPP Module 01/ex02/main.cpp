/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:38:06 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/17 08:49:52 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	
	// Pointer to the string
	std::string *stringPTR = &str;
	
	// Reference to the string
	std::string &stringREF = str;

	std::cout << "Memory address of the string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF. " << &stringREF << std::endl;

	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR " << *stringPTR << std::endl;
	std::cout << "Value pointed to bystringREF. " << stringREF << std::endl;
	
	return (0);	
}
