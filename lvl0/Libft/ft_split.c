/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:56:30 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/12 18:03:10 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	countword(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str != c && *str)
	{
		str++;
		len++;
	}
	return (len);
}

static size_t	countdel(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	if (i > 0 && str[i - 1] == c)
		count--;
	return (count);
}

static char	**ffree(char **str, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**createarr(char **arr, const char *s, char c)
{
	size_t	j;
	size_t	k;

	j = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			continue ;
		arr[j] = malloc(sizeof(char) * countword(s, c) + 1);
		if (arr[j] == NULL)
			return (ffree(arr, j));
		k = 0;
		while (*s != c && *s != '\0')
		{
			arr[j][k] = *s;
			k++;
			s++;
		}
		arr[j][k] = '\0';
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = malloc(sizeof(char *) * (countdel(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	arr = createarr(arr, s, c);
	return (arr);
}

/*#include <stdio.h>
int main(void)
{
    const char *input_string = "paco\0pacoo\0pacooo\0pacoooo\0";
    char delimiter = '\0';
    char **arr = ft_split(input_string, delimiter);
    for (int i = 0; arr[i] != NULL; ++i)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}*/
