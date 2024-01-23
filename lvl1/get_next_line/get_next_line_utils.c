/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:09:21 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/23 20:31:52 by jjuarez-         ###   ########.fr       */
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

char	*ft_substr(char *s)
{
	int		i;
	int		j;
	char	*ch;

	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	ch = (char *) malloc (i + 1);
	if (ch == '\0')
		return (0);
	i++;
	while (s[i] != '\0')
	{
		ch[j] = s[i];
		j++;
		i++;
	}
	ch[j] = '\0';
	return (ch);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == (char) c)
			return (1);
		else
			i++;
	}
	return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		write (1, &s[i], 1);
		i++;
	}
	write (1, "\n", 1); //Hacer condición para que no ponga salto de línea si es el final del archivo Y NO ACABA EN '\N'
}

size_t	ft_strlen(const char *len)
{
	int	i;

	i = 0;
	while (len[i] != '\0')
		i++;
	return (i);
}
