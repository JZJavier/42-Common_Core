/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:03:43 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 18:44:40 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*fin;

	fin = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			fin = (char *)&str[i];
		i ++;
	}
	if (str[i] == (char)c)
		fin = (char *)&str[i];
	return (fin);
}
