/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:52:34 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/14 17:45:33 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		else
			i++;
	}
	if ((char) c == '\0')
		return ((char *) &s[i]);
	return (0);
}

/*#include <stdio.h>
int main (void)
{
	char word [] = "aaaaaabaaaaa";
	int ch = 'b';
	printf("%s", ft_strchr(word, ch));
	return (0);
}*/
