/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:53:26 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/09 12:40:48 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

void	ft_exit(int n_exit);
int		ft_open(char *file, int n);
char	*ft_envp(char *variable, char **envp);
char	*ft_path(char *cmd, char **envp);
void	ft_exec(char *cmd, char **envp);
void	ft_free(char **arr);

#endif
