/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:27:04 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/14 19:16:59 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ch;

	i = 0;
	ch = (char *) malloc (count * size);
	if (!ch)
		return (0);
	while (i < count * size)
	{
		ch[i] = 0;
		i++;
	}
	return (ch);
}

/*#include <stdio.h>
int main(void)
{
	size_t c = 200;
	size_t s = 1;
	printf("%s", ft_calloc(c, s));
	return (0);	
}*/
