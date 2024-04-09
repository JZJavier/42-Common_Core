/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:57:23 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 12:04:24 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen ((char *)str);
	new = (char *) malloc (sizeof (char) * (len + 1));
	if (!new)
		return (0);
	while (i < len)
	{
		new[i] = str[i];
		i ++;
	}
	new[i] = '\0';
	return (new);
}
