/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:44:33 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 12:58:29 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int x, unsigned int y)
{
	int lcm;

	if (x == 0 || y == 0)
		return (0);
	if (x > y)
		lcm = x;
	else
		lcm = y;
	while (1)
	{
		if (lcm % x == 0 && lcm % y == 0)
			return (lcm);
		++lcm;
	}
}
