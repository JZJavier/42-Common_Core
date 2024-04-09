/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:42:35 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 00:18:25 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_char(char *str, char obj)
{
	if (!str)
		return (NULL);
	if (obj == '\0')
		return ((char *)&str[str_len (str)]);
	while (*str && *str != obj)
		str ++;
	if (*str == obj)
		return (str);
	return (NULL);
}

char	*ft_call(size_t size)
{
	char	*tem;
	size_t	i;

	i = 0;
	tem = (char *) malloc (sizeof (char) * (size));
	if (!tem)
		return (NULL);
	while (i < sizeof (char) * (size))
	{
		tem[i] = '\0';
		i ++;
	}
	return (tem);
}

size_t	str_len(char *str)
{
	size_t	num;

	num = 0;
	while (str[num])
		num ++;
	return (num);
}

char	*merge(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*tem;

	i = 0;
	j = 0;
	if (!str1)
		str1 = ft_call (1);
	if (!str1 || !str2)
		return (NULL);
	tem = malloc (sizeof (char) * (str_len (str1) + str_len(str2) + 1));
	if (!tem)
		return (NULL);
	while (str1[i])
	{
		tem[i] = str1[i];
		i ++;
	}
	while (str2[j])
		tem[i ++] = str2[j ++];
	tem [i] = 0;
	free (str1);
	return (tem);
}

char	*str_cp(char *str, size_t len)
{
	size_t	i;
	char	*tem;

	if (!str)
		return (NULL);
	if (len > str_len (str))
		len = str_len (str);
	i = 0;
	tem = malloc (sizeof (char) * (len + 1));
	if (!tem)
		return (tem);
	while (str[i] && i < len)
	{
		tem[i] = str[i];
		i ++;
	}
	tem[i] = '\0';
	return (tem);
}
