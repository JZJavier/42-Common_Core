/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:23:38 by javier            #+#    #+#             */
/*   Updated: 2024/08/13 13:30:21 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    try {
        Array<int> intArray(5);
        
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
        }
        
        std::cout << "Array:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test out of range access
        try {
            std::cout << "Accessing out of range index:" << std::endl;
            intArray[10] = 100; // This should throw an exception
        } catch (const std::out_of_range &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        
        // Lo mismo con Copy constructor
        Array<int> copiedArray(intArray);
        
        std::cout << "Lo mismo con Copy constructor:" << std::endl;
        for (unsigned int i = 0; i < copiedArray.size(); ++i) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Lo mismo con Assignment operator
        Array<int> assignedArray = intArray;
        
        std::cout << "Lo mismo con Assignment operator:" << std::endl;
        for (unsigned int i = 0; i < assignedArray.size(); ++i) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        try {
            std::cout << "Accessing out of range index on Assigned Array:" << std::endl;
            assignedArray[10] = 100; // This should throw an exception
        } catch (const std::out_of_range &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
