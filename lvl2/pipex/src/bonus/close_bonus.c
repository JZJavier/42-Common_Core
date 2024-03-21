/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:29:26 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/21 05:21:45 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	close_fds(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
}

void	close_pipes_fd(t_pipex *pipex, int **pipe_fd)
{
	int	i;

	i = 0;
	while (i < (pipex->pipes_num - 2))
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		free(pipe_fd[i]);
		i++;
	}
	free(pipe_fd);
}

void	waitpids(t_pipex *pipex, int *status)
{
	int	i;

	i = 0;
	while (i < pipex->pipes_num - 1)
	{
		waitpid(-1, status, 0);
		i++;
	}
}
