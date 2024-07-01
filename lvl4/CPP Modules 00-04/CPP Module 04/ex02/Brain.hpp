/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 11:00:01 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
#include <iostream>

class Brain
{
	private:
		std::string		ideas[100];
	public:
						Brain(void);
						Brain(const Brain &obj);
						~Brain(void);
		Brain&			operator=(const Brain &obj);
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};
#endif
