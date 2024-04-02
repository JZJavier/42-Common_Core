/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:16:29 by javgao            #+#    #+#             */
/*   Updated: 2024/03/31 05:14:09 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	setup_input_redirection(t_mini *mini, char *input_file)
{
	int	in_fd;

	if (mini->flag_input == TRUE)
		in_fd = open(input_file, O_RDONLY, 0777);
	else
		in_fd = open(INFILE, O_RDONLY, 0777);
	if (in_fd == -1)
		return (print_error("open failed on infile redirection"));
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	return (0);
}

int	execute_command(t_mini *mini, char *command)
{
	(void)command;
	ft_exec_single(mini->cmds_and_args[0], mini->arry_hash);
	exit(0);
}

int	setup_output_redirection(t_mini *mini, char *output_file)
{
	int	out_fd;

	if (mini->flag_output == TRUE)
		out_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (mini->flag_append_output == TRUE)
		out_fd = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		out_fd = open (OUTFILE, O_RDWR | O_TRUNC, 0666);
	if (out_fd == -1)
		return (print_error("open failed on outfile redirection"));
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	return (0);
}

int	handle_parent_process(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED (status))
		g_sig = WEXITSTATUS(status);
	return (0);
}

int	single_redir(t_mini *mini, char *command, char *infile, char *outfile)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (print_error("fork"));
	else if (pid == 0)
	{
		setup_input_redirection(mini, infile);
		setup_output_redirection(mini, outfile);
		execute_command(mini, command);
	}
	else
	{
		handle_parent_process(pid);
		waitpid(pid, &status, 0);
	}
	return (0);
}
