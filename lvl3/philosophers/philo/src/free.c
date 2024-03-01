/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:10:17 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 18:54:37 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_free(t_philo *philos, int nbr)
{
	int	i;

	if (philos == NULL)
		return ;
	i = 0;
	while (i < nbr)
	{
		pthread_mutex_destroy(philos[i].fork_mutex);
		free(philos[i].fork_mutex);
		i++;
	}
	free(philos);
}
