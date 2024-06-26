/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:49:13 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/31 22:50:43 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosopher_routine(void *arg)
{
	t_philo		*philosopher;
	pthread_t	id;

	philosopher = (t_philo *)arg;
	philosopher->last_eat_time = ft_time();
	philosopher->lifetime = philosopher->last_eat_time
		+ philosopher->simulation->time_to_die;
	if (pthread_create(&id, NULL, monitor, arg))
		return ((void *)TRUE);
	pthread_detach(id);
	while (1)
		eat(philosopher);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philosopher->action_mutex);
		if (!philosopher->eats && ft_time() > philosopher->lifetime)
		{
			write_message(philosopher, DEAD);
			pthread_mutex_lock(&philosopher->simulation->print_mutex);
			pthread_mutex_unlock(&philosopher->simulation->dead_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philosopher->action_mutex);
		usleep(1000);
	}
}

void	*eat_monitor(void *arg)
{
	t_simulation	*simulation;
	int				total_eats;
	int				total_eaten;
	int				i;

	simulation = (t_simulation *)arg;
	total_eaten = 0;
	total_eats = simulation->philosopher_count * simulation->eat_count;
	while (total_eaten < total_eats)
	{
		usleep(1000);
		total_eaten = 0;
		i = 0;
		while (i < simulation->philosopher_count)
		{
			pthread_mutex_lock(&simulation->eat_mutex);
			total_eaten += simulation->philosophers[i].eat_count;
			pthread_mutex_unlock(&simulation->eat_mutex);
			i++;
		}
	}
	write_message(&simulation->philosophers[0], TOTAL_MEALS);
	pthread_mutex_lock(&simulation->print_mutex);
	pthread_mutex_unlock(&simulation->dead_mutex);
	return (NULL);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->simulation->forks[philo->left_fork]);
	write_message(philo, FORK);
	pthread_mutex_lock(&philo->simulation->forks[philo->right_fork]);
	write_message(philo, FORK);
	philo->last_eat_time = ft_time();
	pthread_mutex_lock(&philo->action_mutex);
	philo->lifetime = philo->last_eat_time + philo->simulation->time_to_die;
	pthread_mutex_unlock(&philo->action_mutex);
	write_message(philo, EAT);
	usleep(philo->simulation->time_to_eat * 1000);
	pthread_mutex_lock(&philo->simulation->eat_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->simulation->eat_mutex);
	pthread_mutex_unlock(&philo->simulation->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork]);
	write_message(philo, SLEEP);
	usleep(philo->simulation->time_to_sleep * 1000);
	write_message(philo, THINK);
}
