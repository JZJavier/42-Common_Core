/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:34:01 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/09 05:59:28 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char *file, int in_or_out)
{
	int	fd;

	if (in_or_out == 0)
		fd = open(file, O_RDONLY, 777);
	if (in_or_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (fd == -1)
		exit(0);
	return (fd);
}

void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*ft_envp(char *variable, char **envp)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (ft_strcmp(sub, variable) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}
