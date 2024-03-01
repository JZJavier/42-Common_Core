/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:58:48 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/01 12:29:23 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_philos(t_philo *philos, char **argv, int argc, int *end)
{
	int	i;
	int	goal;

	if (argc == 6)
		goal = ft_atoi(argv[5]);
	else
		goal = -1;
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].philo_id = i + 1;
		philos[i].philo_status = 2;
		philos[i].philo_total_meals = goal;
		philos[i].philo_num = ft_atoi(argv[1]);
		philos[i].fork = 1;
		philos[i].philo_forks = 0;
		philos[i].end = end;
		philos[i].fork_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philos[i].fork_mutex)
			return (1);
		pthread_mutex_init(philos[i].fork_mutex, NULL);
		i++;
	}
	init_philos2(philos, argv);
	return (0);
}

int	init_philos2(t_philo *philos, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].time_last_meal = ft_time();
		i++;
	}
	return (0);
}

void	init_ends(t_philo *philos, int *total_meals, pthread_mutex_t *end_m)
{
	int	i;

	i = 0;
	while (i < philos[0].philo_num)
	{
		philos[i].total_meals = total_meals;
		philos[i].end_m = end_m;
		i++;
	}
}

int	init_threads(pthread_t *th, int nbr, t_philo *philos)
{
	int		i;
	t_args	*args;

	i = 0;
	while (i < nbr)
	{
		args = malloc(sizeof(t_args));
		if (!args)
			return (1);
		args->philo1 = &philos[i];
		if (i == 0)
			args->philo2 = &philos[nbr - 1];
		else
			args->philo2 = &philos[i - 1];
		if (pthread_create(&th[i], NULL, routine, (void *)args) != 0)
			return (1);
		i++;
	}
	return (0);
}
