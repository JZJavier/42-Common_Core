/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:06:45 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/21 14:29:56 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

//This here_doc has been addaptedd to only handdle two commands to fit the
//subject requirements, but should be adapted back fo rminishell.
void	here_child(t_pipex *pipex, int pipe_fd[2])
{
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		print_error("dup2 failed on ft_parent STDIN");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		print_error("dup2 failed on ft_parent STDIN");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close_fds(pipex);
	ft_execute(pipex, pipex->argv[4]);
}

void	here_parent(t_pipex *pipex, int pipe_fd[2])
{
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		print_error("dup2 failed on ft_child STDIN");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		print_error("dup2 failed on ft_child STDOUT");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close_fds(pipex);
	unlink ("here_doc");
	ft_execute(pipex, pipex->argv[3]);
}

void	here_pipex(t_pipex *pipex)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		status;

	if (pipe(pipe_fd) == -1)
		print_error("pipe failed on ft_ppipex");
	pid = fork();
	if (pid == -1)
		print_error("fork failed");
	if (pid == 0)
		here_child(pipex, pipe_fd);
	else
	{
		here_parent(pipex, pipe_fd);
		waitpid(pid, &status, 0);
	}
}

void	here_doc(t_pipex *pipex)
{
	char	*line;
	char	*delimiter;

	delimiter = ft_strjoin(pipex->argv[2], "\n");
	while (1)
	{
		write(1, "here_doc >", 10);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || *line == '\0')
			break ;
		if (ft_strcmp(delimiter, line) == 0)
			break ;
		write (pipex->infile, line, ft_strlen(line));
		write (pipex->infile, "\n", 1);
		free (line);
	}
	free(delimiter);
	close (pipex->infile);
	pipex->infile = open("here_doc", O_CREAT | O_RDWR, 0644);
	if (pipex->infile == -1)
		print_error("Open failed to open here_doc");
	here_pipex(pipex);
}
