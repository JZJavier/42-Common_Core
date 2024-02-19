/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:38:51 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/10 18:20:17 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ch;
	int		i;
	int		j;
	int		count;

	i = ft_strlen ((char *) s1);
	j = ft_strlen ((char *) s2);
	count = 0;
	ch = (char *) malloc (i + j + 1);
	if (ch == '\0')
		return (0);
	while (count < i)
	{
		ch[count] = s1[count];
		count++;
	}
	count = 0;
	while (count < j)
	{
		ch[i + count] = s2 [count];
		count++;
	}
	ch[i + count] = '\0';
	return (ch);
}

/*#include <stdio.h>
int main(void)
{
	char s1 [] = "Pablito";
	char s2 [] = " tiene un Clavito";
	printf("%s", ft_strjoin(s1, s2));
	return(0);
}*/
