/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:20:49 by javgao            #+#    #+#             */
/*   Updated: 2024/03/14 06:38:34 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_exit(char *line)
{
	int		spaces;
	char	*exit;

	spaces = 0;
	while (line[spaces] == ' ')
		spaces++;
	exit = ft_substr(line, spaces, ft_strlen(line));
	if (exit[4] == ' ' || (exit[4] >= 9 && exit[4] <= 13) || exit[4] == '\0')
	{
		if (ft_strncmp(exit, "exit", 3) == 0)
			return (TRUE);
	}
	free(exit);
	return (FALSE);
}
