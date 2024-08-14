/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:21:05 by javier            #+#    #+#             */
/*   Updated: 2024/08/14 09:27:04 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


/*int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}*/

#include "MutantStack.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    MutantStack<int> ms1;

    for (int i = 0; i < 10; ++i) {
        ms1.push(std::rand() % 100);
    }

    std::cout << "Initial stack elements:" << std::endl;
    MutantStack<int>::iterator it = ms1.begin();
    MutantStack<int>::iterator ite = ms1.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "Size of stack after pushes: " << ms1.size() << std::endl;

    std::cout << "Popping top element: " << ms1.top() << std::endl;
    ms1.pop();
    std::cout << "Size of stack after pop: " << ms1.size() << std::endl;

    std::cout << "Stack elements after pop:" << std::endl;
    it = ms1.begin();
    ite = ms1.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Copy constructor
    MutantStack<int> ms2(ms1);
    std::cout << "Copied stack (ms2) elements:" << std::endl;
    it = ms2.begin();
    ite = ms2.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Assignment operator
    MutantStack<int> ms3;
    ms3 = ms1;
    std::cout << "Assigned stack (ms3) elements:" << std::endl;
    it = ms3.begin();
    ite = ms3.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    //-Empty stack
    MutantStack<int> emptyStack;
    std::cout << "Empty stack size: " << emptyStack.size() << std::endl;

    std::cout << "Empty stack elements:" << std::endl;
    it = emptyStack.begin();
    ite = emptyStack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}
