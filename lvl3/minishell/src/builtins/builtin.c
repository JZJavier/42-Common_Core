/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:52 by javgao            #+#    #+#             */
/*   Updated: 2024/04/02 00:01:14 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *command, t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->is_builtin[i] != NULL)
	{
		if (ft_strcmp (command, mini->is_builtin[i]) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	exec_builtin_with_redirection(char *command, char **arguments,
			t_mini *mini, int pipefd[2])
{
	if (ft_strcmp(arguments[0], "哈") == 0 || ft_strcmp(arguments[0], "\b") == 0)
	{
		free(arguments[0]);
		arguments[0] = ft_strdup(" ");
	}
	if (ft_strcmp("echo", ft_lower(command)) == 0)
		ft_echo(mini, arguments, FALSE);
	else if (ft_strcmp("echo -n", ft_lower(command)) == 0)
		ft_echo(mini, arguments, TRUE);
	else if (ft_strcmp("cd", ft_lower(command)) == 0)
		ft_cd(mini, arguments[0]);
	else if (ft_strcmp("pwd", ft_lower(command)) == 0)
		ft_pwd(mini);
	else if (ft_strcmp("export", ft_lower(command)) == 0)
		ft_export(mini, mini->args[0][0]);
	else if (ft_strcmp("unset", ft_lower(command)) == 0)
		ft_unset(mini, mini->args[0][0]);
	else if (ft_strcmp("env", ft_lower(command)) == 0)
		ft_env(mini);
	close(pipefd[1]);
	close(pipefd[2]);
}

int	redir_builtin(t_mini *mini)
{
	int	fd_out;

	if (mini->flag_output == TRUE)
	{
		fd_out = open(mini->outfile[arry_count(mini->outfile) - 1], O_RDWR
				| O_TRUNC | O_CREAT);
		if (fd_out == -1)
			return (print_error("Open failed on redir_builtin"));
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	if (mini->flag_append_output == TRUE)
	{
		fd_out = open(mini->outfile[arry_count(mini->outfile) - 1], O_RDWR
				| O_APPEND | O_CREAT);
		if (fd_out == -1)
			return (print_error("Open failed on redir_builtin"));
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	return (0);
}

void	exec_builtin_without(char *command, char **arguments, t_mini *mini)
{
	if (ft_strcmp(arguments[0], "哈") == 0 || ft_strcmp(arguments[0], "\b") == 0)
	{
		free (arguments[0]);
		arguments[0] = ft_strdup (" ");
	}
	if (ft_strcmp("echo", ft_lower(command)) == 0)
		ft_echo(mini, arguments, FALSE);
	else if (ft_strcmp("echo -n", ft_lower(command)) == 0)
		ft_echo(mini, arguments, TRUE);
	else if (ft_strcmp("cd", ft_lower(command)) == 0)
		ft_cd(mini, arguments[0]);
	else if (ft_strcmp("pwd", ft_lower(command)) == 0)
		ft_pwd(mini);
	else if (ft_strcmp("export", ft_lower(command)) == 0)
		ft_export(mini, mini->args[0][0]);
	else if (ft_strcmp("unset", ft_lower(command)) == 0)
		ft_unset(mini, mini->args[0][0]);
	else if (ft_strcmp("env", ft_lower(command)) == 0)
		ft_env(mini);
}

void	exec_builtin(char *command, char **arguments, t_mini *mini)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;
	char	buffer[4096];
	ssize_t	nread;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		if (redir_builtin(mini) == -1)
			exit(EXIT_FAILURE);
		exec_builtin_with_redirection(command, arguments, mini, pipefd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[1]);
		nread = read(pipefd[0], buffer, sizeof(buffer));
		write(STDOUT_FILENO, buffer, nread);
		close(pipefd[0]);
		waitpid(pid, &status, 0);
	}
}
