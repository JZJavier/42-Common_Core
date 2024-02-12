/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:56:06 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/12 07:30:41 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file1\n", 2);
	exit(0);
}

int	ft_open(char *file, int status)
{
	int	ret;

	if (status == 0)
		ret = open(file, O_RDONLY, 0777);
	if (status == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (status == 2)
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (ret == -1)
		exit(0);
	return (ret);
}

void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*ft_envp(char *variable, char **envp)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (ft_strcmp(sub, variable) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

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
