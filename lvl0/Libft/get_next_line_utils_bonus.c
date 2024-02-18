/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:13:39 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/18 17:39:33 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin2(char *ch, char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		ch[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		ch[i + j] = s2 [j];
		j++;
	}
	ch[i + j] = '\0';
	return (ch);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ch;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
	{
		return (NULL);
	}
	ch = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ch == NULL)
		return (NULL);
	ch = ft_strjoin2(ch, s1, s2);
	free (s1);
	return (ch);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
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

size_t	ft_strlen(const char *len)
{
	int	i;

	i = 0;
	while (len[i] != '\0')
		i++;
	return (i);
}
