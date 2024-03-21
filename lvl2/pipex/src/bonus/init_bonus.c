/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:09:40 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/21 14:35:17 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	init_struct(t_pipex *pipex, int argc, char **argv, char **envp)
{
	init_env(pipex, envp);
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->path = hash_grep(pipex->hash_env, "PATH");
	if (pipex->path == NULL)
		print_error("Missing environment varibale: PATH");
	pipex->paths = NULL;
	pipex->infile = 0;
	pipex->outfile = 0;
	pipex->pipes_num = argc - 2;
	pipex->flag_here_doc = FALSE;
	pipex->flag_parent = FALSE;
	init_path(pipex);
}

void	init_env(t_pipex *pipex, char **envp)
{
	int		i;
	int		len_to_equal;
	char	*key;

	i = 0;
	len_to_equal = 0;
	pipex->hash_env = hash_init();
	while (envp[i])
	{
		len_to_equal = ft_strchrlen(envp[i], '=');
		key = ft_substr(envp[i], 0, len_to_equal);
		hash_push(pipex->hash_env, key, envp[i]);
		free (key);
		i++;
	}
}

void	init_path(t_pipex *pipex)
{
	char	*path;
	char	**paths;
	int		i;
	int		count;

	i = 0;
	path = ft_strtrim(pipex->path, "PATH=");
	paths = ft_split(path, ":");
	count = arry_count(paths);
	pipex->paths = (char **) malloc ((count + 1) * sizeof(char *));
	while (paths[i])
	{
		pipex->paths[i] = ft_strdup(paths[i]);
		i++;
	}
	pipex->paths[i] = NULL;
	free (path);
	ft_free_arr(paths);
}
