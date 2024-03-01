/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:57:51 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 22:48:06 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo			*philos;
	pthread_t		*threads;
	int				end;
	int				total_meals;
	pthread_mutex_t	end_mutex;

	end = 0;
	total_meals = 0;
	if (args_validate(argc, argv) != 0)
		return (1);
	if (argc != 5 && argc != 6)
		return (print_error("Invalid amount of arguments, needed 5 or 6"));
	pthread_mutex_init(&end_mutex, NULL);
	philos = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	if (!philos || init_philos(philos, argv, argc, &end))
		return (philo_end(philos, NULL, ft_atoi(argv[1])));
	init_ends(philos, &total_meals, &end_mutex);
	threads = malloc(ft_atoi(argv[1]) * sizeof(pthread_t));
	if (!threads || init_pinit_threadshilos(threads, ft_atoi(argv[1]), philos))
		return (philo_end(philos, threads, ft_atoi(argv[1])));
	return (philo_end(philos, threads, ft_atoi(argv[1])));
}
