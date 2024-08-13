/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:47:27 by javier            #+#    #+#             */
/*   Updated: 2024/08/13 13:02:08 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print(int const &i)
{
	std::cout << i << std::endl;
}

void addOne(int &i)
{
	i++;
}

int main()
{
	int tab[] = { 0, 1, 2, 3, 4 };
	::iter(tab, 5, print);
	std::cout << std::endl;
	::iter(tab, 5, addOne);
	::iter(tab, 5, print);
	std::cout << std::endl;
	::iter(tab, 5, addOne);
	::iter(tab, 5, print);
	std::cout << std::endl;
	return 0;
}
