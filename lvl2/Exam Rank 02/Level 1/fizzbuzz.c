/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <fizzbuzz@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:27:05 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/02 12:37:58 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_number(int number)
{
	char	str[10] = "0123456789";

	if (number > 9)
		put_number(number / 10);
	write (1, &str[number % 10], 1);
}

int main(void)
{
	int i;

	i = 0;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5  == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			put_number(i);
		i++;
		write (1, "\n", 1);
	}
	return (0);
}
