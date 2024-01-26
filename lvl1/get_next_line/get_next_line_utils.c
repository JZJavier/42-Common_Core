/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:09:21 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/26 07:11:37 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ch;
	int		i;
	int		j;
	int		count;

	i = ft_strlen ((char *) s1);
	j = ft_strlen ((char *) s2);
	count = 0;
	ch = (char *) malloc (i + j + 1);
	if (ch == NULL)
		return (NULL);
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


char *ft_substr(char *s)
{
	int		start;
	int		len;
	int		i;
	char	*str;

	i = 0;
	start = 0;
	len = ft_strlen(s);
	while (s[start] != '\n')
	   start++;
	start = start + 1;
	str	= (char *) malloc (len - start + 1);
	if (s == NULL)
		return (NULL);
	while (start < len) //Hay que añadir otra condición como hasta que no encuentre otro '\n'????
	{
		str[i++] = s [start++];
	}
	str[i] = '\0';
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		else
			i++;
	}
	return (0);
}

size_t	ft_strlen(const char *len)
{
	int	i;

	i = 0;
	while (len[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
int main (void)
{
	printf("%s", ft_substr("sdfgd\nfghjkh\newrtyuu\nretrhnhgr\n"));
	return (0);
}*/
