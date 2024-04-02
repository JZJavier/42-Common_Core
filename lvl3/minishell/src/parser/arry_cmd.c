/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:09:45 by javgao            #+#    #+#             */
/*   Updated: 2024/03/11 23:33:25 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//将comand 和后面的flag 合并在一起 并将修改作用到原来的数组中 无泄漏
static void	args_merge_cmds(char ***args, int keep_ori)
{
	int		i;
	char	*tem;
	char	*tem_join;

	i = 0;
	if (!*args || !**args)
		return ;
	while ((*args)[i])
	{
		if (i > 0 && (*args)[i][0] == '-' && (*args)[i - 1])
		{
			tem = (*args)[i - 1];
			tem_join = ft_strjoin (" ", (*args)[i]);
			(*args)[i - 1] = ft_strjoin (tem, tem_join);
			free (tem);
			free (tem_join);
			if (keep_ori == TRUE)
				arry_del (args, i);
			i --;
		}
		i ++;
	}
}

//这里传入的args必须是已经删除了输入重定向和输出重定向的二维数组, 输出一个单纯的有命令和flag还有管道符组成的数组
char	**args_to_cmds(char ***args)
{
	char	**new;
	int		i;

	new = NULL;
	i = 1;
	if (!*args || !**args)
		return (NULL);
	args_merge_cmds (args, TRUE);
	arry_add (&new, (*args)[0]);
	while ((*args)[i])
	{
		if (is_strsame ((*args)[i], "|") && (*args)[i + 1])
		{
			arry_add (&new, "|");
			arry_add (&new, (*args)[i + 1]);
		}
		i ++;
	}
	return (new);
}

//计算ori_arg中要分割成几个二维数组
int	count_args(char **args)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (!args || !*args)
		return (n);
	while (args[i])
	{
		if (is_strsame (args[i], PIPES))
			n ++;
		i ++;
	}
	return (n);
}

/* char	***args_to_args(char **args)
{
	char	***cmds;
	int		cmds_count;
	char	**current_args;
	int		i;
	int		has_args;

	if (!args || !*args || !**args)
		return (NULL);
	cmds = NULL;
	cmds_count = 0;
	current_args = NULL;
	i = 0;
	while (args[i] != NULL)
	{
		i++;
		has_args = 0;
		while (args[i] != NULL && !is_strsame(args[i], "|"))
		{
			arry_add(&current_args, args[i]);
			has_args = 1;
			i++;
		}
		if (!has_args)
			arry_add(&current_args, "哈");
		cmds_count ++;
		cmds = realloc(cmds, sizeof (char**) * (cmds_count + 1));
		cmds[cmds_count - 1] = current_args;
		cmds[cmds_count] = NULL;
		current_args = NULL;
		if (args[i] != NULL)
			i ++;
	}
	return (cmds);
} */
