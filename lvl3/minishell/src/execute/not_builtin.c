/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:24:12 by javgao            #+#    #+#             */
/*   Updated: 2024/03/25 18:20:40 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_args(char *command, char **arguments)
{
	int		i;
	int		size;
	char	*full;
	char	*temp;

	i = 0;
	size = 0;
	while (arguments[size])
		size++;
	full = ft_strdup(command);
	while (i < size)
	{
		temp = ft_strjoin(full, " ");
		free(full);
		full = temp;
		temp = ft_strjoin(full, arguments[i]);
		free(full);
		full = temp;
		i++;
	}
	return (full);
}

static int	num_args(char **arguments)
{
	int	i;

	i = 0;
	if (*arguments && ft_strcmp(arguments[0], "哈") == 0)
		return (0);
	while (arguments[i])
		i++;
	return (i);
}

void	not_builtin(char *command, char **arguments, t_mini *mini, int flag)
{
	char	*full;
	int		num_arg;

	num_arg = num_args(arguments);
	if (num_arg >= 1)
	{
		full = join_args(command, arguments);
		ft_exec_single(full, mini->arry_hash);
		free (full);
	}
	else
		ft_exec_single(command, mini->arry_hash);
	(void)flag;
}
