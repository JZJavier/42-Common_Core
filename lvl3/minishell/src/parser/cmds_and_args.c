/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_and_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:17:11 by javgao            #+#    #+#             */
/*   Updated: 2024/04/01 22:04:38 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*merge_cmd_args(char *first, char *second)
{
	char	*tem;
	char	*new;

	tem = ft_strjoin (first, " ");
	new = ft_strjoin (tem, second);
	free (tem);
	return (new);
}

static void	t_set_zero(char ***new, int *i, char **tem)
{
	*new = NULL;
	*i = 0;
	*tem = NULL;
}

static void	t_second_if(char **tem, char *str, char ***new, int *i)
{
	if (*tem)
	{
		arry_add (new, *tem);
	}
	else
		arry_add (new, str);
	if (*tem)
		free (*tem);
	*tem = NULL;
	(*i)++;
}

static void	t_first_if(char **tem, char **args, int i)
{
	char	*basura;

	if (!*tem)
		*tem = merge_cmd_args (args[i], args[i + 1]);
	else
	{
		basura = *tem;
		*tem = merge_cmd_args (*tem, args[i + 1]);
		free (basura);
		basura = NULL;
	}
}

char	**args_to_cmds_args(char **args)
{
	char	**new;
	int		i;
	char	*tem;

	t_set_zero (&new, &i, &tem);
	if (!args)
		return (NULL);
	while (args[i])
	{
		if (args[i] && args[i + 1] && !is_strsame (args[i + 1], "|"))
		{
			t_first_if (&tem, args, i);
		}
		else if (args[i] && (is_strsame (args[i + 1], "|") || !args[i + 1]))
		{
			t_second_if (&tem, args[i], &new, &i);
			if (!args[i])
				break ;
		}
		i ++;
	}
	return (new);
}
