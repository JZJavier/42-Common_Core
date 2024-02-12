/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:33:36 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/09 12:41:00 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

void	parent(char **argv, int *fdd, char **envp);
void	child(char **argv, int *fdd, char **envp);
void	ft_exec(char *cmd, char **envp);
char	*ft_path(char *cmd, char **envp);
char	*ft_envp(char *variable, char **envp);
void	ft_free(char **arr);
int		ft_open(char *file, int status);

#endif
