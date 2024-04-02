/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:24:12 by javgao            #+#    #+#             */
/*   Updated: 2024/04/02 00:01:35 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	paths = ft_split(ft_envp("PATH", envp), ":");
	cmds = ft_split(cmd, " ");
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(path, cmds[0]);
		free(path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			arry_destory(cmds);
			arry_destory(paths);
			return (exec);
		}
		free(exec);
	}
	arry_destory(paths);
	arry_destory(cmds);
	return (ft_strdup(cmd));
}

void	ft_exec_single(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;
	int		status;
	pid_t	pid;

	cmds = ft_split(cmd, " ");
	path = ft_path(cmds[0], envp);
	pid = fork();
	if (pid == 0)
	{
		init_sig_child ();
		if (execve(path, cmds, envp) == -1)
		{
			print_error("mini: command not foun");
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		arry_destory (cmds);
		free (path);
		if (WIFEXITED (status))
			g_sig = WEXITSTATUS(status);
	}
}

int	single_command(t_mini *mini)
{
	if (is_builtin(mini->commands[0], mini) == TRUE)
	{
		if (mini->flag_append_output == TRUE || mini->flag_output == TRUE)
			exec_builtin(mini->commands[0], mini->args[0], mini);
		else
			exec_builtin_without(mini->commands[0], mini->args[0], mini);
	}
	else if (check_redir(mini) == TRUE)
		return (EXIT_SUCCESS);
	else
	{
		if (mini->flag_unset_path == TRUE)
			return (print_error("No such file or directory"));
		else if (mini->flag_here_doc == TRUE)
			open_single_here_doc(mini);
		else
			not_builtin(mini->commands[0], mini->args[0], mini, SINGLE);
	}
	return (TRUE);
}
