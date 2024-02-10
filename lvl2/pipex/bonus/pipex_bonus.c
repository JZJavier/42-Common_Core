/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:46 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/09 12:40:49 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	here_doc_in(char **argv, int *fd)
{
	char	*ret;

	close(fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(ret);
			exit(0);
		}
		ft_putstr_fd(ret, fd[1]);
		free(ret);
	}
}

void	here_doc(char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		here_doc_in(argv, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

void	ft_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_exec(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (argc < 5)
		ft_exit(1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			ft_exit(1);
		i = 3;
		fd_out = ft_open(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		fd_in = ft_open(argv[1], 0);
		fd_out = ft_open(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		ft_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	ft_exec(argv[argc - 2], envp);
}
