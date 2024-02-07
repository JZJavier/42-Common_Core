/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:35:24 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 14:44:56 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i])
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

void print_hex(int n)
{
	char *base;

	base = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	write (1, &base[n % 16], 1);	
}

int main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write (1, "\n", 1);
	return (0);
}
