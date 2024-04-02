/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:30:42 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/01 22:42:51 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pipex_bonus(t_mini *mini, int argc, char **argv, char**envp)
{
	t_pipex	pipex;

	if (argc < 5)
		ft_printf("Wrong amount of arguments: ./pipex file1 cmd1 cmd2 file2");
	else
	{
		init_struct(&pipex, argc, argv, envp);
		if (ft_strcmp(argv[1], "here_doc") == 0)
			pipex.flag_here_doc = TRUE;
		open_files_pipex(&pipex, mini, argv);
		if (pipex.flag_here_doc == TRUE)
		{
			here_doc(&pipex);
			unlink ("here_doc");
		}
		else
			ft_pipex(&pipex);
	}
	return (0);
}
