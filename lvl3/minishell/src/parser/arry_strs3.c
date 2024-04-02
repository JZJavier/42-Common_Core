/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_chr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:52:07 by yugao             #+#    #+#             */
/*   Updated: 2024/03/11 20:15:59 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_not_key(char c)
{
	if (c != ' ' && c != '|' && c != '>' && c != '<'
		&& c != QUOTE_BIG && c != QUOTE_LIT)
		return (TRUE);
	return (FALSE);
}

void	argss_display(char ***args)
{
	int	i;

	i = 0;
	if (!args || !*args)
		return ;
	while (args[i])
	{
		arry_display (args[i]);
		i ++;
	}
}

//销毁三维数组
void	argss_destory(char ***argss)
{
	char	***ori;

	ori = argss;
	if (!argss || !*argss)
		return ;
	while (*argss)
	{
		arry_destory(*argss);
		argss++;
	}
	free(ori);
}
