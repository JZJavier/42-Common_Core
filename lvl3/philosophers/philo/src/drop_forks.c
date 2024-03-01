/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils copy 2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:58:56 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 17:37:55 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	drop_forks(t_philo *philo, t_philo *other)
{
	if (*(philo->end) || *(other->end))
		return ;
	pthread_mutex_lock(philo->fork_mutex);
	philo->fork = 1;
	pthread_mutex_unlock(philo->fork_mutex);
	pthread_mutex_lock(other->fork_mutex);
	other->fork = 1;
	pthread_mutex_unlock(other->fork_mutex);
	philo->philo_forks = 0;
}
