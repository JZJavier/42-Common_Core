/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:47:44 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/30 21:37:24 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philosophers(t_simulation *simulation, int philosopher_count)
{
	int	i;

	i = 0;
	while (i < philosopher_count)
	{
		pthread_mutex_init(&simulation->forks[i], NULL);
		pthread_mutex_init(&simulation->philosophers[i].action_mutex, NULL);
		simulation->philosophers[i].position = i;
		simulation->philosophers[i].eat_count = 0;
		simulation->philosophers[i].eats = 0;
		simulation->philosophers[i].left_fork = i;
		simulation->philosophers[i].right_fork = (i + 1) % philosopher_count;
		simulation->philosophers[i].simulation = simulation;
		i++;
	}
	return (TRUE);
}

int	init_struct(int argc, char **argv, t_simulation *simulation)
{
	simulation->philosopher_count = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		simulation->eat_count = ft_atoi(argv[5]);
	else
		simulation->eat_count = -1;
	if (init_philosophers(simulation, simulation->philosopher_count) == FALSE)
		return (printf("Failed to initialize philosophers.\n"), FALSE);
	pthread_mutex_init(&simulation->print_mutex, NULL);
	pthread_mutex_init(&simulation->dead_mutex, NULL);
	simulation->start_time = ft_time();
	return (TRUE);
}

int	start_simulation(t_simulation *simulation)
{
	pthread_t	threads[MAX_PHILOS];
	int			i;

	i = 0;
	if (simulation->eat_count > 0)
	{
		if (pthread_create(&threads[0], NULL, eat_monitor, simulation))
			return (printf("Failed to create eat monitor thread.\n"));
	}
	while (i < simulation->philosopher_count)
	{
		if (pthread_create(&threads[i], NULL, philosopher_routine,
				&simulation->philosophers[i]))
			return (printf("Failed to create philosopher thread.\n"), FALSE);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < simulation->philosopher_count)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (TRUE);
}
