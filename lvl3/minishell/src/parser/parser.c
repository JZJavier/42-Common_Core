/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:24 by yugao             #+#    #+#             */
/*   Updated: 2024/03/12 21:19:09 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	quote_check(char *str)
{
	while (*str)
	{
		if (*str == '\'')
		{
			str ++;
			while (*str && *str != '\'')
				str ++;
			if (!*str)
				return (-1);
		}
		else if (*str == '\"')
		{
			str ++;
			while (*str && *str != '\"')
				str ++;
			if (!*str)
				return (-1);
		}
		str ++;
	}
	return (1);
}

static int	apoy_norme_check(char *str, char *nex, char *check)
{
	if (is_strsame (str, check) && is_strsame (nex, ">>"))
		return (print_error (ERR1), FALSE);
	if (is_strsame (str, check) && is_strsame (nex, "<<"))
		return (print_error (ERR2), FALSE);
	if (is_strsame (str, check) && is_strsame (nex, "<"))
		return (print_error (ERR3), FALSE);
	if (is_strsame (str, check) && is_strsame (nex, ">"))
		return (print_error (ERR4), FALSE);
	if (is_strsame (str, check) && is_strsame (nex, "|"))
		return (print_error (ERR5), FALSE);
	return (TRUE);
}

static int	norme_check(char **ori)
{
	int	len;
	int	i;

	i = 0;
	if (!ori)
		return (TRUE);
	len = arry_count (ori);
	if (is_strsame (ori[len - 1], "|") || is_strsame (ori[len - 1], ">")
		|| is_strsame (ori[len - 1], ">>") || is_strsame (ori[len - 1], "<")
		|| is_strsame (ori[len - 1], "<<"))
		return (print_error(ERR0), FALSE);
	while (i < len)
	{
		if (ori[i + 1] && !apoy_norme_check (ori[i], ori[i + 1], ">"))
			return (FALSE);
		if (ori[i + 1] && !apoy_norme_check (ori[i], ori[i + 1], ">>"))
			return (FALSE);
		if (ori[i + 1] && !apoy_norme_check (ori[i], ori[i + 1], "<"))
			return (FALSE);
		if (ori[i + 1] && !apoy_norme_check (ori[i], ori[i + 1], "<<"))
			return (FALSE);
		i ++;
	}
	return (TRUE);
}

char	**arg_abordar(char *ori)
{
	char	**new_arvs;

	if (!ori)
		return (NULL);
	if (!ori[0])
		return (NULL);
	if (quote_check (ori) == -1)
		return (print_error("Those quotes are not pared!"), NULL);
	new_arvs = NULL;
	split_args (&new_arvs, ori);
	if (!norme_check (new_arvs))
		return (arry_destory (new_arvs), NULL);
	return (new_arvs);
}
/*
int main (void)
{
	// situacion como ||||||| o >>>>>> o <<<<<<<< o <> ><   >>>>le3
	// 中间的">>"被当成文件了 所以le3没有被删除
	char	test[]=" ls >file1 >>file2 -la arg1[1] arg2[1]|grep >
	//file >>fill| cat -d arg1[3] | cd | ls arg1[4] arg2[4]";//write
	// a checker to theck the ilegal situation
	char	**ori_args;
	char	**outfile;
	char	**cmds;
	char	***argss;
	//char	**no_cmds;

	ori_args = arg_abordar (test);
	if (!ori_args)
		printf ("empty");
	//=======================================
	printf ("original args:\n");
	arry_display (ori_args);
	//=======================================
	outfile = args_to_outfile (&ori_args);
	printf ("outfile:\n");
	arry_display (outfile);
	//=======================================
	printf ("args sin outfiles:\n");
	arry_display (ori_args);
	//=======================================
	printf ("simple commands:\n");
	cmds = args_to_cmds (&ori_args);
	arry_display (cmds);
	arry_display (ori_args);
	//=======================================
	printf ("argumentossss:\n");
	argss = args_to_args (&ori_args);
	


	argss_destory (argss);
	arry_destory (cmds);
	arry_destory (ori_args);
	arry_destory (outfile);
	system ("leaks -q minishell");
	return 0;
}*/