/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:49:13 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/10 18:11:04 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	arry_destroy(char **ary)
{
	int	i;

	i = 0;
	if (!ary || !*ary)
		return ;
	while (ary[i])
	{
		free (ary[i]);
		i ++;
	}
	if (ary)
		free (ary);
}
