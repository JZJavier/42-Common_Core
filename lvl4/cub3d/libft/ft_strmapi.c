/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:45:37 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 00:10:29 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*fin;

	i = 0;
	len = ft_strlen ((char *)s);
	fin = (char *) malloc (sizeof (char) * (len + 1));
	if (!fin)
		return (0);
	while (i < len)
	{
		fin[i] = f (i, s[i]);
		i ++;
	}
	fin[i] = '\0';
	return (fin);
}
