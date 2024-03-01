/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:10:17 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 18:52:27 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philo_print(int time, char *message, t_philo *philo)
{
	pthread_mutex_lock(philo->end_m);
	if (!*philo->end)
		printf("%d philo[%d] %s\n", time, philo->philo_id, message);
	pthread_mutex_unlock(philo->end_m);
}
