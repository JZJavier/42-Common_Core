/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:10:50 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/02 14:30:52 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{	
			if ((argv[1][i] == ' ' || argv[1][i] == '\t') && flag == 1)
			{
				i++;
				flag = 0;
			}
			else if ((argv[1][i] == ' ' && argv[1][i + 1] == ' ') || 
					(argv[1][i] == '\t' && argv[1][i + 1] == '\t' ))
				i++;
			else
			{
				write (1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
