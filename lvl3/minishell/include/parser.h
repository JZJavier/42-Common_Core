/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:45 by yugao             #+#    #+#             */
/*   Updated: 2024/03/12 02:19:21 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "./minishell.h"

# define TRUE 1
# define FALSE 0
# define PIPE '|'
# define BIG '>'
# define LIT '<'
# define QUOTE_BIG '\"'
# define QUOTE_LIT '\''
# define PIPES "|"
# define BIGS ">"
# define LITS "<"
# define BIG_BIG ">>"
# define LIT_LIT "<<"
//=====arry_chr.c=====
int		chr_add(char **chrs, char c);
void	split_args(char ***args, char *ori);
int		is_not_key(char c);
//=====arry_strs.c=====
void	arry_init(char **ary, int size);
void	arry_destory(char **ary);
int		arry_add(char ***arys, char *val);
void	arry_display(char **ary);
void	arry_refresh(char ***arys, char **val);
int		arry_del(char ***args, int index);
int		arry_get_index(char **ary, char *val);
//=====arry_utils.c=====
int		is_strsame(char *s1, char *s2);
//=====arry_outfile.c===
char	**args_to_outfile(char ***args);
//=====arry_infile.c===
char	**args_to_infile(char ***args);
//=====arry_cmd.c=======
char	**args_to_cmds(char ***args);
char	***args_to_args(char **args);
void	argss_destory(char ***argss);
void	argss_display(char ***args);
char	**arg_abordar(char *ori);
int		arry_count(char **arys);
int		count_args(char **args);
//=====cmds_and_args.c===
char	**args_to_cmds_args(char **args);
char	**filter_args_infile(char **infile);

#endif