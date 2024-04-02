/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 03:12:41 by javgao            #+#    #+#             */
/*   Updated: 2024/03/12 03:15:37 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_single_quote(char **str, char **new)
{
	(*str)++;
	while (**str != '\'')
	{
		if (**str == '>' || **str == '<')
		{
			chr_add (new, *(*str)++);
			chr_add (new, '\x01');
		}
		else
			chr_add (new, *(*str)++);
	}
	(*str)++;
}

static void	handle_double_quote(char **str, t_hash *hash, char **new)
{
	(*str)++;
	while (**str != '\"')
	{
		if (**str == '$' && *(*str + 1) && *(*str + 1) != ' '
			&& *(*str + 1) != '\'' && *(*str + 1) != '\"' && *(*str + 1) != '$')
			args_add_var (str, hash, new);
		else
		{
			if (**str == '>' || **str == '<')
			{
				chr_add (new, **str);
				chr_add (new, '\x01');
			}
			else
				chr_add (new, **str);
		}
		(*str)++;
	}
	(*str)++;
}

static void	handle_variable(char **str, t_hash *hash, char **new)
{
	if (**str == '$' && *(*str + 1) && *(*str + 1) != '$')
		args_add_var (str, hash, new);
	else
		chr_add (new, **str);
	(*str)++;
}

//liberable
char	*split_arg_filter(char *str, t_hash *hash)
{
	char	*new;

	new = NULL;
	while (*str)
	{
		if (*str == '\'')
			handle_single_quote (&str, &new);
		else if (*str == '\"')
			handle_double_quote (&str, hash, &new);
		else
			handle_variable (&str, hash, &new);
	}
	if (!new)
		chr_add (&new, '\b');
	return (new);
}
