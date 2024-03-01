/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:59:01 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 17:35:30 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *arguments)
{
	t_args	*args;
	t_philo	*philo1;
	t_philo	*philo2;
	int		end;

	args = (t_args *) arguments;
	if (args == NULL || args->philo1 == NULL || args->philo2 == NULL)
		return (NULL);
	philo1 = args->philo1;
	philo2 = args->philo2;
	if (philo1->philo_id % 2)
		usleep(3000);
	while (!(*(philo1->end)))
	{
		if (!philo1->philo_total_meals)
			break ;
		pthread_mutex_lock(philo1->end_m);
		end = *(philo1->end);
		pthread_mutex_unlock(philo1->end_m);
		if (end)
			break ;
		philo_process(philo1, philo2);
	}
	free(arguments);
	return (NULL);
}

void	philo_process(t_philo *philo, t_philo *other)
{
	time_to_die(philo);
	if (*(philo->end))
		return ;
	if (philo->philo_status == NEEDS_EAT)
		time_to_eat(philo, other);
	else if (philo->philo_status == NEEDS_SLEEP)
		time_to_sleep(philo);
	else if (philo->philo_status == NEEDS_THINK)
		time_to_think(philo, other);
}
