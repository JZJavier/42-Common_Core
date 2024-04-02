/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:30:31 by yugao             #+#    #+#             */
/*   Updated: 2024/03/14 12:35:12 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// 比较两个字符串是不是完全相等, 包括\0, 如果相等返回真
// Comparar si dos cadenas son completamente iguales, incluyendo el
// carácter '\0'. Si son iguales, devuelve verdadero.
int	is_strsame(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (FALSE);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (FALSE);
		s1 ++;
		s2 ++;
	}
	return (*s1 == *s2);
}

void	update_statu_write_outfile(t_mini *mini, char **outfile)
{
	if (!outfile)
	{
		mini->flag_output = FALSE;
		mini->flag_append_output = FALSE;
	}
	else if (is_strsame (outfile[arry_count (outfile) - 2], ">"))
	{
		mini->flag_output = TRUE;
		mini->flag_append_output = FALSE;
	}
	else
	{
		mini->flag_append_output = TRUE;
		mini->flag_output = FALSE;
	}
}

void	update_statu_write_dogii(t_mini *mini, char **infile)
{
	if (!infile)
	{
		mini->flag_input = FALSE;
		mini->flag_here_doc = FALSE;
	}
	else if (is_strsame (infile[arry_count (infile) - 2], "<"))
	{
		mini->flag_input = TRUE;
		mini->flag_here_doc = FALSE;
	}
	else
	{
		mini->flag_input = FALSE;
		mini->flag_here_doc = TRUE;
	}
}

void	g_sig_refresh(t_hash *hash, int new)
{
	char	*tem;
	char	*num;

	num = ft_itoa (new);
	tem = ft_strjoin ("?=", num);
	free (num);
	hash_push (hash, "?", tem);
	free (tem);
}
