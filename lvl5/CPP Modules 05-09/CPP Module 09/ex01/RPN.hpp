/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:58:25 by javier            #+#    #+#             */
/*   Updated: 2024/08/14 13:10:26 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>
#include <string>
#include <cmath>

class RPN
{
    private:
        std::string _input;
        bool _error;
        bool _exit;
        std::stack<double> _stack;
        void parseInput();
        void doOperation(char op);
        void pushNumber(double num);
        void printStack();
    public:
        RPN();
        RPN(const std::string& input); // Constructor to initialize with input
        ~RPN();
        void run();
};

#endif
