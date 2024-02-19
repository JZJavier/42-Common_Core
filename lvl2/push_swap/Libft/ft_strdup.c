/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:28:07 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/10 18:18:14 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*a;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	a = (char *) malloc (i + 1);
	if (a == '\0')
		return (0);
	while (j < i)
	{
		a[j] = s1[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}

/*#include <stdio.h>
int main(void)
{
	const char ch[] = "illooooo";
	printf("%s", ft_strdup(ch));
	return (0);
}*/
