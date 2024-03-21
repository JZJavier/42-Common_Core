/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:34:33 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/20 18:29:32 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	open_files(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		print_error("Open failed to open infile");
	pipex->outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->outfile == -1)
		print_error("Open failed to open outfile");
}
