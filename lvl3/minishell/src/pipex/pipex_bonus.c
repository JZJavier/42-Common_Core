/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:33:00 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/01 23:57:15 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		if (access(absolute_path, F_OK) == 0)
		{
			free(command_without_falgs);
			return (absolute_path);
		}
		i++;
	}
	free(command_without_falgs);
	return (NULL);
}

void	ft_execute_pipex(t_pipex *pipex, char *command)
{
	char	*absolute_command;
	char	**cmds;

	absolute_command = ft_path(command, pipex->envp);
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

void	ft_child(t_pipex *pipex, int command_index, int **pipe_fd)
{
	if (command_index == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipe_fd[0][1], STDOUT_FILENO);
	}
	else if (command_index == pipex->pipes_num - 2)
	{
		dup2(pipe_fd[command_index - 1][0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(pipe_fd[command_index - 1][0], STDIN_FILENO);
		dup2(pipe_fd[command_index][1], STDOUT_FILENO);
	}
}

void	multiple_pipes(t_pipex *pipex, int ***pipe_fd)
{
	int	i;

	i = 0;
	*pipe_fd = malloc((pipex->pipes_num - 1) * sizeof(int *));
	if (*pipe_fd == NULL)
		print_error("malloc failed on multpile pipes");
	while (i < (pipex->pipes_num - 2))
	{
		(*pipe_fd)[i] = malloc (2 * sizeof(int));
		if ((*pipe_fd)[i] == NULL)
			print_error("malloc failed on multiple pipes");
		if (pipe((*pipe_fd)[i]) == -1)
			print_error ("pipe failed on ft_pipex");
		i++;
	}
}

void	ft_pipex(t_pipex *pipex)
{
	int		**pipe_fd;
	pid_t	pid;
	int		status;
	int		command_index;

	multiple_pipes(pipex, &pipe_fd);
	command_index = 0;
	while (command_index < pipex->pipes_num - 1)
	{
		pid = fork();
		if (pid == -1)
			print_error("fork failed");
		if (pid == 0)
		{
			ft_child(pipex, command_index, pipe_fd);
			close_pipes_fd(pipex, pipe_fd);
			ft_execute_pipex(pipex, pipex->argv[command_index + 2]);
		}
		command_index++;
	}
	close_pipes_fd(pipex, pipe_fd);
	free(pipe_fd);
	close_fds(pipex);
	waitpids(pipex, &status);
}
