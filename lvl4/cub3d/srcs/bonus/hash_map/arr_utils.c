/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:44:01 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/10 18:10:59 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	is_strsame(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (FALSE);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (FALSE);
		s1 ++;
		s2 ++;
	}
	return (*s1 == *s2);
}

void	arry_init(char **ary, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ary[i] = NULL;
		i ++;
	}
}

int	arry_count(char **arys)
{
	int	i;

	i = 0;
	if (!arys || !*arys)
		return (0);
	while (arys[i])
		i ++;
	return (i);
}

char	**arry_cpy(char **ary)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc (sizeof (char *) * (arry_count (ary) + 2));
	if (!new)
		return (NULL);
	arry_init (new, (arry_count (ary) + 2));
	while (i < arry_count (ary))
	{
		new[i] = ft_strdup (ary[i]);
		i ++;
	}
	arry_destroy (ary);
	return (new);
}

int	arry_add(char ***arys, char *val)
{
	int	i;

	i = 0;
	if (!*arys)
	{
		*arys = malloc (sizeof (char *) * 2);
		if (!*arys)
			return (FALSE);
		(*arys)[0] = ft_strdup (val);
		(*arys)[1] = NULL;
		return (TRUE);
	}
	*arys = arry_cpy (*arys);
	while ((*arys)[i])
		i ++;
	(*arys)[i] = ft_strdup (val);
	return (TRUE);
}
