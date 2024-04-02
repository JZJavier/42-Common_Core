/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_argss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:34:09 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 02:12:25 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	h_args(int *has_args, int *i, char ***cur_args, char *cont)
{
	arry_add (cur_args, cont);
	*has_args = 1;
	(*i)++;
}

static void	h_put_zero(char ****cmds, int *cmds_count
	, char ***current_args, int *i)
{
	*cmds = NULL;
	*cmds_count = 0;
	*current_args = NULL;
	*i = 0;
}

static void	new_space(char ****cmds, int cmds_count)
{
	char	***new_cmds;
	int		i;

	i = 0;
	new_cmds = malloc(sizeof(char **) * (cmds_count + 1));
	if (new_cmds == NULL)
		return ;
	while (i <= cmds_count)
	{
		new_cmds[i] = NULL;
		i ++;
	}
	i = 0;
	while (i < cmds_count - 1)
	{
		new_cmds[i] = (*cmds)[i];
		i ++;
	}
	free (*cmds);
	*cmds = new_cmds;
}

static void	h_fill_zero(char ***cmd, char ***current_args)
{
	*cmd = NULL;
	*current_args = NULL;
}

char	***args_to_args(char **args)
{
	char	***cmds;
	int		cmds_count;
	char	**current_args;
	int		i;
	int		has_args;

	if (!args || !*args || !**args)
		return (NULL);
	h_put_zero (&cmds, &cmds_count, &current_args, &i);
	while (args[i] != NULL)
	{
		i++;
		has_args = 0;
		while (args[i] != NULL && !is_strsame(args[i], "|"))
			h_args (&has_args, &i, &current_args, args[i]);
		if (!has_args)
			arry_add(&current_args, "哈");
		cmds_count ++;
		new_space (&cmds, cmds_count);
		cmds[cmds_count - 1] = current_args;
		h_fill_zero (&cmds[cmds_count], &current_args);
		if (args[i] != NULL)
			i ++;
	}
	return (cmds);
}
