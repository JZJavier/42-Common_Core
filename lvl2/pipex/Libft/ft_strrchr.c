/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:26:05 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/14 17:50:45 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
		i++;
	j = i;
	while (j >= 0)
	{
		if (s[j] == (char) c)
			return ((char *) &s[j]);
		else
			j--;
	}
	if ((char) c == '\0')
		return ((char *) &s[i]);
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	char word [] = "aaaabaabaa ba baaa";
	int ch = '\0';
	printf("%s", ft_strrchr(word, ch));
	return (0);
}*/
