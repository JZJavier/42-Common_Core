/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:06:23 by javgao            #+#    #+#             */
/*   Updated: 2024/04/02 00:00:50 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <curses.h>
# include <term.h>
# include "parser.h"
# include "hash.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <string.h>
# include <signal.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

# define TRUE 1
# define FALSE 0
# define SINGLE 1
# define PIPESS 0
# define REDIRECT 1
# define APPEND 2
//===builtins===
# define NUM_BUILTINS 7
# define HASH_SIZE 200
# define PROMPT "\x1b[1;32mminishell\x1b[0m\x1b[1;36m > \x1b[0m"

# define ERR0 "minishell: syntax error near unexpected token `newline'"
# define ERR1 "minishell: syntax error near unexpected token `>>'"
# define ERR2 "minishell: syntax error near unexpected token `<<'"
# define ERR3 "minishell: syntax error near unexpected token `<'"
# define ERR4 "minishell: syntax error near unexpected token `>'"
# define ERR5 "minishell: syntax error near unexpected token `|'"
# define INFILE "./Libft/ft_printf/.infile"
# define OUTFILE "./Libft/ft_printf/.outfile"

typedef int	t_bool;
typedef struct s_mini
{
	char	*line;
	char	**arg_ori;
	t_hash	*hash_env;
	char	**paths;
	char	**infile; //ABSOLUTE DIRECTION
	char	**outfile; //ABSOLUTE DIRECTION
	char	**commands; // "ls -l | hola echo dfd" ----> "ls -l" "|" "hola"
	char	***args; // "ls -l | hola echo dfd" ---> {""} {"echo" "dfd"}; 
	char	**cmds_and_args;
	int		is_echo_n; //Ver si hay que usar
	char	*is_builtin[NUM_BUILTINS + 1];
	int		argc;
	int		flag_output;
	int		flag_append_output;
	int		flag_unset_path;
	int		flag_here_doc;
	int		flag_input;
	char	**argv;
	char	**argv_out_here;
	char	**arry_hash;
	int		here_doc_file;
	int		here_outfile;
}			t_mini;

typedef struct s_cmd
{
	bool	found;
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	t_hash	*hash_env;
	char	*path;
	char	**paths;
	int		infile;
	int		outfile;
	int		pipes_num;
	int		flag_here_doc;
	int		flag_parent;
}				t_pipex;

int			g_sig;

/*	--------------------------- INIT --------------------------- */
void	init_mini(t_mini *mini, char **envp);
void	init_builtin(t_mini *mini);
void	init_env(t_mini *mini, char **envp);
void	shell_loop(t_mini *mini);
void	init_re(t_mini *mini);
void	check_file(t_mini *mini);

/*	-------------------------- BUILTIN ---------------------------*/
int		is_builtin(char *command, t_mini *mini);
void	exec_builtin(char *command, char **arguments, t_mini *mini);
int		redir_builtin(t_mini *mini);
void	exec_builtin_with_redirection(char *command, char **arguments,
			t_mini *mini, int pipefd[2]);
void	exec_builtin_without(char *command, char **arguments, t_mini *mini);
int		ft_echo(t_mini *mini, char **arguments, int flag);
int		ft_cd(t_mini *mini, char *argument);
int		ft_pwd(t_mini *mini);
int		ft_export(t_mini *mini, char *variable);
int		ft_unset(t_mini	*mini, char *variable);
int		ft_env(t_mini *mini);
int		ft_exit(char *line);

/*	-------------------------- EXECUTE ---------------------------*/
int		ft_execute(t_mini *mini);
int		single_command(t_mini *mini);
void	not_builtin(char	*command, char	**commands, t_mini *mini, int flag);
void	ft_exec_single(char *cmd, char **envp);
char	*join_args(char *command, char **arguments);
char	*ft_path(char *cmd, char **envp);
char	*ft_envp(char *variable, char **envp);
char	**check_cmds_and_args(t_mini *mini);
int		print(t_mini *mini);
void	open_all_files(t_mini *mini);
int		check_redir(t_mini *mini);

/*	----------------------- SINGLE HERE_DOC --------------------------*/
void	open_single_here_doc(t_mini *mini);
void	single_here_doc(t_mini *mini);

/*	-------------------------- SINGLE_REDIR ---------------------------*/
int		setup_input_redirection(t_mini *mini, char *input_file);
int		setup_output_redirection(t_mini *mini, char *output_file);
int		handle_parent_process(pid_t pid);
int		single_redir(t_mini *mini, char *command, char *infile, char *outfile);

/*	--------------------------- ERROR ----------------------------*/
int		print_error(char *error);

/*	--------------------------- SIGNAL ---------------------------*/
void	init_sig(void);
void	init_sig_child(void);
/*	---------------------------- FREE ----------------------------*/
void	ft_free_four(char **one, char **two, char **three, char **four);
void	ft_free_arr(char **arr);

/*	---------------------------- UTILS ----------------------------*/
char	*ft_lower(char *str);
void	update_statu_write_outfile(t_mini *mini, char **outfile);
void	update_statu_write_dogii(t_mini *mini, char **infile);
/*	---------------------------- EXPAND ----------------------------*/
char	**split_filter(char **args, t_hash *hash);

/*	---------------------------- EXPAND ----------------------------*/
char	**split_filter(char **args, t_hash *hash);
char	*split_arg_filter(char *str, t_hash *hash);
void	args_add_var(char **str, t_hash *hash, char **new);

/*	---------------------------- APOYO ------------------------------*/
char	**filter_add_path(char **args_file, t_hash *hash);

/*	---------------------------- GLOBAL ------------------------------*/
void	g_sig_refresh(t_hash *hash, int new);

/*	-------------------------- HERE_DOC --------------------------*/
void	here_doc(t_pipex *pipex);
void	here_pipex(t_pipex *pipex);
void	here_parent(t_pipex *pipex, int pipe_fd[2]);
void	here_child(t_pipex *pipex, int pipe_fd[2]);

/*	--------------------------- PIPEX ----------------------------*/
int		pipex_bonus(t_mini *mini, int argc, char **argv, char**envp);
void	init_struct(t_pipex *pipex, int argc, char **argv, char **envp);
void	init_env_pipex(t_pipex *pipex, char **envp);
void	init_path(t_pipex *pipex);
void	open_files_pipex(t_pipex *pipex, t_mini *mini, char **argv);
void	close_fds(t_pipex *pipex);
void	close_pipes_fd(t_pipex *pipex, int **pipe_fd);
void	ft_pipex(t_pipex *pipex);
void	ft_free_arr(char **arr);
void	ft_execute_pipex(t_pipex *pipex, char *commad);
void	multiple_pipes(t_pipex *pipex, int ***pipe_fd);
void	waitpids(t_pipex *pipex, int *status);

#endif
