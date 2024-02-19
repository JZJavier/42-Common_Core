/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:08:11 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/15 07:39:44 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trimmed;

	i = 0;
	start = 0;
	end = ft_strlen((char *) s1);
	while (s1[start] && checkset (s1[start], set))
		start++;
	while (start < end && checkset(s1 [end - 1], set))
		end--;
	trimmed = (char *) malloc (end - start + 1);
	if (trimmed == '\0')
		return (0);
	while (i + start < end)
	{
		trimmed [i] = s1 [start + i];
		i++;
	}
	trimmed [i] = '\0';
	return (trimmed);
}

/*#include <stdio.h>
int main(void)
{
	char s1 [] = " ., Pablito tiene un Palito ,.";
	char set [] = " a.,";
	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/
