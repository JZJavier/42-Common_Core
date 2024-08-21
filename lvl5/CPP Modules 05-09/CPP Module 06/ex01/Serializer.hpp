/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:24:03 by javier            #+#    #+#             */
/*   Updated: 2024/08/21 17:18:56 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef	size_t	uintptr_t;

typedef struct Data {

	int	 			num;
	std::string		str;

}	Data;

class Serialization
{

	private:
		Serialization();
		~Serialization();
		Serialization(const Serialization&);
    	Serialization& 	operator=(const Serialization&);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
