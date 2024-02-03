/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:36:05 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/02 11:51:10 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		n = n * 10;
		n = n + str[i] - '0';
		i++;
	}
	return (n);
}

int checkprime(int number)
{
	int i;

	i = 2;
	if (number <= 1)
		return (0);
	while (i * i <= number)
	{
		if (number % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_nbr(int n)
{
	if (n >= 10)
		put_nbr(n / 10);
	char digit = n % 10 + '0';
	write(1, &digit, 1);
}

int main(int argc, char **argv)
{
	int n;
	int result;

	result = 0;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		while (n > 0)
		{
			if (checkprime(n))
				result += n;
			n--;
		}
		put_nbr(result);
	}
	write(1, "\n", 1);
}
