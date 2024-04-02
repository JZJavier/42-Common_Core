/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_all_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:37:17 by javgao            #+#    #+#             */
/*   Updated: 2024/03/13 07:59:11 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	open_all_files(t_mini *mini)
{
	int	i;
	int	fd;

	i = 0;
	if (mini->flag_append_output == FALSE && mini->flag_output == FALSE)
		return ;
	while (mini->outfile[i])
	{
		if (ft_strcmp(mini->outfile[i], ">") == 0
			|| ft_strcmp(mini->outfile[i], ">>") == 0)
			i++;
		else
		{
			fd = open(mini->outfile[i], O_CREAT | O_WRONLY, 0777);
			close(fd);
			i++;
		}
	}
}
