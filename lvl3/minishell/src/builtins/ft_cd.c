/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/14 06:39:31 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	cd_no_arg(t_mini *mini)
{
	char	*home;
	char	*variable;
	char	*pwd;
	char	*oldpwd;

	if (hash_grep(mini->hash_env, "HOME") == NULL)
		return (print_error("cd: HOME not set"));
	else
	{
		home = ft_substr(hash_grep(mini->hash_env, "HOME"), 5,
				ft_strlen(hash_grep(mini->hash_env, "HOME")));
		chdir(home);
		pwd = ft_substr(hash_grep(mini->hash_env, "PWD"), 4,
				ft_strlen(hash_grep(mini->hash_env, "PWD")));
		variable = ft_strjoin("PWD=", home);
		oldpwd = ft_strjoin("OLDPWD=", pwd);
		ft_export(mini, variable);
		ft_export(mini, oldpwd);
		ft_free_four(&home, &variable, &oldpwd, &pwd);
	}
	return (EXIT_SUCCESS);
}

static int	cd_dot_dot(t_mini *mini)
{
	char	*oldpwd;
	char	*newpwd;
	char	*newoldpwd;

	if (ft_strcountchars(hash_grep(mini->hash_env, "PWD"), '/') == 1)
	{
		newpwd = ft_strdup("PWD=/");
		chdir("/");
	}
	else
	{
		newpwd = ft_substr(hash_grep(mini->hash_env, "PWD"), 0,
				ft_strrchrlen(hash_grep(mini->hash_env, "PWD"), '/'));
		chdir(newpwd + 4);
	}
	oldpwd = ft_substr(hash_grep(mini->hash_env, "PWD"), 4,
			ft_strlen(hash_grep(mini->hash_env, "PWD")));
	newoldpwd = ft_strjoin("OLDPWD=", oldpwd);
	ft_export(mini, newpwd);
	ft_export(mini, newoldpwd);
	free (oldpwd);
	free(newpwd);
	free(newoldpwd);
	return (EXIT_SUCCESS);
}

static int	cd_word(t_mini *mini, char *argument)
{
	char	*pwd;
	char	*pwd_with_slash;
	char	*oldpwd;
	char	*newoldpwd;
	int		flag;

	flag = FALSE;
	if (ft_strrchr(argument, '/') != NULL)
	{
		argument = ft_strtrim(argument, "/");
		flag = TRUE;
	}
	if (access(argument, F_OK) == -1 || chdir(argument) == -1)
		return (print_error("cd: can't open the folder"));
	pwd_with_slash = ft_strjoin(hash_grep(mini->hash_env, "PWD"), "/");
	pwd = ft_strjoin(pwd_with_slash, argument);
	ft_export(mini, pwd);
	oldpwd = ft_substr(hash_grep(mini->hash_env, "PWD"), 4,
			ft_strlen(hash_grep(mini->hash_env, "PWD")));
	newoldpwd = ft_strjoin("OLDPWD=", oldpwd);
	ft_export(mini, newoldpwd);
	if (flag == TRUE)
		free(argument);
	ft_free_four(&pwd_with_slash, &pwd, &oldpwd, &newoldpwd);
	return (EXIT_SUCCESS);
}

int	ft_cd(t_mini *mini, char *argument)
{
	if (hash_grep(mini->hash_env, "OLDPWD") == NULL)
		hash_push(mini->hash_env, "OLDPWD=", ft_substr(
				hash_grep(mini->hash_env, "PWD"), 4,
				ft_strlen(hash_grep(mini->hash_env, "PWD"))));
	if (argument == NULL || !*argument || ft_strcmp(argument, " ") == 0
		|| ft_strcmp(argument, "哈") == 0)
		return (cd_no_arg(mini));
	else if (ft_strcmp(argument, "..") == 0)
		return (cd_dot_dot(mini));
	else if (argument[0] == '.')
		return (EXIT_SUCCESS);
	else
		return (cd_word(mini, argument));
	return (EXIT_SUCCESS);
}
