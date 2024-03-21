/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:33:00 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/21 01:07:46 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*check_access(char **paths, char *command)
{
	int		i;
	char	*temp;
	char	*absolute_path;
	char	*command_without_falgs;

	i = 0;
	command_without_falgs = ft_substr(command, 0, ft_strchrlen(command, ' '));
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		absolute_path = ft_strjoin(temp, command_without_falgs);
		free(temp);
		if (access(absolute_path, F_OK | X_OK) == 0)
		{
			free(command_without_falgs);
			return (absolute_path);
		}
		i++;
	}
	free(command_without_falgs);
	return (NULL);
}

void	ft_execute(t_pipex *pipex, char *command)
{
	char	*absolute_command;
	char	**cmds;

	absolute_command = check_access(pipex->paths, command);
	if (absolute_command == NULL)
		print_error("wrong command");
	cmds = ft_split(command, " ");
	if (execve(absolute_command, cmds, hash_to_arry(pipex->hash_env)) == -1)
	{
		free(absolute_command);
		ft_free_arr(cmds);
		print_error("excve failed");
		exit(2);
	}
	ft_free_arr(cmds);
}

void	ft_child(t_pipex *pipex, int pipe_fd[2])
{
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		print_error("dup2 failed on ft_parent STDIN");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		print_error("dup2 failed on ft_parent STDIN");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close_fds(pipex);
	ft_execute(pipex, pipex->argv[3]);
}

void	ft_parent(t_pipex *pipex, int pipe_fd[2])
{
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		print_error("dup2 failed on ft_child STDIN");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		print_error("dup2 failed on ft_child STDOUT");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close_fds(pipex);
	ft_execute(pipex, pipex->argv[2]);
}

void	ft_pipex(t_pipex *pipex)
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
		ft_child(pipex, pipe_fd);
	else
	{
		ft_parent(pipex, pipe_fd);
		waitpid(pid, &status, 0);
	}
}
