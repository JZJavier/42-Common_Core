/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:58:56 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 17:37:47 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_forks(t_philo *philo, t_philo *other)
{
	if (*(philo->end) || *(other->end))
		return ;
	pthread_mutex_lock(philo->fork_mutex);
	if (philo->fork)
	{
		philo_print(ft_time(), "has taken a fork", philo);
		philo->fork = 0;
		philo->philo_forks += 1;
	}
	pthread_mutex_unlock(philo->fork_mutex);
	if (philo->philo_forks == 2)
		return ;
	pthread_mutex_lock(other->fork_mutex);
	if (other->fork)
	{
		philo_print(ft_time(), "has taken a fork", philo);
		other->fork = 0;
		philo->philo_forks += 1;
	}
	pthread_mutex_unlock(other->fork_mutex);
}
