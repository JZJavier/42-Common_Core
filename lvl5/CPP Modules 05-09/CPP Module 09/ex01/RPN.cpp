/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:59:26 by javier            #+#    #+#             */
/*   Updated: 2024/08/14 13:16:53 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

RPN::RPN() : _input(""), _error(false), _exit(false) 
{
}

RPN::RPN(const std::string& input) : _input(input), _error(false), _exit(false)
{
}

RPN::~RPN()
{
}

void RPN::run()
{
    if (_input.empty()) 
    {
        std::cout << "Error" << std::endl;
        return;
    }
    parseInput();
    printStack();
}

void RPN::parseInput()
{
    std::istringstream iss(_input);
    std::string token;
    while (std::getline(iss, token, ' '))
    {
        if (token.length() == 1 && !std::isdigit(token[0]))
            doOperation(token[0]);
        else
        {
            std::istringstream tokenStream(token);
            double num;
            if (!(tokenStream >> num))
            {
                std::cout << "Error" << std::endl;
                _error = true;
                return;
            }
            pushNumber(num);
        }
    }
}

void RPN::doOperation(char op)
{
    if (_stack.size() < 2)
    {
        std::cout << "Error" << std::endl;
        _error = true;
        return;
    }
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    switch (op)
    {
    case '+':
        _stack.push(b + a);
        break;
    case '-':
        _stack.push(b - a);
        break;
    case '*':
        _stack.push(b * a);
        break;
    case '/':
        if (a == 0)
        {
            std::cout << "Error" << std::endl;
            _error = true;
            return;
        }
        _stack.push(b / a);
        break;
    case '%':
        if (a == 0)
        {
            std::cout << "Error" << std::endl;
            _error = true;
            return;
        }
        _stack.push(std::fmod(b, a));
        break;
    default:
        std::cout << "Error" << std::endl;
        _error = true;
        break;
    }
}

void RPN::pushNumber(double num)
{
    _stack.push(num);
}

void RPN::printStack()
{
    if (_error)
    {
        _error = false;
        return;
    }
    if (_stack.size() == 1)
    {
        std::cout << _stack.top() << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}
