/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:24:01 by javier            #+#    #+#             */
/*   Updated: 2024/08/21 17:19:46 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serialization::Serialization(){}
Serialization::~Serialization(){}
Serialization::Serialization(const Serialization&){}
Serialization& 	Serialization::operator=(const Serialization&){
    return *this;
}
uintptr_t	Serialization::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}
Data*	Serialization::deserialize(uintptr_t raw){

	return reinterpret_cast<Data*>(raw);
}