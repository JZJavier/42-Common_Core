/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:58:56 by javgao            #+#    #+#             */
/*   Updated: 2024/04/01 22:29:54 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_redir(t_mini *mini)
{
	if (mini->flag_input == TRUE && (mini->flag_append_output == TRUE
			|| mini->flag_output == TRUE))
		return (single_redir (mini, mini->commands[0], mini->infile
				[arry_count(mini->infile) - 1], mini->outfile
				[arry_count(mini->outfile) - 1]), TRUE);
	if (mini->flag_input == TRUE && (mini->flag_append_output == FALSE
			&& mini->flag_output == FALSE))
		return (single_redir (mini, mini->commands[0], mini->infile
				[arry_count(mini->infile) - 1], OUTFILE), TRUE);
	if (mini->flag_input == FALSE && (mini->flag_append_output == TRUE
			|| mini->flag_output == TRUE))
		return (single_redir (mini, mini->commands[0], INFILE,
				mini->outfile[arry_count(mini->outfile) - 1]), TRUE);
	return (FALSE);
}

int	ft_execute(t_mini *mini)
{
	int		i;
	int		pipe_found;

	i = 0;
	pipe_found = 0;
	if (!mini->commands)
		return (EXIT_SUCCESS);
	while (mini->commands[i])
	{
		if (mini->commands[i][0] == '|')
		{
			mini->argc = arry_count (mini->cmds_and_args);
			mini->argv = check_cmds_and_args(mini);
			pipex_bonus(mini, mini->argc + 3, mini->argv,
				hash_to_arry(mini->hash_env));
			pipe_found = 1;
		}
		i++;
	}
	if (!pipe_found)
		single_command(mini);
	return (EXIT_SUCCESS);
}
