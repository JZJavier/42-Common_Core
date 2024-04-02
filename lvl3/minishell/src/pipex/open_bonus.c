/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:34:33 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/01 22:29:27 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	open_files_pipex(t_pipex *pipex, t_mini *mini, char **argv)
{
	if (pipex->flag_here_doc == TRUE)
	{
		pipex->infile = open("here_doc", O_CREAT | O_RDWR, 0644);
		if (pipex->infile == -1)
			print_error("Open failed to open here_doc");
		pipex->outfile = open(argv[pipex->argc - 1], O_CREAT | O_APPEND
				| O_WRONLY, 0644);
		if (pipex->outfile == -1)
			print_error("Open failed to open outfile");
	}
	else if (pipex->flag_here_doc == FALSE)
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
			print_error("Open failed to open infile");
		if (mini->flag_append_output == FALSE)
			pipex->outfile = open(argv[pipex->argc - 1], O_CREAT | O_TRUNC
					| O_WRONLY, 0644);
		else
			pipex->outfile = open(argv[pipex->argc - 1], O_CREAT | O_APPEND
					| O_WRONLY, 0644);
		if (pipex->outfile == -1)
			print_error("Open failed to open outfile");
	}
}
