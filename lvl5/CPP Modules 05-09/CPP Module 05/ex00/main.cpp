/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:59:51 by javier            #+#    #+#             */
/*   Updated: 2024/08/02 09:09:59 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat paco("Paco", 2);
		std::cout << paco << std::endl;
		paco.incrementGrade();
		std::cout << paco << std::endl;
		paco.incrementGrade();
		std::cout << paco << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat illo("Illo", 149);
		std::cout << illo << std::endl;
		illo.decrementGrade();
		std::cout << illo << std::endl;
		illo.decrementGrade();
		std::cout << illo << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}