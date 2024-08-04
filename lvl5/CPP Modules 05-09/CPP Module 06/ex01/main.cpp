/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:25:16 by javier            #+#    #+#             */
/*   Updated: 2024/08/04 06:34:21 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Serializer s;
	Data *data;
	std::string serialized;

	data = new Data;
	data->s1 = "illo";
	data->n = 4;
	data->s2 = "que pasa";

	serialized = s.serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;

	data = s.deserialize();
	if (data)
	{
		std::cout << "Deserialized:" << std::endl;
		std::cout << "s1: " << data->s1 << std::endl;
		std::cout << "n: " << data->n << std::endl;
		std::cout << "s2: " << data->s2 << std::endl;
	}
	else
	{
		std::cout << "Deserialization failed" << std::endl;
	}
	std::cout << "No funciona arreglarlo" << std::endl;
	return 0;
}
