/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:45:53 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 14:18:15 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ischar(const char c, const char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s ++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *chars_to_trim)
{
	size_t	len;
	char	*result;

	if (!str || !chars_to_trim)
		return (NULL);
	while (ischar (*str, chars_to_trim) == 1)
		str ++;
	len = ft_strlen ((char *)str);
	if (len)
		while (ischar (str[len - 1], chars_to_trim) == 1)
			len --;
	result = (char *) malloc (sizeof (char) * (len + 1));
	if (!result)
		return (0);
	ft_strlcpy (result, (char *)str, len + 1);
	return (result);
}

/*
int main ()
{
	char t1[] = "      ";
	char t2[] = " ";
	char *fin;

	fin = ft_strtrim ("1234543211111", " 12");
	printf ("---%s---\n", fin);
	free (fin);
	return 0;
}
*/