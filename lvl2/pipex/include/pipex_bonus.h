/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:21:54 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/21 06:09:44 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define HASH_SIZE 200
# define TRUE 1
# define FALSE 0

typedef int		t_bool;

typedef struct s_node
{
	char			*key;
	char			*val;
	struct s_node	*next;
}				t_node;

typedef struct s_hash
{
	t_node	*bucket[HASH_SIZE];
}				t_hash;

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

/*	-------------------------- HERE_DOC --------------------------*/
void	here_doc(t_pipex *pipex);
void	here_pipex(t_pipex *pipex);
void	here_parent(t_pipex *pipex, int pipe_fd[2]);
void	here_child(t_pipex *pipex, int pipe_fd[2]);

/*	--------------------------- PIPEX ----------------------------*/
void	init_struct(t_pipex *pipex, int argc, char **argv, char **envp);
void	init_env(t_pipex *pipex, char **envp);
void	init_path(t_pipex *pipex);
void	open_files(t_pipex *pipex, char **argv);
void	print_error(char *message);
void	close_fds(t_pipex *pipex);
void	close_pipes_fd(t_pipex *pipex, int **pipe_fd);
void	ft_pipex(t_pipex *pipex);
void	ft_free_arr(char **arr);
void	ft_execute(t_pipex *pipex, char *commad);
void	multiple_pipes(t_pipex *pipex, int ***pipe_fd);
void	waitpids(t_pipex *pipex, int *status);

/*	------------------------- HASH LIST --------------------------*/
t_node	*list_init(void);
t_bool	list_push(t_node *l, char *key, char *val);
t_bool	list_del(t_node *l, char *key);
t_bool	list_grep(t_node *l, char *key);
t_bool	list_destory(t_node *l);
void	list_print(t_node *l);

/*	--------------------------- HASH ----------------------------*/
t_hash	*hash_init(void);
t_bool	hash_push(t_hash *h, char *key, char *val);
char	*hash_grep(t_hash *h, char *key);
t_bool	hash_destory(t_hash	*h);
t_bool	hash_del(t_hash	*h, char *key);
void	hash_display(t_hash	h);
char	**hash_to_arry(t_hash	*h);
int		hash_func(char *key);

/*	-------------------------- ARR_UTILS ---------------------------*/
int		is_strsame(char *s1, char *s2);
void	arry_init(char **ary, int size);
int		arry_count(char **arys);
char	**arry_cpy(char **ary);
int		arry_add(char ***arys, char *val);
void	arry_destroy(char **ary);

#endif