/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:23:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 14:33:50 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int hcd;

	if (argc == 3)
	{
		if (atoi(argv[1]) > atoi(argv[2]))
			hcd = atoi(argv[1]);
		else
			hcd = atoi(argv[2]);
		while (hcd > 1)
		{
			if (atoi(argv[1]) % hcd == 0 && atoi(argv[2]) % hcd == 0)
			{
				printf("%d", hcd);
				break ;
			}
			hcd--;
			if (hcd == 1)
				printf("1");	
		}
	}
	printf("\n");
	return (0);
}
