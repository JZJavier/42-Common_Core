/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:24:03 by javier            #+#    #+#             */
/*   Updated: 2024/08/04 06:29:40 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <sstream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

class Serializer
{
	private:
		std::string _data;
	public:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();
		Serializer & operator=(Serializer const & rhs);
		std::string getData() const;
		void setData(std::string data);
		Data * deserialize();
		std::string serialize(Data * data);
};

#endif