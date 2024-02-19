/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:38:46 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/15 09:19:30 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*ch;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ch = (char *) malloc ((len + 1));
	if (ch == '\0')
		return (0);
	while (j < len)
	{
		ch[i] = s[start + i];
		i++;
		j++;
	}
	ch[i] = '\0';
	return (ch);
}

/*#include <stdio.h>
int main(void)
{
	char const str [] = "Pablito tiene un Palitoooooo";
	unsigned int s = 17;
	unsigned int l = 6;
	printf("%s", ft_substr("", 1, 1));
	return (0);
}*/
