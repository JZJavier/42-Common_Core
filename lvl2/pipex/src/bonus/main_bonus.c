/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:30:42 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/21 14:31:03 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

int	main(int argc, char **argv, char**envp)
{
	t_pipex	pipex;

	if (argc < 5)
		ft_printf("Wrong amount of arguments: ./pipex file1 cmd1 cmd2 file2");
	else
	{
		init_struct(&pipex, argc, argv, envp);
		if (ft_strcmp(argv[1], "here_doc") == 0)
			pipex.flag_here_doc = TRUE;
		open_files(&pipex, argv);
		if (pipex.flag_here_doc == TRUE)
		{
			here_doc(&pipex);
			unlink ("here_doc");
		}
		else
			ft_pipex(&pipex);
	}
}
