/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:45:42 by javier            #+#    #+#             */
/*   Updated: 2024/08/14 08:48:34 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(4);  //Para que salga 5 Not found

	std::cout << "Vector:" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::vector<int>::iterator it = easyfind(vec, i);
		if (it != vec.end())
			std::cout << "Found " << i << std::endl;
		else
			std::cout << "Not found " << i << std::endl;
	}

	std::cout << "List:" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::list<int>::iterator it = easyfind(lst, i);
		if (it != lst.end())
			std::cout << "Found " << i << std::endl;
		else
			std::cout << "Not found " << i << std::endl;
	}

	return 0;
}
