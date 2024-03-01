/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:59:01 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 18:51:46 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	time_to_die(t_philo *philo)
{
	if (ft_time() - philo->time_to_die > philo->time_last_meal)
	{
		philo_print(ft_time(), "died", philo);
		pthread_mutex_lock(philo->end_m);
		*philo->end = 1;
		pthread_mutex_unlock(philo->end_m);
	}
}

void	time_to_eat(t_philo *philo, t_philo *other)
{
	if (*(philo->end))
		return ;
	philo_print(ft_time(), "is eating", philo);
	philo->time_last_meal = ft_time();
	while (!*(philo->end) && ft_time() < philo->time_last_meal
		+ philo->time_to_eat)
		time_to_die(philo);
	drop_forks(philo, other);
	philo->philo_total_meals -= 1;
	philo->philo_status = NEEDS_SLEEP;
}

void	time_to_sleep(t_philo *philo)
{
	int	start;

	if (*(philo->end))
		return ;
	start = ft_time();
	philo_print(ft_time(), "is sleeping", philo);
	while (!*(philo->end) && ft_time() < start + philo->time_to_sleep)
		time_to_die(philo);
	philo->philo_status = NEEDS_THINK;
}

void	time_to_think(t_philo *philo, t_philo *other)
{
	if (*(philo->end) || *(other->end))
		return ;
	philo_print(ft_time(), "is thinking", philo);
	while (!*(philo->end) && philo->philo_forks < 2)
	{
		take_forks(philo, other);
		time_to_die(philo);
	}
	philo->philo_status = NEEDS_EAT;
}
