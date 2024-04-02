/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds_and_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:40:35 by javgao            #+#    #+#             */
/*   Updated: 2024/04/01 22:10:00 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**set_mem(t_mini *mini)
{
	char	**new;

	new = NULL;
	arry_add (&new, "./minishell");
	if (mini->infile == NULL)
		arry_add (&new, "./Libft/ft_printf/.infile");
	else if (mini->flag_here_doc == TRUE)
	{
		arry_add (&new, "here_doc");
		arry_add (&new, mini->infile[arry_count(mini->infile) - 1]);
	}
	else
		arry_add (&new, mini->infile[arry_count(mini->infile) - 1]);
	return (new);
}

char	**check_cmds_and_args(t_mini *mini)
{
	char	**new;
	int		j;

	j = 0;
	new = set_mem (mini);
	if (!new)
		return (NULL);
	while (mini->cmds_and_args[j])
	{
		arry_add (&new, mini->cmds_and_args[j]);
		j ++;
	}
	if (mini->flag_output == FALSE && mini->flag_append_output == FALSE)
		arry_add (&new, "./Libft/ft_printf/.outfile");
	else
		arry_add (&new, mini->outfile[arry_count(mini->outfile) - 1]);
	return (new);
}
