/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:32:40 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/09 05:58:02 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char *cmd, char **envp)
{
	int		i;
	char	*exec;
	char	**paths;
	char	*path;
	char	**cmds;

	i = -1;
	paths = ft_split(ft_envp("PATH", envp), ':');
	cmds = ft_split(cmd, ' ');
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(path, cmds[0]);
		free(path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free(cmds);
			return (exec);
		}
		free(exec);
	}
	ft_free(paths);
	ft_free(cmds);
	return (cmd);
}

void	ft_exec(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd, ' ');
	path = ft_path(cmds[0], envp);
	if (execve(path, cmds, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmds[0], 2);
		ft_free(cmds);
		exit(0);
	}
}

void	child(char **argv, int *fdd, char **envp)
{
	int		fd;

	fd = ft_open(argv[1], 0);
	dup2(fd, 0);
	dup2(fdd[1], 1);
	close(fdd[0]);
	ft_exec(argv[2], envp);
}

void	parent(char **argv, int *fdd, char **envp)
{
	int		fd;

	fd = ft_open(argv[4], 1);
	dup2(fd, 1);
	dup2(fdd[0], 0);
	close(fdd[1]);
	ft_exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(0);
	}
	if (pipe(fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(argv, fd, envp);
	parent(argv, fd, envp);
}
