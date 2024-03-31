/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:51:01 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/31 22:51:09 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	write_message(t_philo *philo, int type)
{
	pthread_mutex_lock(&philo->simulation->print_mutex);
	printf("%llu\t", ft_time() - philo->simulation->start_time);
	if (type == EAT)
		printf("%d is eating\n", philo->position + 1);
	else if (type == SLEEP)
		printf("%d is sleeping\n", philo->position + 1);
	else if (type == THINK)
		printf("%d is thinking\n", philo->position + 1);
	else if (type == TOTAL_MEALS)
	{
		printf("Total meals eated %d\n", philo->simulation->eat_count
			* philo->simulation->philosopher_count);
		exit (0);
	}
	else if (type == FORK)
		printf("%d taken fork\n", philo->position + 1);
	else
	{
		printf("%d is dead\n", philo->position + 1);
		exit (0);
	}
	pthread_mutex_unlock(&philo->simulation->print_mutex);
}
