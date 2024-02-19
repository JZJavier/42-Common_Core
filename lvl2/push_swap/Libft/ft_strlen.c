/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:05:37 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/13 13:56:03 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *len)
{
	int	i;

	i = 0;
	while (len[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
int main(void)
{
	char len[] = "Pedrito";
	printf ("%d",ft_strlen(len));
	return (0);
}*/
