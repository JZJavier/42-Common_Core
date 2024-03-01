/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:58:56 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 17:42:02 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philo_total_meals(t_philo *philo)
{
	if (philo->philo_total_meals < 0)
		return ;
	if (!philo->philo_total_meals)
		*philo->total_meals += 1;
	if (*philo->total_meals == philo->philo_num)
		*philo->end = 1;
}
