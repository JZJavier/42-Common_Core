/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:47:49 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/30 21:54:49 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_simulation	simulation;

	if (argc < 5 || argc > 6)
		return (printf("Invalid number of arguments.\n"));
	if (parse(argv) == FALSE)
		return (-1);
	if (init_struct(argc, argv, &simulation) == FALSE)
		return (printf("Initialization failed.\n"));
	if (start_simulation(&simulation) == FALSE)
		return (printf("Simulation failed to start.\n"));
	pthread_mutex_lock(&simulation.dead_mutex);
	return (0);
}
