/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:34:33 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/21 12:44:51 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	open_files(t_pipex *pipex, char **argv)
{
	if (pipex->flag_here_doc == TRUE)
	{
		pipex->infile = open("here_doc", O_CREAT | O_RDWR, 0644);
		if (pipex->infile == -1)
			print_error("Open failed to open here_doc");
		pipex->outfile = open(argv[pipex->argc - 1], O_CREAT | O_APPEND
				| O_WRONLY, 0644);
		if (pipex->outfile == -1)
			print_error("Open failed to open outfile");
	}
	else if (pipex->flag_here_doc == FALSE)
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
			print_error("Open failed to open infile");
		pipex->outfile = open(argv[pipex->argc - 1], O_CREAT | O_TRUNC
				| O_WRONLY, 0644);
		if (pipex->outfile == -1)
			print_error("Open failed to open outfile");
	}
}
