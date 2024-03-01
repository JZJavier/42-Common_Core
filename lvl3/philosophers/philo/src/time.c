/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:59:06 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 16:11:34 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_time(void)
{
	struct timeval	time;
	static int		t = 0;

	gettimeofday(&time, NULL);
	if (t == 0)
		t = time.tv_sec;
	return (((time.tv_sec - t) * 1000) + (time.tv_usec / 1000));
}
