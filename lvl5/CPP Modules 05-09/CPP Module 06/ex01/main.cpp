/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:25:16 by javier            #+#    #+#             */
/*   Updated: 2024/08/13 12:15:49 by javier           ###   ########.fr       */
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

    s.setData(serialized);

    Data *deserializedData = s.deserialize();
    if (deserializedData)
    {
        std::cout << "Deserialized:" << std::endl;
        std::cout << "s1: " << deserializedData->s1 << std::endl;
        std::cout << "n: " << deserializedData->n << std::endl;
        std::cout << "s2: " << deserializedData->s2 << std::endl;
    }
    else
    {
        std::cout << "Deserialization failed" << std::endl;
    }

    delete data;
    delete deserializedData;

    return 0;
}