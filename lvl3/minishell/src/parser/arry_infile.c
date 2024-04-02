/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:07:51 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 02:12:59 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	args_no_infile(char ***args, char **infile)
{
	int	i;

	i = 0;
	if (!*args || !infile || !*infile)
		return ;
	while (infile[i])
	{
		arry_del (args, arry_get_index (*args, infile[i]));
		i ++;
	}
}

static void	apoy_args_to_infile(char ***args, char ***new, int *i)
{
	if (is_strsame ("<", (*args)[(*i)]))
	{
		arry_add (new, "<");
		if ((*args)[(*i) + 1])
		{
			arry_add (new, (*args)[(*i) + 1]);
			(*i)++;
		}
	}
	else if (is_strsame ("<<", (*args)[(*i)]))
	{
		arry_add (new, "<<");
		if ((*args)[(*i) + 1])
		{
			arry_add (new, (*args)[(*i) + 1]);
			(*i)++;
		}
	}
}

// no olvidas liberar new cuando terminar usandolo
char	**args_to_infile(char ***args)
{
	char	**new;
	int		i;

	i = 0;
	new = NULL;
	if (!*args || !**args)
		return (new);
	while ((*args)[i])
	{
		apoy_args_to_infile (args, &new, &i);
		i ++;
	}
	args_no_infile (args, new);
	return (new);
}

static char	**apoy_filter_args_infile(char **infile, int len)
{
	if (is_strsame (infile[len - 2], infile[len - 4]))
	{
		while (arry_count (infile) != 2)
			arry_del (&infile, 0);
		return (infile);
	}
	else
	{
		while (arry_count (infile) != 4)
			arry_del (&infile, 0);
		return (infile);
	}
}

char	**filter_args_infile(char **infile)
{
	int	len;

	if (!infile)
		return (NULL);
	len = arry_count (infile);
	if (is_strsame (infile [len - 1], "<<"))
	{
		while (arry_count (infile) != 1)
			arry_del (&infile, 0);
		return (infile);
	}
	if (len >= 4)
		return (apoy_filter_args_infile(infile, len));
	return (infile);
}
