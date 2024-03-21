/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:30:42 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/20 18:33:29 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	main(int argc, char **argv, char**envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_printf("Wrong amount of arguments: ./pipex file1 cmd1 cmd2 file2");
	else
	{
		init_struct(&pipex, argv, envp);
		open_files(&pipex, argv);
		ft_pipex(&pipex);
	}
	return (0);
}
