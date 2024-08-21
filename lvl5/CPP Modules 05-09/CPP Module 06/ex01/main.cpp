/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 06:25:16 by javier            #+#    #+#             */
/*   Updated: 2024/08/21 17:22:21 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data originalData;
    originalData.num = 7;
    originalData.str = "illo";

    uintptr_t raw = Serialization::serialize(&originalData);
    std::cout << "Serialized Data: " << raw << std::endl;

    Data* deserializedData = Serialization::deserialize(raw);

    std::cout << "Deserialized Data num: " << deserializedData->num << std::endl;
    std::cout << "Deserialized Data str: " << deserializedData->str << std::endl;

    if (deserializedData == &originalData) {
        std::cout << "Deserialization was successful: pointers match." << std::endl;
    } else {
        std::cout << "Deserialization failed: pointers do not match." << std::endl;
    }

    return 0;
}
