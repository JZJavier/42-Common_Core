/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:59:19 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/19 21:27:26 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "./sed <filename> s1 s2" << std::endl;
		return (1);
	}
	if (!strcmp(argv[2], argv[3]))
	{
		std::cerr << "s1 and s2 are the same" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::ifstream infile(filename.c_str()); //To pass a std::string to const char *
	if (!infile.is_open())
	{
		std::cerr << "Wrong infile" << std::endl;
		return (1);
	}
	std::string	s1 = argv[2];
	std::string s2 = argv[3];

	std::string outfile = filename + ".replace";
	std::ofstream out(outfile.c_str());
	if (!out.is_open()){

		std::cerr << "Error creating the outfile" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline (infile, line))
	{

		if (line.find (s1) == std::string::npos)		//npos is a constant member of the std::string class that represents a value that is not found. 
			out << line << std::endl;
		else
		{
			
			size_t  pos = 0;
			while ((pos = line.find(s1)) != std::string::npos)
			{

				line.erase (pos, s1.length());
				line.insert (pos, s2);
				pos += s2.length ();		//  moves pos past the newly inserted s2
			}
			out << line << std::endl;
		}
	}
	infile.close();
	out.close();
	return (0);
}
