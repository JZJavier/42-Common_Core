/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:10:17 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 15:58:01 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_end(t_philo *philos, pthread_t *threads, int nbr)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(philos[0].end_m);
	if (threads)
	{
		while (i < nbr)
		{
			pthread_join(threads[i], NULL);
			i++;
		}
		free(threads);
	}
	if (philos)
		ft_free(philos, nbr);
	return (1);
}
