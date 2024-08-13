/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:24:01 by javier            #+#    #+#             */
/*   Updated: 2024/08/13 12:16:22 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() : _data("")
{
}

Serializer::Serializer(Serializer const & src)
{
	*this = src;
}

Serializer::~Serializer()
{
}

Serializer & Serializer::operator=(Serializer const & rhs)
{
	if (this != &rhs)
	{
		this->_data = rhs._data;
	}
	return *this;
}

std::string Serializer::getData() const
{
	return this->_data;
}

void Serializer::setData(std::string data)
{
	this->_data = data;
}

Data* Serializer::deserialize() {
    Data* data = new Data;
    std::string s1;
    std::string s2;
    int n;

    std::string::size_type pos = this->_data.find("s1:");
    if (pos == std::string::npos) {
        delete data;
        return NULL;
    }
    pos += 3;
    
    std::string::size_type endPos = this->_data.find("n:", pos);
    if (endPos == std::string::npos) {
        delete data;
        return NULL;
    }
    s1 = this->_data.substr(pos, endPos - pos);

    pos = endPos + 2;
    endPos = this->_data.find("s2:", pos);
    if (endPos == std::string::npos) {
        delete data;
        return NULL;
    }
    std::stringstream ss(this->_data.substr(pos, endPos - pos));
    ss >> n;

    pos = endPos + 3;
    s2 = this->_data.substr(pos);

    data->s1 = s1;
    data->n = n;
    data->s2 = s2;
    return data;
}

std::string Serializer::serialize(Data* data) {
    std::string s1 = data->s1;
    std::string s2 = data->s2;
    int n = data->n;
    std::ostringstream oss;
    oss << n;
    std::string serialized = "s1:" + s1 + "n:" + oss.str() + "s2:" + s2;
    return serialized;
}
