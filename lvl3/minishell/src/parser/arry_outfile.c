/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:40:16 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 13:35:57 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	args_no_outfile(char ***args, char **ofile)
{
	int	i;

	i = 0;
	if (!*args || !ofile || !*ofile)
		return ;
	while (ofile[i])
	{
		arry_del (args, arry_get_index (*args, ofile[i]));
		i ++;
	}
}

static void	apoy_args_to_outfile(char ***args, char ***new, int *i)
{
	if (is_strsame (">", (*args)[(*i)]))
	{
		arry_add (new, ">");
		if ((*args)[(*i) + 1])
		{
			arry_add (new, (*args)[(*i) + 1]);
			(*i)++;
		}
	}
	else if (is_strsame (">>", (*args)[(*i)]))
	{
		arry_add (new, ">>");
		if ((*args)[(*i) + 1])
		{
			arry_add (new, (*args)[(*i) + 1]);
			(*i)++;
		}
	}
}

// no olvidas liberar new cuando terminar usandolo
char	**args_to_outfile(char ***args)
{
	char	**new;
	int		i;

	i = 0;
	new = NULL;
	if (!*args || !**args)
		return (new);
	while ((*args)[i])
	{
		apoy_args_to_outfile (args, &new, &i);
		i ++;
	}
	args_no_outfile (args, new);
	return (new);
}

static void	apoy_filter_add_path(t_hash *hash, char ***new, char *str)
{
	char	*tem;
	char	*fin;
	char	*path;

	path = hash_grep (hash, "PWD");
	while (*path != '=')
		path ++;
	path ++;
	tem = ft_strjoin (path, "/");
	fin = ft_strjoin (tem, str);
	free (tem);
	arry_add (new, fin);
	free (fin);
}

char	**filter_add_path(char **args_file, t_hash *hash)
{
	char	**new;
	char	**ori;

	new = NULL;
	if (!args_file)
		return (NULL);
	ori = args_file;
	while (*args_file)
	{
		if (is_strsame (">", *args_file) || is_strsame ("<", *args_file)
			|| is_strsame (">>", *args_file) || is_strsame ("<<", *args_file))
			arry_add (&new, *args_file);
		else
			apoy_filter_add_path (hash, &new, *args_file);
		args_file ++;
	}
	arry_destory (ori);
	return (new);
}
